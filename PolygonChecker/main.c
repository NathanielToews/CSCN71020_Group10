#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			double triangleSides[3] = { 0, 0, 0 };
			double* triangleSidesPtr = getTriangleSides(triangleSides);

			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;

		case 2:
			printf_s("Rectangle selected.\n");
			double rectanglePoint[4][2];
			getrectangleSides(rectanglePoint);
			for (int i = 0; i < 4; i++) {
				printf("Side %d is: [%lf, %lf] ", i + 1, rectanglePoint[i][0], rectanglePoint[i][1]);
			}
			printf("\n");
			double perimater = pointConnect(rectanglePoint);
			break;

		case 0:
			continueProgram = false;
			break;

		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);
	

	return shapeChoice;
}

double* getTriangleSides(double* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%lf", &triangleSides[i]);
	}
	return triangleSides;
}

void getrectangleSides(double points[4][2]) {

	bool recSidesValid = true;
	for (int i = 0; i < 4; i++) {
		while(recSidesValid == true)
		{
			printf_s("Please enter the points you want 1 at a time, in this format(x y):\n");
			if (scanf_s("%lf %lf", &points[i][0], &points[i][1]) == 2) {
				break;
			}

			else {
				printf("Invalid input! Please try again using the format (x y)\n");
				while (getchar() != '\n');
			}
		}
	}
}