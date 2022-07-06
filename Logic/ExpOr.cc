#include"ExpOr.hh"
using namespace std;
  //constructor
ExpOr::ExpOr(ExpLog &op1,ExpLog&op2):ExpBin(op1,op2){}

  //destructor
ExpOr::~ExpOr(){}

string ExpOr::toString() const{
  string exp = "(";
  exp += op1.toString();
  exp += " OR ";
  exp += op2.toString();
  exp += ")";
  return exp;
}

ThreeVal_t ExpOr::evaluate() const{
  if(op1.evaluate() == T)
    return T;
  else if(op1.evaluate() == F)
    return op2.evaluate();
  else if(op1.evaluate() == U){
    if(op2.evaluate() == T) return T;
    else return U;
  }
  else{
    std::cout<<"erreur sur valeur de l'operation "<<endl;
    exit(EXIT_FAILURE);}
}
