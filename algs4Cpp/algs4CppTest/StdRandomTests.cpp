#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\StdRandom.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::StdRandom;

namespace algs4CppTest
{
	TEST_CLASS(StdRandomTests)
	{
	public:

		TEST_METHOD(StdRandomTest1)
		{
			for (int i = 0; i != 1024; ++i) {
				int x = StdRandom::uniform(1);
				Assert::IsTrue(x == 0, L"", LINE_INFO());
			}


			for (int i = 0,a=-1024,b=1024; i!=100; ++i) {
				int y = StdRandom::uniform(a, b);
				Assert::IsTrue(y>=a && y<b,L"", LINE_INFO());
			}

			double a = -1024.0, b = 1024.0;
			for (int i = 0; i != 100; ++i) {
				double y = StdRandom::uniform(a, b);
				Assert::IsTrue(y >= a && y<b,L"",LINE_INFO());
			}

		}

	};
}
