#include "reaction.hh"
using namespace std;

Reaction::Reaction(string s){
  vector<string> reaction;//identifier ">" la reaction
  vector<string> reactif;//identifier les reactifs
  vector<string> produit;//identifier les produits
  reaction = separer(s,">"); 
  reactif = separer(reaction[0],"+ ");
  produit = separer(reaction[1],"+ ");
  for(const auto &i : reactif)
    _reactif.push_back(Molecule(i));
  for(const auto &j : produit)
    _produit.push_back(Molecule(j));
}

string Reaction::normalise() const{
  stringstream outport;
  int flag = 0;
  map<string,int> reactif,produit;
  //compter le nombre de la molecule
  for(const auto &it : _reactif)
    reactif[it.normalise()]++;
  for(const auto &it : _produit)
    produit[it.normalise()]++;

  for(auto it = reactif.begin();it != reactif.end();it++){//equation en gauche
    if(flag == 0)
      flag = 1;
    else
      outport << " + ";
    if(it->second == 1)
      outport << it->first;
    else
      outport << it->second <<" " << it->first;
  }

  flag = 0;
  outport << "  >  ";
  
  for(auto it = produit.begin();it != produit.end();it++){//equation en droite
    if(flag == 0)
      flag = 1;
    else
      outport << " + ";
    if(it->second == 1)
      outport << it->first;
    else
      outport << it->second << " " << it->first;
  }
  
  return outport.str();
}

ostream& operator<<(ostream &out,Reaction r){
  return out << r.normalise();
}
