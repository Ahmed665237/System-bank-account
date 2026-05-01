#ifndef EMPLOYFEATURES_H
#define EMPLOYFEATURES_H
#include"include.h"
#include<random>
#include<fstream>
using namespace std;
double  max_limit=0; // global variable to keep track any money operations do not exceed the limit
void add(vector<account>&v,const string&filename){
    account user;
    srand(time(nullptr));
    long long x = 100000000000LL + rand() % 900000000000LL;
    // random account number generator
    user.accNumber=x;
    real_name(user.name);
    cout<<"enter client's E-mail:\n";
    cin>>user.email;
    validateBalance(user.balance);
    validMobile(user.mobile);
    cout<<"enter date of opening (day,month,year) ";
    cin>>user.d.day>>user.d.month>>user.d.year;
    user.status="Active";
    cout<<"do you wish to save type y\n";
    char g;
    cin>>g;
    g=tolower(g);
    if(g=='y'){
        v.push_back(user);
        ofstream file(filename,ios::app);// append mode 
        if(!file)
            cout<<"eror opening file\n";
             cout<<"\n";
            file<<"\n";
            file << user.accNumber<<endl; 
             file<< user.name<<endl; 
             file<< user.email<<endl;
            file<< user.balance<<endl; 
             file<< user.mobile<<endl;  
             file<< user.d.day<<endl; 
             file<< user.d.month<<endl; 
             file<< user.d.year;
             cout<<"file successfully saved\n";

        file.close();
    }
}
// fn to add new account and save but needs more validation
void DEL(vector<account>&v,const string &filename){
    cout<<"type account number you wish to delete\n";
    account user;
    int c=0;
    invalid_INT(user.accNumber,12,"account number");// checks if balance is entered correctly
    while(true){
        for(int i=0;i<v.size();i++){
            if(user.accNumber==v[i].accNumber){
                 if(v[i].balance==0){
                v.erase(v.begin()+i);// loop to check if  deleted account has 0 in balance
                saveAccountsToFile(v,filename);
                c++; 
                break;
            }
                else{
                    cout<<"cannot delete account that has a balance\n";
                    break;
                }
            }
        }
        if(c==1)
            break;              // checks if account is in the file 
        else{
            cout<<"enter an existing account number";
            invalid_INT(user.accNumber,12,"account number");
            c=0;
        }
    }
    // DELETE ACCOUNT PART++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
// this fn will serve for the delete 
// i am going to save the modified vector and fill it in a txt file
void change_status(vector<account>&v,const string &filename){
    account user;
    char ans;
    int c=0;
    cout<<"to activate a client's status enter his/her account number\n";
    invalid_INT(user.accNumber,12,"account number");
    while(true){
        for(int i=0;i<v.size();i++){
            if(v[i].accNumber==user.accNumber&&v[i].status=="Inactive"){// change status and balance if =0
                if(v[i].balance==0){
                    cout<<"the client "<<v[i].name<<" has 0 balance he has to add atleast 200 pounds in order to reopen his account\n";
                    cout<<"do you want to proceed?\npress y for yes and save\n";
                    cin>>ans;// if the balance is 0
                    ans=tolower(ans);
                    if(ans=='y'){
                        validateBalance(user.balance);
                        v[i].balance=user.balance;
                    }      
                }
                v[i].status="Active";
                cout<<"operation is a success";
                saveAccountsToFile(v,filename); // where override happens
                c++;
                break;
            }
        }
        if(c>0)
            break;
        else{
              cout<<"enter correct credentials or this account is active\n";
            invalid_INT(user.accNumber,12,"account number"); // validation
        }
    }
}
void modify(vector<account>&v,const string &filename){ // modify fn to update credetntials 'name' 'mobile' 'email'
    account user;
    int c=0;
    cout<<"write account number of client you wish to update his credentials\n";
    invalid_INT(user.accNumber,12,"account number");
    while(true){
        for(int i=0;i<v.size();i++){
            if(user.accNumber==v[i].accNumber&&v[i].status=="Active"){
                cout<<"enter new name\n";
                real_name(user.name);
                cout<<"enter new mobile\n";
                validMobile(user.mobile);
                cout<<"enter new email";
                cin>>user.email;
                v[i].name=user.name;v[i].mobile=user.mobile;v[i].email=user.email;//here are the new credentials
                c++;
                saveAccountsToFile(v,filename);
                break;
            }
        }
        if(c>0)
            break;
        else{
            cout<<"enter the correct credentials to modify this account or\n choose account that is not inactive\n";
            invalid_INT(user.accNumber,12,"account number");
        }
    }
}
bool dailyLimit(double n){
        if(n>50000)
            return false;
        return true;
    }
    void withdraw(vector<account>&v,const string &filename){
        int c=0;
        account user;
        bool cond;
        cout<<"write your account number to withdraw\n";
        invalid_INT(user.accNumber,12,"account number");
        validateBalance(user.balance);
        while(true){
            if(user.balance>10000){
                cout<<"only withdraws up to '10,000'\nplease enter balance again\n"; // to make sure user doesnt exceed the max amount of withdraws
                validateBalance(user.balance);
                continue;
            }
            else if(user.balance<100){
                cout<<"minumum amount to withdraw is '100'\nplease try again\n"; 
                validateBalance(user.balance);
                continue;
            }
            max_limit=user.balance;
            cond=dailyLimit(max_limit);
            for(int i=0;i<v.size();i++){
                if(v[i].accNumber==user.accNumber&&cond&&v[i].status=="Active"){
                    if(v[i].balance>=user.balance){
                        v[i].balance-=user.balance;// new balance after withdrawl
                        saveAccountsToFile(v,filename);
                        c++;
                        break;
                    }
                    else{
                        cout<<"not enough balance to withdraw\n";
                        cout<<"enter again\n";
                        validateBalance(user.balance); // this else if for if user enter a number
                        // bigger than the account balance 
                        i=0;
                        continue;
                    }
                }
            }
            if(c>0)
                break;
            else{
                cout<<"account number not found\n enter it again\n";
                invalid_INT(user.accNumber,12,"account number");
            }
        }
    }// this is the withdraw fn
       void deposit(vector<account>&v,const string &filename){
        int c=0;
        account user;
        bool cond;
        cout<<"write your account number to deposit\n";
        invalid_INT(user.accNumber,12,"account number");
        validateBalance(user.balance);
        while(true){
            if(user.balance>10000){
                cout<<"only deposits up to '10,000'\nplease enter balance again\n"; // to make sure not to exceed the the max deposit
                validateBalance(user.balance);
                continue;
            }
            else if(user.balance<100){
                cout<<"minumum amount to deposit is '100'\nplease try again\n"; 
                validateBalance(user.balance);
                continue;
            }
            max_limit=user.balance;
            cond=dailyLimit(max_limit);
            for(int i=0;i<v.size();i++){
                if(v[i].accNumber==user.accNumber&&cond&&v[i].status=="Active"){  
                    v[i].balance+=user.balance;// new balance after deposit
                    saveAccountsToFile(v,filename);
                    c++;
                    break;
                }
            }
            if(c>0)
                break;
            else{
                cout<<"account number not found or this account is inactive \n enter it again\n";
                invalid_INT(user.accNumber,12,"account number");
            }
        }
       } // this is the deposit fn its baisically from the withdraw fn but shorter
       void transfer(vector<account>& v, const string& filename) {
    account user, receiver;
    double amount = 0.0;

    // 1) Get sender account + amount
    cout << "write account number of the sender:\n";
    invalid_INT(user.accNumber, 12, "account number");

    validateBalance(amount); // amount to transfer

    // optional: reject zero/negative
    if (amount <= 0) {
        cout << "amount must be greater than 0\n";
        return;
    }

    // 2) Find sender
    int senderIdx = -1;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].accNumber == user.accNumber) {
            senderIdx = i;
            break;
        }
    }
    if (senderIdx == -1) {
        cout << "sender account not found\n";
        return;
    }
    if (v[senderIdx].status != "Active") {
        cout << "sender account is not active\n";
        return;
    }
    if (v[senderIdx].balance < amount) {
        cout << "sender doesn't have enough balance\n";
        return;
    }

    // 3) Get receiver account
    cout << "enter the receiver's account number:\n";
    invalid_INT(receiver.accNumber, 12, "account number");

    if (receiver.accNumber == user.accNumber) {
        cout << "cannot transfer to the same account\n";
        return;
    }

    // 4) Find receiver
    int receiverIdx = -1;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].accNumber == receiver.accNumber) {
            receiverIdx = i;
            break;
        }
    }
    if (receiverIdx == -1) {
        cout << "receiver account not found\n";
        return;
    }
    if (v[receiverIdx].status != "Active") {
        cout << "receiver account is not active\n";
        return;
    }

    // 5) Apply transfer + save once
    v[senderIdx].balance -= amount;
    v[receiverIdx].balance += amount;

    if (!saveAccountsToFile(v, filename)) {
        cout << "transfer done in memory but failed to save file\n";
        return;
    }

    cout << "transfer successful\n";
} 
     
#endif
// i want to do the same ooperations in line 244 in the other fns above it 
