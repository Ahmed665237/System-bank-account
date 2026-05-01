#ifndef LOGIN_H
#define LOGIN_H
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct date{
    string day,month,year;
};
struct account{ //here contains account information of account holder
    date d;
    double balance;
    long long  accNumber;
    string email,name,mobile;
    string status;
};
struct employeeLogin{ // employee account to acsess the system bank
    string password;
    string username;
};
#endif