#include "tableau2D.hh"
#include "matrix.hh"
using namespace std;
int main(void)
{
  cout<< "EX1" <<endl;
  Tableau2D<float> tab(10,10);
  tab(2,2) = 42.0;
  cout << tab (2,2) << std::endl ;
  Tableau2D<float> tab2 = tab;
  tab2(1,1) = 1.0;
  if ( tab2 == tab )
    cout << "equal" << endl;
  cout << tab2 << endl;

  cout << "EX2" << endl;
  Matrix<float> a1(5,5,1);
  Matrix<float> a2(5,5,0);
  Matrix<float> a3=a2;
  Matrix<float> a4=(a1+a2+a3)*2;
  a3=a4/2.0;
  cout<<a3<<endl;
  Matrix<float> a5(5, 5, Matrix<float>::identity);
  cout << a5 << endl;


  cout << "transposition de matrice" << endl;
  Matrix<float> a6(3,3,0);
  a6(0,0)=1;
  a6(0,1)=2;
  a6(0,2)=3;
  a6(1,0)=4;
  a6(1,1)=5;
  a6(1,2)=6;
  a6(2,0)=7;
  a6(2,1)=8;
  a6(2,2)=9;
  cout << a6 << endl;
  a6.transposition();
  cout << a6 << endl;

  cout << "les operations de matrice avec reel/matrice" << endl;
  a3=a1*4.0;
  cout<<a3;
  cout<<endl;
  cout<<endl;
  a3=a1+4.0;
  cout<<a3;
  cout<<endl;
  cout<<endl;
  a3=a1-4.0;
  cout<<a3;
  cout<<endl;
  cout<<endl;
  a3=a1/4.0;
  cout<<a3;
  cout<<endl;
  cout<<endl;

  cout << "les operations de matrice avec matrice" << endl;
  a1=a1*3.0;
  a3=a1*a1;
  cout<<a3;
  cout<<endl;
  cout<<endl;
  a3=a1+a3;
  cout<<a3;
  cout<<endl;
  cout<<endl;
  a3=a3-a1;
  cout<<a3;
  cout<<endl;
  cout<<endl;
  return 0;
  
}
