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


	//fill the sums vector 
	vector<int> sums;
	int sumTmp = 0;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < m; j++)
		{
			sumTmp += arr[j][i];
		}
		sums.push_back(sumTmp);
		sumTmp = 0;
	}

	//find biggest and remove it | position aka task  | remove it 
	vector<int>::iterator it = max_element(sums.begin(), sums.end());
	int index = distance(sums.begin(), it);
	sums[index] = 0;

	// vector of ids(order of tasks) | first element in vector
	vector<int> ids;
	ids.push_back(index);


	for (int k = 0; k < t - 1; k++) {
		//next biggest		
		it = max_element(sums.begin(), sums.end());
		index = distance(sums.begin(), it);
		sums[index] = 0;


		//best Cmax time | best place //z
		int bestCmax = 1000000;
		int bestPlace;

		for (size_t z = 0; z < ids.size() + 1; z++) {
			//choose position  in loop (start:0 end: ids.size()+1)
			//wrzucić do Cmaxa i wybrać najmniejszy czas

			ids.insert((ids.begin() + z), index);
			int newCmax = Cmax(arr, ids, m);

			if (newCmax < bestCmax) { bestCmax = newCmax; bestPlace = z; }

			ids.erase(ids.begin() + z);
		}
		ids.insert(ids.begin() + bestPlace, index);
		bestCmax = 100000;
	}



	cout << Cmax(arr, ids, m);
}