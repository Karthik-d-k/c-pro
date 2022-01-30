# config
COMPILER=gcc
VERSION=c17
FLAGS=-Wall -Wextra -lm

SRC_FILES=$(wildcard *.c)
OUT_FILES=$(patsubst %.c, %.out, $(SRC_FILES))

## binaries     : Compile all *.c files
.PHONY : binaries
binaries : $(OUT_FILES)

## *.out        : Compile single *.c file 
%.out : %.c
	$(COMPILER) $< -std=$(VERSION) $(FLAGS) -o $@

## clean        : Remove auto-generated files
.PHONY : clean
clean :
	rm -f *.out

## variables    : Print source and out files 
.PHONY : variables
variables:
	@echo SRC_FILES: $(SRC_FILES)
	@echo OUT_FILES: $(OUT_FILES)

.PHONY : help
help : Makefile
	@sed -n 's/^##//p' $<

# resource + motivation :- \
Mike Jackson (ed.): "Software Carpentry: Automation and Make." \
Version 2016.06, June 2016, \
https://github.com/swcarpentry/make-novice, 10.5281/zenodo.57473.
