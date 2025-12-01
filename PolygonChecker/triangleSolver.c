#include <stdio.h>
#include <stdbool.h>


#define _USE_MATH_DEFINES
#include <math.h>

#include "triangleSolver.h"

char* analyzeTriangle(double a, double b, double c) {
	char* result = "";
	if (a <= 0 || b <= 0 || c <= 0 || a + b < c || a + c < b || b + c < a) {
		result = "Not a triangle";
	}
	else if (a == b && a == c) {
		result = "Equilateral triangle";
	}
	else if ((a == b && a != c) || 
			 (a == c && a != b) ||
			 (b == c && b != a)) {
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene Triangle";
	}

	return result;
}

void triangleAngles(double a, double b, double c, double angleStore[3]) {

    double A = acos((b * b + c * c - a * a) / (2.0 * b * c)) * (180.0 / M_PI);
    double B = acos((a * a + c * c - b * b) / (2.0 * a * c)) * (180.0 / M_PI);
    double C = acos((a * a + b * b - c * c) / (2.0 * a * b)) * (180.0 / M_PI);

	angleStore[0] = A;
	angleStore[1] = B;
	angleStore[2] = C;

}