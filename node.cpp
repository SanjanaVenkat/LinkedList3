#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

//constructor
Node::Node(Student* s) {
  next = NULL;
  student = s;
}
//destructor
Node::~Node() {
  next = NULL;
  //  delete student;
}
//sets next node
void Node::setNext(Node* newnext) {
  next = newnext;
}
//gets next node
Node* Node::getNext() {
  return next;
}
//gets student of node
Student* Node::getStudent() {
  return student;
}

