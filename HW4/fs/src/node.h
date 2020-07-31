#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include "string"
#include "algorithm"

class Node{
public:
  Node(const char * path): _path(path){
    lstat(_path, &_st);
  }

  int size() const{
    return _st.st_size;
  }

  virtual int infoContent() const{
    return size();
  }

  virtual void add(Node *node){
    throw std::string("unable to add");
  }

  virtual int numberOfChildren() const{
    throw std::string("number of children: not applicable");
  }

  virtual std::string name() const{
    std::string p = _path;
    std::size_t found = p.find_last_of("/");
    return p.substr(found+1,p.length());
  }

  virtual std::string find(std::string nodeName){
  }

  virtual std::string getPath(){
    return _path;
  }

private:
  const char * _path;
  struct stat _st;
};

#endif
