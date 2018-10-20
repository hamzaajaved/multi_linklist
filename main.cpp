#include<iostream>
#include <string>
#include <cstring>
#include<stdlib.h>
using namespace std;

struct CLASS{
  string name;
  int no_of_std;
  struct CLASS *next; 
  struct Student *header;
};

struct Student{
  string name;
  int seat_no;
  double GP;
  struct Student *next;
};
struct CLASS *start = NULL;
void insert_class(string Name,int no_of_std);
void insert_student(string Name,int seat_no,double GP);
void print_class();
void print_student();
int main(int argc, char const *argv[])
{
  insert_class("I",10);
  insert_class("II",20);
  insert_student("Hamza",90,3.0);
  insert_student("Hadi",164,3.9);

  print_class();

  system("pause");
  return 0;
}

// INSERT CLASS
void insert_class(string Name,int no_of_std){
  struct CLASS *ptr = new CLASS;
  ptr->name = Name;
  ptr->no_of_std = no_of_std;
  ptr->next = NULL;
  ptr->header = NULL;

  if(start == NULL){
    start = ptr;
  }else{
    struct CLASS *curr = start;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = ptr;
  }
}

// INSERT STUDENT
void insert_student(string Name,int seat_no,double GP){
  struct Student *ptr = new Student;
  ptr->name = Name;
  ptr->seat_no = seat_no;
  ptr->GP = GP;
  ptr->next = NULL;

  if(start->header == NULL){
    start->header = ptr;
  }else{
    struct Student *curr = start->header;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = ptr;
  }
}

//PRINT CLASS
void print_class(){
  struct CLASS *currClass = start;
  while(currClass != NULL){
    cout << "\n\nThe Student in Class " << currClass->name << " are: " << endl;
    struct Student *currStudent = currClass->header;
    while(currStudent != NULL){
        cout << "Name: " << currStudent->name
         << endl;
         cout << " Seat No: " << currStudent->seat_no << endl;
        currStudent = currStudent->next;
    } 
    currClass = currClass->next;
  }
}
