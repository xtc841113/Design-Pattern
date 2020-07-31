#ifndef UT_FS_H
#define UT_FS_H

#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"
#include "../src/node.h"
#include "../src/node_visitor.h"
#include "../src/info_content_visitor.h"
#include "../src/find_visitor.h"
#include "../src/node_iterator.h"
#include "../src/null_iterator.h"

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

TEST (FileSystemTest, Visitor){
  std::string name = "folder";
  Node * test_data = new Folder("./test_data");
  Node * folder1 = new Folder("./test_data/folder");
  Node * folder1_2 = new Folder("./test_data/folder/folder");
  test_data->add(folder1);
  folder1->add(folder1_2);
  NodeVisitor * vfind = new FindVisitor(name);
  test_data->accept(vfind);
  ASSERT_EQ("./folder\n./folder/folder", vfind->findResult());
}

TEST (FileSystemTest, VisitFile)
{
  std::string name = "a.out";
  Node * a_out = new File("./test_data/folder/a.out");
  NodeIterator * it = a_out->createIterator();
  NodeVisitor * nv = new FindVisitor(name);
  a_out->accept(nv);
  ASSERT_EQ("a.out", it->currentItem()->name());
}

TEST (NameTest, FileName)
{
  std::string name = "a.out";
  Node * a_out = new File("./test_data/folder/a.out");
  NodeIterator * it = a_out->createIterator();
  NodeVisitor * nv = new FindVisitor(name);
  a_out->accept(nv);
  ASSERT_EQ("a.out", nv->findResult());
}

TEST (, FileSearchItsSelf)
{
  std::string nodeName = "a.out";
  Node * a_out = new File("./test_data/folder/a.out");
  NodeVisitor * fv = new FindVisitor(nodeName);
  a_out->accept(fv);
  ASSERT_EQ(nodeName, fv->findResult());
}

TEST (, SearchLastFileInFolder)
{
  std::string nodeName = "a.out";
  Node * test_data = new Folder("./test_data");
  Node * a_out1 = new File("./test_data/a.out");
  Node * folder = new Folder("./test_data/folder");
  Node * a_out2 = new File("./test_data/folder/a.out");
  test_data->add(a_out1);
  test_data->add(folder);
  folder->add(a_out2);
  NodeVisitor *fv = new FindVisitor(nodeName);
  test_data->accept(fv);
  ASSERT_EQ("./a.out\n./folder/a.out", fv->findResult());
}

TEST (, FileSearchNotItsSelf)
{
  std::string nodeName = "b.out";
  Node * a_out = new File("./test_data/folder/a.out");
  NodeVisitor * fv = new FindVisitor(nodeName);
  a_out->accept(fv);
  ASSERT_EQ("", fv->findResult());
}

TEST (, FolderSearchItsSelf)
{
  std::string nodeName = "folder";
  Node * folder = new Folder("./test_data/folder");
  NodeVisitor * fv = new FindVisitor(nodeName);
  folder->accept(fv);
  ASSERT_EQ("",fv->findResult());
}

TEST (, FolderSearchNotItsSelf)
{
  std::string nodeName = "test_data";
  Node * folder = new Folder("./test_data/folder");
  NodeVisitor * fv = new FindVisitor(nodeName);
  folder->accept(fv);
  ASSERT_EQ("",fv->findResult());
}

TEST (, SearchFileInFolder)
{
  std::string nodeName = "a.out";
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  folder->add(a_out);
  NodeVisitor * fv = new FindVisitor(nodeName);
  folder->accept(fv);
  ASSERT_EQ("./a.out", fv->findResult());
}

TEST (, SearchFolderInFolder)
{
  std::string nodeName = "folder";
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  test_data->add(folder);
  NodeVisitor * fv = new FindVisitor(nodeName);
  test_data->accept(fv);
  ASSERT_EQ("./folder",fv->findResult());
}

TEST (, SearchTwoSameFolderInFolder)
{
  std::string nodeName = "folder";
  Node * test_data = new Folder("./test_data");
  Node * folder1 = new Folder("./test_data/folder");
  Node * folder1_2 = new Folder("./test_data/folder/folder");
  test_data->add(folder1);
  folder1->add(folder1_2);
  NodeVisitor * fv = new FindVisitor(nodeName);
  test_data->accept(fv);
  ASSERT_EQ("./folder\n./folder/folder", fv->findResult());
}

TEST (FileSystemTest, VisitFile1)
{
  std::string name = "hello.cpp";
  Node * a_out = new File("./test_data/folder/a.out");
  NodeVisitor * nv = new FindVisitor(name);
  a_out->accept(nv);
  ASSERT_EQ("", nv->findResult());
}

#endif
