//Sanjana Venkat
//1.8.19
//Student list project using linked lists, modified to meet new requirements and using .o file
#include <iostream>
#include <cstring>
#include <iomanip>
#include "student.h"
#include "node.h"

using namespace std;

//functions
void printStudents(Node* start);
Node* addStudent(Node* start);
Node* deleteStudent(Node* start);
void averageStudents(Node* start);

// recursive add function
Node* add(Node* first, Node* last, Node* next, Node* n) {
    bool done = false;
    
    //adds to start of list (first)
      if (last == NULL && next->getStudent()->getid() > n->getStudent()->getid()) {
      n->setNext(next);
      first = n;
      done = true;
    }
      //adds to middle of the list based on values less than and greater in list
    else if (next->getStudent()->getid() > n->getStudent()->getid() && last->getStudent()->getid() < n->getStudent()->getid()) {
      last->setNext(n);
      n->setNext(next);
      done = true;
     }

    
     last = next;
     //adds to beginning of list
     if (next->getNext() != NULL && done == false) {
       first = add(first, last, next->getNext(), n);
     }
     
     //adds to end of list
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
  //using recursion
  else {
    first = add(first, last, next, n);
    }
  //returns the start of the list
  return first;
  }

//prints all students
void printStudents(Node* start) {
  
  Node* current = start;
  //while the student isn't null (end of list)
  if (current != NULL) {
    Student* s = current->getStudent();
    //prints current student
    cout << s->getfirst() << " " << s->getlast() << " " << s->getid() << " "<< setprecision(3) << s->getgpa() << endl;
    if (current->getNext() != NULL) {
      //using recursion to print next student
      printStudents(current->getNext());
    }
}
  
  }

void averageStudents(Node* start) {
  float a = 0;
  float ave = 0;
  int count = 0;
  Node* current = start;
  //averages student gpas
  while (current!= NULL) {
    Student* s = current->getStudent();
    a = a + s->getgpa();
    count = count + 1;
    current = current->getNext();
  }
  ave = a/count;
  //prints gpa to three decimals
  cout << "Average gpa of all students: "<< setprecision(3) << ave << endl;
}


//recursive delete function
Node* deletest(Node* start, Node* last, Node* next, int studentid) {
  //if the student id matches
  if (next->getStudent()->getid() == studentid) {
    //deletes student from list
    if (last != NULL) {
      last->setNext(next->getNext());
      delete next;
      return start;
    }
    //delete first student
    else {
      start = next->getNext();
      delete next;
      return start;
    }
  }
    else {
      //deleting recursive
      if (next->getNext() != NULL) {
      deletest(start, next, next->getNext(), studentid);
      }
      //no id match found
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
  //recursive delete after entering student id to delete
start = deletest(start, last, next, studentid);

//returns new start
 return start;

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
 //responses
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
