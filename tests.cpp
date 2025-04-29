#include "doubly_linked_list.h"
#include <gtest/gtest.h>

TEST(DoublyLinkedListTest, BasicOperations) {
    DoublyLinkedList<int> list;
    EXPECT_EQ(list.size(), 0);

    list.append(10);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), 10);

    list.prepend(5);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.get(0), 5);

    list.removeByIndex(0);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), 10);
}

TEST(DoublyLinkedListTest, InsertAndReplace) {
    DoublyLinkedList<std::string> list;
    list.append("world");
    list.prepend("Hello");
    list.insert("beautiful", 1);
    
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list.get(1), "beautiful");
    
    list.replace("wonderful", 1);
    EXPECT_EQ(list.get(1), "wonderful");

    list.remove("wonderful");
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list.get(1), "world");
}

TEST(DoublyLinkedListTest, EdgeCases) {
    DoublyLinkedList<int> list;
    EXPECT_THROW(list.get(0), std::out_of_range);
    
    list.append(1);
    EXPECT_EQ(list.get(0), 1);
    
    EXPECT_FALSE(list.replace(2, 1));
    EXPECT_TRUE(list.replace(2, 0));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
