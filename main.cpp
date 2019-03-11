#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

using namespace std;


int main () {
    int zadania[] = {4, 0, 3, 1, 2};
    int kolejnosc[5]={};
    int maszyna1[] = {4, 4, 10, 6, 2};
    int maszyna2[] = {5, 1, 4, 10, 3};

    int n=sizeof(maszyna1)/sizeof(int); //liczba zadan

    long long silnia=1;

    int mspan = 32767;
    int mspan_m1[] = {5,9,31,0,4};
    int mspan_m2[] = {1,2,3,4,5};

    for (int i=n; i > 1; i--){
        silnia=silnia*i;
    }

    do {
        int *j, *k;
        j=k=zadania;
        k+=1;

        int M1time = maszyna1[*j]+maszyna1[*k];
        int M2time = maszyna1[*j]+maszyna2[*j];

        cout << *j << ' ';
        do {
            if(M1time>=M2time){
                j+=1;
                k+=1;
                M2time += (maszyna2[*j]+abs(M1time-M2time));
                M1time += maszyna1[*j];
            } else {
                j+=1;
                M1time += maszyna1[*j]+abs(M1time-M2time);
            }
            cout << *j << ' ';
        } while (j<&zadania[4]);

        if (M1time>=M2time) {
            M2time+=abs(M1time-M2time);
        }
        int pom=abs(k-j);
        while(pom>0){
            ++k;
            M2time+=*k;
            --pom;
        }

        if (( (M1time>M2time)?M1time:M2time )  < mspan ) {
            mspan = ( (M1time>M2time)?M1time:M2time );
            for(int x = 0; x < n; x++){
                mspan_m1[x]=maszyna1[ (zadania[x])];
                mspan_m2[x]=maszyna2[(zadania[x])];
                kolejnosc[x]=zadania[x];
            }
        }

        cout << '\n';
    } while ( next_permutation(zadania,zadania+n) );

    cout << "Elementow w tablicy: " << n << '\n';
    cout << "Mozliwych permutacji: " << silnia << '\n';
    cout << "Najkorzystniejsza permutacja: \n";
    for(int i = 0; i < n; ++i){
        cout << " | " << mspan_m1[i] ;
    }
    cout << " | \n |  " ;
    for(int i = 0; i < n; ++i){
        cout << " | " << mspan_m2[i] ;
    }
    //cout << "\nCzas wykonywania przegladu zupelnego:  " << mspan;
    cout << "\nKolejnosc wykonywania zadan na maszynie nr 1:   ";
    for(int i = 0; i < n; ++i){
        cout << kolejnosc[i]+1 << "   " ;
    }

    return 0;
}