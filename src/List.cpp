#include "List.h"

List::List() {
    x = nullptr;
    next = nullptr;
    size = 1;
}

List::List(TokenNUM* _x) {
    x = _x;
    next = nullptr;
    size = 1;
}

void list_append(List *head, TokenNUM* tmp) {
    auto i = head;
    while (i->next) {
        i -> size++;
        i = i->next;
    }
    i -> size++;
    i -> next = new List(tmp);
}

TokenNUM* list_get(List *head,int num){
    auto i = head;
    if(num<=head->size){
        for(int j=1;j<=num;j++){
            i=i->next;
        }
        return i->x;
    }
    return nullptr;
}
void list_print(List *head, TokenARRAY* arr) {
    std::string varpart = "";
    if (arr) {
        int len = arr->get_list_size();
        for (int i = 0; i < len; i ++) {
            std::string l = arr->get_l_list(i);
            std::string r = arr->get_r_list(i);
            if (l[0] == '-') {
                l[0] = '+';
                varpart = varpart + "[" + r + l + "-1]";
            } else {
                varpart = varpart + "[" + r + "-" + l + "+1]";
            }
        }
    }
    auto i = head;
    printf("%s", (i->x->get_value() + varpart).c_str());
    i = i->next;
    while (i) {
        printf(",%s", (i->x->get_value() + varpart).c_str());
        i=i->next;
    }
}

void list_add(List *head, List *head2) {
    while (head->next) {
        head->size += head2->size;
        head = head->next;
    }
    head->size += head2->size;
    head->next = head2;
}

ExpList::ExpList() {
    x = nullptr;
    next = nullptr;
    size = 1;
}

ExpList::ExpList(Const* _x) {
    x = _x;
    next = nullptr;
    size = 1;
}

void list_append(ExpList *head, Const* tmp) {
    auto i = head;
    while (i->next) {
        i -> size++;
        i = i->next;
    }
    i -> size++;
    i -> next = new ExpList(tmp);
}