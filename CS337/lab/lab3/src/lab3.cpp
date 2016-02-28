//============================================================================
// Name        : lab3.cpp
// Author      : Nick Gaulke
// Version     :
// Copyright   : Your copyright notice
// Description : Statstics Program in C++, Ansi-style
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

int main() {
	// print program title
	cout << "Statistic Program" << endl;
	cout << "-----------------" << endl;
	int size = 0;

	// get number of inputs that must be within 1-100
	while(size < 1 || size > 100) {
		cout << "Please enter the size of the dataset of integers (1-100): ";
		cin >> size;
	}

	// get the values for the calculation
	int curr;
	int min = INT_MAX;
	int max = INT_MIN;
	int mean = 0;
	for(int i = 0; i < size; i++) {
		cout << "Value " << i+1 << ": ";
		cin >> curr;
		if(curr < min) min = curr;
		if(curr > max) max = curr;
		mean += curr;
	}

	// print the data
	cout << "Minimum: " << min << endl;
	cout << "Maximum: " << max << endl;
	cout << "Mean: " << (double)mean / (double)size;
	return 0;
}
