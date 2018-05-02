// #include "image.h"
// #include "decorator.h"
#include "rotate.h"

#include <vector>

#include "exception.h"
#include <iostream>
#include <sstream>
#include <fstream>
using std::ostringstream;
using std::endl;
using std::ifstream;


using namespace std;

//Parameterized constructor
Rotate::Rotate(Image *component, std::string source): Decorator{component,source} {}

void Rotate::render(PPM &ppm){
	//Render call for polymorphic function 
  component->render(ppm);
  std::vector<Pixel> newPixel;
  //Copy the Pixels into temp vector

  for(auto it=(ppm.getPixels()).begin();it<(ppm.getPixels()).end();it++)
  {
  	Pixel np;
  	np.r = it->r ;
    np.g = it->g;
    np.b = it->b ;

    
    newPixel.push_back(np);
  }
  std::vector<Pixel> rotPixel=newPixel;
  
  int r=ppm.getHeight();
  int c=ppm.getWidth();
  
  for(int i=0;i<c;i++){
  
    for(int j=0;j<r;j++)
    {
      
      rotPixel[i*r + j] = newPixel[c* (r - j - 1) + i];
    }
  }
  int ctr=0;
  
  int *wp=&(ppm.getWidth());  
  *wp=r;  //Changing the width of the referenced object
  int *hp=&(ppm.getHeight());
  *hp=c;  //Changing the height of the referenced object
  
  for(auto it=(ppm.getPixels()).begin();it<(ppm.getPixels()).end();it++)
  { 
  	(*it)=rotPixel[ctr];	
  	ctr++;
  
  }
}
