
#include "ExpLog.hh"
#include <string>
#include <sstream>
using namespace std;

class Atom: public ExpLog{
public:
static int _uniqseq;
//constructeur
Atom(int seq);
Atom(ThreeVal_t val=U);
Atom(const Atom &Atom);
ThreeVal_t evaluate()const;
string toString()const;
Atom& operator=(const bool &bol);
Atom& operator=(const ThreeVal_t &val);
Atom& operator=(const Atom &Atom);
bool operator==(ThreeVal_t val)const;
//desctructeur
~Atom();

private:
int _seq;
ThreeVal_t _val;
std::string _nom;
};
