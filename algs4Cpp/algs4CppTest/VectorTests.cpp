#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algs4Cpp\Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algs4Cpp::Vector;
using std::initializer_list;
using std::sqrt;

namespace algs4CppTest
{
	TEST_CLASS(VectorTests)
	{
	private:
		double sumOfSquare(initializer_list<double> lst)
		{
			double sum = 0;
			for (double x : lst)
			{
				sum += x*x;
			}
			return sum;
		}

	public:

		TEST_METHOD(VectorTest1)
		{
			Vector x({ 1.0,2.0,3.0,4.0 });
			Vector y({ 5.0,2.0,4.0,1.0 });

			Vector z = x + y;
			Assert::IsTrue(z==Vector({ 6.0,4.0,7.0,5.0 }));

			z = x - y;
			Assert::IsTrue(z == Vector({ -4.0,0.0,-1.0,3.0 }));

			z = x.scale(2);
			Assert::IsTrue(z == Vector({ 2.0,4.0,6.0,8.0 }));
			
			Assert::IsTrue(x.dot(y) == (5.0+4.0+12.0+4.0));

			Assert::IsTrue(x.magnitude() == sqrt(sumOfSquare({ 1.0,2.0,3.0,4.0 })));
			Assert::IsTrue(x.direction() == x.scale(1 / x.magnitude()));
			Assert::IsTrue(x.distanceTo(y) == sqrt(sumOfSquare({ -4.0,0.0,-1.0,3.0 })));
		}

	};
}
