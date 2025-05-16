/*
  precaution to take while using this library.
    1. call setEnble() function in setup compulsory.
    2. Serial.begin() is not called in this library. 
       Expected to call inside the main.c code.
*/

#ifndef BTS7960_H
#define BTS7960_H

#include <Arduino.h>

class BTS7960 {
private:
  int lpwm, rpwm;
  int Renb, Lenb;
  bool enableUse;

public:
  BTS7960(int, int);
  BTS7960(int, int, int, int);
  void rotate(int);
  void stop();
  void test(int);
  void setEnable(bool);
};

#endif