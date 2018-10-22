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
void deleteAClass(string Name,CLASS **start);
void deleteAStudent(int seat_no,CLASS **start);
void print_class(CLASS **start);


int main(int argc, char const *argv[])
{
  struct CLASS *start = NULL;
  int val;
  do{
    cout << "\n1 - Insert Class: \n2 - Insert Student: \n3 - Delete Class: \n4 - Delete Student: \n5 - Search A Student:  \n6 - Print All Students:  \n7 - Exit Menu" << endl;
  
    cout << "Your Choice: " << endl;
    cin >> val;
      switch(val){
        case 1:
        {
           system("CLS");
           string className;
            int totalNoOfStd;
            cout << "Enter Class Name: ";
            cin >> className;
            cout << "Enter Total No of Students in Class: ";
            cin >> totalNoOfStd;
            insert_class(className,totalNoOfStd,&start);
            cout << "Class Successfully Inserted! Please Insert Students " << endl;
            break;
        }
        case 2:
        {
            system("CLS");
            string stdClass;
            cout << "Enter Class Name to Insert Student: ";
            cin >> stdClass;
            string stdName;
            cout << "Enter Student Name: ";
            cin >> stdName;
            int seatNo;
            cout << "Enter Seat No: ";
            cin >> seatNo;
            double GP;
            cout << "Enter GP: ";
            cin >> GP;

            CLASS *curr = searchClass(stdClass, &start);
            if(curr == NULL){
              cout << "Class Not Found" << endl;
            }else{
              insert_student(stdName,seatNo,GP,&curr->header);
            }
            cout << "Student Successfully Inserted! " << endl;
            break;
        }
        case 3:
        {
            system("CLS");
            string delClassName;
            cout << "Enter Class Name to Delete: ";
            cin >> delClassName;

            deleteAClass(delClassName,&start);
            cout << "Class Successfully Deleted!" << endl;
            break;
        }
        case 4:
        {
            system("CLS");
            int delSeatNo;
            cout << "Enter SeatNo To Delete Student: ";
            cin >> delSeatNo;

            deleteAStudent(delSeatNo,&start);
            cout << "Student Successfully Deleted!" << endl;
            break;
        }
        case 5:
        {
            system("CLS");
            int searchSeatNo;
            cout << "Enter SeatNo To Search A Student: ";
            cin >> searchSeatNo;

            searchStudent(searchSeatNo,&start);
            break;
        } 
        case 6:
        {
            system("CLS");
            cout << "PRINTING ALL CLASSES" << endl;
            print_class(&start);
            break;
        }
      }
  }while(val != 7);
  // // Insert Classes
  // insert_class("I",10, &start);
  // insert_class("II",20,&start);
  // insert_class("III",10,&start);

  // // Insert Students in Class I
  // insert_student("Hamza",90,3.0,&start->header);
  // insert_student("Hadi",164,3.9,&start->header);

  // CLASS *curr = searchClass("III", &start);
  // if(curr == NULL){
  //   cout << "Class Not Found" << endl;
  // }else{
  //   // Insert Students in Class III
  //   insert_student("Owais",100,3.9,&curr->header);
  //   insert_student("Sohail",101,3.7,&curr->header);
  //   insert_student("Ali Mustafa",102,3.8,&curr->header);
  // }
  // print_class(&start);

  // searchStudent(90,&start);
  // searchStudent(100,&start);
  // searchStudent(102,&start);
  // searchStudent(500,&start);

  // deleteAClass("II",&start);
  // cout << "After deletion of Class II" << endl;
  // print_class(&start);

  // deleteAStudent(164,&start);
  // deleteAStudent(101,&start);

  // cout << "After deletion of 164 and 101" << endl;
  // print_class(&start);


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

// Delete A Class
void deleteAClass(string Name,CLASS **start){
  struct CLASS *curr = *start;
  if((*start)->name == Name){
    *start = (*start)->next;
    free(curr);
  }else{
    curr = (*start)->next;
    struct CLASS *prev = *start;
    while(curr->name != Name){
      curr = curr->next;
      prev = prev->next;
    }
    prev->next = curr->next;  
    free(curr);
  }
}

// Delete A Student
void deleteAStudent(int seat_no,CLASS **start){
  struct CLASS *currClass = *start;
  Student *currStudent= NULL;
  int temp = 0;
  while(currClass != NULL){
        currStudent = currClass->header;
        if(currStudent->seat_no == seat_no){ 
          currClass->header = currStudent->next;
          free(currStudent);
        }else{
          currStudent= (currClass->header)->next;
          Student *prev= currClass->header;
        
        while(currStudent != NULL){
          if(currStudent->seat_no == seat_no){
            temp++;
            prev->next= currStudent->next;
            break;
          }
          currStudent = currStudent->next;
        }
        currClass = currClass->next;
    }
  }
  if(temp > 0){
    free(currStudent);
  }else{
    cout<<"\nStudent is not in any class.\n";
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
