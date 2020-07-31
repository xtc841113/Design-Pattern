#ifndef INFO_CONTENT_VISITOR_H
#define INFO_CONTENT_VISITOR_H
#include "node_visitor.h"

class Node;
class Folder;
class File;
class Link;

class InfoContentVisitor : public NodeVisitor
{
public:
  InfoContentVisitor();

  void visitFile(File * file);
  void visitFolder(Folder * folder);
  void visitLink(Link * link);

  int getContentSize()
  {
    return _size;
  }
  std::string findResult(){}
  std::vector<Node*> getLinks(){}
private:
  int _size;
};

#endif
