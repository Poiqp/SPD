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

//count Cmax of given vector 
int Cmax(int t, vector<vector<int> > vect) {
	int sum = 0;
	sum = vect[0][0];

	for (int i = 0; i < t; i++) {
		sum += vect[i][1];
	}
	
	sum += vect[t-1][2];
	return sum;
}

//test if it can run 
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

//delete a task with its RPQ 
void DeleteRow(vector<vector<int> > & vect, int row) {

	if (vect.size() > row)
	{
		vect.erase(vect.begin() + row);
	}
}

//finding the smallest R and delete corresponding tasks from vector, return smallest R's
vector<vector<int> > Sort(int & t, vector<vector<int> > & vect, int time) {
	vector<vector<int> > sorted;
	vector<int> tmp(3,0);
	vector<bool> rowsToDelete(vect.size(),false);

	for (int i = 0; i < t; i++) {
		if (vect[i][0] == time) {
			tmp[0] = vect[i][0];
			tmp[1] = vect[i][1];
			tmp[2] = vect[i][2];
			sorted.push_back(tmp);
			rowsToDelete[i] = true;
			t--;
		}
	}

	for (int i = 0; i < vect.size(); i++)
	{
		while(rowsToDelete[i] == true) {
			DeleteRow(vect, i);
			rowsToDelete.erase(rowsToDelete.begin() + i);
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

	
	int time = 0;
	vector<vector<int> > sorted;
	
	/*		TEST GENERALNY PÊTLI SCIAGAJACEJ NAJMNIEJSZE R 
	for(time = 0; time < 4; time++) {

		cout << "________________" << time << endl;
		
		for (const std::vector<int> &v : vect)
		{
			for (int x : v) std::cout << x << ' ';
			std::cout << std::endl;
		}
		
		sorted = Sort(t, vect, time);
		
		for (const std::vector<int> &k : vect)
		{
			for (int z : k) std::cout << z << ' ';
			std::cout << std::endl;
		}
		
		
		cout << "sorted   : " << endl;
		for (const std::vector<int> &m : sorted)
		{
			for (int o : m) std::cout << o << ' ';
			std::cout << std::endl;
		}
		*/
	}
} 
