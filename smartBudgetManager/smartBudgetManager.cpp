#include <iostream>
#include "sqlite3.h"
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

void addTransaction(sqlite3* db) { //--доступ-до-бази--//
    string type, category, date, description;
    double amount;

    cout << "Тип (дохід/витрати): ";
    cin >> type;

    cout << "Сума: ";
    cin >> amount;

    cout << "Категорія: ";
    cin >> category;

    cout << "Дата: ";
    cin >> date;

    cout << "Опис: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //--очистка залишків введення cin--//

    getline(cin, description);
    //--для речень--//


    for (int i = 0; i < description.size(); i++) {
        if (description[i] == '\'')
            description[i] = ' ';
    }


    string amt = to_string(amount);
    replace(amt.begin(), amt.end(), ',', '.');
    //--фікс що б уникнути проблем з SQL--//


        string sql =    //--SQL запит--//
            "INSERT INTO transactions (type, amount, category, date, description) VALUES ('" + type + "', " + amt + ", '" + category + "', '" + date + "', '" + description + "');";






        //cout << "\n--- SQL DEBUG START ---\n";
        //cout << sql << endl;
        //cout << "--- SQL DEBUG END ---\n";

    char* errMsg = 0;
    sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg); 

    if (errMsg) {
        cout << "Error: " << errMsg << endl;
        sqlite3_free(errMsg);//звільнення памяті//
    }
    else {
        cout << "Успішно додано!\n";
    }
}

int callback(void* NotUsed, int argc, char** argv, char** colNames) {

    for (int i = 0; i < argc; i++) {
        cout << colNames[i] << ": " << (argv[i] ? argv[i] : "NULL") << " | ";
    }
    cout << endl;
    return 0;
}



void showTransactions(sqlite3* db) {
    string sql = "SELECT * FROM transactions;";

    char* errMsg = 0;

    sqlite3_exec(db, sql.c_str(), callback, 0, &errMsg);

    if (errMsg) {
        cout << "Error: " << errMsg << endl;
        sqlite3_free(errMsg);
    }
}


void initDB(sqlite3* db) {
    string sql =
        "CREATE TABLE IF NOT EXISTS transactions ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "type TEXT,"
        "amount REAL,"
        "category TEXT,"
        "date TEXT,"
        "description TEXT);";

    char* errMsg = 0; 
    sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
}




int callbackSum(void* data, int argc, char** argv, char** colNames)
{
    double* result = (double*)data;

    if (argv[0] != nullptr) {
        *result = std::stod(argv[0]);
    }

    return 0;
}


void showBalance(sqlite3* db) {
    string sqlIncome = "SELECT SUM(amount) FROM transactions WHERE type='plus';";
    string sqlExpense = "SELECT SUM(amount) FROM transactions WHERE type='minus';";

    double income = 0, expense = 0;
    char* errMsg = 0;


    sqlite3_exec(db, sqlIncome.c_str(), callbackSum, &income, &errMsg);
    if (errMsg) 
    { cout << errMsg << endl; sqlite3_free(errMsg); errMsg = 0; }


    sqlite3_exec(db, sqlExpense.c_str(), callbackSum, &expense, &errMsg);
    if (errMsg)
    { cout << errMsg << endl; sqlite3_free(errMsg); }



    double balance = income - expense;

    cout << "\n--- БАЛАНС ---\n";
    cout << "Дохід: " << income << "\n";
    cout << "Витрати: " << expense << "\n";
    cout << "Баланс: " << balance << "\n";
}


int main()
{
    cout << "PROGRAM STARTED\n";


    setlocale(LC_ALL, "uk_UA.UTF-8");
    sqlite3* db;    




    if (sqlite3_open("budget.db", &db)) {
        cout << "Can't open DB\n";
        return 1;
    }

    initDB(db);
    cout << "DB ready!\n";
    int choice;


    while (true) {
        //cout << "\n1 - Add\n2 - Show\n0 - Exit\n";
        cout << "\n1 - Add\n2 - Show\n3 - Balance\n0 - Exit\n";
        cin >> choice;

        if (choice == 1) addTransaction(db);
        else if (choice == 2) showTransactions(db);
        else if (choice == 3) showBalance(db);
        else if (choice == 0) break;
    }


    sqlite3_close(db);
    return 0;
}
