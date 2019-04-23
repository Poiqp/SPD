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
	// cout << vect[1][0] << endl;


	cout << TestVec(t,vect)<<endl;
	cout << Cmax(t, vect) << endl;

} 
