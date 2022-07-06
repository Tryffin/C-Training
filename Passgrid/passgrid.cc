#include "passgrid.hh"
#include <iostream>
#include <ctime>
#include <string>
#include <chrono>
#include <stdlib.h> 
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

// obtain a seed from the system clock:
std::default_random_engine PassGrid::_generator(std::chrono::system_clock::now().time_since_epoch().count());
std::uniform_int_distribution<int> PassGrid::_distribution(33,94);


PassGrid::PassGrid(const PassGrid & p)
{
  //std::cerr << "PassGrid(const PassGrid & p): Not yet Implemented" << std::endl;
  _w= p.getH() ;
  _h =p.getW() ;
  grid = new char*[p.getH()];
  for(size_t i=0; i<p.getH() ;i++){
      grid[i]= new char[p.getW()];
  }
  for(size_t i=0; i<p.getH() ;i++ ){
      for(size_t j=0;j<p.getW();j++){
      
          grid[i][j]=p(i,j);
      }
    }
}

PassGrid::PassGrid(std::size_t w, std::size_t h)
{
  //std::cerr << "PassGrid(size_t w, size_t h): Not yet Implemented" << std::endl;
  _w= w;
  _h= h;
  grid = new char*[_h];
  for(size_t i=0; i<_h ;i++){
      grid[i]= new char[_w];
  }
  reset();
}

PassGrid::~PassGrid()
{
  //std::cerr << "~PassGrid(): Not yet Implemented" << std::endl;
  delete[] grid;
} 


void PassGrid::save(std::ostream& out) const
{
  //std::cerr << "save: Not yet Implemented" << std::endl;

  for(size_t i=0; i<getH() ;i++ ){
      for(size_t j=0;j<getW();j++){

          out<<grid[i][j];

     } 
  }
}

void PassGrid::print() const
{
  //std::cerr << "Not yet Implemented" << std::endl;

  save(std::cout);
  
}


void PassGrid::load(std::istream& in)
{
  //std::cerr << "load: Not yet Implemented" << std::endl;
  for(size_t i=0; i<getH() ;i++ ){
      for(size_t j=0;j<getW();j++){

          in>>grid[i][j];

     } 
  }
}

void PassGrid::reset()
{
  //std::cerr << "reset(): Not yet Implemented" << std::endl;
  
  for(size_t i=0; i<getH() ;i++ ){
      for(size_t j=0;j<getW();j++){

          grid[i][j]=rand() %61 +33;
      
     } 
  }
} 


char *PassGrid::generate(const Path& p)const
{
  //std::cerr << "generate: Not yet Implemented" << std::endl;return "";
  char*pass=new char[p.len+1];

  for(int i=0;i<p.len+1;i++){
     pass[i]=(char)grid[p.pos[i][0]][p.pos[i][1]]; 
  }
   return pass;
}
