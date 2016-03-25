//Oniel Toledo   Assignment09   CS202
//the following class, complexPlot, calls upon the classes bitmapImage and complexType.
//the bitmapImage class is used to run the image calculations 
//the complexType class performs all the complex calculations
#ifndef COMPLEXPLOT_H
#define COMPLEXPLOT_H
#include <iostream>
#include <string>
#include <cmath>
#include "bitmapImage.h"
#include "complexType.h"
using namespace std;

class complexPlot: public bitmapImage{
 public:
  //constructors
  complexPlot ();
  complexPlot (int,int, int=0, string="");
  complexPlot (const complexPlot&);
  //functions
  void readFileName();
  void setFileName(string);
  string getFileName() const;
  void readImageSize();
  void setImageSize(int, int);
  int functionCount();
  int getFunctionNumber();
  void setFunctionNumber(int);
  void readFunctionNumber();
  void createComplexPlotImage();
  void createImageFile();
 private:
  complexType func1(complexType, complexType);
  complexType func2(complexType, complexType);
  complexType func3(complexType, complexType);
  complexType func4(complexType);
  complexType func5(complexType);
  complexType func6(complexType);
  complexType func7(complexType);
  complexType func8(complexType);
  complexType func9(complexType);
  complexType func10(complexType);
  complexType func11(complexType);
  void setHSV(complexType, double&, double&, double&);
  void setRGB(double, double, double, int&, int&, int&);
  //variables
  string fileName;
  int funcNumber;
  //constants
  static const int W_MIN=300;
  static const int W_MAX=12000;
  static const int H_MIN=300;
  static const int H_MAX=12000;
  static const int FUNC_LIMIT=11;
  static const double PI=3.14159265358;
  static const double E =2.71828182845;
  
};
#endif

