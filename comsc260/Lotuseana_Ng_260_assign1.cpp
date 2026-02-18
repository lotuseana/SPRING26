#include <iostream>
using namespace std;

const int COLS = 1;

int getTotal(int[][COLS], int);
double getAverage(int[][COLS], int);
int getRowTotal(int[][COLS], int);
int getColumnTotal(int[][COLS], int, int);
int getHighestInRow(int[][COLS], int);
int getLowestInRow(int[][COLS], int);

int main()
{
	// const int ROWS = 4;

	// int testArray[ROWS][COLS] =
	// 				{ { 1,   2,  3,  4,  5 },
	// 				{   6,   7,  8,  9, 10 },
	// 				{  11,  12, 13, 14, 15 },
	// 				{  16,  17, 18, 19, 20 } };

	// cout << "The total of the array elements is "
	// 	 << getTotal(testArray, ROWS)
	// 	 << endl;

	// cout << "The average value of an element is "
	// 	 << getAverage(testArray, ROWS)
	// 	 << endl;

	// cout << "The total of row 0 is "
	// 	 << getRowTotal(testArray, 0)
	// 	 << endl;

	// cout << "The total of col 2 is "
	// 	 << getColumnTotal(testArray, 2, ROWS)
	// 	 << endl;

	// cout << "The highest value in row 2 is "
	// 	 << getHighestInRow(testArray, 2)
	// 	 << endl;

	// cout << "The lowest value in row 2 is "
	// 	 << getLowestInRow(testArray, 2)
	// 	 << endl;

	// system("PAUSE");

	// test case 5
	const int ROWS = 1;

	int testArray[ROWS][COLS] =
		{{1}};

	cout << "The total of the array elements is "
		 << getTotal(testArray, ROWS)
		 << endl;
	cout << "The average value of an element is "
		 << getAverage(testArray, ROWS)
		 << endl;

	cout << "The total of row 0 is "
		 << getRowTotal(testArray, 0)
		 << endl;

	cout << "The total of col 0 is "
		 << getColumnTotal(testArray, 0, ROWS)
		 << endl;

	cout << "The highest value in row 0 is "
		 << getHighestInRow(testArray, 0)
		 << endl;

	cout << "The lowest value in row 0 is "
		 << getLowestInRow(testArray, 0)
		 << endl;

	system("PAUSE");
	return 0;
}

int getTotal(int array[][COLS], int rows)
{
	// 1. keeping a running total
	int total = 0;
	// 2. nested loop; iterates each row
	for (int i = 0; i < rows; i++)
	{
		// 3. within each row, iterates each column to traverse all elements of 2d array
		for (int j = 0; j < COLS; j++)
		{
			total += array[i][j];
		}
	}
	return total;
}

double getAverage(int array[][COLS], int rows)
{
	// 4. average given by (total) / (number of elements), so using getTotal function
	return (float)getTotal(array, rows) / (COLS * rows);
}

int getRowTotal(int array[][COLS], int rowToTotal)
{
	// 5. running total for the row total
	int rowTotal = 0;
	// 6. iterates each iterm of given row and adds it to the total
	for (int i = 0; i < COLS; i++)
	{
		rowTotal += array[rowToTotal][i];
	}
	return rowTotal;
}

int getColumnTotal(int array[][COLS], int colToTotal, int rows)
{
	// 7. same logic as getRowTotal, but with a column instead
	int colTotal = 0;
	for (int i = 0; i < rows; i++)
	{
		colTotal += array[i][colToTotal];
	}
	return colTotal;
}

int getHighestInRow(int array[][COLS], int rowToSearch)
{
	// 8. sets a highest current valye (points to the first element of the row initially)
	int highest = array[rowToSearch][0];
	for (int i = 0; i < COLS; i++)
	{
		// 9. for each element of the row, if it is higher than the current highest, update the highest current
		if (array[rowToSearch][i] > highest)
		{
			highest = array[rowToSearch][i];
		}
	}
	return highest;
}

int getLowestInRow(int array[][COLS], int rowToSearch)
{
	// 10. same logic as getHighestInRow except to find the smallest element
	int lowest = array[rowToSearch][0];
	for (int i = 0; i < COLS; i++)
	{
		if (array[rowToSearch][i] < lowest)
		{
			lowest = array[rowToSearch][i];
		}
	}
	return lowest;
}
