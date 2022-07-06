#include <string>
#include "Atom.hh"
using namespace std;

//Constructeur
Atom::Atom(int seq):_seq(seq){
  _nom = "a_";
  _nom += std::to_string(seq);
}

Atom::Atom(ThreeVal_t val):_val(val){
  _nom = "a_";
  _nom += std::to_string(_uniqseq);
  _uniqseq += 1;
}

Atom::Atom(const Atom &Atom){
  _val = Atom._val;
  _nom = "a_";
  _nom += std::to_string(_uniqseq);
  _uniqseq += 1;
}
//evaluation qui retourne de la valeur de l'Atom
ThreeVal_t Atom::evaluate() const {
  ThreeVal_t val = _val;
  return val;
}

//retourne une chaˆıne de caractere de la forme  (a_1 = val)
string Atom::toString() const {
  string nom="(";
  string val;
  nom += _nom;
  nom += " = ";
  switch(_val){
        case U : 
            val = "U"; 
            break;
 
        case T : 
            val = "T"; 
            break;
        case F : 
            val = "F"; 
            break;
  }
  nom += val;
  nom += ")";
  return nom;
}

Atom& Atom::operator=(const bool &bol){
  switch(bol){
  case false : _val=F;break;
  case true : _val=T;break;
  }
  return *this;
}

Atom& Atom::operator=(const ThreeVal_t &val){
  _val=val;
  return *this;
}


Atom& Atom::operator=(const Atom &Atom){
  _val=Atom._val;
  return *this;
}

bool Atom::operator==(ThreeVal_t val)const{
  if(val==_val) return 1;
  else return 0;
}


//Destructeur
Atom::~Atom() {}
