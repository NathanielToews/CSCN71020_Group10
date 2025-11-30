#include <stdio.h>
#include "rectangleSolver.h"

#define _USE_MATH_DEFINES
#include <math.h>


double pointConnect(double array[4][2]) {

	// array[point #][x or y]
	// array[0][1] = point 1y

	// sides length solve
	double s1, s2, s3, s4;
	s1 = sqrt(pow(array[0][0] - array[1][0], 2) + pow(array[0][1] - array[1][1], 2));
	s2 = sqrt(pow(array[1][0] - array[2][0], 2) + pow(array[1][1] - array[2][1], 2));
	s3 = sqrt(pow(array[2][0] - array[3][0], 2) + pow(array[2][1] - array[3][1], 2));
	s4 = sqrt(pow(array[3][0] - array[0][0], 2) + pow(array[3][1] - array[0][1], 2));

	// perimeter solve
	double perimeter = s1 + s2 + s3 + s4;

	// checks if a rectangle
	// uses cos law to find the angle between sides
	double angle1 = (acos((s1 * s1 + s4 * s4 - pow(sqrt(pow(array[1][0] - array[3][0], 2) + pow(array[1][1] - array[3][1], 2)), 2)) / (2 * s1 * s4)))*(180/M_PI); // between side 1 and 4
	double angle2 = (acos((s1 * s1 + s2 * s2 - pow(sqrt(pow(array[0][0] - array[2][0], 2) + pow(array[0][1] - array[2][1], 2)), 2)) / (2 * s1 * s2)))*(180/M_PI); // between side 1 and 2
	double angle3 = (acos((s3 * s3 + s2 * s2 - pow(sqrt(pow(array[3][0] - array[1][0], 2) + pow(array[3][1] - array[1][1], 2)), 2)) / (2 * s3 * s2)))*(180/M_PI); // between side 3 and 2
	double angle4 = (acos((s3 * s3 + s4 * s4 - pow(sqrt(pow(array[2][0] - array[0][0], 2) + pow(array[2][1] - array[0][1], 2)), 2)) / (2 * s1 * s4)))*(180/M_PI); // between side 3 and 4
	
	
	// checks that all angles are equal to 90 degrees (this has tollernce to make sure that if a double is slightly off it will still work)	
	if (fabs(angle1 - 90) < 1e-6 && fabs(angle2 - 90) < 1e-6 && fabs(angle3 - 90) < 1e-6 && fabs(angle4 - 90) < 1e-6) {
		int area = s1 * s2;
		printf("This is a rectangle and the area is %d", area);
	}
	printf("The perimeter is %lf", perimeter);

	return perimeter;
}