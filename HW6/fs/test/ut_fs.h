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

TEST_F (FileSystemTest, Size)
{
  ASSERT_EQ(4096,test_data->size());
  ASSERT_EQ(4096, folder->size());
  ASSERT_EQ(83, hello_cpp->size());
  ASSERT_EQ(8432, a_out->size());
  ASSERT_EQ(12, hello->size());
  ASSERT_EQ(8432, dynamic_cast<Link *>(hello)->getSource()->size());
  ASSERT_EQ(3, test_data->numberOfChildren());
}

// TEST_F (FileSystemTest, Visitor)
// {
//   NodeVisitor * icv = new InfoContentVisitor();
//   a_out->accept(icv);
//   ASSERT_EQ(8432, icv->getContentSize());
//   delete icv;
//
//   NodeVisitor * icv10 = new InfoContentVisitor();
//   hello->accept(icv10);
//   ASSERT_EQ(8432,icv10->getContentSize());
//
//   NodeVisitor * icv2 = new InfoContentVisitor();
//   folder->accept(icv2);
//   ASSERT_EQ(8432, icv2->getContentSize());
//
//   NodeVisitor * icv3 = new InfoContentVisitor();
//   test_data->accept(icv3);
//   ASSERT_EQ(16947,icv3->getContentSize());
//
// }
TEST_F (FileSystemTest,NodeIterator){
  std::unique_ptr<NodeIterator> it(test_data->createIterator());
  // NodeIterator * it = test_data->createIterator();
  it->first();
  ASSERT_EQ(4096, it->currentItem()->size());
  it->next();
  ASSERT_EQ(12, it->currentItem()->size());
  it->next();
  ASSERT_EQ(83, it->currentItem()->size());
  it->next();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  ASSERT_ANY_THROW(it->next());

  // delete it;
}

TEST_F (FileSystemTest, Throw) {
  ASSERT_ANY_THROW(new File("./test_data/folder"));
  ASSERT_ANY_THROW(new Folder("./test_data/hello"));
  ASSERT_ANY_THROW(new Link("./test_data/hello.cpp"));
}

TEST_F (FileSystemTest, findLinkInFile) {
  NodeVisitor * icv99 = new FindLinkVisitor();
  a_out->accept(icv99);
  ASSERT_EQ(0, (icv99->getLinks()).size());
}

TEST_F (FileSystemTest, findLinkInLink) {
  NodeVisitor * icv999 = new FindLinkVisitor();
  hello->accept(icv999);
  ASSERT_EQ(1, (icv999->getLinks()).size());
}

TEST_F (FileSystemTest, findLinkInFolder) {
  NodeVisitor * icv9999 = new FindLinkVisitor();
  test_data->accept(icv9999);
  ASSERT_EQ(1, (icv9999->getLinks()).size());
}

// TEST_F (FileSystemTest, buildddd){
//   NodeBuilder nb;
//   nb.build("makefile");
//   ASSERT_EQ(872, nb.getRoot()->size());
// }

TEST_F (FileSystemTest, NodeBuilderOnFile) {
  NodeBuilder nb;
  // nb.build("test_data/hello.cpp");
  // ASSERT_EQ(83, nb.getRoot()->size());
  //
  // nb.build("test_data/hello");
  // ASSERT_EQ(12, nb.getRoot()->size());

  nb.build("test_data/folder");
  ASSERT_EQ(4096, nb.getRoot()->size());

  // std::unique_ptr<NodeIterator> it(nb.getRoot()->createIterator());
  // it->first();
  // ASSERT_EQ(8432, it->currentItem()->size());

  // it->next();
  // ASSERT_TRUE(it->isDone());
  //
  // nb.build("test_data");
  // ASSERT_EQ(160, nb.getRoot()->size());
  // std::unique_ptr<NodeIterator> it1(nb.getRoot()->createIterator());
  // it1->first();
  // ASSERT_EQ(96, it1->currentItem()->size());
  // it1->next();
  // ASSERT_EQ(12, it1->currentItem()->size());
  // it1->next();
  // ASSERT_EQ(83, it1->currentItem()->size());
  // it1->next();
  // ASSERT_TRUE(it1->isDone());
}

#endif
