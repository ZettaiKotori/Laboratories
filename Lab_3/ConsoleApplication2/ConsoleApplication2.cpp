#include <iostream>
#include <cstdlib>

struct slist {
    slist* next;
    int    val;
};
bool slist_add(slist*& lst, int val);
void slist_clear(slist*& lst);
void slist_remove(slist*& lst, bool (*pfcmp)(int));
void slist_print(std::ostream& _out, const slist* lst);

bool compare(int n) { return ((n % 2) == 0); }


int main(void) {
    slist* lst = NULL;
    for (int i = 0; i < 17; ++i)
        slist_add(lst, 1 + rand() % 9);

    slist_print(std::cout, lst);
    slist_remove(lst, &compare);
    slist_print(std::cout, lst);
    slist_clear(lst);
    return 0;
}

//удаление
void slist_remove(slist*& lst, bool (*pcmp)(int)) {
    slist* q, * t = lst, * p = lst;
    while (p != NULL) {
        if ((*pcmp)(p->val)) {
            if (p == lst)
                q = t = lst = lst->next;
            else
                q = t->next = p->next;

            delete p;
            p = q;
            continue;
        }
        t = p;
        p = p->next;
    }
}

//добавление
bool slist_add(slist*& lst, int val) {
    slist* p = new (std::nothrow) slist();
    if (p != NULL) {
        p->val = val;
        p->next = lst;
        lst = p;
    }
    return (p != NULL);
}

//удаление всех
void slist_clear(slist*& lst) {
    slist* t;
    while (lst != NULL) {
        t = lst;
        lst = lst->next;
        delete t;
    }
}

//печать
void slist_print(std::ostream& _out, const slist* lst) {
    for (; lst != NULL; lst = lst->next)
        _out << lst->val << ' ';
    _out << std::endl;
}