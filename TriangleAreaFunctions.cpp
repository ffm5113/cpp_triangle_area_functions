// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++: From control structures through objects. Pearson. 
// Heron's Formula for Area of a Triangle
// https://www.mathopenref.com/heronsformula.html

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <cmath>    // To access power function for calculations
#include <ctime>    // Access random number generator
using namespace std;

// Global Constant Initialization
const string TITLE = "Triangle Area Function Program";
const string AUTHOR_LINE = "By Forrest Moulin";

// Function prototypes to notify compiler
// 2 functions triangleArea are overloaded
double triangleArea(double base, double height);
double triangleArea(double side1, double side2, double side3);

// Uses reference parameter to update the keepLooping 
// char (Y yes, N no)
void continuePrompt(char &keepLooping);
void baseHeightPrompt();
void threeSidesPrompt();

int main()
{
	// Seed the random number generator
	// using current time
	srand(time(NULL));
	// Dynamic Variable Initialization
	int randomFormula;
	double base, height, area,
		side1, side2, side3;
	char keepLooping = 'Y';

	// Program Logic
	cout << fixed << setprecision(2) << TITLE 
		<< endl << AUTHOR_LINE << endl;

	while (keepLooping == 'Y' || keepLooping == 'y')
	{
		// Two random options, 0 or 1
		// 0 represents base/height formula
		// 1 represents 3-sides length formula
		randomFormula = rand() % 2;
		if (randomFormula == 0)
		{
			baseHeightPrompt();
			cin >> base >> height;
			area = triangleArea(base, height);
		}
		else // randomFormula == 1
		{
			threeSidesPrompt();
			cin >> side1 >> side2 >> side3;
			area = triangleArea(side1, side2, side3);
		}
		
		if (area == 0)
		{
			cout << "Invalid entry." << endl << endl
				<< "The length of two sides of a triangle must"
				<< endl << "always be greater than the third side."
				<< endl << "Restarting the program..."
				<< endl;
		}
		else
		{
			cout << "The calculated area is " << area << "."
				<< endl << endl;
			// Ignore cin stream size of 1000
			// and delimiter of '\n' to avoid
			// infinite loop :)
			cin.ignore(1000, '\n');

			continuePrompt(keepLooping);

			if (keepLooping == 'n' || keepLooping == 'N')
			{
				cout << endl << "Exiting the program..." << endl
					<< "Until next time! :)" << endl;
				return 0;
			}
			else if (keepLooping == 'y' || keepLooping == 'Y')
			{
				continue;
			}
			else
			{
				cout << "Invalid entry." << endl;
				cin.ignore(1000, '\n');
				continuePrompt(keepLooping);
			}
			cin.ignore(1000, '\n');
		}
	}
}
double triangleArea(double base, double height)
{	// A = 1/2 base * height 
	return 0.5 * base * height;
}
double triangleArea(double side1, double side2, double side3)
{	// Use Heron's Formula
	double p = 0.5 * (side1 + side2 + side3);
	// 1/2 perimeter (p) = (side1 + side2 + side3)/2
	// Area A = sqrt(p(p - side1)*(p - side2)*(p - side3))
	return pow((p * (p - side1) * (p - side2) * (p - side3)), 0.5);
}
void continuePrompt(char &keepLooping)
{
	cout << "Would you like to continue?" << endl
		<< "Please enter Y for yes or N for no."
		<< endl << endl;
	cin >> keepLooping;
}
void baseHeightPrompt()
{
	cout << endl << "Please enter the base and height of a triangle,"
		<< endl << "using the same units rounded to whole numbers"
		<< endl << "(space delimited)." << endl << endl;
}
void threeSidesPrompt()
{
	cout << endl << "Please enter the lengths of the 3 sides of the"
		<< endl << "triangle. Be sure to use the same units, and"
		<< endl << "round your entries to whole numbers (space delimited)."
		<< endl << endl;
}
/*
* CONSOLE OUTPUT
* Triangle Area Function Program
* By Forrest Moulin
*
* Please enter the lengths of the 3 sides of the
* triangle. Be sure to use the same units, and
* round your entries to whole numbers (space delimited).
*
* 3 4 5
* The calculated area is 6.00.
*
* Would you like to continue?
* Please enter Y for yes or N for no.
*
* u
* Invalid entry.
* Would you like to continue?
* Please enter Y for yes or N for no.
*
* y
*
* Please enter the lengths of the 3 sides of the
* triangle. Be sure to use the same units, and
* round your entries to whole numbers (space delimited).
*
* 10 20 30
* Invalid entry.
*
* The length of two sides of a triangle must
* always be greater than the third side.
* Restarting the program...
*
* Please enter the lengths of the 3 sides of the
* triangle. Be sure to use the same units, and
* round your entries to whole numbers (space delimited).
*
* 11 20 30
* The calculated area is 55.88.
*
* Would you like to continue?
* Please enter Y for yes or N for no.
*
* y
*
* Please enter the base and height of a triangle,
* using the same units rounded to whole numbers
* (space delimited).
*
* 10 15
* The calculated area is 75.00.
*
* Would you like to continue?
* Please enter Y for yes or N for no.
*
* n
*
* Exiting the program...
* Until next time! :)
*/
