#ifndef MATRIX_HH
#define MATRIX_HH
#include "tableau2D.hh"
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>

class Matrix : public Tableau2D<T>{
public :
  // constructeurs
  Matrix(const size_t& nbC,const size_t& nbL,const int& numIni);
  Matrix(const size_t& nbC,const size_t& nbL,const bool& numIden);
  Matrix(const Matrix& m);

  // operations matrice/reels
  Matrix<T> operator+(const T& t);
  Matrix<T> operator-(const T& t);
  Matrix<T> operator*(const T& t);
  Matrix<T> operator/(const T& t);

  // operations entre matrice
  Matrix<T> operator+(const Matrix<T>& m);
  Matrix<T> operator-(const Matrix<T>& m);
  Matrix<T> operator*(const Matrix<T>& m);

  //transposition
  void transposition();
  static bool identity;
};

// constructeur avec valeur initiale
template <typename T>
Matrix<T>::Matrix(const size_t& nbC,const size_t& nbL,const int& numIni):Tableau2D<T>(nbC,nbL){
  for(size_t i=0;i<nbL;i++)
    {
      for(size_t j=0;j<nbC;j++)
	this->table[i][j] = numIni;
    }
}

// constructeur avec identification
template <typename T>
Matrix<T>::Matrix(const size_t& nbC,const size_t& nbL,const bool& numIden):Tableau2D<T>(nbC,nbL){
  if(numIden)
    {
      for(size_t i=0;i<nbL;i++)
	{
	  for(size_t j=0;j<nbC;j++)
	    {
	      if(i==j)
		this->table[i][j] = 1;
              else
		this->table[i][j] = 0;
	    }
	}
    }
  else
    for(size_t i=0;i<nbL;i++)
    {
      for(size_t j=0;j<nbC;j++)
	this->table[i][j] = 0;
    }
}

// constructeur par copie
template <typename T>
Matrix<T>::Matrix(const Matrix& m):Tableau2D<T>(m){}

// operateur + matrice/reel
template <typename T>
Matrix<T> Matrix<T>::operator+(const T& t){
  Matrix<T> rt = *this;
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<rt.nbColumn;j++)
	rt.table[i][j] += t;
    }
  return rt;
}

// operateur - pour matrice/reel
template <typename T>
Matrix<T> Matrix<T>::operator-(const T& t){
  Matrix<T> rt = *this;
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<rt.nbColumn;j++)
	rt.table[i][j] -= t;
    }
  return rt;
}

// operateur * pour matrice/reel
template <typename T>
Matrix<T> Matrix<T>::operator*(const T& t){
  Matrix<T> rt = *this;
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<rt.nbColumn;j++)
	rt.table[i][j] *= t;
    }
  return rt;
}

// operateur / pour matrice/reel
template <typename T>
Matrix<T> Matrix<T>::operator/(const T& t){
  Matrix<T> rt = *this;
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<rt.nbColumn;j++)
	rt.table[i][j] /= t;
    }
  return rt;
}

// operateur + entre matrice
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m){
  Matrix<T> rt = *this;
  if((rt.nbLine != m.nbLine)||(rt.nbColumn != m.nbColumn))
    {
      cout << "type correspond pas, on peut pas faire addition" << endl;
      exit(0);
    }
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<rt.nbColumn;j++)
	rt.table[i][j] += m.table[i][j];
    }
  return rt;
}

// operateur - entre matrice
template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m){
  Matrix<T> rt = *this;
  if((rt.nbLine != m.nbLine)||(rt.nbColumn != m.nbColumn))
    {
      cout << "type correspond pas, on peut pas faire substraction" << endl;
      exit(0);
    }
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<rt.nbColumn;j++)
	rt.table[i][j] -= m.table[i][j];
    }
  return rt;
}

// operateur * entre matrice
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& m){
  Matrix<T> mt = *this;
  Matrix<T> rt(this->nbLine,m.nbColumn,0);
  
  if(rt.nbColumn != m.nbLine)
    {
      cout << "type correspond pas, on peut pas faire multiplicatioin" << endl;
      exit(0);
    }
  
  for(size_t i=0;i<rt.nbLine;i++)
    {
      for(size_t j=0;j<m.nbColumn;j++)
	{
	  //rt.table[i][j] = 0;
	  for(size_t k=0;k<m.nbLine;k++)
	    {
	      rt.table[i][j] = rt.table[i][j] + mt.table[i][k]*m.table[k][j];
	    }
	  
	}
    }
  return rt;
}

// transposition
template <typename T>
void Matrix<T>::transposition(){
  Matrix<T> rt = *this;
  for(size_t i=0;i<this->nbLine;i++)
    {
      
      for(size_t j=0;j<this->nbColumn;j++)
	this->table[i][j] = rt.table[j][i];
    }
}
template <typename T>
bool Matrix<T>::identity(1);

#endif
