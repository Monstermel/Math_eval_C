#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Node {
    union {
        int      _int;
        char     _char;
        unsigned _uint;
        double   _double;
    } Data;
    unsigned     data_type;
    struct Node* next;
};

typedef struct Node Node;

#endif  // LIST_H_INCLUDED