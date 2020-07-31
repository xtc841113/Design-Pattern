#ifndef FOLDER_H
#define FOLDER_H

#include <map>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <iostream>
#include "node.h"
#include "node_visitor.h"
#include "node_iterator.h"

class Folder:public Node{
public:
  class FolderIterator : public NodeIterator
  {
  public:
    FolderIterator(Folder * f): _folder(f)
    {

    }
    void first()
    {
      _it = _folder->_children.begin();
    }
    Node* currentItem()
    {
      if (isDone())
      {
        throw std::string("no current item");
      }
      return _it->second;
    }
    void next()
    {
      if (isDone())
      {
        throw std::string("moving past the end");
      }
      _it++;
    }
    bool isDone()
    {
      return _it == _folder->_children.end();
    }
  private:
    Folder * _folder;
    std::map<std::string, Node*>::iterator _it;
  };

  Folder(const char* path):Node(path){
    struct stat st;
    if (lstat(path, &st) == 0){
      if (!S_ISDIR(st.st_mode)){
        throw std::string ("Do not indicate the Folder path.");
      }
    }

  }

  void add(Node *node)
  {
    _children.insert(std::pair<std::string, Node *>(node->name(), node));
    node->setParent(this);
  }

  int numberOfChildren() const
  {
    return _children.size();
  }

  void accept(NodeVisitor * icv)
  {
    //std::cout <<"進accept()"<<std::endl;
    icv->visitFolder(this);
  }

  NodeIterator * createIterator()
  {
    return new FolderIterator(this);
  }

private:
  std::map<std::string, Node *> _children;
};

#endif
