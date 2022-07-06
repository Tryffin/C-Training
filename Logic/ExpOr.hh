#include "ExpBin.hh"
#include <string>
#include <sstream>
using namespace std;
class ExpOr:public ExpBin{
public:
  //constructor
  ExpOr(ExpLog&,ExpLog&);

  //destructor
  ~ExpOr();

  string toString() const;
  ThreeVal_t evaluate() const;
  
};
