#include "image.h"
#include "decorator.h"

Decorator::Decorator(Image *component, std::string source): component{component}, source{source}{}

Decorator::~Decorator(){ delete component;}
