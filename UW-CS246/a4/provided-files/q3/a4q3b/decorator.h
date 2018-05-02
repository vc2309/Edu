#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "image.h"

//Abstract class for the Decorator
class Decorator: public Image {
	
 protected:
 	std::string source;
  Image *component;
 public:
  Decorator(Image *component, std::string source);
  virtual ~Decorator();
};

#endif
