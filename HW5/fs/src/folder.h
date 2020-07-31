#include <map>
#include <string>
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

  Folder(const char* path):Node(path)
  {

  }

  void add(Node *node)
  {
    _children.insert(std::pair<std::string, Node *>(node->name(), node));
  }

  int numberOfChildren() const
  {
    return _children.size();
  }

  void accept(NodeVisitor * nv)
  {
    nv->visitFolder(this);
  }

  NodeIterator * createIterator()
  {
    return new FolderIterator(this);
  }

private:
  std::map<std::string, Node *> _children;
};
