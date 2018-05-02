// #include "image.h"
// #include "decorator.h"
#include "sepia.h"

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
Sepia::Sepia(Image *component, std::string source): Decorator{component,source} {}

void Sepia::render(PPM &ppm){
	//Render call for polymorphic function
	component->render(ppm);
  
  std::vector<Pixel> newPixel;
  for(auto it=(ppm.getPixels()).begin();it<(ppm.getPixels()).end();it++)
  {
  	Pixel np;
  	np.r = it->r *.393 + it->g * .769 + it->b * .189;
    np.g = it->r *.349 + it->g * .686 + it->b * .168;
    np.b = it->r *.272 + it->g * .534 + it->b * .131;

    np.r=np.r>255 ? 255 : np.r;	
    np.g=np.g>255 ? 255 : np.g;
    np.b=np.b>255 ? 255 : np.b;
    newPixel.push_back(np);
  }
  int ctr=0;
  for(auto it=(ppm.getPixels()).begin();it<(ppm.getPixels()).end();it++)
  {
  	(*it).r=newPixel[ctr].r;
  	(*it).g=newPixel[ctr].g;
  	(*it).b=newPixel[ctr].b;
  	
  	ctr++;
  }
}
