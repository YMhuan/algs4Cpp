#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\Queue.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::Queue;
using std::string;

namespace algs4CppTest
{
	TEST_CLASS(QueueTests)
	{
	public:

		TEST_METHOD(QueueTest1)
		{
			Queue<string> queue;
			Assert::IsTrue(queue.isEmpty() == true, L"", LINE_INFO());
			Assert::IsTrue(queue.size() == 0, L"", LINE_INFO());

			queue.enqueue("Kevin Wayne");
			queue.enqueue("Robert Sedgewick");
			queue.enqueue("Einsten");
			Assert::IsTrue(queue.size() == 3, L"", LINE_INFO());

			string item = queue.dequeue();
			Assert::IsTrue(queue.size() == 2, L"", LINE_INFO());
			Assert::IsTrue(item== "Kevin Wayne", L"", LINE_INFO());
		}

	};
}
