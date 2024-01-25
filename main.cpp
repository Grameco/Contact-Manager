#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#include"mycontacts.cpp"                    //includeing a file from same folder
contacts obj;                               //creating an object for the class from mycontacts.cpp
int flag, p;

void searchbyemail(){
    char email[50];
    cout<<endl<<"Enter Email: ";
    cin>>email;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("namesearch.txt",ios::out);
    for(int i=1; i<=size; i++){
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.email,email)==0){
            wr.write((char*)&obj,sizeof(obj));
            cout<<"Record Matched"<<endl;
            flag=1;
        }
    }
    if(flag!=1){
        cout<<endl<<"No Record Matched";
    }
    rd.close();
    wr.close();

    rd.open("namesearch.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

cout<<endl;
cout<<endl;
        cout<<left;
        cout<<setw(25);
        cout<<"Name";
        cout<<setw(20);
        cout<<"Mobile";
        cout<<setw(35);
        cout<<"Email";
        cout<<setw(25);
        cout<<"Insta";
        cout<<setw(25);
        cout<<"Twitter";
        cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";

    for(int i=1; i<=s; i++){
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
        cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";
    }
}

void searchbyname(){
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("emailsearch.txt",ios::out);
    for(int i=1; i<=size; i++){
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0){
            wr.write((char*)&obj,sizeof(obj));
            cout<<"Record Matched"<<endl;
            flag=1;
        }
    }
    if(flag!=1){
        cout<<endl<<"No Record Matched";
    }
    rd.close();
    wr.close();

    rd.open("emailsearch.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    cout<<endl<<endl;
    cout<<left;
    cout<<setw(25);
    cout<<"Name";
    cout<<setw(20);
    cout<<"Mobile";
    cout<<setw(35);
    cout<<"Email";
    cout<<setw(25);
    cout<<"Insta";
    cout<<setw(25);
    cout<<"Twitter";
    cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";

    for(int i=1; i<=s; i++){
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
        cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";
    }
}

void searchbymobile(){
    char mobile[50];
    cout<<endl<<"Enter Mobile: ";
    cin>>mobile;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("mobilesearch.txt",ios::out);                  //ios :: out -> inbuilt fstream mode to give output from the file, write in the file
    for(int i=1; i<=size; i++){                            //run a loop for the whole file till it ends
        rd.read((char*)&obj,sizeof(obj));                  //start reading the file
        if(strcmp(obj.mobile,mobile)==0){                  //if the contact number gets a match
            wr.write((char*)&obj,sizeof(obj));             //write it in the new file
            cout<<"Record Matched"<<endl;
            flag=1;
        }
    }
    if(flag!=1){
        cout<<endl<<"No Record Matched";
    }
    rd.close();
    wr.close();

    rd.open("mobilesearch.txt",ios::in);
    rd.seekg(0,ios::end);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);

    cout<<endl<<endl;
    cout<<left;
    cout<<setw(25);
    cout<<"Name";
    cout<<setw(20);
    cout<<"Mobile";
    cout<<setw(35);
    cout<<"Email";
    cout<<setw(25);
    cout<<"Insta";
    cout<<setw(25);
    cout<<"Twitter";
    cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";

    for(int i=1; i<=s; i++){
        rd.read((char*)&obj,sizeof(obj));
        obj.display();
        cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";
    }
}

void updatecontact(){
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1; i<=size; i++){
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0){
            cout<<endl<<"Record Matched." << endl << "Enter the updated contact details: " << endl;
            obj.accept();
            flag=1;
        }
    wr.write((char*)&obj,sizeof(obj));
    }
    if(flag!=1){
        cout<<endl<<"No Record Matched";
    }
    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt","mydatafile.txt");
}

void removecontact(){
    char name[50];
    cout<<endl<<"Enter Name: ";
    cin>>name;
    fstream rd;
    rd.open("mydatafile.txt",ios::in);
    rd.seekg(0,ios::end);
    int size=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);
    fstream wr;
    wr.open("tempfile.txt",ios::app);
    for(int i=1; i<=size; i++){
        rd.read((char*)&obj,sizeof(obj));
        if(strcmp(obj.name,name)==0){
            cout<<endl<<"Record Removed.";
            flag=1;
        }
        else{
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    if(flag!=1){
        cout<<endl<<"No Record Matched";
    }
    rd.close();
    wr.close();
    remove("mydatafile.txt");
    rename("tempfile.txt","mydatafile.txt");
}

void readdata(){
    fstream rd;                                                   //creating an object for the file
    rd.open("mydatafile.txt",ios::in);                            //opening the file in read mode
    rd.seekg(0,ios::end);                                         //seek the relative current end of the sequence
    cout<<endl<<"Size of file is: "<<rd.tellg();                  
    cout<<endl<<"Number of objects: "<<rd.tellg()/sizeof(obj);
    int s=rd.tellg()/sizeof(obj);
    rd.seekg(0,ios::beg);                                         //seek the relative beginning of the sequence

    //setting the headers for the data  to make it simple to understand at the time of display

    cout<<endl<<endl;
    cout<<left;                                                  //left allignment entir4e sequence
    cout<<setw(25);                                              //set width to desired size
    cout<<"Name";
    cout<<setw(20);
    cout<<"Mobile";
    cout<<setw(35);
    cout<<"Email";
    cout<<setw(25);
    cout<<"Insta";
    cout<<setw(25);
    cout<<"Twitter";
    cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";

    for(int i=1; i<=s; i++){
        rd.read((char*)&obj,sizeof(obj));                        //read the data from the file
        obj.display();                                           //call the display function
        cout<<endl<<"-------------------------------------------------------------------------------------------------------------------------";
    }
}
void addcontact(){
    char name[50];
    cout<<endl<<"Enter Name: ";
    fgets(name, 50, stdin);
    
    fstream rd;                                      //creating an object for the inbuilt fstream class for reading the file

    //first check if name is already stored or it's a new name
    rd.open("mydatafile.txt",ios::in);               //opening a txt file to store data, in read mode
    rd.seekg(0,ios::end);                            //request a seek relative to the current end of the sequence
    int size=rd.tellg()/sizeof(obj);                 //tellg -> getting the current read position (size of file), sizeof -> gives size of object
    rd.seekg(0,ios::beg);                            //request a seek relative to the beginning of the stream
    for(int i=1; i<=size; i++){                      //size -> number of objects in the file
        rd.read((char*)&obj,sizeof(obj));            //reading the file data
        if(strcmp(obj.name,name)==0){                //if the entered name is equal to the stored object name 
            flag=1;                                  //mark an indication
        }
    }

    if(flag==1){
        cout<<endl<<"Name Already Exist.";
    }
    else{                                            //we can accept and write in the file
    obj.accept();                                    //call the accept function and store the values given by user 
    fstream wr;                                      //creating an object for the inbuilt class for writing into it
    wr.open("mydatafile.txt",ios::app);              //open in append mode
    wr.write((char*)&obj,sizeof(obj));               //write the stored values into the file
    wr.close();                                      //close the file
    cout<<endl<<"File Written"<<endl;
    }
    
}
void exit(){
    cout<<endl<<"Exiting the program...";
    cout<<endl<<"End of the program...";
}

void clear_record(){
    fstream rd;
    rd.open( "mydatafile.txt", ios :: out | ios :: trunc );
    rd.close();
}

int main(){
    // addcontact();
    // readdata();
    // updatecontact();
    // searchbyname();
    // searchbymobile();
    // searchbyemail();
    // readdata();
    removecontact();
    // readdata();
    return 0;
}