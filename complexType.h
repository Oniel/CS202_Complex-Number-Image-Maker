//Oniel Toledo   Assignment09   CS202
//The following class is one of the base classes for the complexPlot class.
//arithmetic such as addition, subtraction, multiplication, and division are
//performed in this class for the use of complexPlot
//performs all the complex calculations for the derived class complexPlot.
#ifndef COMPLEXTYPE_H
#define COMPLEXTYPE_H
#include <iostream>
#include <string>
#include <cmath>
#include "bitmapImage.h"
using namespace std;

class complexType: public bitmapImage {
  //friend non-member functions(have complete access to all class members)
  friend ostream& operator <<(ostream&, const complexType&);
  friend istream& operator >>(istream&, const complexType&);
 public:
  //constructor
  complexType (double=0.0, double=0.0);
  //operator overload functions, the current class object will perform the following
  //operators to the passed object of type complexType
  complexType operator +(const complexType&);
  complexType operator -(const complexType&);
  complexType operator /(const complexType&);
  complexType operator *(const complexType&);
  bool operator== (const complexType&);
  //functions
  double angle();
  double abs();
  complexType sine();
  complexType cose();
  complexType cSqrt();
  //setters
  void setComplex(const double&, const double&);
  //getters
  void getComplex(double&, double&) const;
 private:
  double realPart;
  double imaginaryPart;  
};
#endif
