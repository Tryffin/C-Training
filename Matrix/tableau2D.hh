#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Tableau2D
{
protected:
  T** table; 
  size_t nbLine;
  size_t nbColumn;

public:
  Tableau2D(std::size_t nbC, std::size_t nbL);
  Tableau2D(const Tableau2D&);
  T operator()(std::size_t C, std::size_t L)const;
  T& operator()(std::size_t C, std::size_t L);
  template<typename U>
  friend std::ostream& operator<<(std::ostream& , const Tableau2D<U> &);
  bool operator== (const Tableau2D<T>& lhs) const;
  Tableau2D<T>& operator=(const Tableau2D<T>& m);
  virtual ~Tableau2D();
};

// constructeur
template<typename T>
Tableau2D<T>::Tableau2D(std::size_t nbC, std::size_t nbL)
{
  nbLine = nbL;
  nbColumn = nbC;
  table = new T*[nbL];
  for(size_t i=0;i<nbL;i++)
    {
      table[i] = new T[nbC];
    }
}

// constructeur par copie
template<typename T>
Tableau2D<T>::Tableau2D(const Tableau2D<T>& t)
{
  nbLine = t.nbLine;
  nbColumn = t.nbColumn;
  table = new T*[nbLine];
  for(size_t i=0;i<nbLine;i++)
    {
      table[i] = new T[nbColumn];
    }
  for(size_t j=0;j<nbLine;j++)
    {
      for(size_t k=0;k<nbColumn;k++)
	{
	  table[j][k] = t.table[j][k];
	}
    }
}

// destructeur
template<typename T>
Tableau2D<T>::~Tableau2D()
{
  for(size_t i=0;i<nbLine;i++)
    {
      delete[] table[i];
    }
  delete[] table;
}

// operateur <<
template<typename T>
std::ostream& operator<<(std::ostream& os , const Tableau2D<T> & t)
{
  for(size_t i=0;i<t.nbLine;i++)
    {
      for(size_t j=0;j<t.nbColumn;j++)
	{
	  cout.width(10);
	  os << t.table[i][j] << " ";
	}
      os << endl;
    }
  return os;
}

// operateur ==
template<typename T>
bool Tableau2D<T>::operator==(const Tableau2D<T>& rhs) const
{
  if(rhs.nbLine != nbLine) return 0;
  if(rhs.nbColumn != nbColumn) return 0;
  for(size_t i=0;i<nbLine;i++)
    {
      for(size_t j=0;j<nbColumn;j++)
	{
	  if(rhs.table[i][j] != table[i][j])
	    {
	      return 0;
	    }
	}
    }
  return 1;
}

// operateur =
template<typename T>
Tableau2D<T>& Tableau2D<T>::operator=(const Tableau2D<T>& m)
{
  size_t nbline,nbcolumn;
  if(m.nbLine<nbLine)
    nbline = m.nbLine;
  else
    nbline = nbLine;
  if(m.nbColumn<nbColumn)
    nbcolumn = m.nbColumn;
  else
    nbcolumn = nbColumn;
  for(size_t i=0;i<nbline;i++)
    {
      for(size_t j=0;j<nbcolumn;j++)
	{
	  table[i][j] = m.table[i][j];
	}
    }
  return *this;
}

// operateur de lecture
template<typename T>
T Tableau2D<T>::operator()(std::size_t C, std::size_t L)const
{
  return table[C][L];
}

// operateur d'ecrire
template<typename T>
T& Tableau2D<T>::operator()(std::size_t C, std::size_t L)
{
  T& t = table[C][L];
  return t;
}
