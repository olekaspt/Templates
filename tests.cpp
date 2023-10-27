
#include "LinkedList.h"
#include <gtest/gtest.h>


	void TestEmpty(IList<int>& list)
	{
			ASSERT_TRUE(list.isEmpty());
			//patrick

			ASSERT_EQ(std::string(""), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);

	}
		TEST(PointerBasedLinkedList,TestEmpy)
		{
			LinkedList<int> linkedList = LinkedList<int>();

			TestEmpty(linkedList);

		}
		
		void Test1Add(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1"), list.toString());
			ASSERT_TRUE(list.getSize() == 1);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList,Test1Add)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			Test1Add(linkedList);
		}

		void Test2Add(IList<int> & list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2"), list.toString());
			ASSERT_TRUE(list.getSize() == 2);
			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}


		TEST(PointerBasedLinkedList,Test2Add)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			Test2Add(linkedList);

		}

		void Test3Add(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), list.toString());
			ASSERT_TRUE(list.getSize() == 3);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}


		TEST(PointerBasedLinkedList,Test3Add)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			Test3Add(linkedList);

		}

		void Test11Add(IList<int>& list, bool isPointerBased)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));
			ASSERT_TRUE(list.add(4));
			ASSERT_TRUE(list.add(5));
			ASSERT_TRUE(list.add(6));
			ASSERT_TRUE(list.add(7));
			ASSERT_TRUE(list.add(8));
			ASSERT_TRUE(list.add(9));
			ASSERT_TRUE(list.add(10));
			if(isPointerBased)
			{
				ASSERT_TRUE(list.add(11));
			}
			else
			{
				ASSERT_FALSE(list.add(11));//Capacity is 11 so won't add
			}

			ASSERT_FALSE(list.isEmpty());

			if(isPointerBased)
			{
				ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10 11"), list.toString());
				ASSERT_TRUE(list.getSize() == 11);
			}
			else
			{
				ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10"), list.toString());//Capacity is 11 so won't add
				ASSERT_TRUE(list.getSize() == 10);
			}

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList, Test11Add)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			Test11Add(linkedList, true);

		}

		void TestRemoveNonExistant(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_FALSE(list.remove(4));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2 3"), list.toString());
			ASSERT_TRUE(list.getSize() == 3);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList, TestRemoveNonExistant)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			TestRemoveNonExistant(linkedList);

		}

		void TestBeginingRemove(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_TRUE(list.remove(1));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("2 3"), list.toString());
			ASSERT_TRUE(list.getSize() == 2);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList, TestBeginingRemove)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			TestBeginingRemove(linkedList);

		}

		void TestMiddleRemove(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_TRUE(list.remove(2));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 3"), list.toString());
			ASSERT_TRUE(list.getSize() == 2);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList, TestMiddleRemove)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			TestMiddleRemove(linkedList);

		}

		void TestEndRemove(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));

			ASSERT_TRUE(list.remove(3));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 2"), list.toString());
			ASSERT_TRUE(list.getSize() == 2);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList, TestEndRemove)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			TestEndRemove(linkedList);

		}

		void TestMultipleRemove(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(1));
			ASSERT_TRUE(list.add(2));
			ASSERT_TRUE(list.add(3));
			ASSERT_TRUE(list.add(4));
			ASSERT_TRUE(list.add(5));
			ASSERT_TRUE(list.add(6));
			ASSERT_TRUE(list.add(7));
			ASSERT_TRUE(list.add(8));
			ASSERT_TRUE(list.add(9));
			ASSERT_TRUE(list.add(10));

			ASSERT_TRUE(list.remove(2));
			ASSERT_TRUE(list.remove(4));
			ASSERT_TRUE(list.remove(6));
			ASSERT_TRUE(list.remove(8));

			ASSERT_FALSE(list.remove(2));
			ASSERT_FALSE(list.remove(4));
			ASSERT_FALSE(list.remove(6));
			ASSERT_FALSE(list.remove(8));

			ASSERT_FALSE(list.isEmpty());

			ASSERT_EQ(std::string("1 3 5 7 9 10"), list.toString());
			ASSERT_TRUE(list.getSize() == 6);

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);
		}

		TEST(PointerBasedLinkedList, TestMultipleRemove)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			TestMultipleRemove(linkedList);

		}


		void TestAddingZero(IList<int>& list)
		{
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));
			ASSERT_TRUE(list.add(0));

			ASSERT_TRUE(list.getSize() == 10);

			ASSERT_EQ(std::string("0 0 0 0 0 0 0 0 0 0"), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
		}

		TEST(PointerBasedLinkedList, TestAddingZero)
		{
			LinkedList<int> linkedList = LinkedList<int>();
			TestAddingZero(linkedList);

		}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
