//
//  Library.hpp
//  Library Management-App
//
//  Created by  Rob the deer on 25.05.2022.
//

#pragma once

#include <iostream>
#include <fstream>

using namespace std;


    

//CLASS #1 FOR BOOK
class Book
{
    char book_no[6];
    string book_name;
    string author_name;
    char publish_year[4];
        
public:
    void add_book();//Done
    void show_book();//done
    void modify_book();//Done
    char* return_BookNo() {return book_no;}//Done
    void report(); //Done
};
//CLASS #2 FOR STUDENT
class Student
{
    char stud_admissionNo[6];
    char stud_name[20];
    char stud_bookNo[6];
    int token;
    
public:
    void add_student(); //Done
    void show_student();//Done
    void modify_student();//Done
    char* returnAdmissionNo() {return stud_admissionNo;}//Done
    char* returnStud_bookNo(){return stud_bookNo;} //Done
    int returnToken() {return token;} //Done
    void add_token(){token=1;} //Done
    void reset_token(){token=0;}//Done
    void get_StudBookNo(char t[]);//Done
    void Report();//Done
};

//CLASS #3 FOR STORAGE
class Storage
{
    //Variables for storage
    fstream file4Books,file4Students;
    //Variables for deletion
    fstream file4TempStorage; //for the the deleted stuff
    Book book;
    Student student;
    
public:
    //functions for writing data
    void write_book();//Done
    void write_student();//Done
    //functions for readinng data
    void display_bookDetails(char n[]);//Done
    void display_studentDetails(char n[]);//Done
    //functions for modifying data
    void modify_book();//Done
    void modify_student();//Done
    //functions for deleting data
    void delete_book();//Done
    void delete_student();//Done
    
    //function to display all
    void display_allBooks();//Done
    void display_allStudents();//Done
    //Issuing and depositing
    void book_issue();//Done
    void book_deposit();//Done
};

//CLASS FOR INTRO AND MENU
class IntroMenu {
    Storage storage;
    
public:
    void Welcome();//Done
    void Menu();//Done
    void Admin();//Done
    
};
