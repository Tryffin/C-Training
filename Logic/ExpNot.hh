#ifndef EXPNOT_HH
#define EXPNOT_HH
#include"Atom.hh"
using namespace std;
class ExpNot: public ExpLog{
public:
  //constructeur 
  ExpNot(ExpLog &operation);
  ExpNot(ExpNot &expnot);
  ~ExpNot();
  ThreeVal_t evaluate()const ;
  string toString() const ;

  private:
  ExpLog &_operation;
};
#endif