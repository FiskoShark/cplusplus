#include <iostream>
using namespace std;

//   ----------------------------------------------------------------------------   заміна значень   ---------------------------------------   //
void zaminaZnachennya(int& number, int& number1, int& number2) {
    int timchasove = number;
    number = number1;
    number1 = timchasove;
    number2 = number + number1;
}

//   ---------------------------------------------------------------------------   вивід непарних чисел ----------------------------------   //
void adresNeparnyh(int masyv[], int rozmir) {
    for (int i = 0; i < rozmir; i++) {
        if (masyv[i] % 2 != 0) {
            cout << "непарне число: " << masyv[i] << " за адресом: " << &masyv[i] << endl;
        }
    }
}




int main() {
    //    ---------------------------------------------------------   завдання 1   ------------------------------------------   //
    setlocale(LC_ALL, "");


    int number = 1, number1 = 5, number2 = 5;

    cout << "до зміни:\n";
    cout << "number = " << number << "\nnumber1 = " << number1 << "\nnumber2 = " << number2 << endl;

    zaminaZnachennya(number, number1, number2);

    cout << "\nпісля змін:\n";
    cout << "number = " << number << "\nnumber1 = " << number1 << "\nnumber2 = " << number2 << endl;

    //    ---------------------------------------------------------   завдання 2   ------------------------------------------   //
    cout << "\n---------------------------------------------------";

    int masyv[] = { 2, 3, 4, 7, 8, 11 };
    int rozmir = sizeof(masyv) / sizeof(masyv[0]);

    cout << "\nадрес непарних чисел:\n";
    adresNeparnyh(masyv, rozmir);

    return 0;
}
