#include "find_node_by_pathname_visitor.h"
#include "find_visitor.h"
#include "folder.h"
#include "file.h"
#include "link.h"
#include "node_iterator.h"
#include <vector>
#include <string.h>
#include <cstdio>
#include <sys/stat.h>

static int layer =0;


FindNodeByPathnameVisitor::FindNodeByPathnameVisitor(std::vector<std::string>* pathnames):_pathnames(pathnames),_output(nullptr){}

void FindNodeByPathnameVisitor::visitFile(File *file)
{
  int len = _pathnames->size();
  if(len == 0)
    return;
  if((*_pathnames)[0] == file->name() && len == 1)
    _output = file;
  else if((*_pathnames)[len-1] == file->name() && layer == len-1)
    _output = file;
}

void FindNodeByPathnameVisitor::visitLink(Link *link)
{
  int len = _pathnames->size();
  if(len == 0)
    return;
  if((*_pathnames)[0] == link->name() && len == 1)
    _output = link;
  else if((*_pathnames)[len-1] == link->name() && layer == len-1)
    _output = link;
}

void FindNodeByPathnameVisitor::visitFolder(Folder *folder)
{
  int len = _pathnames->size();
  if(len == 0)
    return;
  if(layer == 0)
    _output = nullptr;
  if((*_pathnames)[0] == folder->name() && len == 1)
    _output = folder;
  else if((*_pathnames)[len-1] == folder->name()&& layer == len-1)
    _output = folder;

  NodeIterator * it = folder->createIterator();
  for(it->first(); !it->isDone(); it->next())
  {
    layer++;
    it->currentItem()->accept(this);
    layer--;
  }
}
