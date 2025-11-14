#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" char* triangleAngles(int side1, int side2, int side3);

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
			int side1 = 1, side2 = 1, side3 = 1;

			char* result = triangleAngles(side1, side2, side3);

			Assert::AreEqual("60, 60, 60", result);
		}
	};

}
