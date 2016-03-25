//Oniel Toledo   Assignment 09   CS202
//The following file is the implementation file for the class object complexType.
//ComplexType is an independant class that is used for the complexPlot function.
//performs operator overloading functions as well as calcuations for absolute value,
//sine, cose, and square root functions.
#include <iostream>
#include <string>
#include <cmath>
#include "bitmapImage.h"
#include "complexType.h"

using namespace std;

//~~~~~~~~~~~~~~~~~~~~constructor~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//simple constuctor, reads and stores the passed parameters to realPart and imaginaryPart accordingly
complexType::complexType(double real, double imaginary){ 
  realPart = real;
  imaginaryPart = imaginary;
}

//~~~~~~~~~~~~~~~~~~~~friend functions~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//output stream function
ostream& operator <<(ostream& os, const complexType& cObject){
  double real, imaginary;
  cObject.getComplex(real, imaginary);
  os << "(" << real << ", " << imaginary << ")";
  return os;
}

//input stream function
istream& operator >>(istream& is, const complexType& cObject){
  char ch;
  double real, imaginary;
  cObject.getComplex(real, imaginary);
  is >> ch >> real >> ch >> imaginary >> ch;
  return is;
}

//~~~~~~~~~~~~~~~~~~~~~~~~operator overload functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//function that adds two objects of type complexType, the first object adds the
// second object to itself by refrencing the operator + and passing the second object
//as a parameter, in this case 'two'
complexType complexType::operator +(const complexType& two){
  complexType temp;//create a new object
  double real, imaginary;
  two.getComplex(real, imaginary);//return the two variables within the passed object class
  //since operator + uses x and adds y to it(as in a + b), the current object that is open is x as is
  //x's class variables, w/ temp having been created, x's variables can be added to y's variables and
  //stored within temp's variables (comment mainly for self clarification)
  temp.setComplex(realPart + real, imaginaryPart + imaginary);
  return temp;
}

//function that subtracts the current class object to the passed object
complexType complexType::operator -(const complexType& two){
  complexType temp;
  double real, imaginary;
  two.getComplex(real, imaginary);
  temp.setComplex(realPart - real, imaginaryPart - imaginary);
  return temp;
}

//function that multiplies the current class object to the passed object
complexType complexType::operator *(const complexType& two){
  complexType temp;
  double real, imaginary, tempReal, tempImaginary;
  two.getComplex(real, imaginary);
  //multiplication calculations for the the current object times the passed object 'two'
  tempReal = (realPart*real-imaginaryPart*imaginary);
  tempImaginary = (realPart*imaginary+imaginaryPart*real);
  temp.setComplex(tempReal, tempImaginary);
  return temp;
}

//function that divides the current class object to the passed object
complexType complexType::operator /(const complexType& two){
  complexType temp;
  double real, imaginary, tempReal, tempImaginary;
  two.getComplex(real, imaginary);
  //division calculations algorithms
  tempReal = (realPart*real+imaginaryPart*imaginary)/(pow(real,2)+pow(imaginary,2));
  tempImaginary = (-realPart*imaginary+imaginaryPart*real)/(pow(real,2)+pow(imaginary,2));
  temp.setComplex(tempReal, tempImaginary);//set calculations to the temp object and return it
  return temp;
}

//returns true or false depending if the current object's variables is equal to the passed object's 
//variables
bool complexType::operator ==(const complexType& two){
  double real, imaginary;
  two.getComplex(real, imaginary);
  return (realPart==real && imaginaryPart==imaginary);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Additional Functions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//function to determine the angle between the real and imaginary parts of the current object
double complexType::angle(){
  return (atan2(imaginaryPart,realPart));
}

//returns the absolute realPart and imaginaryPart variables
double complexType::abs(){
  return (sqrt(pow(realPart,2)+pow(imaginaryPart,2)));
}

//return the calculated sine value of realPart and imaginaryPart
complexType complexType::sine(){
  complexType temp;
  double real, imaginary;
  //sin calculations for the real and imaginary part
  real = sin(realPart)*cosh(imaginaryPart);
  imaginary = cos(realPart)*sinh(imaginaryPart);
  temp.setComplex(real, imaginary);
  return temp;
}

//return the object with the calcuated realPart and imaginaryPart
complexType complexType::cose(){
  complexType temp;
  double real, imaginary;
  real = cos(realPart)*cosh(imaginaryPart);
  imaginary = sin(realPart)*sinh(imaginaryPart);
  temp.setComplex(real, imaginary);
  return temp;
}

//function that finds the square root of the real and imaginary part of the current object
complexType complexType::cSqrt(){
  complexType temp;
  double tempReal, tempImaginary;
  double real = realPart;//variables set for less writing
  double imaginary = imaginaryPart;
  //calculate the square root of the realPart variable, store as the variable 'tempReal'
  tempReal = sqrt((real+sqrt(pow(real,2)+pow(imaginary,2)))/2);
  //calculate the square root part of the imaginaryPart variable
  tempImaginary =(imaginary/(std::abs(imaginary)))*sqrt((-real+sqrt(pow(real,2)+pow(imaginary,2)))/2);
  temp.setComplex(tempReal, tempImaginary);//set the new calculates to the temp object and return
  return temp;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~getters and setters~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//setComplex sets the passed parameters to the 'realPart' and 'imaginaryPart' variables
void complexType::setComplex(const double &real, const double &imaginary){
  realPart = real;//set passed parameters to realPart and imaginaryPart, respectively
  imaginaryPart = imaginary;
}

//gets the complex class variables and sets the passed parameters to them.
void complexType::getComplex(double &real, double &imaginary) const{
  real = realPart;//set the passed parameters to the same value as the class variables
  imaginary = imaginaryPart;
}

