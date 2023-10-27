
#include "LinkedListNonTemplate.h"
#include <gtest/gtest.h>


	void TestEmpty(IListNonTemplate& list)
	{
			ASSERT_TRUE(list.isEmpty());
			//patrick

			ASSERT_EQ(std::string(""), list.toString());

			list.clear();
			ASSERT_TRUE(list.isEmpty());
			ASSERT_TRUE(list.getSize() == 0);

	}
		TEST(LinkedListNonTemplate,TestEmpy)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();

			TestEmpty(linkedList);

		}
		
		void Test1Add(IListNonTemplate& list)
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

		TEST(LinkedListNonTemplate,Test1Add)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			Test1Add(linkedList);
		}

		void Test2Add(IListNonTemplate & list)
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

		TEST(LinkedListNonTemplate,Test2Add)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			Test2Add(linkedList);

		}

		void Test3Add(IListNonTemplate& list)
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

		TEST(LinkedListNonTemplate,Test3Add)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			Test3Add(linkedList);

		}

		void Test11Add(IListNonTemplate& list, bool isPointerBased)
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


		TEST(LinkedListNonTemplate, Test11Add)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			Test11Add(linkedList, true);

		}

		void TestRemoveNonExistant(IListNonTemplate& list)
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


		TEST(LinkedListNonTemplate, TestRemoveNonExistant)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			TestRemoveNonExistant(linkedList);

		}

		void TestBeginingRemove(IListNonTemplate& list)
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

		TEST(LinkedListNonTemplate, TestBeginingRemove)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			TestBeginingRemove(linkedList);

		}

		void TestMiddleRemove(IListNonTemplate& list)
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

		TEST(LinkedListNonTemplate, TestMiddleRemove)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			TestMiddleRemove(linkedList);

		}

		void TestEndRemove(IListNonTemplate& list)
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


		TEST(LinkedListNonTemplate, TestEndRemove)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			TestEndRemove(linkedList);

		}

		void TestMultipleRemove(IListNonTemplate& list)
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


		TEST(LinkedListNonTemplate, TestMultipleRemove)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			TestMultipleRemove(linkedList);

		}


		void TestAddingZero(IListNonTemplate& list)
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



		TEST(LinkedListNonTemplate, TestAddingZero)
		{
			LinkedListNonTemplate linkedList = LinkedListNonTemplate();
			TestAddingZero(linkedList);

		}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
