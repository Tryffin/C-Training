#ifndef MOLECU_HH
#define MOLECU_HH
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "separer.hh"
using namespace std;

class Molecule{
public:
  Molecule(string s);
  string normalise() const;
private:
  string atoms;
  vector<string> atom;
};

ostream& operator<<(ostream& out,Molecule m);
#endif


