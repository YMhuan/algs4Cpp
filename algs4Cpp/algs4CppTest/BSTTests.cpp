#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\BST.h"
#include<random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::BST;
using std::string;
using std::uniform_int_distribution;
using std::default_random_engine;

namespace algs4CppTest
{
	TEST_CLASS(BSTTests)
	{
	public:

		TEST_METHOD(BSTTest1)
		{
			BST<string, int> st;

			st.put("asd", 355);
			st.put("dsd", 25);
			st.put("esd", 15);
			while (st.size() > 0)
			{
				string k = *st.min();
				st.erase(k);
			}

			string keys[]= { "to", "be", "or", "not", "to", "be", "is", "quest" };
			size_t sz = sizeof(keys) / sizeof(*keys);
			for (size_t i = 0; i < sz; ++i)
				st.put(keys[i], i);
			Assert::IsTrue(!(st.isEmpty()) && (st.size() == 6), L"", LINE_INFO());

			string key = "not";
			Assert::IsTrue(st.contains(key), L"", LINE_INFO());
			st.erase(key);
			Assert::IsFalse(st.contains(key), L"", LINE_INFO());
			Assert::IsNull(st.get(key), L"", LINE_INFO());

			int value = *st.get("is");
			Assert::IsTrue(value == 6, L"", LINE_INFO());
			Assert::IsTrue(*st.select(3) == "quest", L"", LINE_INFO());

			Assert::IsNull(st.get("world"), L"", LINE_INFO());

		}

	};
}
