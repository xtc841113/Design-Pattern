#ifndef FIND_VISITOR_H
#define FIND_VISITOR_H
#include <string>
#include "node_visitor.h"
class Folder;
class File;

class FindVisitor:public NodeVisitor{
public:
  FindVisitor(std::string name);
  void visitFolder(Folder *folder);
  void visitFile(File *file);
  std::string findResult(){
    return _output;
  }
  int getContentSize(){}
  

private:
  std::string _name;
  std::string _output;
};

#endif
