// Diagramm.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double x, y;
	bool disc, graph, inSector = false;
	bool aboveLine, underLine, onLine= false;

	cout << "Enter coordinates of a point (x, y): ";
	cin >> x >> y;

	//В случая, когато търсим дали точка попада в кръг с център (a, b), ще използваме формулата,
	//която проверява какво е разстоянието от от точката (а, b) до въведената (x, y)
	// център - (0,-1) радиус 2
	double r = sqrt(pow(x - 0, 2) + pow(y - (-1), 2));

	//Ако разстоянието между точките е по-малко или равно от радиуса то точката е в кръга
	if (r <= 2) {
		cout << "The point is on the disc";
		disc = true;
	}
	else { //В противен случай не е
		cout << "The point is outside the disc";
		disc = false;
	}

	if ((x+1) * (x+1) <= y )
	{
		cout << "\n The point is in the graph";
		graph = true; 
	}
	else
	{
		cout << "\n The point is not in the graph";
		graph = false;
	}

	if (y < -x)
	{
		cout << "\n The point is under the line";
		underLine = true; 
		aboveLine = false;
		onLine = false;
	}
	else if (y > -x)
	{
		cout << "\n The point is above the line";
		aboveLine = true; 
		underLine = false;
		onLine = false;
	}
	else
	{
		cout << "\n The point is on the line";
		onLine = true;
		aboveLine = false; 
		underLine = false;
	}

	if (disc && aboveLine && !graph)
	{
		inSector = true;
	}
	else if (disc && onLine && !graph)
	{
		inSector = true;
	}
	else if (!disc && underLine && graph)
	{
		inSector = true;
	}
	else if (!disc && onLine && graph)
	{
		inSector = true;
	}
	else
	{
		inSector = false;
	}
	if (inSector)
	{
		cout << "\n true";
	}
	else
	{
		cout << "\n False";

	}
	
	
	
	return 0;

}