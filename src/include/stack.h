#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// Tipos de datos que soporta el stack
enum _DATA_TYPES {
    _int_,
    _uint_,
    _char_,
    _str_,
    _double_,
};

struct Stack {
    size_t size;
    Node*  head;
};

typedef struct Stack Stack;

void pop(Stack* cntnr);
bool empty(Stack cntnr);
void init_stack(Stack* cntnr);
void free_stack(Stack* cntnr);
void swap(Stack* stck_1, Stack* stck_2);
void push(Stack* cntnr, void* data, unsigned data_type);

int      top_int(Stack cntnr);
char*    top_str(Stack cntnr);
unsigned top_uint(Stack cntnr);
char     top_char(Stack cntnr);
double   top_double(Stack cntnr);

#endif  // STACK_H_INCLUDED
