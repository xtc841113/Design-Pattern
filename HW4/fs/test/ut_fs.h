#ifndef UT_FS_H
#define UT_FS_H

#include "iostream"
#include <sys/stat.h>
#include "../src/folder.h"
#include "../src/file.h"


TEST (FileSystemTest, FileSearchItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ("a.out",a_out->find("a.out"));
}
TEST (FileSystemTest, FileSearchNotItsSelf)
{
  Node * a_out = new File("./test_data/folder/a.out");
  ASSERT_EQ("",a_out->find("b.out"));
}
TEST (FileSystemTest, FolderSearchItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ("",folder->find("folder"));
}
TEST (FileSystemTest, FolderSearchNotItsSelf)
{
  Node * folder = new Folder("./test_data/folder");
  ASSERT_EQ("",folder->find("test_data"));
}

TEST (FileSystemTest, SearchFileInFolder)
{
  Node * folder = new Folder("./test_data/folder");
  Node * a_out = new File("./test_data/folder/a.out");
  folder->add(a_out);
  ASSERT_EQ("./a.out",folder->find("a.out"));
}

TEST (FileSystemTest, SearchFolderInFolder)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  test_data->add(folder);
  ASSERT_EQ("./folder",test_data->find("folder"));
}

TEST (FileSystemTest, 78la)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder2");
  Node * folder3 = new Folder("./test_data/folder2/folder");
  Node * data_out = new File("./test_data/data.out");
  Node * data2_out = new File("./test_data/folder/data2.out");
  test_data->add(folder);
  test_data->add(folder2);
  test_data->add(data_out);
  folder2->add(data2_out);
  folder2->add(folder3);
  ASSERT_EQ("./folder\n./folder2/folder",test_data->find("folder"));
}

TEST (FileSystemTest, 78lala)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder2");
  Node * folder3 = new Folder("./test_data/folder/folder");
  test_data->add(folder);
  test_data->add(folder2);
  folder->add(folder3);
  ASSERT_EQ("./folder\n./folder/folder",test_data->find("folder"));
}

TEST (FileSystemTest, 78lalala)
{
  Node * test_data = new Folder ("./test_data");
  Node * folder = new Folder("./test_data/folder");
  Node * folder2 = new Folder("./test_data/folder2");
  Node * folder2_1 = new Folder("./test_data/folder2/folder");
  Node * data_out = new File("./test_data/a.out");
  Node * data2_out = new File("./test_data/folder/a.out");
  test_data->add(folder);
  test_data->add(folder2);
  test_data->add(data_out);
  folder2->add(folder2_1);
  folder->add(data2_out);
  ASSERT_EQ("./folder/a.out\n./a.out",test_data->find("a.out"));
}



#endif
