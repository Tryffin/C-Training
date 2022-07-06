#include"ExpAnd.hh"
using namespace std;
  //constructor
ExpAnd::ExpAnd(ExpLog&op1,ExpLog&op2):ExpBin(op1,op2){}

  //destructor
ExpAnd::~ExpAnd(){}

string ExpAnd::toString() const{
  string exp = "(";
  exp += op1.toString();
  exp += " AND ";
  exp += op2.toString();
  exp += ")";
  return exp;
}

ThreeVal_t ExpAnd::evaluate() const{
  
  if(op1.evaluate() == T)
    return op2.evaluate();

  else if(op1.evaluate() == F)
    return F;

  else if(op1.evaluate() == U){
    if(op2.evaluate() == F) return F;
    else return U;
  }
   else{
    cout<<"erreur sur valeur de l'operation "<<endl;
    exit(EXIT_FAILURE);}
}



