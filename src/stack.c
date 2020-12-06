#include "include/stack.h"

#include <stdio.h>

void pop(Stack* cntnr) {
    if (cntnr->head == NULL) return;
    cntnr->size--;
    Node* aux = cntnr->head;
    if (aux->data_type == _str_) {
        while (aux->Data._char != '\0') {
            cntnr->head = aux->next;
            free(aux);
            aux = cntnr->head;
        }
        cntnr->head = aux->next;
        free(aux);
        aux = cntnr->head;
        return;
    }
    cntnr->head = aux->next;
    free(aux);
    return;
}
bool empty(Stack cntnr) {
    if (cntnr.head == NULL)
        return true;
    else
        return false;
}
void init_stack(Stack* cntnr) {
    cntnr->size = 0;
    cntnr->head = NULL;
    return;
}
void free_stack(Stack* cntnr) {
    Node *bff_1, *bff_2 = cntnr->head->next;
    free(cntnr->head);
    cntnr->head = NULL;
    while (bff_2 != NULL) {
        bff_1 = bff_2->next;
        free(bff_2);
        bff_2 = bff_1;
    }
    return;
}
void swap(Stack* stck_1, Stack* stck_2) {
    Stack aux = *stck_1;
    *stck_1   = *stck_2;
    *stck_2   = aux;
    return;
}
void push(Stack* cntnr, void* data, unsigned data_type) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    switch (data_type) {
        case _int_:
            new_node->data_type = _int_;
            new_node->Data._int = *((int*) data);
            break;
        case _uint_:
            new_node->data_type  = _uint_;
            new_node->Data._uint = *((unsigned*) data);
            break;
        case _char_:
            new_node->data_type  = _char_;
            new_node->Data._char = *((char*) data);
            break;
        case _str_: {
            char* str            = (char*) data;
            new_node->data_type  = _str_;
            new_node->Data._char = '\0';
            new_node->next       = cntnr->head;
            cntnr->head          = new_node;
            for (long long j = strlen(str) - 1; - 1 < j; j--) {
                new_node             = (Node*) malloc(sizeof(Node));
                new_node->data_type  = _str_;
                new_node->Data._char = str[j];
                new_node->next       = cntnr->head;
                cntnr->head          = new_node;
            }
            cntnr->size++;
        }
            return;
        case _double_:
            new_node->data_type    = _double_;
            new_node->Data._double = *((double*) data);
            break;
    }
    new_node->next = cntnr->head;
    cntnr->head    = new_node;
    cntnr->size++;

    return;
}

int top_int(Stack cntnr) {
    if (cntnr.head->data_type != _int_) {
        return 0;
    }
    return cntnr.head->Data._int;
}
char* top_str(Stack cntnr) {
    if (cntnr.head->data_type != _str_) {
        return (char*) NULL;
    }

    Node*     head = cntnr.head;
    long long len  = 0;
    while (head->Data._char != '\0') {
        len++;
        head = head->next;
    }
    len++;

    char* str = (char*) calloc(len, sizeof(char));
    head      = cntnr.head;
    len--;
    for (long long i = 0; i < len; i++) {
        str[i] = head->Data._char;
        head   = head->next;
    }

    return str;
}
char top_char(Stack cntnr) {
    if (cntnr.head->data_type != _char_) {
        return '\0';
    }
    return cntnr.head->Data._char;
}
unsigned top_uint(Stack cntnr) {
    if (cntnr.head->data_type != _uint_) {
        return 0U;
    }
    return cntnr.head->Data._uint;
}
double top_double(Stack cntnr) {
    if (cntnr.head->data_type != _double_) {
        return 0.0;
    }
    return cntnr.head->Data._double;
}

// Solo falta la funcion free