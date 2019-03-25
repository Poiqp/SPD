// ZAD_2_B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

int CountSum(vector<int> task) {
	int sum_of_elems = 0;
	for (auto& n : task)
		sum_of_elems += n;
	return sum_of_elems;
}



vector<int> MakeSums(int n, vector<vector<int>> table) {
	vector<int> sumOfAColumn(n);
	for (int n : sumOfAColumn) {
		sumOfAColumn.push_back(CountSum(table[n]));
	}
	return sumOfAColumn;
}



int main()
{	
	int n = 4;		// number of tasks aka vectors
	vector<vector<int>> taskTable(n);
	taskTable[0].push_back(1);
	taskTable[0].push_back(2);
	taskTable[1].push_back(5);
	taskTable[1].push_back(2);
	taskTable[1].push_back(2);
	taskTable[2].push_back(2);
	taskTable[2].push_back(2);

	int tmp = CountSum(taskTable[0]);
	cout << tmp << endl;
	int tmp2 = CountSum(taskTable[1]);
	cout << tmp2 << endl;

	cout << CountSum(taskTable[0]) << endl;
	cout << CountSum(taskTable[1]) << endl;

	vector<int> TB;
	TB.push_back(tmp);
	TB.push_back(tmp2);
	TB.push_back(CountSum(taskTable[2]));




	for (int n : TB) {
		std::cout << n << '\n';
	}

	cout << TB[0] << '   ' << TB[1] << endl << endl;

	vector<int> NEW = MakeSums(2, taskTable);


	

	//cout << VectorOfSums[1] << '    ' << VectorOfSums[2] << endl;


}
