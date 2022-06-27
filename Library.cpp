//
//  Library.cpp
//  Library Management-App
//
//  Created by  Rob the deer on 25.05.2022.
//

#include "Library.hpp"
#include <iostream>
#include<iomanip>
#include <fstream>

using namespace std;

//Defining functions for class object BOOK
void Book::add_book()
{
    cout<<"\n|_|-|_|-|_|-|_|-|_|-|_|\n";
    cout<<"(~|ADD NEW BOOK|~)\n";
    cout<<"\nEnter Book Number:";
    cin>>book_no;
    cout<<"\nEnter Book Name:";
    getline(cin,book_name);
    cout<<"\nEnter Book Author:";
    getline(cin,author_name);
    cout<<"\nEnter Year of Publishment:";
    cin>>publish_year;
    
    //cout<<"\n########################";
    
   // cout<<"\n\nBook added!\n\n";
}

void Book::show_book()
{
   
    cout<<"\nBook Number:";
    cout<<book_no;
    cout<<"\nBook Name:";
    cout<<book_name;
    cout<<"\nBook's Author:";
    cout<<author_name;
    cout<<"\nPublish year:";
    cout<<publish_year;
}

void Book::modify_book()
{
    cout<<"\nBook Number:"<<book_no;
    cout<<"\nModify Book name:";
    cin>>book_name;
    cout<<"\nModify Book Author:";
    cin>>author_name;
}

void Book::report()
{
   
    //Draw upper line of the table
    cout<<left
    <<setw(20)<<setfill('-')<<left<<'+'
    <<setw(31)<<setfill('-')<<left<<'+'
    <<setw(31)<<setfill('-')<<left<<'+'
    <<setw(31)<<setfill('-')<<left<<'+'
    <<setw(20)<<setfill('-')<<'+'<<'+'
    <<endl;
    
    //Inner contents of the table
    cout<< setfill(' ')<<'|'<<left
    <<setw(19)<<"Entry No."<<setfill(' ')
    <<'|'<<setw(30)<<"Book Number"<<setfill(' ')
    <<'|'<<setw(30)<<"Book Name"<<setfill(' ')
    <<'|'<<setw(30)<<"Book Author"<<setfill(' ')
    <<'|'<<right<<"Year of Publishment"<<'|'
    <<endl;
     
    //Drawing the lower part of the table
    cout<< left << setw(20) << setfill('-') << left
    <<setw(20)<<setfill('-')<<left<<'+'
    <<setw(31)<<setfill('-')<<left<<'+'
    <<setw(31)<<setfill('-')<<left<<'+'
    <<setw(31)<<setfill('-')<<left<<'+'
    <<setw(20)<<setfill('-')<<'+'<<'+'<<endl;
    
    //Data inside the table
    cout<< setfill(' ')<<'|'<<left
        <<setw(19)<<"One"
        <<setfill(' ')<<'|'<<setw(30)<<book_no
        <<setfill(' ')<<'|'<<setw(30)<<book_name
        <<setfill(' ')<<'|'<<setw(30)<<author_name
        <<setfill(' ')<<'|'<<right<<publish_year<<setw(16)<<'|'<<endl;
   
   
  
}


//Defining functions for class object Student

void Student::add_student()
{
    cout<<"\nEnter Student Admission Number:";
    cin>>stud_admissionNo;
    cout<<"\nEnter Student's Name:";
    cin>>stud_name;
    token=0;
    stud_bookNo[0]='\0';
    cout<<"\nStudent's records have been successifully added";
    
    
}

void Student::show_student()
{
    cout<<"STUDENT'S DETAILS\n";
    cout<<"Admission Number:";
    cout<<stud_admissionNo;
    cout<<"Student's name:";
    puts(stud_name); //puts is handy in printing strings to the screen
    cout<<"No. of Book issued:\n"<<token;
    if(token==1)
    {
        cout<<"Book Number:"<<stud_bookNo;
    }
    
}

void Student::modify_student()
{
    cout<<"Admission Number:"<<stud_admissionNo;
    cout<<"Modify Student Name:";
    cin>>stud_name;
}

void Student::get_StudBookNo(char t[])
{
    strcpy(stud_bookNo, t);
}

void Student::Report()
{
    cout<<stud_admissionNo<<setw(20)<<stud_name<<setw(10);
    cout<<token<<endl;
}

//Functions for WRITING IN FILE


void Storage::write_book()
{
    char choice;
    file4Books.open("book.dat",ios::out|ios::app); //open the the file that we want to write data in.
    do {
        book.add_book();
        file4Books.write((char*)&book, sizeof(Book));
        cout<<"\n\nDo you want to save? (Y/N)";
        cin>>choice;
        cout<<"\n\nBook added!"<<endl;
    }while (choice=='y'||choice=='Y');
    file4Books.close();
    cout<<"\n\n";
    
    
    
}

//WRITING STUDENT DATA TO FILE
void Storage::write_student()
{
    char choice;
    file4Students.open("student.dat",ios::out|ios::app);
     
    
    do {
        student.add_student();
        file4Students.write((char*)&student, sizeof(Student));
        cout<<"\n\nDo you want to save student's details? (Y/N):\n";
        cin>>choice;
        
        
    } while (choice=='y'|| choice=='Y');
    file4Students.close();
    exit(0);
}

//Functions for reading data from file and displaying it
void Storage::display_bookDetails(char n[])
{
    cout<<"\nBOOK DETAILS\n";
    int flag=0;
    file4Books.open("book.dat",ios::in);//Only for reading
    while (file4Books.read((char*)&book,sizeof(Book))) {
        if (strcmp(book.return_BookNo(),n)==0) {
            book.show_book();
            flag=1;
        }
    }
    file4Books.close();
    if (flag==0) {
        cout<<"\nBook Does not Exist";
    }
    cin.get();
}

//Function for reading and displaying student's data
void Storage::display_studentDetails(char n[])
{
    cout<<"\n\nSTUDENT DETAILS\n";
    int flag=0;
    file4Students.open("student.dat",ios::in);
    while (file4Students.read((char*)&student, sizeof(Student)))
    {
        if (strcmp(student.returnAdmissionNo(), n)==0) {
            student.show_student();
            flag=1;
        }
    }
    file4Students.close();
    if (flag==0) {
        cout<<"\n\nStudent Doesn't exist\n";
        
    }
    cin.get();
}

//FUNCTION FOR MODIFYING /EDITING BOOK RECORDS
void Storage::modify_book()
{
    char n[6];
    int found=0;
    cout<<"\n\nMODIFY BOOK RECORD\n";
    cout<<"\n\nEnter Book number:";
    cin>>n;
    file4Books.open("book.dat",ios::in|ios::out);
    while (file4Books.read((char*)&book, sizeof(Book))&& found==0) {
        if (strcmp(book.return_BookNo(), n)==0) {
            book.show_book();
            cout<<"Enter New Details of the Book\n";
            book.modify_book();
            unsigned long pos=-1*sizeof(book);
            file4Books.seekp(pos,ios::cur);
            file4Books.write((char*)&book, sizeof(Book));
            cout<<"\nRecords updated\n";
            cout<<"\n\nChanges saved";
            found=1;
            
        }
    }
    file4Books.close();
    if (found==0) {
        cout<<"\n\nRecords not found";
    }
    cin.get();

}
//FUNCTION FOR MODIFYING STUDENT RECORDS
void Storage::modify_student()
{
    char n[6];
    int found=0;
    cout<<"\n\nMODIFY STUDENT RECORD";
    cout<<"\n\nEnter Student Admission number:";
    cin>>n;
    file4Students.open("student.dat",ios::in|ios::out);
    while (file4Students.read((char*)&student, sizeof(Student)) && found ==0) {
        if (strcmp(student.returnAdmissionNo(), n)==0) {
            student.show_student();
            cout<<"\nENTER NEW STUDENT DETAILS";
            student.modify_student();
            unsigned long pos =-1*sizeof(student);
            file4Students.seekp(pos,ios::cur);
            file4Students.write((char*)&student, sizeof(Student));
            cout<<"\n\nRecords updated";
            cout<<"\n\nCHANGES SAVED!!\n";
            found =1;
        }
    }
    file4Students.close();
    if (found==0) {
        cout<<"\n\nRecord not found";
    }
}

//FUNCTION FOR BOOK DELETION
void Storage::delete_book()
{
    char n[6];
    cout<<"\n\nDELETE BOOK\n";
    cout<<"\n\nEnter the book number of the book you want to delete:";
    cin>>n;
    file4Books.open("book.dat",ios::in|ios::out);
    file4TempStorage.open("Temp.dat",ios::out);
    file4Books.seekg(0,ios::beg);
    while (file4Books.read((char*)&book, sizeof(Book))) {
        if (strcmp(book.return_BookNo(), n)!=0) {
            file4TempStorage.write((char*)&book, sizeof(book));
        }
    }
    file4TempStorage.close();
    file4Books.close();
    remove("book.dat");
    rename("file4TempStorage", "book.dat");
    cout<<"\n\nRecord deleted..";
    cin.get();
}

//FUNCTION FOR STUDENT DELETION
void Storage::delete_student()
{
    char n[6];
    int flag =0;
    cout<<"\n\nDELET STUDENT RECORD\n";
    cout<<"\n\nEnter Admission Number fo the student yu want to delete:";
    cin>>n;
    file4Students.open("student.dat",ios::in|ios::out);
    file4TempStorage.open("Temp.dat",ios::out);
    file4Students.seekg(0,ios::beg);
    while (file4Students.read((char*)&student, sizeof(Student))) {
        if (strcmp(student.returnAdmissionNo(), n)!=0) {
            file4TempStorage.write((char*)&student, sizeof(Student));
        }
        else
        {
            flag=1;
        }
    }
    file4TempStorage.close();
    file4Students.close();
    remove("student.dat");
    rename("file4TempStorage", "student.dat");
    if (flag==1)
    {
        cout<<"\n\nRecord deleted!";
        
    }
    else
    {
        cout<<"\n\nRecord Not Found!";
    }
    cin.get();
}

//FUNCTIONS TO DISPLAY ALL BOOKS IN THE LIBRARY

void Storage::display_allBooks()
{
    file4Books.open("book.dat",ios::in);
    if (!file4Books) {
        cout<<"\nERROR!! FILE COULD NOT OPEN";
        cin.get();
        return;
    }
    cout<<"\n\nLIST OF BOOKS IN THE LIBRARY\n";
    while (file4Books.read((char*)&book, sizeof(Book)))
    {
        book.report();
            //Draw a line under the data
            cout<< left << setw(20) << setfill('-') << left
            <<setw(20)<<setfill('-')<<left<<'+'
            <<setw(31)<<setfill('-')<<left<<'+'
            <<setw(31)<<setfill('-')<<left<<'+'
            <<setw(31)<<setfill('-')<<left<<'+'
            <<setw(20)<<setfill('-')<<'+'<<'+'<<endl;
        
    }
    file4Books.close();
        
}

//FUNCTION TO DISPLAY STUDENTS AND THE BOOKS THEY HAVE
void Storage::display_allStudents()
{
    file4Students.open("student.dat",ios::in);
    if (!file4Students) {
        cout<<"\nERROR!! FILE COULD NOT BE OPENED";
        cin.get();
        return;
    }
    
    while (file4Students.read((char*)&book, sizeof(Book))) {
        student.Report();
    }
    file4Books.close();
    cin.get();
}

//FUNCTION TO ISSUE BOOK

void Storage::book_issue()
{
    char stdno[6],bkno[6];
    int found=0,flag=0;
  
    cout<<"\n\nBOOK ISSUE...";
    cout<<"\n\n\tEnter Student Admission NO.";
    cin>>stdno;
    file4Students.open("student.dat",ios::in|ios::out);
    file4Books.open("book.dat",ios::in|ios::out);
    //Searching the book
    while (file4Students.read((char*)&student, sizeof(Student))&& found ==0)
    {
        if (strcmp(student.returnAdmissionNo(), stdno)==0)
        {
            found=1;
            if (student.returnToken()==0)
            {
                cout<<"\n\n\tEnter the book number:";
                cin>>bkno;
                while (file4Books.read((char*)&book, sizeof(Book))&& flag==0)
                {
                    if (strcmp(book.return_BookNo(),bkno)==0)
                    {
                        book.show_book();
                        flag=1;
                        student.add_token();
                        student.get_StudBookNo(book.return_BookNo());
                        unsigned long pos=-1*sizeof(student);
                        file4Students.seekp(pos,ios::cur);
                        file4Students.write((char*)&student, sizeof(Student));
                        cout<<"\n\n\t Book issued succesifuly!";
                        cout<<"\n\nPlease note the following: \nWrite the current date in backside of the book and submit withn 15 days.\n";
                        cout<<"\n\nFine for each day will be 1 rubles and it will\n be taken after a 15 day period";
                    }
                }
                if (flag==0)
                {
                    cout<<"\nBook does not exist";
                }
                else
                {
                    cout<<"You have not returned last book.\n";
                    cout<<"Book can be issued only after you return the previoud one\n";
                }
            }
            if (found==0)
            {
                cout<<"Student record does not exist...\n";
                cin.get();
                file4Books.close();
                file4Students.close();
            }
        }
    }
    
}

//FUNCTION TO DEPOSIT THE BOOK

void Storage::book_deposit()
{
    char stdn[6];
    int found=0,flag=0,days,fine;
    
    cout<<"\n\nBOOK DEPOSIT...";
    cout<<"\n\n\tEnter the student's admission No. ";
    cin>>stdn;
    file4Books.open("book.dat",ios::in|ios::out);
    file4Students.open("student.dat",ios::in|ios::out);
    while (file4Students.read((char*)&student, sizeof(Student))&& found ==0)
    {
        if (strcmp(student.returnAdmissionNo(), stdn)==0)
        {
            found=1;
            if (student.returnToken()==1)
            {
                while (file4Books.read((char*)&book, sizeof(Book))&& flag==0)
                {
                    if (strcmp(book.return_BookNo(), student.returnStud_bookNo())==0)
                    {
                        book.show_book();
                        flag=1;
                        cout<<"\n\nBook deposited in no. of days";
                        cin>>days;
                        if (days>15)
                        {
                            fine =(days-15)*1;
                            cout<<"\n\nFine has to be deposited rub";
                            cout<<fine;
                        }
                        student.reset_token();
                        unsigned long pos=-1*sizeof(student);
                        file4Students.seekp(pos,ios::cur);
                        file4Students.write((char*)&student, sizeof(Student));
                        cout<<"\n\n\t Book deposited successifuly";
                    }
                }
                if (flag==0)
                {
                    cout<<"Book does not exist";
                }
                else
                {
                    cout<<"No book issued... \nPlease check!!";
                }
            }
        }
    }
    if (found==0)
    {
        cout<<"Student record does not exist...";
    }
    cin.get();
    file4Books.close();
    file4Students.close();
    
}

//MENU FUNCTIONS
void IntroMenu::Welcome()
{
   //Welcome remarks
    
    for (int i=0; i<=100; i++)
    {
        cout<<"#";
    }
    
    
    
    cout<<"\n# WELCOME TO THE ROB-THE-DEER LIBRARY"<<setw(64)<<"#";
    cout<<"\n# THIS PROGRAM WAS WRITTEN BY: ROBERT NYAMUGADA"<<setw(54)<<"#";
    cout<<"\n# Junior C++ Programmer"<<setw(78)<<"#";
    //Date and time
    cout<<"\n# The time is:"<<setw(87)<<"#";
    auto givetime= chrono::system_clock::to_time_t(chrono::system_clock::now());
    cout<<"\n# "<<ctime(&givetime)<<"#"<<setw(101)<<"#\n";
    for (int i=0; i<=100; i++) {
        cout<<"#";
    }
    cout<<"\n";
    
    
    
    
}

void IntroMenu::Menu()
{
    cout<<"\n\n***WELCOME TO THE LIBRARY MAIN MENU***";
    cout<<"\n\n\t1.BOOK ISSUE";
    cout<<"\n\n\t2.BOOK DEPOSIT";
    cout<<"\n\n\t3.ADMIN MENU";
    cout<<"\n\n\t4.EXIT";
    cout<<"\n\n\t Please Select an option(1-4):";
    int choice;
    cin>>choice;
    switch (choice) {
        case 1:
            storage.book_issue();
            break;
        case 2:
            storage.book_deposit();
            break;
        case 3:
            Admin();
            break;
        case 4: exit(0);
        default:
            break;
    }
}

void IntroMenu::Admin()
{
   
    cout<<"\n\n\t<<<ADMIN MENU>>>";
    char num[6];
    int choice;
    cout<<"\n\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\n\t2.SHOW ALL STUDENT RECORDS";
    cout<<"\n\n\t3.SEARCH STUDENT RECORD";
    cout<<"\n\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\n\t6.ADD BOOK TO THE LIBRARY";
    cout<<"\n\n\t7.DISPLAY ALL BOOKS IN THE LIBRARY";
    cout<<"\n\n\t8.SEARCH BOOKS IN STOCK";
    cout<<"\n\n\t9.MODIFY BOOK STATUS";
    cout<<"\n\n\t10.REMOVE BOOK FROM THE LIBRARY";
    cout<<"\n\n\t11.RETURN TO MAIN MENU";
    cout<<"\n\n\tEnter option (1-11):";
    
    cin>>choice;
    switch (choice) {
        case 1:
            storage.write_student();
            Menu();
            break;
        case 2:
            storage.display_allStudents();
            Menu();
            break;
        case 3:
            cout<<"\n\n\tEnter Admission Number:";
            cin>>num;
            storage.display_studentDetails(num);
            Menu();
            break;
        case 4:
            storage.modify_student();
            Menu();
            break;
        case 5:
            storage.delete_student();
            Menu();
            break;
            
        case 6:
            storage.write_book();
            Menu();
            break;
        case 7:
            storage.display_allBooks();
            Menu();
            break;
        case 8:
            cout<<"\n\n\tEnter Book number:";
            cin>>num;
            storage.display_bookDetails(num);
            Menu();
            break;
        case 9:
            storage.modify_book();
            Menu();
            break;
        case 10:
            storage.delete_book();
            Menu();
            break;
        case 11:
            Menu();
        default:
            break;
    }
}
