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
		
		TEST_METHOD(SolvedSquare) // SOLVED = points in order
		{
			double array[4][2] = { {1,5}, {4,5}, {4,2}, {1,2} };
			double result = pointConnect(array);

			double perimeter = 3 + 3 + 3 + 3;

			Assert::AreEqual(perimeter, result);

		}

		TEST_METHOD(SolvedSqureAngled)
		{
			double array[4][2] = { {5,10}, {10,5}, {5,0}, {0,5} };
			double result = pointConnect(array);

			double perimeter = sqrt(50)*4;

			Assert::AreEqual(perimeter, result);

		}

		TEST_METHOD(SolvedRandomPoints)
		{
			double array[4][2] = { {2,4}, {3,2}, {2,1}, {0.5,0.5} };
			double result = pointConnect(array);

			double perimeter = sqrt(5) + sqrt(2) + sqrt(2.5) + sqrt(14.5);

			Assert::AreEqual(perimeter, result);

		}

		TEST_METHOD(SolvedArrow) // points that shape an arrow when points are connected
		{
			double array[4][2] = { {5,5}, {5,4}, {6,3}, {4,3} };
			double result = pointConnect(array);

			double perimeter = 1 + sqrt(2) + 2 + sqrt(5);

			Assert::AreEqual(perimeter, result);

		}

		TEST_METHOD(SolvedRectangleAngled)
		{
			double array[4][2] = { {4,6}, {6,4}, {2,0}, {0,2} };
			double result = pointConnect(array);

			double perimeter = sqrt(8)*2 + sqrt(32)*2;

			Assert::AreEqual(perimeter, result);

		}

		TEST_METHOD(SolvedRandomNegative)
		{
			double array[4][2] = { {-2,-4}, {-3,-2}, {-2,-1}, {-0.5,-0.5} };
			double result = pointConnect(array);

			double perimeter = sqrt(5) + sqrt(2) + sqrt(2.5) + sqrt(14.5);

			Assert::AreEqual(perimeter, result);

		}

		TEST_METHOD(SolvedSquarePositiveNegative)
		{
			double array[4][2] = { {4,4}, {4,-4}, {-4,-4}, {-4,4} };
			double result = pointConnect(array);

			double perimeter = 8 + 8 + 8 + 8;

			Assert::AreEqual(perimeter, result);

		}
		

	};
}
