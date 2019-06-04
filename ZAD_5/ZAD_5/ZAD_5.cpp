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

/////////// FUNKCJE DLA SCHRAGE I SHRAGE PTMN /////////////////////////////////

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

//sort by a column | od najwiekszego do najmniejszego po Q
bool SortByColQ(const vector<int>& v1, const vector<int>& v2) {
	return v1[2] > v2[2];
}

//cmax 
int Cmax(vector<vector<int> > vect) {
	int sum = 0;
	int qProjected = 0;
	sum = vect[0][0];


	for (unsigned int i = 0; i < vect.size(); i++) {

		if (sum < vect[i][0]) { sum = vect[i][0]; }
		sum += vect[i][1];

		qProjected = max(qProjected, sum + vect[i][2]);
	}

	return qProjected;
}

//gotowe R wzglêdem czasu vect -> ready
void GetReady(vector<vector<int> > & vect, vector<vector<int> > & ready, int time) {
	vector<int> tmp(3, 0);

	for (unsigned int i = 0; i < vect.size(); i++) {
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

//zwaraca gotowe do wykonania zadanie przy czym wrzuca je na ready i sciaga z wektora zadan | druga wersja zwracajaca 
vector<int> GetReadyPrime(vector<vector<int> > & vect, vector<vector<int> > & ready, int time) {
	vector<int> tmp(3, 0);

	for (unsigned int i = 0; i < vect.size(); i++) {
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

//zanjduje i œciaga z wektora zadanie o najwiekszym Q 
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

	for (unsigned int i = 0; i < vect.size(); i++) {
		if (vect[i][0] < smallestR) { smallestR = vect[i][0]; }
	}
	return smallestR;
}

///////////  SCHRAGE I SCHRAGE PTMN //////////////////////////

/// Schrage zwaraca wartoœæ Cmaxa | zwraca zmienianego vecta wg kolejnoœci
int Schrage(vector<vector<int> > & vect) {
	int time = 0;
	int getP = 0;
	vector<vector<int> > ready;
	vector<vector<int> > order;

	time = FindSmallestRTime(vect);

	while (vect.empty() != 1 || ready.empty() != 1) {

		GetReady(vect, ready, time);

		if (ready.empty() == 1) {
			time = FindSmallestRTime(vect);
		}
		else {
			getP = GetOrder(ready, order);
			time += getP;
		}
	}
	vect = order;

	return Cmax(order);
}

/// SchragePTMN zwaraca wartoœæ Cmaxa
int SchragePTMN(vector<vector<int> >  vect) {
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
			act = GetReadyPrime(vect, ready, time);
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
			cmax = max(cmax, time + act[2]);
		}
	}
	return cmax;
}

/////////// CARLIER FUNKCJE //////////////////////////
///sprawdzic 
/*
int findA(vector<vector<int> > vect, int B) {
	int ID=0;
	int sum = 0;
	//sum = vect[0][0];

	for (int i = 0; i <= B; i++) {
		if (sum < vect[i][0]) { 
			sum = vect[i][0]; 
			ID = i;
		}
		sum += vect[i][1];
	}
	return ID;
}*/

// rownoznaczne sa!
vector<vector<int> > cutBloc(vector<vector<int> > vect, int B) {
	vector<vector<int> > bloc;
	vector<int> tmp(3, 0);
	int blocIT = 0;

	for (unsigned int i = 0; i <= B; i++) {
		tmp[0] = vect[i][0];
		tmp[1] = vect[i][1];
		tmp[2] = vect[i][2];

		bloc.push_back(tmp);
	}
	return bloc;
}
int findA(vector<vector<int> > vect, int B) {
	vector<vector<int> > doB = cutBloc(vect, B);

	int ID = 0;
	int cmax = Cmax(doB);
	int sum_tmp = 0;

	for (int i = 0; i <= B; i++) {
		for (int j = i; j <= B; j++) {
			sum_tmp += vect[j][1];
		}

		if (vect[i][0] + sum_tmp + vect[B][2] == cmax) {
			ID = i;
		}
		sum_tmp = 0;
	}
	return ID;
}

int findB(vector<vector<int> > vect) {
	int ID;
	int sum = 0;
	int qProjected = 0;
	sum = vect[0][0];

	for (unsigned int i = 0; i < vect.size(); i++) {

		if (sum < vect[i][0]) { sum = vect[i][0]; }
		sum += vect[i][1];

		// znajduje odpowiednie q i jego ID 
		if (max(qProjected, sum + vect[i][2]) == sum + vect[i][2]) {
			qProjected = sum + vect[i][2];
			ID = i;
		}
	}
	return ID;
}

int findC(vector<vector<int> > vect, int A, int B) {
	int ID=0;
	int qB = vect[B][2];
	int maxQ = 0;

	for ( int i = A; i < B; i++) {
		if (vect[i][2] >= maxQ && vect[i][2] < qB) {
			ID = i;
		}
	}
	return ID;
}

/// wycinanie bloku bez C
vector<vector<int> > cutBloc_woC(vector<vector<int> > vect, int C, int B) {
	vector<vector<int> > bloc;
	vector<int> tmp(3,0);
	int blocIT = 0;
	
	for (unsigned int i = C+1; i <= B; i++) {
		tmp[0] = vect[i][0];
		tmp[1] = vect[i][1];
		tmp[2] = vect[i][2];

		bloc.push_back(tmp);
	}
	return bloc;
}

///wycinanie bloku z C
vector<vector<int> > cutBloc_wC(vector<vector<int> > vect, int C, int B) {
	vector<vector<int> > bloc;
	vector<int> tmp(3, 0);
	int blocIT = 0;

	for (unsigned int i = C ; i <= B; i++) {
		tmp[0] = vect[i][0];
		tmp[1] = vect[i][1];
		tmp[2] = vect[i][2];

		bloc.push_back(tmp);
	}
	return bloc;
}

int findMinR_bloc(vector<vector<int> > vect) {
	int ID = 0;
	int smallestR = vect[0][0];

	for (unsigned int i = 0; i < vect.size(); i++) {
		if (vect[i][0] < smallestR) { 
			smallestR = vect[i][0]; 
			ID = i;
		}
	}
	return smallestR;
}

int findMinQ_bloc(vector<vector<int> > vect) {
	int ID = 0;
	int smallestQ = vect[0][2];

	for (unsigned int i = 0; i < vect.size(); i++) {
		if (vect[i][2] < smallestQ) { 
			smallestQ = vect[i][2]; 
			ID = i;
		}
	}
	return smallestQ;
}

int sumP_bloc(vector<vector<int> > vect) {
	int sumP = 0;

	for (unsigned int i = 0; i < vect.size(); i++) {
		sumP += vect[i][1];
	}
	return sumP;
}

int maximum(int a, int b, int c)
{
	int max = (a < b) ? b : a;
	return ((max < c) ? c : max);
}

///////////// CARLIER /////////////////////////

vector<vector<int> > Carlier(vector<vector<int> >  vect , int & UB) {
	vector<vector<int> > Uorder;
	Uorder = vect;
	
	int U = Schrage(Uorder);

	if (U < UB) {
		UB = U;
		vect = Uorder;
	}
	int LB = SchragePTMN(vect);

	cout << UB << endl;

	int B = findB(vect);
	int A = findA(vect, B);
	int C = findC(vect, A, B);

	cout << "               "  << A << endl;

	if (C == 0) {
		return vect;
	}

	vector<vector<int> > K;
	vector<vector<int> > K_wC;
	int rK, qK, pK, hK, rK_wC, qK_wC, pK_wC, hK_wC;
	int old_R, old_Q;

	K = cutBloc_woC(vect, C, B);
	K_wC = cutBloc_wC(vect, C, B);

	rK = findMinR_bloc(K);
	qK = findMinQ_bloc(K);
	pK = sumP_bloc(K);
	hK = rK + qK + pK;
		
	rK_wC = findMinR_bloc(K_wC);
	qK_wC = findMinQ_bloc(K_wC);
	pK_wC = sumP_bloc(K_wC);
	hK_wC = rK_wC + qK_wC + pK_wC;

	old_R = vect[C][0];
	vect[C][0] = max(old_R, rK + pK);


	int LBa = LB;
	LBa = maximum(hK, hK_wC, LBa);

	if (LBa < UB) {
		Carlier(vect, UB );
	}

	vect[C][0] = old_R;

	old_Q = vect[C][2];
	vect[C][2] = max(old_Q, qK + pK);


	int LBb = LB;
	LBb = maximum(hK, hK_wC, LBb);

	if (LBb < UB) {
		Carlier(vect, UB );
	}
	
	vect[C][2] = old_Q;
}



int main()
{
	// t-tasks, m=3 - rpq 
	int t, m;
	ifstream data("inData001.txt");
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
	//int wynik = Schrage(vect);
	
	//cout << wynik << endl;
	int UB = 9999999;
	vector<vector<int> > finalOrder;

	finalOrder = Carlier(vect,UB);

	
	/*
	
	vector<vector<int> > brandNewOrder;
	vector<vector<int> > brandNewNewOrder;

	brandNewOrder = vect;

	Schrage(brandNewOrder);

	int B = findB(brandNewOrder);
	cout << B << endl;

	int A = findA(brandNewOrder, B);
	cout << A << endl;

	int C = findC(brandNewOrder, A , B);
	cout << C << endl;

	brandNewNewOrder = brandNewOrder;

	cout << brandNewOrder[C][0] << "    " << brandNewOrder[C][1] << "    " << brandNewOrder[C][2] << endl;

	brandNewOrder = cutBloc_woC(brandNewOrder, C, B);
	brandNewNewOrder = cutBloc_wC(brandNewNewOrder, C, B);

	PrintVect(brandNewOrder);
	PrintVect(brandNewNewOrder);
	*/

	

}
