#include "path.hh"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <time.h>
using namespace std;

Path::Path(int n, size_t hmax, size_t wmax):len(n-1),hmax(hmax),wmax(wmax){
  //std::cerr << "Path(): Not yet Implemented" << std::endl;
  direction=new int[len];
  pos=new int[n][2];
  srand((unsigned)time(NULL)); 
  h=rand()%hmax;    //le minimum(0,0)
  w=rand()%wmax;    //point depart
  pos[0][0]=h;
  pos[0][1]=w;
   for(int i=0;i<len;i++){
    nouveau_dir(i);
    int dir=direction[i];
    majpos(dir,i+1);;
  }
}


void Path::nouveau_dir(int i){
  if(h==0){
    if(w==0){         
      switch(rand()%3){
      case 0: direction[i]=2;break;
      case 1: direction[i]=4;break;
      case 2: direction[i]=8;break;}
    }
    else if(w==wmax-1){  
      switch(rand()%3){
      case 0: direction[i]=3;break;
      case 1: direction[i]=7;break;
      case 2: direction[i]=2;break;}
    }
    else{                 
      switch(rand()%5){
      case 0: direction[i]=2;break;
      case 1: direction[i]=3;break;
      case 2: direction[i]=4;break;
      case 3: direction[i]=7;break;
      case 4: direction[i]=8;break;}
    }
  }
  else if(h==hmax-1){       
    if(w==0){            
      switch(rand()%3){
      case 0: direction[i]=1;break;
      case 1: direction[i]=4;break;
      case 2: direction[i]=6;break;}
      }
    else if(w==wmax-1){  
      switch(rand()%3){
      case 0: direction[i]=1;break;
      case 1: direction[i]=3;break;
      case 2: direction[i]=5;break;}
    }                    
    else{
      switch(rand()%5){
      case 0: direction[i]=1;break;
      case 1: direction[i]=3;break;
      case 2: direction[i]=4;break;
      case 3: direction[i]=5;break;
      case 4: direction[i]=6;break;}
    }
  }
  else{            
    if(w==0){          
    switch(rand()%5){
    case 0: direction[i]=1;break;
    case 1: direction[i]=2;break;
    case 2: direction[i]=4;break;
    case 3: direction[i]=6;break;
    case 4: direction[i]=8;break;}
    }
    else if(w==wmax-1){
    switch(rand()%5){
    case 0: direction[i]=1;break;
    case 1: direction[i]=2;break;
    case 2: direction[i]=3;break;
    case 3: direction[i]=5;break;
    case 4: direction[i]=7;break;}
    }
    else{             
    switch(rand()%8){
    case 0: direction[i]=1;break;
    case 1: direction[i]=2;break;
    case 2: direction[i]=3;break;
    case 3: direction[i]=4;break;
    case 4: direction[i]=5;break;
    case 5: direction[i]=6;break;
    case 6: direction[i]=7;break;
    case 7: direction[i]=8;break;}
    }
  }
}

void Path::majpos(int dir,int i){
  switch(dir){
  case 1: h--;break;
  case 2: h++;break;
  case 3: w--;break;
  case 4: w++;break;
  case 5: h--;w--;break;
  case 6: h--;w++;break;
  case 7: h++;w--;break;
  case 8: h++;w++;break;
  }
  pos[i][0]=h;
  pos[i][1]=w;
}

Path::~Path()
{
  //std::cerr << "~Path(): Not yet Implemented" << std::endl;
  delete[] direction;
  delete[] pos;
}

std::string Path::toString() const
{
  //std::cerr << "toString(): Not yet Implemented" << std::endl;
  return "";
}

void Path::print() const
{
  //std::cerr << "Path::print(): Not yet Implemented" << std::endl;
  cout<<"Le point de depart est:("<<pos[0][0]+1<<","<<pos[0][1]+1<<") ";
  
  int i=0;
  while(i<len){
    switch(direction[i]){
    case 1:cout<<"N";break;
    case 2:cout<<"S";break;
    case 3:cout<<"W";break;
    case 4:cout<<"E";break;
    case 5:cout<<"NW";break;
    case 6:cout<<"NE";break;
    case 7:cout<<"SW";break;
    case 8:cout<<"SE";break;
    }
    if(!(i==len-1))
      cout<<"-";
    i++;
  }
  cout<<endl;
}


