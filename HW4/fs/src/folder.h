#include "node.h"
#include "string"
#include "algorithm"
#include "iostream"

static std::string output;
static int layer = 0;
class Folder:public Node{
public:
  Folder(const char* path):Node(path){

  }

  void add(Node *node){
    _children.push_back(node);
  }

  int infoContent() const{
    int sum = 0;
    for (int i = 0; i < _children.size(); i++){
      sum += _children[i]->infoContent();
    }
    return sum;
  }

  int numberOfChildren() const{
    return _children.size();
  }

  std::string find(std::string nodeName){
    if(layer == 0){
        output.clear();
    }

    if (_children.size() == 0)
      output+="";
    else{
      //std::cout << "number of children: " << _children.size() << std::endl;
      for (int j = 0; j < _children.size(); j++){
        if (nodeName == _children[j]->name()){
          output += getPath()+"/"+nodeName+"\n";
        }
          //std::cout <<  "There are " << _children[j]->numberOfChildren() <<  " childs in " << _children[j]->name() << std::endl;
          layer++;
          _children[j]->find(nodeName);
          layer--;
      }

    }
    if (layer == 0){
      size_t pos = output.find(getPath());
      while(pos != std::string::npos){
        output.replace(pos,getPath().length(),".");
        pos = output.find(getPath());
      }
      int l = output.length();
      output = output.substr(0,l-1);

    }
    return output;

  }
private:
  std::vector<Node *> _children;
};
