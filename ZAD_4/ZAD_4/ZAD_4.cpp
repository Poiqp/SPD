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

int Cmax(int t, vector<vector<int> > vect) {
	int sum = 0;
	sum = vect[0][0];

	for (int i = 0; i < t; i++) {
		sum += vect[i][1];
	}
	
	sum += vect[t-1][2];
	return sum;
}

bool TestVec(int t, vector<vector<int> > vect) {
	int sum = 0;
	sum = vect[0][0];

	for (int i = 0; i < t-1; i++) {
		sum += vect[i][1];
		if (sum < vect[i+1][0]) {
			return false;
		}
	}
	return true;
}

vector<vector<int> > Sort(int t, vector<vector<int> > vect) {
	int time = 1;
	vector<vector<int> > sorted;
	vector<int> tmp(3,0);

	while (sorted.size() != t) {
		for (int i = 0; i < t; i++) {
			if (vect[i][0] == time) {
				tmp[0] = vect[i][0];
				tmp[1] = vect[i][1];
				tmp[2] = vect[i][2];
				sorted.push_back(tmp);
			}
		}
		time++;
	}
	return sorted;
}


int main()
{
	// t-tasks, m=3 - rpq 
	int t, m;
	ifstream data("in2.txt");
	data >> t;
	data >> m;
	vector<vector<int> > vect(t);

	//filing up vector 
	for (int i = 0; i < t; i++) {
		vector<int> vectTmp;
		vect.push_back(vectTmp);
	}
	// vect[t][R=0,P=1,Q=2]
	for (int i = 0; i < t; i++) {
		int tmp;
		data >> tmp;
		vect[i].push_back(tmp);
		data >> tmp;
		vect[i].push_back(tmp);	
		data >> tmp;
		vect[i].push_back(tmp);
	}

	cout << TestVec(t,vect)<<endl;
	cout << Cmax(t, vect) << endl;

	// posortowany wektor wzgledem R
	vector<vector<int> > sorted;
	sorted = Sort(t, vect);

	cout << sorted[0][0] << sorted[1][0] << sorted[2][0] <<  endl;

} 
