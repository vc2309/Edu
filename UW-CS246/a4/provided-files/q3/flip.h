#ifndef _FLIP_H_
#define _FLIP_H_
#include "image.h"
#include "decorator.h"

//Concrete decorator Flip
class Flip: public Decorator
{
public:
	Flip(Image *component, std::string source);
	void render(PPM &ppm) override;
	
};

#endif
