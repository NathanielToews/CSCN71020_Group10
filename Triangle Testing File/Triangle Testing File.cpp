#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(double a, double b, double c);
extern "C" char* triangleAngles(double side1, double side2, double side3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace TriangleTestingFile
{
	TEST_CLASS(TriangleTestingFile)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

		}
	};

	TEST_CLASS(TriangleAngleTests)
	{
	public:

		TEST_METHOD(Equilateral) // testing when triangle sides are equal
		{
			double side1 = 1,  side2 = 1,  side3 = 1;

			char* result = triangleAngles(side1, side2, side3);

			Assert::AreEqual("60, 60, 60", result);
		}
	};


	TEST_CLASS(TriangleSidePass)
	{
	public:

		TEST_METHOD(EqualSides)
		{
			double a = 60, b = 60, c = 60;

			char* result = analyzeTriangle(a, b, c);

			Assert::AreEqual("Equilateral triangle", result);

		}

		TEST_METHOD(TwoEqualSides)
		{
			double a = 30, b = 60, c = 60;

			char* result = analyzeTriangle(a, b, c);

			Assert::AreEqual("Isosceles triangle", result);

		}

		TEST_METHOD(DifferentSides)
		{
			double a = 30, b = 40, c = 60;

			char* result = analyzeTriangle(a, b, c);

			Assert::AreEqual("Scalene Triangle", result);

		}

	};



}