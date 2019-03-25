// ZAD_2_on_arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	// tasks machines 
	// number of tasks, number of machines, array <columns>=tasks <rows>=machines
	int t,m, arr[100][100];
	ifstream data("TextFile1.txt");
	data >> t; 
	data >> m;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < m; j++)
		{
			data >> arr[i][j];
		}
	}
	/*
	cout << t << "  " << m << endl;
	cout << arr[1][1] << endl;
	*/


	//fill the sums vector 
	vector<int> sums;
	int sumTmp = 0;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < m; j++)
		{
			sumTmp += arr[i][j];
		}
		sums.push_back(sumTmp);
		sumTmp = 0;
	}
	/*
	for (int n : sums) {
		std::cout << n << '\n';
	}
	*/


	//find biggest and remove it 
	vector<int>::iterator it = max_element(sums.begin(), sums.end());
	int max = *it;
	// position of it needed
	sums.erase(it);





}
