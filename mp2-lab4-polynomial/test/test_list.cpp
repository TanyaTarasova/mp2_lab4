#include "List.h"

#include <gtest.h>

TEST(Node, can_create_node)
{
	ASSERT_NO_THROW(Node<int> n(2));
}

TEST(Node, can_copy_node)
{
	Node<double> n1(1);
	ASSERT_NO_THROW(Node<double> n2(n1));
}

TEST(Node, node_store_correct_data_after_copy)
{
	Node<int> n1(0);
	Node<int> n2(n1);
	EXPECT_EQ(n1.data, n2.data);
}

TEST(List, can_create_empty_list)
{
	ASSERT_NO_THROW(List<int> l1());
}

TEST(List, can_copy_list)
{
	List<int> l1;
	ASSERT_NO_THROW(List<int> l2(l1));
	List<int> l2(l1);
	EXPECT_EQ(l1.getBegin(), l2.getBegin());
}

TEST(List, list_store_correct_data_after_copy)
{
	List<int> l1;
	l1.push_back(5);
	List<int> l2(l1);
	EXPECT_EQ(l1.getSize(), l2.getSize());
	EXPECT_NE(l1.getBegin(), l2.getBegin());
}

TEST(List, list_can_push_back)
{
	List<int> l1;
	l1.push_back(5);
	EXPECT_EQ(1, l1.getSize());
	EXPECT_EQ(5, l1.getElement(0));
}

TEST(List, list_can_pop_back)
{
	List<int> l1;
	l1.push_back(5);
	ASSERT_NO_THROW(l1.pop_back());
	ASSERT_ANY_THROW(l1.pop_back());
}

TEST(List, list_can_pop_front)
{
	List<int> l1;
	l1.push_back(5);
	l1.push_back(3);
	ASSERT_NO_THROW(l1.pop_front());
	EXPECT_EQ(1, l1.getSize());
	EXPECT_EQ(3, l1.getElement(0));
	ASSERT_NO_THROW(l1.pop_front());
	ASSERT_ANY_THROW(l1.pop_front());
}

TEST(List, list_have_correct_size)
{
	List<int> l1;
	l1.push_back(5);
	EXPECT_EQ(1, l1.getSize());
	l1.push_back(3);
	EXPECT_EQ(2, l1.getSize());
	ASSERT_NO_THROW(l1.pop_back());
	EXPECT_EQ(1, l1.getSize());
}

TEST(List, list_can_return_element)
{
	List<int> l1;
	l1.push_back(5);
	l1.push_back(2);
	EXPECT_EQ(5, l1.getElement(0));
	EXPECT_EQ(2, l1.getElement(1));
}

TEST(List, list_can_change_element)
{
	List<int> l1;
	l1.push_back(5);
	l1.push_back(2);
	l1.push_back(4);
	ASSERT_NO_THROW(l1.changeElement(1,3));
	EXPECT_EQ(5, l1.getElement(0));
	EXPECT_EQ(3, l1.getElement(1));
	EXPECT_EQ(4, l1.getElement(2));
	EXPECT_EQ(3, l1.getSize());
}

TEST(List, list_can_equal_itself)
{
	List<int> l1;
	l1.push_back(5);
	ASSERT_NO_THROW(l1 = l1);
	EXPECT_EQ(1, l1.getSize());
	EXPECT_EQ(5, l1.getElement(0));
}

TEST(List, list_can_equal_list_from_two_elements)
{
	List<int> l1;
	l1.push_back(5);
	l1.push_back(3);
	List<int> l2;
	ASSERT_NO_THROW(l2 = l1);
	EXPECT_EQ(2, l2.getSize());
	EXPECT_EQ(5, l2.getElement(0));
	EXPECT_EQ(3, l2.getElement(1));
}

TEST(List, list_can_equal_list_from_one_element)
{
	List<int> l1;
	l1.push_back(5);
	List<int> l2;
	ASSERT_NO_THROW(l2 = l1);
	EXPECT_EQ(1, l2.getSize());
	EXPECT_EQ(5, l2.getElement(0));
}

TEST(List, list_can_equal_empty_list)
{
	List<int> l1;
	List<int> l2;
	ASSERT_NO_THROW(l2 = l1);
	EXPECT_EQ(0, l2.getSize());
	ASSERT_ANY_THROW(l2.getElement(0));
}