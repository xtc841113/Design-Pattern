#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include <iostream>

class NodeBuilder {
public:
  NodeBuilder() {}

  void build(const char * path) {
    struct stat st;
    if (lstat(path, &st) == 0) {
      if (S_ISREG(st.st_mode))
        _root = new File(path);
      else if (S_ISLNK(st.st_mode))
        _root = new Link(path);
      else if (S_ISDIR(st.st_mode)) {
        _root = new Folder(path);
        DIR * dir = opendir(path);
        if (dir == nullptr)
          throw std::string("open folder error");

        struct dirent * entry = nullptr;
        while((entry = readdir(dir)) != nullptr) {
          if (std::string(entry->d_name) != "."
              && std::string(entry->d_name) != "..") {
            NodeBuilder nb;
            //const char * fakePathName = (std::string(path));
            // char * pathName;
            // strcat(pathName,path);
            // strcat(pathName,("/").c_str());
            // strcat(pathName,(entry->d_name).c_str());
            std::string pathName1 = (std::string(path)+ "/" + entry->d_name).c_str();
            const char * pathName = pathName1.c_str();
            std::cout << "right: " << pathName <<std::endl;
            std::cout << path << std::endl;
            nb.build(pathName);
            _root->add(nb.getRoot());
          }
        }
      }
    }
  }

  Node * getRoot() {
    return _root;
  }

private:
  Node * _root;
};

#endif
