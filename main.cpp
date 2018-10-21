#include<iostream>
#include<stdlib.h>
using namespace std;

// Structures
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


// Prototypes Declared
void insert_class(string Name,int no_of_std,CLASS **start);
void insert_student(string Name,int seat_no,double GP,Student **start);
CLASS* searchClass(string classtoSearch, CLASS **start);
void searchStudent(int seat_no, CLASS **start);
void print_class(CLASS **start);



int main(int argc, char const *argv[])
{
  struct CLASS *start = NULL;
  // Insert Classes
  insert_class("I",10, &start);
  insert_class("II",20,&start);
  insert_class("III",10,&start);

  // Insert Students in Class I
  insert_student("Hamza",90,3.0,&start->header);
  insert_student("Hadi",164,3.9,&start->header);

  CLASS *curr = searchClass("III", &start);
  if(curr == NULL){
    cout << "Class Not Found" << endl;
  }else{
    // Insert Students in Class III
    insert_student("Owais",100,3.9,&curr->header);
    insert_student("Sohail",101,3.7,&curr->header);
    insert_student("Ali Mustafa",102,3.8,&curr->header);
  }
  print_class(&start);

  searchStudent(90,&start);
  searchStudent(100,&start);
  searchStudent(102,&start);
  searchStudent(500,&start);
  system("pause");
  return 0;
}

// INSERT CLASS
void insert_class(string Name,int no_of_std,CLASS **start){
  struct CLASS *ptr = new CLASS;
  ptr->name = Name;
  ptr->no_of_std = no_of_std;
  ptr->next = NULL;
  ptr->header = NULL;

  if(*start == NULL){
    *start = ptr;
  }else{
    struct CLASS *curr = *start;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = ptr;
  }
}

// INSERT STUDENT
void insert_student(string Name,int seat_no,double GP,Student **start){
  struct Student *ptr = new Student;
  ptr->name = Name;
  ptr->seat_no = seat_no;
  ptr->GP = GP;
  ptr->next = NULL;

  if(*start == NULL){
    *start = ptr;
  }else{
    struct Student *curr = *start;
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = ptr;
  }
}

// Search A Class
CLASS* searchClass(string classtoSearch, CLASS **start){
  struct CLASS *curr = *start;
  int temp = 0;
  while(curr != NULL){
    if(curr->name == classtoSearch){
      temp++;
      break;
    }
    curr = curr->next;
  }
  if(temp > 0){
    return curr;
  }else{
    return NULL;
  }
}

// Search A Student
void searchStudent(int seat_no, CLASS **start){
  struct CLASS *currClass = *start;
  int temp = 0;
  while(currClass != NULL){
     struct Student *currStudent = currClass->header;
      while(currStudent != NULL){
        if(currStudent->seat_no == seat_no){ 
          temp++;
          break;
        }
        currStudent = currStudent->next;
      }
    currClass = currClass->next;
  }

  if(temp == 1){
    cout << "\nSeat No: " << seat_no << " Found!" << endl;
  }else{
     cout << "\nSeat No: " << seat_no << " Does Not Exist!" << endl;
  }
}


//PRINT CLASS
void print_class(CLASS **start){
  struct CLASS *currClass = *start;
  while(currClass != NULL){
    cout << "\n\nClass Name: " << currClass->name <<  endl;
    struct Student *currStudent = currClass->header;
    while(currStudent != NULL){
        cout << "Name: " << currStudent->name << endl;
        cout << "Seat No: " << currStudent->seat_no << endl;
        cout << "GP: " << currStudent->GP << "\n" << endl;
        currStudent = currStudent->next;
    } 
    currClass = currClass->next;
  }
}

