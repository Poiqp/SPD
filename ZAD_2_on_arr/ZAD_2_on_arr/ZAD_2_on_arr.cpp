// ZAD_2_on_arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

int Cmax(int tab[100][100], vector<int> ids) {





}

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


	//find biggest and remove it | value of it | position aka task  | remove it 
	vector<int>::iterator it = max_element(sums.begin(), sums.end());
	int max = *it;
	int index = distance(sums.begin(), it);
	sums.erase(it);

	// vector of ids(order of tasks) | first element in vector
	vector<int> ids;
	ids.push_back(index);

	for (int k = 0; k < t; k++) {
		//next biggest
		it = max_element(sums.begin(), sums.end());
		max = *it;
		index = distance(sums.begin(), it);
		sums.erase(it);

		//best Cmax time | best place //z
		int bestCmax = 1000000;
		int bestPlace;

		for (int z = 0; z < ids.size()+ 1; z++) {
			//choose position  in loop (start:0 end: ids.size()+1)
			//wrzucić do Cmaxa i wybrać najmniejszy czas
			ids.insert(ids.begin() + z, index);
			//if (newCmax < bestCmax){bestCmax =newCmax; bestPlace=z;}
			ids.erase(ids.begin() + z);
		}
		ids.insert(ids.begin() + bestPlace, index);
	}


	//Cmax 
	//CMAX(tab,ids);
}
