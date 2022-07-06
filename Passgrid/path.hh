#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

typedef enum  Direction {N, NE, NW , S, SE, SW, E,W}  Direction;
// A Path is build with a size and 2 Bounds
class Path{
 public:
  Path(int n, size_t hmax, size_t wmax);
  ~Path();
  std::size_t getSize() const { std::cerr << "Path::getSize(): Not yet Implemented" << std::endl;
return 1;}
  std::size_t getStartX()const{ std::cerr << "Path::getStartX(): Not yet Implemented" << std::endl;
return 1;}
  std::size_t getStartY()const{ std::cerr << "Path::getStartY(): Not yet Implemented" << std::endl;
return 1;}
  std::string toString() const;
  void print()const;
  Direction  operator()(size_t i) const{std::cout << "Path::operator(): Not yet Implemented" << std::endl; return N;}
  int (*pos)[2]=NULL;
  int len;
  int hmax,wmax,h,w;
  int *direction=NULL;
  void nouveau_dir(int i);
  void majpos(int dir,int i);
  
 private:
  std::size_t size;
  Direction * path; 
  std::size_t start_x;
  std::size_t start_y;
  
};

