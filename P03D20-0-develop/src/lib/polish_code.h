//#ifdef SRC_POLYSH_H
//#define SRC_POLYSH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEPARATOR " "

typedef struct polish_stack {
  char *full_name;
  char *sym;
  int priority;
  struct polish_stack *back;
} p_stack;

p_stack *init_p_item(char *f_name, char *c_name, int priority);
int push_p_item(p_stack *item, p_stack **stack);
p_stack *pop_p_item(p_stack **stack);

int pop_operator_to_str(char *str, p_stack **stack, int priority);
p_stack *find_operator(char *stroke, p_stack *op_prior);
int print_symbol(char *str, char *sym);
int print_separator(char *str);
p_stack *read_operator(char *p_str, p_stack *op_prior);

char *replace_variable(char *dst, char *name, double value);
int str_cut(char *str, int begin, int len);

char *polysh_code(char *str, p_stack *op_prior);

int is_digit(char sym);

//#endif  // SRC_POLYSH_H_