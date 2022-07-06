#include "ExpBin.hh"
#include <string>
#include <sstream>
using namespace std;
class ExpAnd:public ExpBin{
public:
  //constructor
  ExpAnd(ExpLog&a,ExpLog&b);
  //destructor
  ~ExpAnd();
  
  string toString() const;
  ThreeVal_t evaluate() const;
};

