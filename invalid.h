#include<iostream>
#include <string>
#include<limits>
using namespace std;
void invalid_INT(long long& n,int index,string type) {
    //cout<<"\nplease enter your password:\n";
    string input;
    while (true) {
        getline(cin,input);
        if(input.empty()){
            cout << "Invalid input\n\nplease enter a correct "<<type<<"form: ";
            continue; // this skips anything under it in the loop
            // used if user entered an empty input
        }
        if(input.size()!=index){
            cout << "Invalid input\n\nplease enter a complete or valid "<<type<<"form: ";
            continue;
        }
        //here we will add an if to control size of string 
        bool valid = true;
        for (char c : input) { // char c loops through each character in "input"
            if (!isdigit(c)) { // returns true if char = 0-9
                valid = false;
                break;
            }
        }

        if (valid) {
            n = stoll(input); // turns string to long long  
            break;
        }

        cout << "Invalid input\n\nplease enter a correct "<<type<<"form: ";
    }
}/*this a function that makes sure that the user entered the correct int and the right amount 
as it scans to se if there are letters */

// i still want to add a suggested password part
void invalid_username(string& user,string type){
    cout<<"\nplease enter a "<<type<<":\n";
    string input;
    bool con=true;
    while(con){
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,input);
        if(input.empty()||input[0]==' '){
            cout<<"enter a valid "<<type<< "please:\n";
            continue;
        }
        user=input;
        con=false;
    }
}// this validates username input or name anything that is a string 
void checkUsername(string &user, const vector<employeeLogin> v,int &x){
    bool con=true;
    while(con){
        for(int i=0;i<v.size();i++){
            if(user==v[i].username){
                cout<<"correct username\n";
                con=false;
                x=i;
                break;
            }
        }
        if(con==true){
            cout<<" you have entered username incorrectly try again:\n";
            getline(cin,user);
        }
    }
}
   


void checkpassword(string &user,vector<employeeLogin> v,int x){
    bool con=true;
    while(con){
        for(int i=0;i<v.size();i++){
            if(user==v[x].password){
                cout<<"correct password\n";
                con=false;
                break;
            }
        }
        if(con==true){
            cout<<" you have entered password incorrectly try again:\n";
            getline(cin,user);
        }
    }
}
void real_name(string &name){
    int flag=1,x=1,n=0;
    while(flag){
    invalid_username(name,"name");
        for(char c :name){
            if(isdigit(c)){
                cout<<"dont write any numbers just letters\n";
                x++;
                break;
            }
        }
        if(x==1){
            flag=0;
        }
        x=1;
    }
}
// to check if bank clerk wrote a real name 
void validMobile(string &mobile){
    int i=0;
   while(true){
        invalid_username(mobile,"mobile");
        if(!isdigit(mobile[0])){
            cout<<"write valid mobile number\n";
            continue;
        }
        else if(mobile.length()!=11){
            cout<<"write complete mobile";
            continue;
        }
        else
            break;
   }
}
// fn to check if mobile is written correct
void validateBalance(double &balance) {
    string input;
    //if (cin.peek() == '\n')
    //cin.ignore(numeric_limits<streamsize>::max(), '\n'); // dont delete unless in full phase testing
    while (true) {
        cout << "enter clients balance:\n";
        getline(cin, input);
        if (input.empty() || input[0] == ' ') {
            cout << "enter correct balance\n";
            continue;
        }
        bool ok = true;
        for (char c : input) {
            if (!isdigit(c) && c != '.') { // allow decimals
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "enter correct balance\n";
            continue;
        }
        balance = stod(input);
        break;
    }
}
