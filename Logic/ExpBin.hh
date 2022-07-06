
#include "ExpNot.hh"
class ExpBin:public ExpLog{
public:
  //constructor
  ExpBin(ExpLog &a,ExpLog &b);
  //destructor
  virtual ~ExpBin();
  
  virtual string toString() const  = 0;
  virtual ThreeVal_t evaluate()const = 0;
protected:
  ExpLog &op1;
  ExpLog &op2;
};
