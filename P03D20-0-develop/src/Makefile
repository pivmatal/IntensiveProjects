GCC = gcc-11
FLAGS = -Wall -Wextra -Werror
CFLAGS = $(FLAGS) -c
RM = rm -rf
MKDIR = mkdir -p
TMP = temp

all: clean makedir graph

graph: $(TMP)/graph.o $(TMP)/polish.o $(TMP)/calculator.o
	$(GCC) $(FLAGS) $^ -o $@
	./$@

$(TMP)/graph.o: graph.c
	$(GCC) $(CFLAGS) $^ -o $@

$(TMP)/polish.o: lib/polish_code.c
	$(GCC) $(CFLAGS) $^ -o $@

$(TMP)/calculator.o: lib/calculator.c
	$(GCC) $(CFLAGS) $^ -o $@

makedir:
	$(MKDIR) $(TMP)

clean: 
	$(RM) $(TMP)