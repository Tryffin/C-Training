#ifndef REACTION_HH
#define REACTION_HH
#include "molecu.hh"
using namespace std;
class Reaction{
public:
  Reaction(string s);
  string normalise()const;
private:
  vector<Molecule> _reactif;
  vector<Molecule> _produit;
};
ostream& operator<<(ostream &out,Reaction r);
#endif
