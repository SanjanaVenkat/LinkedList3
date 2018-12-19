//Sanjana Venkat
//12.17.18
//Student list project using linked lists
#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "node.h"

using namespace std;

void printStudents(Node* start);
Node* addStudent(Node* start);
Node* deleteStudent(Node* start);
void averageStudents(Node* start);

//adds a student
Node* addStudent(Node* start) {
  char f[100];
  char l[100];
  int i = 0;
  float g = 0;
  Node* current = start;
  Node* first = start;
  Student* s = new Student();
  cout << "Enter student first name" << endl;
  cin >> f;
  s->setfirst(f);
  cout << "Enter student last name" << endl;
  cin >> l;
  s->setlast(l);
  cout << "Enter student ID" << endl;
  cin >> i;
  s->setid(i);
  cout << "Enter student GPA" << endl;
  cin >> g;
  s->setgpa(g);
  if (current == NULL) {
    current = new Node(s);
    first = current;
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    Node* n = new Node(s);
    current->setNext(n);
  }
  return first;
  }

//prints all students
void printStudents(Node* start) {
  
  Node* current = start;
  while (current != NULL) {
    Student* s = current->getStudent();
    cout << s->getfirst() << " " << s->getlast() << " " << s->getid() << " "<< setprecision(3) << s->getgpa() << endl;
    current = current->getNext();
  }
  }

void averageStudents(Node* start) {
  float a = 0;
  float ave = 0;
  int count = 0;
  Node* current = start;
  while (current!= NULL) {
    Student* s = current->getStudent();
    a = a + s->getgpa();
    count = count + 1;
    current = current->getNext();
  }
  ave = a/count;
  cout << "Average gpa of all students: "<< setprecision(3) << ave << endl;
}

//deletes student by id
Node* deleteStudent(Node* start) {
  Node* newstart = start;
  int studentid;
  int index;
  bool idexists = false;
  Node* current = start;
  Node* track = NULL;
  cout << "Enter student id" << endl;
  cin >> studentid;
  //while current is valid and has not found id
 
  while (current != NULL && idexists == false) {
    //current student
    Student* s = current->getStudent();
    
    if (studentid == s->getid()) {
      if (track != NULL) {
	track->setNext(current->getNext());
      }
      else {
	newstart = newstart->getNext();
      }
      idexists = true;
    }
       
    else {
      track = current;
      current = current->getNext();
      
    }
 
  }
  if (idexists == true) {
  delete current->getStudent();
  delete current;
  cout << "Student deleted" << endl;
  }
  else {
    cout << "Student with this ID does not exist" << endl;
  }
 
  return newstart;
}

//asks what user wants to do
void getResponse(char response[10]) {
  bool running = true;
  cout << "Enter ADD, PRINT, AVERAGE, DELETE, or QUIT" << endl;
  cin >> response;
  running == true;
}



//main, runs functions based on response
int main() {
  Node* start = NULL;
char response[10];
 char add[] = "ADD";
 char print[] = "PRINT";
 char del[] = "DELETE";
 char quit[] = "QUIT";
 char ave[] = "AVERAGE";
 bool running = true;
 getResponse(response);
  while (running == true) {
    if (strcmp(add, response) == 0) {
      start = addStudent(start);
      getResponse(response);
        }
    else if (strcmp(print, response) == 0)
     {
       printStudents(start);
      getResponse(response);
           }
    else  if (strcmp(del, response) == 0) {
      start = deleteStudent(start);
      getResponse(response);

      }
    else if (strcmp(ave, response) == 0) {
      averageStudents(start);
      getResponse(response);
    }
    else if (strcmp(quit, response) == 0) {
      cout << "Quitting" << endl;
        return 0;
      }
 else {
      cout << "Enter a valid response" << endl;
      getResponse(response);
    }
  }

  return 0;
}
