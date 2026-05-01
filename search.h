#include"include.h"
using namespace std;
void query_search(vector<account>v){
    cout<<"write the account number to get full information about the account:\n";
    long long search;
    int flag=1,no=12;
    string type="Account number";
    while(flag){
        invalid_INT(search,no,type);// fn to chaeck for invalid int 
        for(int i=0;i<v.size();i++){
            if(search==v[i].accNumber){
                cout<< "Account Number: "<< v[i].accNumber << endl;
                cout<< "Name: "<< v[i].name<< endl;
                cout<< "Email: "<< v[i].email<< endl;
                cout<< "Balance: "<< v[i].balance<< endl;
                cout<<  "mobile: "<<v[i].mobile<<endl;
                cout<< "Date: "<< v[i].d.day<<" "<<v[i].d.month<<" "<<v[i].d.year<< endl;
                cout<< "Status: "<< v[i].status<< endl;
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"incorrect account number\nPlease try again";
    }
}
void advanced_search(const vector<account>& v){
    cout << "write down the name/prefix of the account(s) you want:\n";

    string name;
    real_name(name);                 // reads + validates
    if (name.empty()) return;

    name[0] = toupper((unsigned char)name[0]); // optional
    int x = (int)name.size();

    bool found = false;

    for (int i = 0; i < (int)v.size(); i++) {
        if ((int)v[i].name.size() >= x && v[i].name.substr(0, x) == name) {
            cout << "---------------------------------\n";
            cout << "Account Number: " << v[i].accNumber << endl;
            cout << "Name: " << v[i].name << endl;
            cout << "Email: " << v[i].email << endl;
            cout << "Balance: " << v[i].balance << endl;
            cout << "Mobile: " << v[i].mobile << endl;
            cout << "Date: " << v[i].d.day << " " << v[i].d.month << " " << v[i].d.year << endl;
            cout << "Status: " << v[i].status << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No accounts found with that prefix.\n";
    }
}