#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>

extern "C" char* analyzeTriangle(double a, double b, double c);
extern "C" void triangleAngles(double side1, double side2, double side3, double angleStore[3]);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;




namespace TriangleTestingFile
{

	TEST_CLASS(TriangleAngleTests)
	{
	public:

		TEST_METHOD(Equilateral) // testing when triangle sides are equal
		{
			double angles[3];
			triangleAngles(1, 1, 1, angles);

			Assert::AreEqual(60.0, angles[0], 0.001);
			Assert::AreEqual(60.0, angles[1], 0.001);
			Assert::AreEqual(60.0, angles[2], 0.001);
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