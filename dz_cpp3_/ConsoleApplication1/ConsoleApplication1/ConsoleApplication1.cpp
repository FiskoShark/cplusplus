#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "");

    srand(time(0));
    int level, questions, correct = 0;
    cout << "������� ����� ��������� (1 - �����, 2 - ��������, 3 - �����): ";
    cin >> level;



    if (level == 1) questions = 5;
    else if (level == 2) questions = 10;
    else questions = 15;

    for (int i = 0; i < questions; i++) {
        int a = rand() % (level * 5) + 1;
        int b = rand() % (level * 5) + 1;
        int answer;
        cout << "������ ���� " << a << " * " << b << " ? ";
        cin >> answer;

        if (answer == a * b) {
            cout << "���������??\n";
            correct++;
        }
        else {
            cout << "�����������!?? ��������� �������: " << a * b << endl;
        }
    }
    cout << "���� ������: " << (correct * 12 / questions) << " ���� � 12\n";
    return 0;
}
