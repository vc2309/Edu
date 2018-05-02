#ifndef _SEPIA_H_
#define _SEPIA_H_
#include "image.h"
#include "decorator.h"

//Concrete implementation for Sepia transformation 
class Sepia: public Decorator
{
public:
	Sepia(Image *component, std::string source);
	void render(PPM &ppm) override;
	
};

#endif
