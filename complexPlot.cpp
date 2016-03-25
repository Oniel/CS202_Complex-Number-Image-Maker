//Oniel Toledo   Assignment09   CS202
//The following class implementation file for the complexPlot object is a derivation
//of the bitmapImage class, the complexPlot object also accesses the complexType 
//class for arithmetic operations and object manipulations.
//Depending on what is expected the class can create, using 11 functions a *.bmp image 
//that outputs HSV values in complex expression form.
#include <iostream>
#include <string>
#include <cmath>
#include "bitmapImage.h"
#include "complexType.h"
#include "complexPlot.h"
using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~constructors~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//constructor with no passed parameters, all class and base class varaibles are set to 0
complexPlot::complexPlot(){
  int wdth=0, hght=0;
  bitmapImage::setSize(wdth, hght);//set size to 0,0
  fileName="";//no file name
  funcNumber=0;//no function
}

//constructor for a passed width, height, functionNumber, and fileName
complexPlot::complexPlot(int w, int h, int funcNo, string fName){
  string tempExtension="";//temporary storage for string variables
  int wLength;//store length of fName
  bool goodW = false, goodH = false;
  int wdth = bitmapImage::getWidth();
  int hght = bitmapImage::getHeight();

  //error checking for width, if good set goodW to true
  if(w >= W_MIN && w <= W_MAX)
    goodW= true;
  else
    cout << "Error, width must be between 300 and 12000." << endl;
  //error checking for height, if good set goodH to true
  if(h >= H_MIN && h <= H_MAX)
    goodH=true;
  else
    cout << "Error, height must be between 300 and 12000." << endl;
  if(goodW==true && goodH==true) //if both width and height are good 
    bitmapImage::setSize(w, h);//use the setSize function set the width and height simultaneously
    
  //error checking for aspect ratio
  if(wdth==w && hght==h){
    if((wdth/hght) < 0.5 || (wdth/hght) > 2.0)
      cout << "Error, invalid aspect ratio. Must be between 0.5 and 2.0." << endl;
      }

  //error checking for function number to be performed for the object
  if(funcNo >=0 && funcNo <=11)
    funcNumber = funcNo;
  else
    cout << "Error, function number must be between 0 and 11." << endl;

  //error checking for the passed fileName
  if(fName!="" && fName!=".bmp"){
    wLength = fName.length();//find length of fName
    for(int i=wLength-4; i<wLength; i++)
      tempExtension += fName[i];//read and store the last 4 chars of fName
    if(tempExtension==".bmp"){//compare to ".bmp" if same store fName, else error msg
      setFileName(fName);}
    else
      if(tempExtension!=".bmp")
	cout << "Error, file must be '.bmp' extension." << endl;
  }
  else//either fName is empty or it has an invalid naming convension
    cout << "Error, invalid file name." << endl;
}
//copy constructor, via deep copy the passed parameter object will set the current class object
//with the same complexPlot array
complexPlot::complexPlot(const complexPlot& two){
  //obtain the passed object's width and height
  int W = two.getWidth();
  int H = two.getHeight();
  //set the current clas object's width and height values to the width and height from object 'two'
  bitmapImage::setSize(W, H);
  for(int y=0; y<H;y++)//now deep copy 'two' to the current class object
    for(int x=0; x<W;W++)
      bitmapImage::setPixel(x, y, two.getPixel(x, y));
      //set the pixel in x,y of the current object to the pixel value in 
}

//functions
//function to prompt user for a specified file name of extension .bmp, error checks
//and re-prompt for proper input until valid file name has been entered
void complexPlot::readFileName(){
  string fName, temp="";
  int wLength;
  while(true){//loop until user provides good output file name
    cout << "Enter Output File Name: ";
    cin >> fName;//read and store file name
    wLength = fName.length();//obtain length
    if(wLength < 5)//of fName is less than 5 chars long it is automatically invalid
      cout << "Error, invalid file name." << endl << "Please re-enter." << endl;
    else
      if(wLength >=5){//if length of fName is 5 or greater...
	for(int i=wLength-4; i<wLength;i++)//error check for correct extension
	  temp += fName[i];//store the last 4 chars in fName
	if(temp!=".bmp"){//of the last 4 chars in fName are not ".bmp" error msg
	  cout << "Error, file name must be '.bmp' extension." << endl;
	  cout << "Please re-enter." << endl;
	  temp="";//invalid extension, reset temp to blank
	}
	else
	  if(temp==".bmp"){//valid extension and right size store fileName and break
	    fileName = fName;
	    break;
	  }
      }
  }//end of while
}

//set the passed parameter to the fileName variable, error check for bad fileName
void complexPlot::setFileName(string fName){
  string temp="";//create a temp sting for possible extension comparison
  if(fName!=""){
    int wLength = fName.length();
    if(wLength <= 4)//if the length is less than 5 chars, it is of invalid size 
      cout << "Error, invalid file name." << endl;
    else
      if(wLength > 4){//if the length of fName is 5 chars or greater, might be ok
	for(int i=wLength-4; i <wLength; i++)//check for a valid extension
	  temp += fName[i];
	if(temp!=".bmp")//compare the last 4 chars of fName to ".bmp"
	  cout << "Error, file name must be '.bmp' extension." << endl;
	else
	  if(temp==".bmp")
	    fileName = fName;//parameter is valid, initialize the variable accordingly
      }
  }
  else
    cout << "Error, invalid file name." << endl;//parameter is "", invalid, error msg
}

//return the FileName
string complexPlot::getFileName() const{
  return fileName;}

//prompts user for height and width values to be stored to the base class variables
//will reprompt until appropriate values are recieved
void complexPlot::readImageSize(){
  int wdth, hght;
  double ratio;
  while(true){//loop until break keyword is reached
    cout << "Enter image size (width, height): ";
    cin >> wdth >> hght;
    if(hght==0)
      cout << "Error, height must be between 300 and 12000." << endl << "Please re-enter." << endl;
    else{
      ratio = wdth/hght;//store ratio of width and height
      if(wdth>=W_MIN && wdth<=W_MAX && hght>=H_MIN && hght<=H_MAX && ratio>=0.5 && ratio<=2.0){
	bitmapImage::setSize(wdth, hght);//if valid width and height set them
	break;
      }
      else{//one or more values are invalid, display error msgs accordingly and re-loop
	if(wdth<W_MIN || wdth>W_MAX)
	  cout << "Error, width must be between 300 and 12000." << endl << "Please re-enter." << endl;
	if(hght<H_MIN || hght>H_MAX)
	  cout << "Error, height must be between 300 and 12000." << endl << "Please re-enter." << endl;
	if(ratio<0.5 || ratio>2.0)
	  cout << "Error, aspect ratio. Must be between 0.5 and 2.0." << endl << "Please re-enter." << endl;
      }
    }
  }

}

//sets passed parameters to the base class width and height variables accordingly, also 
//error checks for any invalid parameter values
void complexPlot::setImageSize(int wdth, int hght){
  //if wdth and hght are within range of 300 and 12000 set the variables
  if(wdth>=W_MIN && wdth<=W_MAX && hght>=H_MIN && hght<=H_MAX){
    bitmapImage::setSize(wdth, hght);
  }
  else//if either wdth or hght are invalid display appropriate error messages
    if((wdth<W_MIN) || (wdth>W_MAX) || (hght<H_MIN) || (hght>H_MAX)){
      if(wdth<W_MIN || wdth>W_MAX)//if wdth is invalid, error msg
	cout << "Error, width must be between 300 and 12000." << endl;
      if(hght<H_MIN || hght>H_MAX)//if hght is invalid, error msg
	cout << "Error, height must be between 300 and 12000." << endl;
    }
}

//returns the number of functions available
int complexPlot::functionCount(){
  return FUNC_LIMIT;}

//return function number
int complexPlot::getFunctionNumber(){
  return funcNumber;}

//simple function, error checks passed function number if less than 0 or greater than 11,dsply erorr msg, else store
void complexPlot::setFunctionNumber(int fNo){
  if(fNo>=0 && fNo<=11)
    funcNumber = fNo;//good function number store to class variable
  else
    if(fNo<0 || fNo>11)//bad function, output error msg
      cout << "Error, function number must be 0 and 11." << endl;
}

//prompts a user for a function number, will re-prompt until valid function number
void complexPlot::readFunctionNumber(){
  int fNo;
  while(true){
    cout << "Enter, Function Number (1 - 11): ";
    cin >> fNo;
    if(fNo>=0 && fNo<=11){//if fNo is greater than 0 and it is less than 11 store funcNumber and break
      funcNumber = fNo;
      break;
    }
    else
      if(fNo<0 || fNo>11){
	cout << "Error, function number must be 0 and 11." << endl;
	cout << "Error, function number must between 1 and 11." << endl;
      }
  }//end of while loop
}

//creates the actual image through access to func1()-func11(), the given algorthims
//also play a critical role in the file image output
void complexPlot::createComplexPlotImage(){
  double rmi= -3;
  double rma=  3;
  double imi= -3;
  double ima=  3;
  double im, re, hue, sat, val;
  int red, green, blue;
  complexType cObj;
  complexType vObj;
  int hght = getHeight();
  int wdth = getWidth();
  //for each pixel at x,y of vObject do the following calculations
  for(int y=0; y<hght; y++)
    for(int x=0; x<wdth; x++){
      im = ima - (ima-imi)*y/(hght-1);
      re = rma - (rma-rmi)*x/(wdth-1);
      cObj.setComplex(re, im);//set the complex of object c and v
      vObj.setComplex(re, im);//to the calcuated re and im
      //if statment tree to that redirects to one of the 11 functions
      //depenant on what functionNumber was assigned to the current object
      if(funcNumber==0)
	;
      else
	if(funcNumber==1)
	  vObj = func1(vObj, cObj);
	else
	  if(funcNumber==2)
	    vObj =func2(vObj, cObj);
	  else
	    if(funcNumber==3)
	      vObj = func3(vObj, cObj);
	    else
	      if(funcNumber==4)
		vObj = func4(vObj);
	      else
		if(funcNumber==5)
		  vObj = func5(vObj);
		else
		  if(funcNumber==6)
		    vObj = func6(vObj);
		  else
		    if(funcNumber==7)
		      vObj = func7(vObj);
		    else
		      if(funcNumber==8)
			vObj = func8(vObj);
		      else
			if(funcNumber==9)
			  vObj = func9(vObj);
			else
			  if(funcNumber==10)
			    vObj = func10(vObj);
			  else
			    if(funcNumber==11)
			      vObj = func11(vObj);
      setHSV(vObj, hue, sat, val);//determine the hue, saturation, and brightness values of object z
      setRGB(hue, sat, val, red, green, blue);//pass the HSV values through as well as the RGB vals
      //if(getFunctionNumber() == 7) 
	//cout << getFunctionNumber() << " hue: " << hue << "  sat: " << sat << "  val: " << val << endl;
      bitmapImage::setPixelRGB(x, y, red, green, blue); 
      hue=0;//set values to 0 for next loop
      sat=0;
      val=0;
      red=0;
      green=0;
      blue=0;
      }
}

//creates a bmp file using the base class function 'saveToBitmapFile()'
void complexPlot::createImageFile(){
  bitmapImage::saveToBitmapFile(fileName, 24);//save as file name at 24-bit depth
}

//Complex Calculations Functions
//passes two objects of class complexType
complexType complexPlot::func1(complexType z, complexType c){
  complexType temp;
  temp = z*z+c;
  return temp;
}

//function2
complexType complexPlot::func2(complexType z, complexType c){
  complexType temp;
  temp = func1(z, z) + c;
  return temp;
}

//function3
complexType complexPlot::func3(complexType z, complexType c){
  complexType temp;
  temp = func2(z, z) + c;
  return temp;
}

//function4
complexType complexPlot::func4(complexType z){
  complexType temp;
  temp = z*PI;
  temp.cose();
  return temp;
}

//function5
complexType complexPlot::func5(complexType z){
  complexType temp;
  complexType temp1(1.0, 0.0);//create an object to represent 1
  temp = z*z + temp1;
  return temp;
}

//function6
complexType complexPlot::func6(complexType z){
  complexType temp, tempz;
  complexType temp1(1.0, 0.0);
  tempz = z*z*z-temp1;
  temp = (tempz.sine())/z;
  
  return temp;
}

//function7
complexType complexPlot::func7(complexType z){
  complexType temp, tempz;
  complexType temp1(1.0, 0.0);
  temp = func8(z) + temp1/func8(z);
  temp = func6(temp);
  return temp;
}

//function8
complexType complexPlot::func8(complexType z){
  complexType temp;
  complexType temp1(1.0, 0.0);
  complexType temp2(2.0, 0.0);//complexType object to repesent the number 2
  complexType tempi(0.0, 1.0);//object that repesents i
  temp = ((z*z-temp1)*(z-temp2-tempi)*(z-temp2-tempi));
  temp = temp / (z*z + temp2 + temp2*tempi);
  temp = func9(temp);
  return temp;
}

//function9
complexType complexPlot::func9(complexType z){
  complexType temp;
  complexType temp1(1.0,0.0);
  temp = z + temp1/z;
  return temp;
}

//function10
complexType complexPlot::func10(complexType z){
  complexType temp;
  temp = z.cSqrt();
  return temp;
}

//function11
complexType complexPlot::func11(complexType z){
  complexType temp;
  complexType temp1(1.0 , 0.0);
  temp = (z*z+temp1)/(z*z-temp1);
  return temp;
}

//set image functions
//calculates the hue, saturation, and brightness values for the passed complexType object 'z'
void complexPlot::setHSV(complexType cObject, double& hue, double& sat, double& val){
  double m, k, ranges=0.0, rangee=1.0;
  //below is the algorithm for calculating th hue, saturation, and brightness value for object cObject
  hue = cObject.angle();
  while(hue < 0.0){
    hue += 2.0*PI;}
  hue /= 2.0*PI;
  m = cObject.abs();
  while(m > rangee){
    ranges = rangee;
    rangee *= E;}
  k = (m-ranges)/(rangee-ranges);
  if(k<0.5)
    sat = 2.0*k;
  else{
    sat = 1.0-2.0*(k-0.5);}
  sat = 1.0 - pow((1.0-sat),3);
  sat = 0.4 + (0.6*sat);
  if(k < 0.5)
    val = 2.0*k;
  else{
    val = 1.0-(2.0*(k-0.5));}
  val = 1.0 - val;
  val = 1.0 - pow((1.0-val),3);
  val = 0.6 + (0.4*val);
  //nothing is returned, but the passed parameters hue,sat, and val are returned with the 
  //new calculations
}

//given the passed hue, sat, and val the setRGB function will calcuate and return the calcuated values
//of the red, green, blue variables
void complexPlot::setRGB(double hue, double sat, double val, int& red, int& green, int& blue){
  double R, G, B;
  if(sat==0.0){//if saturation is 0 set to white
    red=255;
    green=255;
    blue=255;
  }
  else{//for all other possibilities do the following
    if(hue==1.0)
      hue=0.0;
    double z = floor(6.0*hue);//perform the following calculations
    double f = 6.0*hue-z;
    double p = val*(1.0-sat);
    double q = val*(1.0-(sat*f));
    double t = val*(1.0-(sat*(1.0-f)));
    //if statements depending on the value of z
    if(z==0){
      R=val;
      G=t;
      B=p;
    }
    else
      if(z==1){
	R=q;
	G=val;
	B=p;
      }
      else
	if(z==2){
	  R=p;
	  G=val;
	  B=t;
	}
	else
	  if(z==3){
	    R=p;
	    G=q;
	    B=val;
	  }
	  else
	    if(z==4){
	      R=t;
	      G=p;
	      B=val;
	    }
	    else
	      if(z==5){
		R=val;
		G=p;
		B=q;
	      }
    //scale RGB values
    R *=256.0;
    G *=256.0;
    B *=256.0;
    //if either RGB are higher than 255, then set it to 255
    if(R>255.0)
      R=255.0;
    if(G>255.0)
      G=255.0;
    if(B>255.0)
      B=255.0;
    //static cast R,G,B back to integers and store in the original passed parameters
    red = static_cast<int>(R);
    green = static_cast<int>(G);
    blue = static_cast<int>(B);
  }  
}



