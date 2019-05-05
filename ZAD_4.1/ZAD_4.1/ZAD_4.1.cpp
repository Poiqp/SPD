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

//sort by a column | od najwiekszego do najmniejszego po Q
bool SortByColQ(const vector<int>& v1, const vector<int>& v2) {
	return v1[2] > v2[2];
}

//count Cmax of given vector ALE NIE DO KONCA BO NIE DOLICZA DZIUR 
int Cmax(vector<vector<int> > vect) {
	int sum = 0;
	sum = vect[0][0];

	for (int i = 0; i < vect.size(); i++) {

		if (sum < vect[i][0]) { sum = vect[i][0]; }
		sum += vect[i][1];
	}

	sum += vect[vect.size() - 1][2];
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

//zwaraca gotowe do wykonania zadanie przy czym wrzuca je na ready i sciaga z wektora zadan
vector<int> GetReady(vector<vector<int> > & vect, vector<vector<int> > & ready, int time) {
	vector<int> tmp(3, 0);

	for (int i = 0; i < vect.size(); i++) {
		if (vect[i][0] <= time) {
			tmp[0] = vect[i][0];
			tmp[1] = vect[i][1];
			tmp[2] = vect[i][2];
			ready.push_back(tmp);
			vect.erase(vect.begin() + i);
			break;
		}
	}

	return tmp;
}

//najwieksze Q , ready -> order ||| zwraca P 
vector<int> GetBiggestQ(vector<vector<int> > & ready) {
	vector<int> tmp(3, 0);

	sort(ready.begin(), ready.end(), SortByColQ);

	tmp[0] = ready[0][0];
	tmp[1] = ready[0][1];
	tmp[2] = ready[0][2];
	ready.erase(ready.begin());

	return tmp;
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
	ifstream data("in50.txt");
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
	int cmax = 0;
	int l = 0;

	
	vector<vector<int> > ready;
	vector<int> act;
	vector<int> prev(3);
	
	prev[0] = 0;
	prev[1] = 0;
	prev[2] = 999999;

	while (vect.empty() != 1 || ready.empty() != 1) {

		while (vect.empty() != 1 && FindSmallestRTime(vect) <= time) {
			act = GetReady(vect, ready, time);
			if (act[2] > prev[2]) {
				prev[1] = time - act[0];
				time = act[0];

				if (prev[1] > 0) {
					ready.push_back(prev);
				}
			}
		}
		if (ready.empty() == 1) {
			time = FindSmallestRTime(vect);
		}
		else {
			act = GetBiggestQ(ready);
			prev = act;
			time = time + act[1];
			cmax = time + act[2];
		}
	}


	cout << cmax;
}

