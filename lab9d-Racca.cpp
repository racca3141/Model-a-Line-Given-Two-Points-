// Emerson Racca
// 11/04/2021
// Lab 9d - Model a Line (Given Two Points)

/*
Redesign the line class where two points can determine a line.
That is, this model will store two points only.
All information about the line can be calculated from these two points.

1. Code a method that calculates and returns the slope.
2. Code a method that nicely outputs the lines in the form y = mx + b.
3. Code a method that evaluates for any x-value.

In the main, declare two Point objects and use them to instantiate ONE Line object called myLine.
Show that your methods work with NO user interface.
*/

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Point {
	double x, y;

	Point(double xArg = 0, double yArg = 0);
};

struct Line {
	Point p1, p2;

	Line(Point p1Arg, Point p2Arg);

	//methods
	double slope(void);
	double yIntercept(void);
	double evaluateY(double xArg);
	void print(void);
};

int main(void) {
	srand(time(0));

	double x;

	cout << "Model a Line (Given Two Points)" << endl;
	cout << "Given two points, a line is calculated by computing the slope and y-intercept." << endl;
	cout << "For the line, a method is used to evaluate y given a random x." << endl;
	cout << "Note: When the line is in the form of x = n (where slope is infinity), evaluating y doesn't make sense." << endl << endl;

	for (int i = 0; i < 100; i++) {
		
		Point loc1((pow(-1, rand() % 2)) * (rand() % 50), (pow(-1, rand() % 2)) * (rand() % 50));
		Point loc2((pow(-1, rand() % 2)) * (rand() % 50), (pow(-1, rand() % 2)) * (rand() % 50));

		Line line1(loc1, loc2);

		line1.print();
		cout << "-------------------------" << endl;
		cout << "Point 1: (" << loc1.x << "," << loc1.y << ")" << endl;
		cout << "Point 2: (" << loc2.x << "," << loc2.y << ")" << endl;
		cout << "Slope:          " << line1.slope() << endl;
		cout << "y-intercept:    " << line1.yIntercept() << endl;
		x = (pow(-1, rand() % 2)) * (rand() % 50);
		cout << "If x = " << x << ", y = " << line1.evaluateY(x) << endl;
		cout << endl << endl;
	}

	return 0;
}

Point::Point(double xArg, double yArg) {
	x = xArg;
	y = yArg;
}

Line::Line(Point p1Arg, Point p2Arg) {
	p1 = p1Arg;
	p2 = p2Arg;
}

double Line::slope(void) {
	return ((p2.y - p1.y) / (p2.x - p1.x));
}

double Line::yIntercept(void) {
	// y = mx + b, so b = y - mx
	return p1.y - slope() * p1.x;
}

double Line::evaluateY(double xArg) {
	// y = mx + b
	return slope() * xArg + yIntercept();
}

void Line::print(void) {
	/*
	Special cases:
	1 - vertical line: p1.x == p2.x, so x = p1.x					(10,0),(10,100) or (-5,0),(-5,-10)
	2 - vertical line at x = 0: p1.x == p2.x == 0, so x = 0			(0,10),(0,-25)
	3 - horizontal line: p1.y == p2.y, so y = p1.y					(-5,-15),(35,-15)
	4 - horizontal line at y = 0: p1.y == p2.y == 0, so y = 0		(25,0),(-100,0)
	Normal cases:
	5 - y-intercept is negative: conditional display				
	6 - y-intercept is 0: conditional display
	7 - slope is 1: y = x + b
	8 - slope is -1: y = -x + b
	*/

	if (p1.x == p2.x)
		cout << "x = " << p1.x << endl; // 1 & 2		
	else if (p1.y == p2.y)
		cout << "y = " << p1.y << endl; // 3 & 4
	else {
		// 7
		if (slope() == 1) {
			if (yIntercept() < 0)
				cout << "y = x - " << -1 * yIntercept() << endl; // 5				(5,0),(10,5)
			else if (yIntercept() == 0)
				cout << "y = x" << endl; // 6										(2,2),(4,4)
			else
				cout << "y = x + " << yIntercept() << endl;	//						(5,10),(10,15)
		}
		// 8
		else if (slope() == -1) {
			if (yIntercept() < 0)
				cout << "y = -x - " << -1 * yIntercept() << endl; // 5				(-5,-5),(-7,-3)
			else if (yIntercept() == 0)
				cout << "y = -x" << endl; // 6										(-10,10),(-8,8)
			else
				cout << "y = -x + " << yIntercept() << endl; //						(20,20),(30,10)
		}
		else {
			if (yIntercept() < 0)
				cout << "y = " << slope() << "x - " << -1 * yIntercept() << endl; // 5	(10,0),(12,5)
			else if (yIntercept() == 0)
				cout << "y = " << slope() << "x" << endl; // 6							(4,3),(8,6)
			else
				cout << "y = " << slope() << "x + " << yIntercept() << endl; //			(20,20),(22,21)
		}
	}
}