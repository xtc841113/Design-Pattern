#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "string"
#include "algorithm"



class File: public Node{
public:
  File(const char * path): Node(path){

  }
  //
  // std::string name(){
  //
  // }

  std::string find(std::string nodeName){
    std::string p = name();
    //std::cout << name() << std::endl;
    std::size_t found = p.find(nodeName,0);
    if (found!=std::string::npos)
      return nodeName;
    else
      return "";
  }
};

#endif
