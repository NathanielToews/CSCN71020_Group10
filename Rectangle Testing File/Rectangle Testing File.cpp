#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

extern "C" double pointConnect(double array[4][2]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTestingFile
{
	TEST_CLASS(RectangleConnectTest)
	{
	public:
		
		TEST_METHOD(Test)
		{
			double array[4][2] = { {1,2}, {4,2}, {1,5}, {7,3} };
			double result = pointConnect(array);

			double perimeter = 3 + 3 + sqrt(10) + sqrt(40);

			Assert::AreEqual(perimeter, result);

		}
	};
}
