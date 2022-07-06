#include "molecu.hh"
using namespace std;

Molecule::Molecule(string s):atoms(s){
  atom = separer(s,"-=");
}

string Molecule::normalise()const{
  map<string,int> mapatom;
  stringstream sortie;
  //compter le nb d'atome
  for(const auto& it1 : atom)
    mapatom[it1]++;
  //ecrit le molecule sous forme normale
  for(const auto& it2 : mapatom)
    {
      if(it2.second==1){
          sortie << it2.first;
      }
	  
      else{
          sortie << it2.first << it2.second;
      }
	  
    }
  return sortie.str();
}


ostream& operator<<(ostream& out,Molecule m){
  return out << m.normalise();
}
