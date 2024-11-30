#include "Header.h"

int task6(void) {
	cout << "task6\n";

	return 0;
}

//#include<iostream>
//#include<vector>
//#include<cstdlib>
//#include<ctime>
//
//using namespace std;
//
//int  task6(void) {
//    int n,i,j,k;
//    cin>>n;
//    vector < vector <int> > matr(n, vector <int> (n));
//    srand(time(NULL));
//    for (i = 0;i < n; i++) {
//        for (j = 0; j < n;j++) {
//            matr[i][j] = rand()%100;
//        }
//    }
//    for (i = 0;i < n; i++) {
//        for (j = 0; j < n;j++) {
//            cout<<matr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//    for (i=0;i<n;i++) {
//        for (k = 1;k < n; k+=2) {
//            for (j = k; j < n - 1;j++) {
//                swap(matr[i][j],matr[i][n-1]);
//            }
//        }
//    }
//    for (i = 0;i < n; i++) {
//        for (j = 0; j < n;j++) {
//            cout<<matr[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//    return 0;
//}
