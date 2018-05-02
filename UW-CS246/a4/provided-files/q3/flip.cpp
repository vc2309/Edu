// #include "image.h"
// #include "decorator.h"
#include "flip.h"

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
Flip::Flip(Image *component, std::string source): Decorator{component,source} {}

void Flip::render(PPM &ppm){
  //Render call for polymorphic function 
  component->render(ppm);
  
  std::vector<Pixel> newPixel; //Temp vector to copy Pixels
  

  for(auto it=(ppm.getPixels()).begin();it<(ppm.getPixels()).end();it++)
  {
  	Pixel np;
  	np.r = it->r ;
    np.g = it->g;
    np.b = it->b ;

    
    newPixel.push_back(np);
  }
  int w=ppm.getWidth();
  int ctr=w-1;
  int row=0;



  for(auto it=(ppm.getPixels()).begin();it<(ppm.getPixels()).end();it++)
  {
    
  	(*it).r=newPixel[ctr].r;
  	(*it).g=newPixel[ctr].g;
  	(*it).b=newPixel[ctr].b;
  	
  	ctr--;
    if(ctr<row*(w)) //Starting counter from the end of each row
    {
      row++;
      ctr=row*(w) + (w-1);
      
    }
  }
}
