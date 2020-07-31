#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "node_visitor.h"
#include "null_iterator.h"

class File: public Node{
public:
  File(const char * path): Node(path)
  {

  }

  void accept(NodeVisitor * nv)
  {
    nv->visitFile(this);
  }

  NodeIterator* createIterator()
  {
    return new NullIterator(this);
  }
};

#endif
