#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>



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
	return tabPom[m - 1][ids.size() - 1];
}

int main()
{
	// tasks machines 
	// number of tasks, number of machines, array <columns>=tasks <rows>=machines
	int t, m, arr[100][100];
	ifstream data("dane.txt");
	data >> t;
	data >> m;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < m; j++)
		{
			data >> arr[j][i];
		}
	}


	// vector of ids(order of tasks)
	vector<int> ids;
	for (int i = 0; i < t; i++) {
		ids.push_back(i);
	}

	vector<int> bestID;
	int bestCmax=100000;
	int newCmax;


	// permutations 
	do {
		newCmax = Cmax(arr, ids, m);
		if (newCmax < bestCmax) { 
			bestID = ids;
			bestCmax = newCmax; 
		}

	}while (next_permutation(ids.begin(), ids.end()));
	


	cout << Cmax(arr, bestID, m);
	
}