#ifndef LINK_H
#define LINK_H
#include "node.h"
#include <sys/stat.h>
#include <string>
#include "node_visitor.h"
#include <iostream>

class Link : public Node{
public:
  Link(const char * path, Node * node = nullptr) : Node(path)
  {
    struct stat st;
    if (lstat(path, &st) == 0){
      if (!S_ISLNK(st.st_mode)){
        throw std::string ("Do not indicate the Link path.");
      }
    }
    this->addLink(node);
  }

  void accept(NodeVisitor * icv)
  {
    icv->visitLink(this);
  }

  void addLink(Node * node)
  {
    _source = node;
  }

  Node * getSource() {
    return _source;
  }

private:
  Node * _source;
};

#endif
