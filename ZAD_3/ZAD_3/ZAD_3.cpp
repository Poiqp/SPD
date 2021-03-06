#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <math.h>
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

	// temperatura początkowa | temperatura końcowa | prawdopodobieństwo | współczynnik chłodzenia
	float T = 100000;
	float Tk = 0.0001;
	float P = 0;
	float wsp = 0.99;

	// ustalanie czasu początkowego dla rand | zmienna losowa (0,1) | losowe miejsca w wektorze do zamiany miejsc 
	srand(time(NULL));
	double RND;
	int RNDid1,RNDid2;
	
	// wektory przechowujące kolejność PI' oraz PI | zmienne przechowujące wartości Cmax PI' oraz PI
	vector<int> prev, act;
	int Fprev=0, Fact=0;
	
	//iterator zliczający przejścia pętli | tymczasowa zmienna do przechowaywania do inserta 
	int k = 0;
	int tmp = 0;

	
	while (T > Tk) {

		//Pi
			act = ids;
			Fact = Cmax(arr, ids, m);

		//Pi'
			prev = ids;
			RNDid1 = rand() % (prev.size() - 1); RNDid2 = rand() % (prev.size() - 1);

			//swap
			//iter_swap(prev.begin() + RNDid1, prev.begin() + RNDid2);

			//insert
			tmp = *( prev.begin() + RNDid2);
			prev.erase(prev.begin() + RNDid2);
			prev.insert(prev.begin() + RNDid1, tmp);

			Fprev = Cmax(arr, prev, m);


		//wyznaczanie prawdopodobieństwa przejścia
		P = exp((Fact - Fprev) / T);

		if (Fprev >= Fact) {
			RND = ((double)rand()/(RAND_MAX));
			if (P >= RND) { ids = prev; }
			else { ids = act; }
		}
		else { ids = prev; }

		k++;
		T = T * wsp;
	}
	
	cout << k << endl;
	cout << Cmax(arr, ids, m);
}