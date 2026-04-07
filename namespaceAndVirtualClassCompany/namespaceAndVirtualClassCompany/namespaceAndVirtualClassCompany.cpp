
#include <iostream>
using namespace std;

class Worker {          ///---------------  абстрактний клас
protected:
    double salary;

public:
    Worker(double sal) : 
        salary(sal) {}

    virtual double calculateBonus() = 0;

    virtual void printInfo() {
        double bonus = calculateBonus();
        cout << "зарплата: " << salary
            << ", бонус: " << bonus
            << ", все: " << salary + bonus << endl;
    }
};


class Manager : public Worker {         ///---------------  менеджер
public:
    Manager(double sal) :
        Worker(sal) {}

    double calculateBonus() override {
        return salary * 0.20;
    }

};


class Intern : public Worker {          ///---------------  стажер
public:
    Intern(double sal) : Worker(sal) {}

    double calculateBonus() override {
        return salary * 0.10;
    }
};



int main()
{
    setlocale(LC_ALL, "uk_UA.UTF-8");
    cout << "Hello World!\n";

    //Worker* w1 = new Manager(5000);
    //cout << "бонус менеджера: " << w1->calculateBonus() << endl;
    //delete w1;

    //Worker* w2 = new Intern(2000);
    //cout << "бонус стажера: " << w2->calculateBonus() << endl;
    //delete w2;




    Worker* workers[3];
    //масив вказівників//

    workers[0] = new Manager(5000);
    workers[1] = new Intern(2000);
    workers[2] = new Manager(8000);

    for (int i = 0; i < 3; i++) {
        cout << "працівник №: " << i + 1 << " отримує бонус: " << workers[i]->calculateBonus() << endl;
    }



    for (int i = 0; i < 3; i++) {
        cout << "Працівник №" << i + 1 << ": ";
        workers[i]->printInfo();
    }



    ///або...
    for (int i = 0; i < 3; i++) { //---очищення---//
    delete workers[i];
    }

}

