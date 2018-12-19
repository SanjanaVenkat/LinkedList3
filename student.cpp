#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;
//constructor
Student::Student() {

}
//destructor
Student::~Student() {

}
//sets student info
void Student::setgpa(float g) {
  gpa = g;
}

void Student::setid(int i) {
  id = i;
}

void Student::setfirst(char f[]) {
  strcpy(firstname, f);
}

void Student::setlast(char l[]) {
  strcpy(lastname, l);
}
//returns student info
float Student::getgpa() {
  return gpa;
}

int Student::getid() {
  return id;
}

char* Student::getfirst() {
  return firstname;
}

char* Student::getlast() {
  return lastname;
}


