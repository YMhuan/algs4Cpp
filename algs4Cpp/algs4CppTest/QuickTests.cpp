#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\Quick.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::Quick;
using std::vector;
using std::string;
using std::exception;

namespace algs4CppTest
{
	TEST_CLASS(QuickTests)
	{
	public:

		TEST_METHOD(QuickTest1)
		{
			vector<string> a{ "aba" };
			string s= Quick<string>::select(a,0);

			Quick<string>::sort(a);
			Assert::IsTrue(s == a[0], L"", LINE_INFO());

			a = vector<string>{ "zoo","able","after","cury","aba","bed","bug","boy","bing"," " };
			s = Quick<string>::select(a, a.size() - 1);
			Assert::IsTrue(s=="zoo", L"", LINE_INFO());

			Quick<string>::sort(a);
			Assert::IsTrue(a[1] == "aba", L"", LINE_INFO());



			auto funcPtr = [&]() {Quick<string>::select(a, a.size()); };
			Assert::ExpectException<std::invalid_argument>(funcPtr, L"", LINE_INFO());

		}

	};
}
