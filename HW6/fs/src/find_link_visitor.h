#ifndef FIND_LINK_VISITOR
#define FIND_LINK_VISITOR
#include "node_visitor.h"
#include <string>
#include <vector>

class Node;
class Folder;
class File;
class Link;

class FindLinkVisitor : public NodeVisitor{
public:
  FindLinkVisitor();
  void visitFolder(Folder * folder);
  void visitFile(File * file);
  void visitLink(Link * link);
  std::vector<Node*> getLinks()
  {
    return _links;
  }
  int getContentSize(){}
  std::string findResult(){};
private:
  std::vector<Node*> _links;

};
#endif
