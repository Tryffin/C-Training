#include "molecu.hh"
#include "reaction.hh"
#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

int main()
{

  cout << "--- Ex1 ---" << endl;
  ifstream infile("molecules.txt");
  ofstream outfile;
  outfile.open("res_normalisation.txt",ios::out);
  list<Molecule> les_molecules;
  string s;
  while( infile >> s)
    {
      les_molecules.push_back(Molecule(s));
    }
  
  for(const auto& iter : les_molecules)
     {
       cout << iter.normalise() << endl;
       outfile << iter.normalise() << endl;;
     }
  infile.close();
  outfile.close();
   
  
  cout << "--- Ex2 ---" << endl;
  infile.open("reactions.txt");
  outfile.open("res_reactions.txt",ios::out);
  list<Reaction> lesReactions;
  while(getline(infile,s))
    {
      if(!s.empty())
	lesReactions.push_back(Reaction(s));
    }
  for(const  auto& iter : lesReactions)
   {
     cout << iter.normalise() << endl;
     outfile << iter.normalise() << endl;
   }

    cout << "--- Bonus ---" << endl;
   for(const auto& i : les_molecules)
     cout << i << " ";                 
   cout << endl;
   
   for(const auto& j : lesReactions)
     cout << j << " " << endl;        
  
  infile.close();
}
