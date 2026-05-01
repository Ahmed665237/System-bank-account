#include "include.h"
#include<fstream>
#include"employFeatures.h"
int main(){
    int x;
    employeeLogin employ;
    account client;
    vector<account>allClientAccounts,allClientAccounts2;
    vector <employeeLogin> allempAccounts;
    allempAccounts=loadFile("employAccounts.txt");
int choice=-1;
invalid_username(employ.username, "username");
invalid_username(employ.password, "password");
checkUsername(employ.username, allempAccounts, x);
checkpassword(employ.password, allempAccounts, x);
allClientAccounts  = loadFileClients("clientAccounts.txt");
allClientAccounts2 = loadFileClients("clients.txt_copy.txt");

do {
    printMenu();

    cin >> choice;
    if (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid choice. Please enter a number.\n";
    continue;
}

cin.ignore(numeric_limits<streamsize>::max(), '\n');// flush newline for getline-based fns

    // login once (only the first time user tries any option)
   

    switch (choice) {
        case 1:
            query_search(allClientAccounts);
            break;

        case 2:
            advanced_search(allClientAccounts);
            break;

        case 3:
            add(allClientAccounts2, "clients.txt_copy.txt");
            break;

        case 4:
            modify(allClientAccounts2, "clients.txt_copy.txt");  // "change/modify account"
            break;

        case 5:
            change_status(allClientAccounts2, "clients.txt_copy.txt");
            break;

        case 6:
            withdraw(allClientAccounts2, "clients.txt_copy.txt");
            break;

        case 7:
            deposit(allClientAccounts2, "clients.txt_copy.txt");
            break;

        case 8:
            transfer(allClientAccounts2, "clients.txt_copy.txt");
            break;

        case 9:
            DEL(allClientAccounts2, "clients.txt_copy.txt");
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
    }

} while (choice != 0);
return 0;
}