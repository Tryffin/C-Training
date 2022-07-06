#include "ExpLog.hh"
using namespace std;

ostream& operator<<(ostream &out,ThreeVal_t val) {
  string valstr;

  switch(val){

  case F : 
    valstr="F"; 
    break;
  case U : 
    valstr="U"; 
    break;
  
  case T : 
    valstr="T";
    break;
  }
  return out << valstr <<endl;
}

