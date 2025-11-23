#include <iostream>
using namespace std;

int main() {
    int rozmirMasiva;
    cout << "ведіть розмір масиву: ";
    cin >> rozmirMasiva;

    int* masiv;
    masiv = new int[rozmirMasiva];

    cout << "введіть елементи масиву: \n";
    for (int i = 0; i < rozmirMasiva; i++) {
        cin >> masiv[i];
    }

    int vibor;
    do {
        cout << "\nменю:\n";
        cout << "1 - додати елемент\n";
        cout << "2 - очистити пам'ять\n";
        cout << "3 - вивести середнє значення\n";
        cout << "0 - вийти\n";
        cout << "ваш вибір: ";
        cin >> vibor;

        switch (vibor) {

        case 1: {
            cout << "введіть значення нового елемента: ";
            int chislo;
            cin >> chislo;

            // ------------------------------- масив нов --------------------------- //
            int* noviyMasiv;
            noviyMasiv = new int[rozmirMasiva + 1];

            // ------------------------------- заповнення масиву ------------------------ //
            for (int i = 0; i < rozmirMasiva; i++) {
                noviyMasiv[i] = masiv[i];
            }



            noviyMasiv[rozmirMasiva] = chislo;
            rozmirMasiva++;

            delete[] masiv;
            masiv = noviyMasiv;

            cout << "елемент додано!\n";
            break;
        }



        case 2:
            delete[] masiv;
            masiv = nullptr; // - порожній вказівник - //
            rozmirMasiva = 0;
            cout << "память очищено!\n";
            break; // - вихід з свіча - //




        case 3:
            if (masiv == nullptr || rozmirMasiva == 0) {
                cout << "масив порожній!\n";
            }
            else {
                double suma = 0;
                for (int i = 0; i < rozmirMasiva; i++) {
                    suma += masiv[i];
                }
                cout << "середнє значення = " << suma / rozmirMasiva << endl;
            }
            break;




        case 0:
            cout << "вихід...\n";
            break;

        default:
            cout << "НЕВІРНИЙ ВИБІР! Ваші дані очищено… \n";
        }

    } while (vibor != 0);

    // на випадок якщо память не очищена
    delete[] masiv;

    return 0;
}
