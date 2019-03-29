#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <time.h>
#include <stdlib.h>



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

	//randomizing ids
	auto rng = default_random_engine{};


	float T = 100000;
	float Tk = 0.0001;
	float P = 0.7;
	float wsp = 0.70;

	srand(time(NULL));
	float RND;

	vector<int> prev, act;
	int Fprev=0, Fact=0;
	

	
	while (T > Tk) {

		 T = T*wsp;

		//F(pi)
		shuffle(begin(ids), end(ids), rng);
		act = ids;
		Fact = Cmax(arr, ids, m);

		//F(pi-1)
		prev_permutation(ids.begin(), ids.end());
		prev = ids;
		Fprev = Cmax(arr, ids, m);

		if (Fprev < Fact) {
			RND = rand() / (RAND_MAX);

			if (P < RND) { ids = prev; }
		}
		else { ids = act; }

		// jak ustalic T i Tk oraz P i wsp

	}




	
	cout << Cmax(arr, ids, m);

}