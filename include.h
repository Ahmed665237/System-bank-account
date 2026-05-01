#ifndef COMMON_H
#define COMMON_H
#include<iostream>
#include<string>
#include<vector>
#include "login.h"
#include "invalid.h"
#include"search.h"
#include<fstream>
#include<cstdio>
using namespace std;
vector<employeeLogin> loadFile( const string& filename){ // "const" is imp to prevent mod.
    vector<employeeLogin> login;
    employeeLogin user;
    ifstream file (filename);// opens file for reading var name file 
    if(!file){
        cout<<"error opening file "<<filename;
        return login;
    }
    while(getline(file,user.username)){// i wrote file as this is read mode
        getline(file,user.password);
        login.push_back(user);
    }
    file.close();
    return login;
    /*this is a while loop that reads the file usernames and passwords that match each 
    other and puts them in a vector */
}

// fn that reads employee login credititials txt file 

vector<account> loadFileClients(const string& filename) {
    vector<account> login;
    account user;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return login;
    }

    string line; // temporary string for numeric conversions

    while (getline(file, line)) {
        //  Account Number
         user.accNumber = stoll(line);

        //  Name and email
        getline(file, user.name);
        getline(file, user.email);

        //  Balance
        getline(file, line);
        user.balance = stof(line);

        //  Mobile
        getline(file, user.mobile);
         //user.mobile = stoll(line);

        //  Date as strings
        getline(file, user.d.day);
        getline(file, user.d.month);
        getline(file, user.d.year);

        //  Status
        getline(file, user.status);

        // Add user to vector
        login.push_back(user);
    }

    return login;
}
// this is a fn that reads the clients accounts
// everything is string as the file
bool deleteFile(const string & filename){
    int result = remove(filename.c_str());
    return result==0;
}
bool saveAccountsToFile(const vector<account>& v, const string& filename) {
    ofstream file(filename, ios::out);
    if (!file.is_open()) return false;

    for (const account& a : v) {
        file << a.accNumber << '\n';
        file << a.name << '\n';
        file << a.email << '\n';
        file << a.balance << '\n';
        file << a.mobile << '\n';
        file << a.d.day << '\n';
        file << a.d.month << '\n';
        file << a.d.year << '\n';
        file << a.status << "\n";
    }

    file.close();
    return true;
}// this fn creates a new file using a vector
void printMenu() {
    cout << "========================================\n";
    cout << "        BANK MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1) Regular Search        (By Account Number)\n";
    cout << "2) Major Search          (By Name / Prefix)\n";
    cout << "3) Add Account\n";
    cout << "4) Modify Account        (Edit account data)\n";
    cout << "5) Change Status         (Active / Inactive)\n";
    cout << "6) Withdraw\n";
    cout << "7) Deposit\n";
    cout << "8) Transfer\n";
    cout << "9) Delete Account\n";
    cout << "0) Exit\n";
    cout << "----------------------------------------\n";
    cout << "Enter your choice: ";
}

#endif
