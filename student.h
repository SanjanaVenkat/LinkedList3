#include <iostream>
#include <cstring>

using namespace std;


#ifndef STUDENT_H
#define STUDENT_H
//student class, sets and returns student information
class Student {
 public:
  Student();
  ~Student();
  void setgpa(float g);
  void setid(int i);
  void setfirst(char f[]);
  void setlast(char l[]);
  float getgpa();
  int getid();
  char* getfirst();
  char* getlast();
 private:
  float gpa;
  int id;
  char firstname[100];
  char lastname[100];
};
#endif
