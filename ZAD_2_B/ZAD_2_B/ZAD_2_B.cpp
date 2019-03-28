// ZAD_2_on_arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

int Cmax(int tab[100][100], vector<int> ids, int m) {
	int tabPom[100][100] = { 0 };
	int sumPomPoz = 0;
	int sumPomPion = 0;


	for (size_t i = 0; i < ids.size(); i++) {
		sumPomPoz += tab[0][*(ids.begin() + i)];
		tabPom[0][i] = sumPomPoz;
	}
	for (int j = 0; j < m; j++) {
		sumPomPion += tab[j][*ids.begin()];
		tabPom[j][0] = sumPomPion;
	}
	for (int y = 1; y < m; y++) {
		for (size_t x = 1; x < ids.size(); x++) {
			tabPom[y][x] = max(tabPom[y - 1][x], tabPom[y][x - 1]) + tab[y][ids[x]];
		}
	}
	return tabPom[m-1][ids.size()-1];
}

int main()
{

	int t= 4;
	int m = 3;

	int arr[100][100] = { 0 };

	arr[0][0] = 1;
	arr[1][0] = 3;
	arr[2][0] = 8;

	arr[0][1] = 9;
	arr[1][1] = 3;
	arr[2][1] = 5;

	arr[0][2] = 7;
	arr[1][2] = 8;
	arr[2][2] = 6;

	arr[0][3] = 4;
	arr[1][3] = 8;
	arr[2][3] = 7;


	//fill the sums vector 
	vector<int> sums;
	sums.push_back(12);
	sums.push_back(17);
	sums.push_back(21);
	sums.push_back(19);


	//find biggest and remove it | value of it | position aka task  | remove it 
	vector<int>::iterator it = max_element(sums.begin(), sums.end());
	int max = *it;
	int index = distance(sums.begin(), it);
	sums.erase(it);


	// vector of ids(order of tasks) | first element in vector
	
	vector<int> ids;
	ids.push_back(0);
	ids.push_back(3);
	ids.push_back(2);
	ids.push_back(1);

	/*
	it = max_element(sums.begin(), sums.end());
	index = distance(sums.begin(), it);
	sums.erase(it);

	ids.push_back(index);

	it = max_element(sums.begin(), sums.end());
	index = distance(sums.begin(), it);
	sums.erase(it);

	ids.push_back(index);

	it = max_element(sums.begin(), sums.end());
	index = distance(sums.begin(), it);
	sums.erase(it);

	ids.push_back(index);
*/


//	cout << ids[0] << ids[1] << ids[2] << endl;


	/*
	for (int k = 0; k < t-1; k++) {
		//next biggest
		it = max_element(sums.begin(), sums.end());
		max = *it;
		cout << max << endl;
		index = distance(sums.begin(), it);
		sums.erase(it);
	}
	*/



	cout << Cmax(arr, ids, m);



}