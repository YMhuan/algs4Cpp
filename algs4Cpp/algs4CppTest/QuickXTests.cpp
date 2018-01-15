#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\QuickX.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::QuickX;
using std::vector;
using std::string;

namespace algs4CppTest
{
	TEST_CLASS(QuickXTests)
	{
	public:

		TEST_METHOD(QuickXTest1)
		{
			vector<string> a{ "aba" };
			string s = "aba";
			QuickX<string>::sort(a);
			Assert::IsTrue(s == a[0], L"", LINE_INFO());

			a = vector<string>{ "zoo","able","after","cury","aba","bed","bug","boy","bing"," " };
			

			QuickX<string>::sort(a);
			Assert::IsTrue(a[1] == "aba", L"", LINE_INFO());

		}

	};
}
