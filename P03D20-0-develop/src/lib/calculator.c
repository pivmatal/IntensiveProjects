#include "calculator_polish.h"

d_stack *init_d_item(double value) {
  d_stack *item = (d_stack *)malloc(sizeof(d_stack *));
  item->value = value;
  item->back = NULL;
  return item;
}
int push_d_item(double value, d_stack **stack) {
  d_stack *item = init_d_item(value);
  item->back = *stack;
  *stack = item;
  return !!stack;
}
double pop_d_item(d_stack **stack) {
  d_stack *out = *stack;
  *stack = out->back;
  double res = out->value;

  return res;
}

double calculator_polish(char *str) {
  d_stack *stack = init_d_item(-9999);

  while (*str) {
    switch (*str) {
    case ' ':
    case '\n':
    case '=':
      break;
    case '+':
      push_d_item(pop_d_item(&stack) + pop_d_item(&stack), &stack);
      break;
    case '-':
      push_d_item(pop_d_item(&stack) - pop_d_item(&stack), &stack);
      break;
    case '*':
      push_d_item(pop_d_item(&stack) * pop_d_item(&stack), &stack);
      break;
    case '/':
      push_d_item(pop_d_item(&stack) / pop_d_item(&stack), &stack);
      break;
    case 's':
      push_d_item(sin(pop_d_item(&stack)), &stack);
      break;
    case 'c':
      push_d_item(cos(pop_d_item(&stack)), &stack);
      break;
    case 't':
      push_d_item(tan(pop_d_item(&stack)), &stack);
      break;
    case 'g':
      push_d_item(1 / tan(pop_d_item(&stack)), &stack);
      break;
    case 'q':
      push_d_item(sqrt(pop_d_item(&stack)), &stack);
      break;
    case 'l':
      push_d_item(log10(pop_d_item(&stack)), &stack);
      break;
    default:
      char *string = (char *)malloc(sizeof(char *) * 20);
      if (*string != '0' && *string != '.') {
        sscanf(str, "%s", string);
        double temp = 0;
        temp = atof(string);
        push_d_item(temp, &stack);
      }

      int length = strlen(string);
      str += length;

      break;
    }
    str++;
  }

  return pop_d_item(&stack);
}
