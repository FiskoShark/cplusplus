#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 1. таблиця множення від-до з дефолтними параметрами
void tablicaMnozhennya(int start = 1, int end = 10) {
    for (int i = start; i <= end; ++i) {
        for (int j = 1; j <= 10; ++j) {
            cout << i << " * " << j << " = " << i * j << "\t";
        }
        cout << endl;
    }
}
// ------------ ------------------- ----------- //



// оберт тексту
string zvorotniiRyadok(string text) {
    string reversed = "";
    int i = text.length() - 1;
    while (i >= 0) {
        reversed = reversed + text[i];
        i--;
    }
    return reversed;
}
// --------- ----------- ----------------- //



// 3. заміна значень у змінних через вказівникии
void obminZnachen(int* x, int* y) {
    cout << "було: x = " << *x << ", y = " << *y << endl;

    int t = *x;
    *x = *y;
    *y = t;

    cout << "стало: x = " << *x << ", y = " << *y << endl;
}

int main() {
    setlocale(LC_ALL, "");

    // перевірка функції таблиці множення за параметрами
    //
    cout << "(розширте вікно консолі для зручності)\n";
    cout << "таблиця множення з 2 до 4:\n\n";
    tablicaMnozhennya(2, 4);
    cout << "  " << endl;


    // оберт тексту
    //
    string word = "привіт"; 
    cout << "оригінал: " << word << endl;
    cout << "реверс: " << zvorotniiRyadok(word) << endl;
    cout << "  " << endl;



    // перевірка заміни значень через вказівники
    //
    int a = 5, b = 10;
    obminZnachen(&a, &b);



    return 0;
}
