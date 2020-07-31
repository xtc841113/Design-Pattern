#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include "node_iterator.h"
class NodeVisitor;

class Node
{
public:
  Node(const char * path): _path(path),_p(nullptr)
  {
    if(lstat(_path, &_st) != 0)
      throw std::string("error");

  }

  int size() const
  {
    return _st.st_size;
  }

  virtual void accept(NodeVisitor * icv) = 0;

  std::string path()
  {
    return _path;
  }

  virtual std::string name() const
  {
    std::string path = _path;
    std::size_t lastIndexOfSlash = path.find_last_of("/");
    return path.substr(lastIndexOfSlash + 1);
  }

  virtual std::string change() const
  {
    std::string path = _path;
    std::size_t lastIndexOfSlash = path.find_last_of("/");
    path = path.substr(lastIndexOfSlash + 1);
    return path.replace(path.find("."), 1, "_");  
  }

  virtual void add(Node *node)
  {
    throw std::string("unable to add");
  }

  virtual int numberOfChildren() const
  {
    throw std::string("number of children: not applicable");
  }

  virtual NodeIterator* createIterator()
  {
    return nullptr;
  }

  Node * getParent() const{
    return _p;
  }

  void setParent (Node * p){
    _p = p;
  }


  virtual ~ Node()
  {

  }
private:
  const char * _path;
  struct stat _st;
  Node * _p;
};

#endif
