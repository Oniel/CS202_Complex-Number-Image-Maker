//  CS 202 - Provided Main
//	This main uses the complexType and mandelbrot types.

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#include "complexType.h"
#include "complexPlot.h"

using namespace std;


// ****************************************************

int main()
{
  
// ---------------------------------------------------
//  Some quick tests for the complex type.

	complexType	num1(23.0, 34.0);
	complexType	num2, num3;
	
	num2 = num2 + complexType(3.0, 4.0);
	num3 = num3 + complexType(26.0, 38.0);

	cout << endl << "--------------------------------------------" << endl;
	cout << "Part 1: Complex Number Tests." << endl;
	cout << "          num1 = " << num1 << endl;
	cout << "          num2 = " << num2 << endl;
	cout << "          num3 = " << num3 << endl;
	cout << "     num1+num2 = " << (num1+num2) << endl;
	cout << "     num1-num2 = " << (num1-num2) << endl;
	cout << "     num1*num2 = " << (num1*num2) << endl;
	cout << "     num1/num2 = " << (num1/num2) << endl;
	cout << "   angle(num1) = " << num1.angle() << endl;
	cout << "     abs(num1) = " << num1.abs() << endl;
	cout << "    sine(num1) = " << num1.sine() << endl;
	cout << "    cose(num1) = " << num1.cose() << endl;
	cout << "   cSqrt(num1) = " << num1.cSqrt() << endl;

	if ( num1 == num2 ) {
		cout << "          num1 = num2" << endl;
	} else {
		cout << "          num1 != num2" << endl;
	}
	if ( num2 == num2 ) {
		cout << "          num2 = num2" << endl;
	} else {
		cout << "          num2 != num2" << endl;
	}
	cout << endl;
		
// ---------------------------------------------------
//  Simple, initial tests
//	Note, first image is the one on the assignment handout

	cout << endl << "--------------------------------------------" << endl;
	cout << "Part 2: Complex Plot Image Creation." << endl << endl;

	complexPlot	cmplxImageA(300, 300, 0, "cplxF0.bmp");
	cmplxImageA.createComplexPlotImage();
	cmplxImageA.createImageFile();

	complexPlot	cmplxImageB(500, 500, 11, "cplxF11.bmp");
	cmplxImageB.createComplexPlotImage();
	cmplxImageB.createImageFile();
	
// ---------------------------------------------------
//  Test copy constructor.
//	image 'cplxF0.bmp' should be same as 'cplxF0copy.bmp'

	complexPlot	cmplxImageC(cmplxImageA);

	cmplxImageC.setFileName("cplxF0copy.mpb");			// error
	cmplxImageC.setFileName("cplxF0copy.bmp");

// ---------------------------------------------------
//  Error testing (all errors)

	cout << endl << "--------------------------------------------" << endl;
	cout << endl << "Constructor Error Testing (size): " << endl;
	complexPlot	cmplxImageErr1(300, 3, 0, "cplxErr.bmp");
	complexPlot	cmplxImageErr2(3, 300, 0, "cplxErr.bmp");
	complexPlot	cmplxImageErr3(-300, 300, 0, "cplxErr.bmp");
	complexPlot	cmplxImageErr4(300, -300, 0, "cplxErr.bmp");
	complexPlot	cmplxImageErr5(300, 15000, 15, "cplxErr.bmp");
	complexPlot	cmplxImageErr6(15000, 300, 10, "cplxErr.bmp");

	cout << endl << "Constructor Error Testing (file name): " << endl;
	complexPlot	cmplxImageErr7a(300, 300, 0, "cplxErr.bpm");
	complexPlot	cmplxImageErr7b(300, 300, 0, ".bmp");
	complexPlot	cmplxImageErr7c(300, 300, 0, "");		// valid

	complexPlot	cmplxImageErr9;					// valid

	cout << endl << "setImageSize() Error Testing: " << endl;
	cmplxImageErr9.setImageSize(300, 3);
	cmplxImageErr9.setImageSize(3, 300);
	cmplxImageErr9.setImageSize(-300, 300);
	cmplxImageErr9.setImageSize(300, -300);
	cmplxImageErr9.setImageSize(300, 15000);
	cmplxImageErr9.setImageSize(15000, 300);

	cout << endl << "setImageSize() Aspect Ratio Error Testing: " << endl;
	cmplxImageErr9.setImageSize(12000, 300);
	cmplxImageErr9.setImageSize(300, 12000);

	cout << endl << "setFileName() Error Testing: " << endl;
	cmplxImageErr9.setFileName("cplxErr.bpm");
	cmplxImageErr9.setFileName(".bmp");
	cmplxImageErr9.setFileName("");

	cout << endl << "setFunctionNumber() Error Testing: " << endl;
	cmplxImageErr9.setFunctionNumber(-3);
	cmplxImageErr9.setFunctionNumber(300);
	cmplxImageErr9.setFunctionNumber(30);
	cmplxImageErr9.setFunctionNumber(cmplxImageErr9.functionCount()+1);
	
// ---------------------------------------------------
//  Generate image for each function

	complexPlot	cmplxImageTst;
	string	fName = "complex";
	string	fNum;
	int	fCount;
	ostringstream	tmp;

	fCount = cmplxImageTst.functionCount();
	//testing removed when done
	tmp.clear();
	tmp.str("");
	tmp<<7;
	fNum = tmp.str();
	fName = "tst" + fNum + ".bmp";
	cmplxImageTst.setImageSize(800, 800);
	cmplxImageTst.setFileName(fName);
	cmplxImageTst.setFunctionNumber(7);
	cmplxImageTst.createComplexPlotImage();
	cmplxImageTst.createImageFile();


		for (int i=0; i<=fCount; i++) {
		tmp.clear();
		tmp.str("");
		tmp << i;
		fNum = tmp.str();
		fName = "tst" + fNum + ".bmp";
		cmplxImageTst.setImageSize(800, 800);
		cmplxImageTst.setFileName(fName);
		cmplxImageTst.setFunctionNumber(i);
		cmplxImageTst.createComplexPlotImage();
		cmplxImageTst.createImageFile();
	
		}
	
// ---------------------------------------------------
//  Read image information from user.

	complexPlot	cmplxImageU;

	cout << endl;
	cout << "------------------------------------------" << endl;
	cout << "Enter Image Information:" << endl;
	cmplxImageU.readFunctionNumber();
	cmplxImageU.readImageSize();
	cmplxImageU.readFileName();
	cmplxImageU.createComplexPlotImage();
	cmplxImageU.createImageFile();
	cout << endl;
	
// ---------------------------------------------------

	return 0;
}

