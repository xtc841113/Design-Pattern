#include "find_visitor.h"
#include "file.h"
#include "folder.h"
#include "node_iterator.h"

static int layer = 0;

FindVisitor::FindVisitor(std::string name):_output(""), _name(name){}

void FindVisitor::visitFile(File *file)
{
    if(layer == 0)
    {
      _output.clear();
    }
    NodeIterator * it = file->createIterator();
    std::string path = it->currentItem()->path();
    if(it->currentItem()->name() == _name)
    {
        if(layer == 0)
        {
            _output = _name;
        }
        else
        {
            _output += path + "\n";
        }
    }
}

void FindVisitor::visitFolder(Folder *folder)
{
    NodeIterator * it = folder->createIterator();
    std::string path = folder->path();
    std::string replace = ".";
    if(layer == 0)
    {
      _output.clear();
    }
    if(folder->name() == _name && layer != 0)
    {
      _output += path + "\n";
    }
    for(it->first(); !it->isDone(); it->next())
    {
      layer++;
      it->currentItem()->accept(this);
      layer--;
    }
    if(layer == 0)
    {
      std::size_t pos = _output.find(path);
      while(pos != std::string::npos)
      {
        _output.replace(pos, path.length(), ".");
        pos = _output.find(path);
      }
      _output = _output.substr(0, _output.length() - 1);
    }
}
