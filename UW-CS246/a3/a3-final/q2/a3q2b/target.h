#ifndef _TARGET_H_
#define _TARGET_H_
#include <iostream>
#include <string>

const int maxDepends = 10;

struct Target 
{  // You may add fields and methods as you see fit
  std::ostream &out;  // Stream where Target will print its output
  std::string name;
  static int globalTime;  // used to keep track of when touched
  int time;
  Target* targetDepends [maxDepends];
  int size;

  Target(const std::string &name, std::ostream &out = std::cout);
  bool isLeaf() const;
  void addDepend(Target *d);
  void update(int time);
  int lastUpdated() const;
    int recursiveDepends(int last_time, Target* target);
  void build();
};

#endif
