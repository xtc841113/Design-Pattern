#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H
#include <vector>
#include <string>

class Node;
class File;
class Folder;
class Link;

class NodeVisitor
{
public:
  virtual void visitFile(File * file) = 0;
  virtual void visitFolder(Folder * folder) = 0;
  virtual void visitLink(Link * link) = 0;
  virtual std::vector<Node*> getLinks(){};
  virtual int getContentSize(){};
  virtual std::string findResult(){};
};
#endif
