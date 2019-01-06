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

// recursive add

Node* add(Node* first, Node* last, Node* next, Node* n) {
    bool done = false;
    
    //less than next, greater than last
      if (last == NULL && next->getStudent()->getid() > n->getStudent()->getid()) {
      n->setNext(next);
      first = n;
      done = true;
    }
    else if (next->getStudent()->getid() > n->getStudent()->getid() && last->getStudent()->getid() < n->getStudent()->getid()) {
      last->setNext(n);
      n->setNext(next);
      done = true;
     }

    
     last = next;
     if (next->getNext() != NULL && done == false) {
       first = add(first, last, next->getNext(), n);
     }
     

     if (last->getNext() == NULL && done == false) {
	last->setNext(n);
     }
     return first;
}

//adds a student
Node* addStudent(Node* start) {
  char f[100];
  char l[100];
  int i = 0;
  float g = 0;
  Node* current = start;
  Node* first = start;
  Node* last = NULL;
  Node* next = start;
  bool done = false;
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
  Node* n = new Node(s);
  // first student
  if (current == NULL) {
    current = new Node(s);
    first = current;
    done = true;
  }
  // next students
  
  else {
    first = add(first, last, next, n);
    }
  
  return first;
  }

//prints all students
void printStudents(Node* start) {
  
  Node* current = start;
  if (current != NULL) {
    Student* s = current->getStudent();
    cout << s->getfirst() << " " << s->getlast() << " " << s->getid() << " "<< setprecision(3) << s->getgpa() << endl;
    if (current->getNext() != NULL) {
      printStudents(current->getNext());
    }
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


Node* deletest(Node* start, Node* last, Node* next, int studentid) {

  if (next->getStudent()->getid() == studentid) {
    if (last != NULL) {
      last->setNext(next->getNext());
      delete next;
      return start;
    }
    else {
      start = next->getNext();
      delete next;
      return start;
    }
  }
    else {
      if (next->getNext() != NULL) {
      deletest(start, next, next->getNext(), studentid);
      }
      else {
	cout << "Student with this id does not exist" << endl;
	return start;
      }
    }

  }
  


//deletes student by id
Node* deleteStudent(Node* start) {
  Node* newstart = start;
  int studentid;
  int index;
  bool idexists = false;
  Node* last = NULL;
  Node* next = start;
  cout << "Enter student id" << endl;
  cin >> studentid;

start = deletest(start, last, next, studentid);


 return start;

}
/*
  //while current is valid and has not found id
 
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
   
 
  
  if (idexists == true) {
  delete current->getStudent();
  delete current;
  cout << "Student deleted" << endl;
  }
  
  else if (idexists == false){
    if (current->getNext() == NULL) {
      cout << "Student with this id does not exist" << endl;
    }
    else {
      deleteStudent(current->getNext());
    }
    } 
 
  return newstart;
}

*/

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
