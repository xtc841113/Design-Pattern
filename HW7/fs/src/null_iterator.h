#ifndef NODE_ITERATOR_H
#define NODE_ITERATOR_H
#include "node_iterator.h"
class Node;

class NullIterator:public NodeIterator
{
  public:
    NullIterator(Node *file):_file(file){}
    void first(){
      //definition by yourself
    }
    Node* currentItem(){
      return nullptr;
    }
    void next() {
      //definition by yourself
    }
    bool isDone(){
      return true;
    }
  private:
    Node * _file;
};

#endif
