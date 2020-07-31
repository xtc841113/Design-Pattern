#ifndef FIND_NODE_BY_PATHNAME_VISITOR_H
#define FIND_NODE_BY_PATHNAME_VISITOR_H
#include <string>
#include <vector>
#include "node_visitor.h"
class Folder;
class File;
class Link;
class Node;

class FindNodeByPathnameVisitor : public NodeVisitor{
  public:
      FindNodeByPathnameVisitor(std::vector<std::string>* pathnames);
      void visitFolder(Folder * folder);
      void visitFile(File * file);
      void visitLink(Link * link);
      Node * getNode() const{
        return _output;
      }

  private:
    Node * _output;
    std::vector<std::string>* _pathnames;
};

#endif
