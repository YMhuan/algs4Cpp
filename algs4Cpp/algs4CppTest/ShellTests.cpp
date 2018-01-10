#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\Shell.h"
#include<fstream>
#include<string>
#include<algorithm>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::Shell;
using std::ifstream;
using std::string;
using std::vector;


namespace algs4CppTest
{
	TEST_CLASS(ShellTests)
	{
	public:

		TEST_METHOD(ShellTest1)
		{
			ifstream input("tiny.txt");
			vector<string> svec;
			string s;
			while (input >> s) {
				svec.push_back(s);
			}
			Shell<string>::sort(svec);
			Assert::IsTrue(std::is_sorted(svec.begin(),svec.end()));

		}

	};
}
