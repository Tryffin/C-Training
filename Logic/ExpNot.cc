#include "ExpNot.hh"
using namespace std;

//constructeur
ExpNot::ExpNot(ExpLog &operation):_operation(operation){}
ExpNot::ExpNot(ExpNot &expnot):_operation(expnot) {}
//destrcuteur
ExpNot::~ExpNot() {}

ThreeVal_t ExpNot::evaluate() const {
  ThreeVal_t val = _operation.evaluate();
  ThreeVal_t tmpval;
  switch(val){
      case U: 
      tmpval=U; 
      break;
    
      case F: 
      tmpval=T;
      break;
  
      case T : 
      tmpval=F; 
      break;
  }
  return tmpval;
}

string ExpNot::toString() const {
  string exp = "NOT";
  exp += _operation.toString();
  return exp;
}