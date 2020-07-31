#include "find_link_visitor.h"
#include "folder.h"
#include "file.h"
#include "link.h"
#include "node_iterator.h"
#include <sys/stat.h>
#include <vector>
#include <iostream>

static int layer = 0;
FindLinkVisitor::FindLinkVisitor(){}

void FindLinkVisitor::visitFolder(Folder * folder){
  //std::cout<<"進visitor"<<std::endl;
  if(layer == 0)
    _links.clear();

  NodeIterator * it = folder->createIterator();
  struct stat st;
  it->first();
  const char * p = (it->currentItem()->path()).c_str();

  if (lstat(p, &st) == 0){
    if (S_ISLNK(st.st_mode))
      _links.push_back(it->currentItem());
  }

  for(it->first(); !it->isDone(); it->next())
    {
      layer++;
      it->currentItem()->accept(this);
      layer--;
    }
}

void FindLinkVisitor::visitFile(File * file){}
void FindLinkVisitor::visitLink(Link * link){
  _links.push_back(link);
}
