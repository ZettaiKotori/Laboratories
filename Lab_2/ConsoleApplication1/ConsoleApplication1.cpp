#include <iostream>

using namespace std;

struct date
{
    int dd;
    int mm;
    int yy;
};

struct commodity
{
    char name[30]; // наименование товара
    int num; // количество товара
    double price; // цена товара
    date d; // дата поступления товара
};

// функция для обмена ячейками массива структур
void swapp(commodity& a, commodity& b)
{
    commodity temp;
    temp = a;
    a = b;
    b = temp;
}

int main() {

    const int N = 3; // размер массива
    commodity ar[N]; // массив структур
    date currentDate; // объект структуры для текущей датты

    // текущая дата
    currentDate.dd = 21;
    currentDate.mm = 05;
    currentDate.yy = 2021;

    // заполним для проверки массив структур
    strcpy_s(ar[0].name, "Dress");
    ar[0].price = 120000;    // цена
    ar[0].num = 32; // количество
    ar[0].d.dd = 21;// дата
    ar[0].d.mm = 05;
    ar[0].d.yy = 2020;

    strcpy_s(ar[1].name, "Jeans");
    ar[1].price = 120000;    // цена
    ar[1].num = 24; // количество
    ar[1].d.dd = 21; // дата
    ar[1].d.mm = 05;
    ar[1].d.yy = 2020;

    strcpy_s(ar[2].name, "T-short");
    ar[2].price = 120000;    // цена
    ar[2].num = 14; // количество
    ar[2].d.dd = 21;// дата
    ar[2].d.mm = 05;
    ar[2].d.yy = 2020;

    // сначала отсортируем массив структур по названию товаров
    for (int i(1); i < N; i++) {
        for (int j(N - 1); j >= i; j--) {
            for (int k(0); ar[j - 1].name[k]; k++) {
                if (ar[j - 1].name[k] > ar[j].name[k]) { swapp(ar[j - 1], ar[j]); break; } // если буква первого слова больше чем буква второго, то меняем местами слова и переходим к следующему слову
                else if (ar[j - 1].name[k] == ar[j].name[k]) continue; // если буквы равны, то проверяем следующую букву
                else break;
            }
        }
    }

    // теперь выведем те товары, которые соответсвуют заданным условиям
    // т.е. их цена больше 1000 и лежат на складе больше месяца
    for (int i(0); i < N; i++) {
        if (ar[i].price > 100000)
            if (currentDate.yy > ar[i].d.yy) cout << ar[i].name << endl;
            else if (currentDate.mm > ar[i].d.mm && currentDate.dd > ar[i].d.dd) cout << ar[i].name << endl;
    }
    cin.get();
    return 0;
}