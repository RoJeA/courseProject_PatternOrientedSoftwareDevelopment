#ifndef UT_FILE_H
#define UT_FILE_H

#include <sys/stat.h>
#include "../src/file.h"
#include "../src/folder.h"
#include "../src/utilities.h"

class NodeTest : public ::testing::Test{
protected:
  void SetUp() {
    hw = new Folder("test/test_folder/hw");
    a_out = new File("test/test_folder/hw/a.out");
    hw1_cpp = new File("test/test_folder/hw/hw1.cpp");
    hello_txt= new File("test/test_folder/hello.txt");
    test_folder= new Folder("test/test_folder");
    hw->addChild(a_out);
    hw->addChild(hw1_cpp);
    test_folder->addChild(hello_txt);
    test_folder->addChild(hw);
  }
  void TearDown() {
    delete hw;
    delete a_out;
    delete hw1_cpp;
    delete hello_txt;
    delete test_folder;
  }
  Folder* hw;
  Node* a_out;
  Node* hw1_cpp;
  File* hello_txt;
  Node* test_folder;
};

// TEST(StatApi, GetSize) {
//   struct stat st;
//   ASSERT_EQ(0, stat("test/test_folder/hello.txt", &st));
//   int size = st.st_size;
//   ASSERT_EQ(14, size);
// }
//
// TEST_F(NodeTest, First) {
//   ASSERT_EQ(14, hello_txt->size());
// }
//
// TEST_F(NodeTest, Second) {
//   Iterator * it= test_folder->createIterator();
//   ASSERT_EQ(128, test_folder->size());
//   it->first();
//   ASSERT_EQ(14, it->currentItem()->size());
//   it->next();
//   ASSERT_EQ(128, it->currentItem()->size());
// }

TEST_F(NodeTest, AddException){
  ASSERT_ANY_THROW(hello_txt->addChild(test_folder));
}

TEST_F(NodeTest, CatchException){
  try{
    hello_txt->addChild(test_folder);
    ASSERT_EQ(true, false);
  } catch(std::string s){
    ASSERT_EQ("Invalid add!", s);
  }
}

TEST_F(NodeTest, InfoByteFunctionOnFile){
  //ASSERT_EQ(14, infoByte(hello_txt));
}

TEST_F(NodeTest, InfoByteFunctionOnFolder){
  //ASSERT_EQ(19027, infoByte(hw));
}

TEST_F(NodeTest, IteratorFromFolder) {
  Iterator * it = hw->createIterator();
  it->first(); // Initialize
  ASSERT_EQ(a_out, it->currentItem());
  it->next();
  ASSERT_EQ(hw1_cpp, it->currentItem());
  it->next();
  ASSERT_TRUE(it->isDone());
}

TEST_F(NodeTest, IteratorFromFile){
  Iterator* it= hello_txt->createIterator();
  ASSERT_TRUE(it->isDone());
}

// ///MyGTest
// TEST(NodeTest, ExistanceInfoNode){
//   try{
//     Node* a_out = new File("test/test_folder/hw/aw.out");
//     ASSERT_EQ(true, false);
//   } catch(std::string s){
//     ASSERT_EQ("Node is not exist!", s);
//   }
//   try{
//     Node* a_out = new Folder("test/test_folder/hww");
//     ASSERT_EQ(true, false);
//   } catch(std::string s){
//     ASSERT_EQ("Node is not exist!", s);
//   }
// }

// TEST(FileTest,WrongTypeFile){
//   try{
//     Node* hw = new File("test/test_folder/hw");
//     ASSERT_EQ(true, false);
//   } catch(std::string s){
//     ASSERT_EQ("It is not File!", s);
//   }
// }

// TEST(FolderTest, WrongTypeFolder){
//   try{
//    Node* a_out = new Folder("test/test_folder/hw/a.out");
//     ASSERT_EQ(true, false);
//   } catch(std::string s){
//     ASSERT_EQ("It is not Folder!", s);
//   }
// }
// TEST(NodeTest, NameInfoNode){
//   Node* a_out = new File("test/test_folder/hw/a.out");
//   ASSERT_EQ("a.out", a_out->name());

//   Node* hw = new Folder("test/test_folder/hw");
//   ASSERT_EQ("hw", hw->name());
// }
// TEST(NodeTest, FindNode){
//    Node* hw = new Folder("test/test_folder/hw");
//    Node* a_out = new File("test/test_folder/hw/a.out");
//    Node* hw1_cpp = new File("test/test_folder/hw/hw1.cpp");
//    Node* TA_folder = new Folder("test/test_folder/hw/TA_folder");
//    Node* TA_folder_a_out = new File("test/test_folder/hw/TA_folder/a.out");
//    ASSERT_EQ("a.out", a_out->findNode("a.out"));
//    hw->addChild(a_out);
//    hw->addChild(hw1_cpp);
//    hw->addChild(TA_folder);
//    TA_folder->addChild(TA_folder_a_out);
//    ASSERT_EQ("./hw1.cpp", hw->findNode("hw1.cpp"));
//    ASSERT_EQ("./a.out\n./TA_folder/a.out", hw->findNode("a.out"));
// }
// TEST(NodeTest, ListNode){
//   try{
//    Node* a_out = new File("test/test_folder/hw/a.out");
//    a_out->listNode();
//    ASSERT_EQ(true, false);
//   } catch(std::string s){
//     ASSERT_EQ("Not a directory", s);
//   }

//   Node* hw = new Folder("test/test_folder/hw");
//   Node* a_out = new File("test/test_folder/hw/a.out");
//   Node* hw1_cpp = new File("test/test_folder/hw/hw1.cpp");
//   hw->addChild(a_out);
//   hw->addChild(hw1_cpp);
//   ASSERT_EQ("a.out hw1.cpp", hw->listNode());
// }

#endif
