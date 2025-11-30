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
		
		TEST_METHOD(SolvedSquare)
		{
			double array[4][2] = { {1,5}, {4,5}, {4,2}, {1,2} };
			double result = pointConnect(array);

			double perimeter = 3 + 3 + 3 + 3;

			Assert::AreEqual(perimeter, result);

		}


	};
}
