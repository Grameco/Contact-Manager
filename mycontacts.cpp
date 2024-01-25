#include<iostream>
#include<iomanip>
using namespace std;
class contacts{
    private:
    char name[50], mobile[50], email[50], insta[50], twitter[50]; 
    public:
    void accept(){
        cout<<endl<<"Enter Name: ";
        fgets(name, 50, stdin);
        cout<<endl<<"Enter Mobile: ";
        cin>>mobile;
        cout<<endl<<"Enter Email ID: ";
        cin>>email;
        cout<<endl<<"Enter Insta ID: ";
        cin>>insta;
        cout<<endl<<"Enter Twitter Handle: ";
        cin>>twitter; 
    }
    void display(){
        cout<<endl;
        cout<<left;
        cout<<setw(25);
        cout<<name;
        cout<<setw(20);
        cout<<mobile;
        cout<<setw(35);
        cout<<email;
        cout<<setw(25);
        cout<<insta;
        cout<<setw(25);
        cout<<twitter;
    }

    friend void removecontact();
    friend void searchbymobile();
    friend void searchbyemail();
    friend void updatecontact();
    friend void searchbyname();
    friend void addcontact();
};