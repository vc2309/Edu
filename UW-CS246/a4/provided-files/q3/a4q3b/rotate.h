#ifndef _ROTATE_H_
#define _ROTATE_H_
#include "image.h"
#include "decorator.h"

//Concrete decorator for rotate transformation
class Rotate: public Decorator
{
public:
	Rotate(Image *component, std::string source);
	void render(PPM &ppm) override;
	
};

#endif
