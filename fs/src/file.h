#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "node_visitor.h"
#include <string>
#include <sys/stat.h>

class File: public Node{
public:
  File(const char * path): Node(path){
    struct stat st;
    if (lstat(path, &st) == 0){
      if (!S_ISREG(st.st_mode)){
        throw std::string ("Do not indicate the file path.");
      }
    }
  }

  void accept(NodeVisitor * icv){
    icv->visitFile(this);
  }
};

#endif
