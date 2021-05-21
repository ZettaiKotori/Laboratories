#include <iostream>
#include <time.h>
using namespace std;

struct stek {
    int num;
    stek* next;
};

void push(stek*& stk, int n) {
    stek* temp = new stek;
    temp->next = stk;
    temp->num = n;
    stk = temp;
}

void show(stek* stk) {
    stek* temp = stk;
    while (temp) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findAverage(stek* stk) {
    int amount = 0, i = 0;
    for (stek* temp = stk; temp; temp = temp->next, i++)
        amount += temp->num;
    return amount / i;
}

void cleanOut(stek*& stk) {
    for (stek* temp = stk->next; stk->next; temp = stk->next) {
        delete stk;
        stk = temp;
    }
}

int main() {
    stek* stk = new stek;
    stk = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        push(stk, rand() % 100);
    show(stk);
    stk->num = findAverage(stk);
    show(stk);
    system("pause > nul");
}
