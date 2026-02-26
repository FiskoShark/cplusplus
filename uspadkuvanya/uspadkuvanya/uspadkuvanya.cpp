
#include <iostream>
using namespace std;


//------------- Base -------------//
template <typename T1, typename T2>
class Base {
protected:
    T1 name;
    T2 surName;

public:
    // конструктор //
    Base(T1 name, T2 surName) {
        this->name = name;
        this->surName = surName;
    }

    // вивід конструктора //
    void print() {
        cout << "ваше імя: " << name << endl;
        cout << "прізвище: " << surName << endl;
    }

    // деструктор //
    ~Base() {
        cout << "Base знищено\n";
    }
};

// ------------------------ Child ------------------------ //
template <typename T1, typename T2, typename T3, typename T4> 
class Child : public Base < T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    Child(T1 name, T2 surName, T3 value3, T4 value4) : Base<T1, T2>(name, surName) {
        this->value3 = value3;
        this->value4 = value4;
    }

    void printChild() {
        this->print();
        cout << "ваш вік: " << value3 << endl;
        cout << "ваш ID: " << value4 << endl;
    }

    ~Child() {
        cout << "Child знищено\n";
    }
};

//  ----------------------------------  Child2  ----------------------------------  //
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child <T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    Child2(T1 name, T2 surName, T3 value3, T4 value4, T5 value5, T6 value6) : Child<T1, T2, T3, T4>(name, surName, value3, value4) {
        this->value5 = value5;
        this->value6 = value6;
    }

    void printChild2() {
        this->printChild();
        cout << "value5: " << value5 << endl;
        cout << "value6: " << value6 << endl;
    }

    ~Child2() {
        cout << "Child2 знищено\n";
    }
};

int main()
{
    setlocale(LC_ALL, "uk_UA.UTF-8");

    cout << "Hellow World!\n";

    //-------------------- окремі виводи кожного класу----------------------//
    Base<string, string> obj("Ivan", "Petrenko");
    obj.print();

    Child<string, string, int, float> obj1("Ivan", "Petrenko", 90, 3.001);
    obj1.printChild();

    Child2<string, string, int, float, bool, char> obj2("Ivan", "Petrenko", 90, 3.001, true, 'q');
    obj2.printChild2();

}

