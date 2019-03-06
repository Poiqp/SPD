#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include "task.h"
#include "pch.h"

using namespace std;

int main()
{
   
	vector<task> zadania;
	
	// dodawanie zdań 
	task zad_1(2, 4, 1);
	task zad_2(4, 2, 2);
	task zad_3(3, 6, 3);

	zadania.push_back(zad_1);
	zadania.push_back(zad_2);
	zadania.push_back(zad_3);

	sort(zadania.begin, zadania.end );

do {
	cout << zadania.at(0).id << ' ' << zadania.at(1).id << ' ' << zadania.at(2).id << '\n';
} while (next_permutation(zadania.at.begin, zadania.at.end));

cout << "After loop: " << zadania.at(0).id << ' ' << zadania.at(1).id << ' ' << zadania.at(2).id << '\n';

return 0;

}