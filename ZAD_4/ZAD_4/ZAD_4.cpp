#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>

using namespace std;

//show vector 
void PrintVect(vector<vector<int> > vect) {
	for (const vector<int> &v : vect)
	{
		for (int x : v) cout << x << ' ';
		cout << endl;
	}
	cout << endl;
}

//sort by a column | od najwiekszego do najmniejszego 
bool SortByCol(const vector<int>& v1, const vector<int>& v2) {
	return v1[2] > v2[2];
}

//count Cmax of given vector 
int Cmax(int t, vector<vector<int> > vect) {
	int sum = 0;
	sum = vect[0][0];

	for (int i = 0; i < t; i++) {
		sum += vect[i][1];
	}

	sum += vect[t - 1][2];
	return sum;
}

//test if it can run 
bool TestVec(int t, vector<vector<int> > vect) {
	int sum = 0;
	sum = vect[0][0];

	for (int i = 0; i < t - 1; i++) {
		sum += vect[i][1];
		if (sum < vect[i + 1][0]) {
			return false;
		}
	}
	return true;
}

//gotowe R wzglêdem czasu vect -> ready
void GetReady(vector<vector<int> > & vect, vector<vector<int> > & ready, int time) {
	vector<int> tmp(3, 0);

	for (int i = 0; i < vect.size(); i++) {
		if (vect[i][0] == time) {
			tmp[0] = vect[i][0];
			tmp[1] = vect[i][1];
			tmp[2] = vect[i][2];
			ready.push_back(tmp);
			vect.erase(vect.begin() + i);
			i--;
		}
	}
}

//najwieksze Q , ready -> order
void GetOrder(vector<vector<int> > & ready, vector<vector<int> > & order) {
	vector<int> tmp(3, 0);

	sort(ready.begin(), ready.end(), SortByCol);

	while (!ready.empty()) {
		tmp[0] = ready[0][0];
		tmp[1] = ready[0][1];
		tmp[2] = ready[0][2];
		order.push_back(tmp);
		ready.erase(ready.begin());
	}
}


int main()
{
	// t-tasks, m=3 - rpq 
	int t, m;
	ifstream data("in2.txt");
	data >> t;
	data >> m;
	vector<vector<int> > vect;

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


	int time = 0;
	vector<vector<int> > ready;
	vector<vector<int> > order;

	time = 1;
	cout << "__________CZAS= " << time << endl;
	PrintVect(vect);
	GetReady(vect, ready, time);
	GetOrder(ready, order);
	PrintVect(order);

	time = 2;
	cout << "__________CZAS= " << time << endl;
	PrintVect(vect);
	GetReady(vect, ready, time);
	GetOrder(ready, order);
	PrintVect(order);

	time = 3;
	cout << "__________CZAS= " << time << endl;
	PrintVect(vect);
	GetReady(vect, ready, time);
	GetOrder(ready, order);
	PrintVect(order);

	time = 4;
	cout << "__________CZAS= " << time << endl;
	PrintVect(vect);
	GetReady(vect, ready, time);
	GetOrder(ready, order);
	PrintVect(order);

}



