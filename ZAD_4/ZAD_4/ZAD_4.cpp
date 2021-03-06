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

//cmax 
int Cmax(vector<vector<int> > vect) {
	int sum = 0;
	int qProjected = 0;
	sum = vect[0][0];
	

	for (int i = 0; i < vect.size(); i++) {

		if (sum < vect[i][0]) { sum = vect[i][0]; }
		sum += vect[i][1];

		qProjected = max(qProjected, sum + vect[i][2]);
	}

	return qProjected;
}

//gotowe R wzgl�dem czasu vect -> ready
void GetReady(vector<vector<int> > & vect, vector<vector<int> > & ready, int time) {
	vector<int> tmp(3, 0);

	for (int i = 0; i < vect.size(); i++) {
		if (vect[i][0] <= time) {
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
int GetOrder(vector<vector<int> > & ready, vector<vector<int> > & order) {
	vector<int> tmp(3, 0);

	sort(ready.begin(), ready.end(), SortByCol);

		tmp[0] = ready[0][0];
		tmp[1] = ready[0][1];
		tmp[2] = ready[0][2];
		order.push_back(tmp);
		ready.erase(ready.begin());

		return tmp[1];
}

//najmniejsze R 
int FindSmallestRTime(vector<vector<int> >  vect) {
	int smallestR = vect[0][0];

	for (int i = 0; i < vect.size(); i++) {
		if (vect[i][0] < smallestR) { smallestR = vect[i][0]; }
	}
	return smallestR;
}


int main()
{
	// t-tasks, m=3 - rpq 
	int t, m;
	ifstream data("in200.txt");
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
	int getP = 0;
	vector<vector<int> > ready;
	vector<vector<int> > order;

	time = FindSmallestRTime(vect);
	
	while (vect.empty() != 1 || ready.empty() != 1) {

		GetReady(vect, ready, time);

		if (ready.empty() == 1 ) {
			time = FindSmallestRTime(vect);
		}
		else {
			getP = GetOrder(ready, order);
			time += getP;
		}
	}


	
	PrintVect(order);

	cout << time << endl;
	cout << order.size() << endl;
	cout << Cmax(order) << endl; 
	
}


