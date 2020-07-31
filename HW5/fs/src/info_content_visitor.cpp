#include "info_content_visitor.h"
#include "file.h"
#include "folder.h"
#include "node_iterator.h"

InfoContentVisitor::InfoContentVisitor(): _size(0)
{
}

void InfoContentVisitor::visitFile(File * file)
{
  _size += file->size();
}

void InfoContentVisitor::visitFolder(Folder * folder)
{
  NodeIterator * it = folder->createIterator();
  for (it->first(); !it->isDone(); it->next())
  {
    it->currentItem()->accept(this);
  }
}
