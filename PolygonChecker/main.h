#pragma once

typedef struct {
	int x;
	int y;
} Point;

void printWelcome();
int printShapeMenu();
int* getTriangleSides(int* triangleSides);
void getrectangleSides(Point* points);
