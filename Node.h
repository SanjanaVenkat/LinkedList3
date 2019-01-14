#ifndef NODE_H
#define NODE_H

#include "Student.h"
#include <iostream>
class Node {

 public:
  //Constructor that sets student it points to and the next node
  Node(Student* student = NULL, Node* node = NULL);
  //Deconstructor just deletes Student
  ~Node();
  //This obtians the next node
  Node* getNext();
  //This will set the next node 
  void setNext(Node* newnext);
  //This getter will return the student 
  Student* getStudent();
  //This will set the student of a node
  void setStudent(Student* newstudent);
  

 private:

  //data memebers
  Student* student;
  Node* next;
};
#endif
