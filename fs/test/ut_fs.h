#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/info_content_visitor.h"
#include "../src/find_link_visitor.h"
#include "../src/node_iterator.h"
#include "../src/link.h"
#include "../src/node_builder.h"
#include "../src/find_node_by_pathname_visitor.h"
#include <vector>
#include <memory>

TEST (MiscTest, lstatOnFolder)
{
  const char * path = "./test_data";
  struct stat st;
  ASSERT_EQ(0, lstat(path, &st));
  ASSERT_EQ(4096, st.st_size);
  ASSERT_EQ(true, S_ISDIR(st.st_mode));
  ASSERT_EQ(false, S_ISREG(st.st_mode));
  ASSERT_EQ(false, S_ISLNK(st.st_mode));
}

class FileSystemTest: public ::testing::Test
{
protected:
  void SetUp() override
  {
    test_data = new Folder ("./test_data");
    folder = new Folder("./test_data/folder");
    hello_cpp = new File("./test_data/hello.cpp");
    a_out = new File("./test_data/folder/a.out");
    hello = new Link("./test_data/hello", a_out);
    folder->add(a_out);
    test_data->add(folder);
    test_data->add(hello);
    test_data->add(hello_cpp);
  }

  void TearDown() override
  {
    delete a_out;
    delete hello_cpp;
    delete hello;
    delete folder;
    delete test_data;
  }

  Node * test_data;
  Node * folder;
  Node * hello_cpp;
  Node * a_out;
  Node * hello;

};

TEST (FindNodeByPathnameVisitor, Link){
      Node * hello = new Link("./test_data/hello");
      std::vector<std::string>* names = new std::vector<std::string>{std::string("hello")};
      FindNodeByPathnameVisitor * fv = new FindNodeByPathnameVisitor(names);
      hello->accept(fv);
      ASSERT_EQ(hello, fv->getNode());
}

TEST (FindNodeByPathnameVisitor, LinkInFolder){
      Node * test_data = new Folder ("./test_data");
      Node * hello = new Link("./test_data/hello");
      test_data->add(hello);
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("hello")};
      FindNodeByPathnameVisitor * fv = new FindNodeByPathnameVisitor(names);
      test_data->accept(fv);
      ASSERT_EQ(hello, fv->getNode());
}

TEST (FindNodeByPathnameVisitor, nonExistingFileInFileSystem){
      Node * test_data = new Folder ("./test_data");
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"), std::string("helloWorld")};
      FindNodeByPathnameVisitor * fv = new FindNodeByPathnameVisitor(names);
      test_data->accept(fv);
      ASSERT_EQ(nullptr, fv->getNode());
}

TEST (FindNodeByPathnameVisitor, FileSystemTest){
      Node * test_data = new Folder ("./test_data");
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data")};
      FindNodeByPathnameVisitor * fv = new FindNodeByPathnameVisitor(names);
      test_data->accept(fv);
      ASSERT_EQ(test_data, fv->getNode());
}

TEST (FindNodeByPathnameVisitor, folderInFolder){
      Node * test_data = new Folder ("./test_data");
      Node * folder = new Folder ("./test_data/folder");
      test_data->add(folder);
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"),std::string("folder")};
      FindNodeByPathnameVisitor * fv = new FindNodeByPathnameVisitor(names);
      test_data->accept(fv);
      ASSERT_EQ(folder, fv->getNode());
}

TEST (FindNodeByPathnameVisitor, Nest){
      Node * test_data = new Folder ("./test_data");
      Node * folder = new Folder ("./test_data/folder");
      Node * a_out = new File ("./test_data/folder/a.out");
      test_data->add(folder);
      folder->add(a_out);
      std::vector<std::string>* names = new std::vector<std::string>{std::string("test_data"),std::string("folder"),std::string("a.out")};
      FindNodeByPathnameVisitor * fv = new FindNodeByPathnameVisitor(names);
      test_data->accept(fv);
      ASSERT_EQ(a_out, fv->getNode());
}




#endif
