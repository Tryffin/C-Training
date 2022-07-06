
#include<iostream>
#include<string>

using namespace std;

enum ThreeVal_t {F,U,T};

class ExpLog{
public:
  virtual string toString() const  = 0;
  virtual ThreeVal_t evaluate()const = 0;
  virtual bool operator==(ThreeVal_t val)const =0;
};

ostream& operator<<(ostream &out,ThreeVal_t val);
