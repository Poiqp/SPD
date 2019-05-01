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

//finding the smallest R
vector<vector<int> > Sort(vector<vector<int> > & vect, int time) {
	vector<vector<int> > sorted;
	vector<int> idToDelete;
	vector<int> tmp(3,0);

	for (int i = 0; i < vect.size()/3; i++) {
		if (vect[i][0] == time) {
			tmp[0] = vect[i][0];
			tmp[1] = vect[i][1];
			tmp[2] = vect[i][2];
			sorted.push_back(tmp);
			vect.erase(vect.begin() + i);
			idToDelete.push_back(i);
		}
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

	//tests 
	//cout << TestVec(t,vect)<<endl;
	//cout << Cmax(t, vect) << endl;
	//tests

	/*
	for (const std::vector<int> &v : vect)
	{
		for (int x : v) std::cout << x << ' ';
		std::cout << std::endl;
	}
	*/

	
	int time = 1;
	vector<vector<int> > sorted;
	
	//size == 6
	sorted = Sort(vect, time);
	//size == 5 cos jest nie tak trzeba to ogarnac 



} 
