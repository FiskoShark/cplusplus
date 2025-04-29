#include <iostream>
using namespace std;



// ---------------------------------------------------------------------------------------------------------  мінімальні і максимальні елементи масиву -------------------- //
void findMinMax(int arr[], int size) {
    if (size == 0) {
        cout << "масив порожній :(" << endl;
        return;
    }

    int minVal = arr[0], maxVal = arr[0]; 
    int minIndex = 0, maxIndex = 0; 

    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
    }
    cout << "мінімум " << minVal << " (індекс: " << minIndex << ")" << endl;
    cout << "максимум: " << maxVal << " (індекс:  " << maxIndex << ")" << endl;
    cout << "// ---------------------- 1 ------------------------ //\f" << endl;
}




// ------------------------------------------------------------------------------------------------------------------------ реверс масива -------------------------------- //
void reverseArr(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) { 
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// --------------------------------------------------------------------------------------------------------------------------- перевірка number ---------------------------- //
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) { 
        if (num % i == 0) return false; 
    }
    return true;
}




// ------------------------------------------------------------------------------------------------------------------------- прості числа ------------------------------- //
int count(int arr[], int size) {
    int count = 0; 
    for (int i = 0; i < size; i++) { 
        if (isPrime(arr[i])) count++;
    }
    return count;
    
}

int main() {
    setlocale(LC_ALL, "");

    // --min-max таск 1
    int arr[] = { 10, 5, 2, 8, 11, 3, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    findMinMax(arr, size);


    // --реверс таск 2
    reverseArr(arr, size);
    cout << "реверсований масив: ";
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n// ---------------------- 2 ------------------------ //\f" << endl;

    // ---прості number 
    cout << "кількість простих чисел: " << count(arr, size) << endl;
    cout << "// ---------------------- 3 ------------------------ //" << endl;
    return 0;



}
