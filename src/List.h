#ifndef LIST_H
#define LIST_H

#include "SymbolType.h"
#include "SymbolTable.h"

extern SymbolTable symbol_table;

struct List {
    int size;
    TokenNUM* x;
    List* next;
    List();
    List(TokenNUM* _x);
};

void list_add(List *head, List *head2);

void list_append(List *head, TokenNUM* tmp);

void list_print(List *head, TokenARRAY* arr = NULL);

TokenNUM* list_get(List *head,int num);

struct ExpList {
    int size;
    Const* x;
    ExpList* next;
    ExpList();
    ExpList(Const* _x);
};

void list_append(ExpList *head, Const* tmp);

#endif
