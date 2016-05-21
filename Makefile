##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
##
## This library is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library.  If not, see <http://www.gnu.org/licenses/>.
##

PREFIX		?= arm-none-eabi
#PREFIX		?= arm-elf

STYLECHECK      := scripts/checkpatch.pl
STYLECHECKFLAGS := --no-tree -f --terse --mailback

space:=
space+=
SRCLIBDIR:= $(subst $(space),\$(space),$(realpath lib))

TARGETS:= stm32/f0 stm32/f1 stm32/f2 stm32/f3 stm32/f4 stm32/f7 \
	  stm32/l0 stm32/l1 stm32/l4 \
	  lpc13xx lpc17xx lpc43xx/m4 lpc43xx/m0 lm3s lm4f \
	  efm32/tg efm32/g efm32/lg efm32/gg k20dx \
	  sam/3a sam/3n sam/3s sam/3u sam/3x \
	  vf6xx

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
Q := @
# Do not print "Entering directory ...".
MAKEFLAGS += --no-print-directory
endif

IRQ_DEFN_FILES	:= $(shell find . -name 'irq.json')
STYLECHECKFILES := $(shell find . -name '*.[ch]')

all: build

build: lib

%.genhdr:
	@printf "  GENHDR  $*\n";
	@./scripts/irq2nvic_h ./$*;

%.cleanhdr:
	@printf "  CLNHDR  $*\n";
	@./scripts/irq2nvic_h --remove ./$*

LIB_DIRS:=$(wildcard $(addprefix lib/,$(TARGETS)))
$(LIB_DIRS): $(IRQ_DEFN_FILES:=.genhdr)
	@printf "  BUILD   $@\n";
	$(Q)$(MAKE) --directory=$@ SRCLIBDIR="$(SRCLIBDIR)"

lib: $(LIB_DIRS)
	$(Q)true

html doc:
	$(Q)$(MAKE) -C doc html

clean: $(IRQ_DEFN_FILES:=.cleanhdr) $(LIB_DIRS:=.clean) $(EXAMPLE_DIRS:=.clean) doc.clean styleclean

%.clean:
	$(Q)if [ -d $* ]; then \
		printf "  CLEAN   $*\n"; \
		$(MAKE) -C $* clean SRCLIBDIR="$(SRCLIBDIR)" || exit $?; \
	fi;


stylecheck: $(STYLECHECKFILES:=.stylecheck)
styleclean: $(STYLECHECKFILES:=.styleclean)

# the cat is due to multithreaded nature - we like to have consistent chunks of text on the output
%.stylecheck: %
	$(Q)if ! grep -q "* It was generated by the irq2nvic_h script." $* ; then \
		$(STYLECHECK) $(STYLECHECKFLAGS) $* > $*.stylecheck; \
		if [ -s $*.stylecheck ]; then \
			cat $*.stylecheck; \
		else \
			rm -f $*.stylecheck; \
		fi; \
	fi;

%.styleclean:
	$(Q)rm -f $*.stylecheck;


LDTESTS		:=$(wildcard ld/tests/*.data)

genlinktests: $(LDTESTS:.data=.ldtest)

%.ldtest:
	@if ./scripts/genlinktest.sh $* >/dev/null; then\
		printf "  TEST  OK  : $*\n";		\
	else						\
		printf "  TEST FAIL : $*\n";		\
	fi;


.PHONY: build lib $(LIB_DIRS) doc clean generatedheaders cleanheaders stylecheck genlinktests
