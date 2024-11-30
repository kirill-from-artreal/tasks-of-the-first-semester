#include "Header.h"

int task5(void) {
	cout << "task5\n";

	return 0;
}


//#include<iostream>
//#include<vector>
//#include<cstdlib>
//#include<cstring>
//#include<string>
//#include<ctype.h>
//#include<stdlib.h>
//
//using namespace std;
//
//int  task5(void) {
//    string str,n="1",newstr,extstr;
//    int i,min,max,j,k;
//    cout << "Vvedite stroku" << endl;
//    getline(cin,str);
//    vector<int> probel;
//    vector<string> words;
//    vector<string> words2;
//    while (str[str.size()-1] == ' ') {
//        str.erase(str.size()-1);
//    }
//     while (str[0] == ' ') {
//        str.erase(0,1);
//    }
//    probel.push_back(0);
//    for (i=0;i<str.size();i++) {
//        if (str[i]==' ' && str[i+1]==' ') {
//            str.erase(i+1,1);
//            i--;
//        }
//        if (str[i]==' ' && str[i-1]!=' ') {
//            probel.push_back(i);
//        }
//    }
//    probel.push_back(str.size());
//    if (str.size() == 0) {
//    	cout << "stroka pustaya" << endl;
//    	return 0;
//	}
//    for (i=0;i<probel.size()-1;i++) {
//        if (i==0) {
//            words.push_back(str.substr(probel[i],probel[i+1] - probel[i]));
//        }
//        else {
//            words.push_back(str.substr(probel[i]+1,probel[i+1] - probel[i] - 1));
//        }
//    }
//    for (i=0;i<words.size();i++) {
//        k = 0;
//        extstr = words[i];
//        for (j=0;j<extstr.size();j++) {
//            if (isalpha(extstr[j])) {
//                k++;
//            }
//        }
//        if (extstr.size()==k) {
//            words2.push_back(words[i]);
//        }
//    }
//    for (i=0;i<words2.size();i++) {
//        if (i==0) {
//            min = words2[0].size();
//            max = words2[0].size();
//        }
//        if (words2[i].size()<min) {
//            min = words2[i].size();
//        }
//        if (words2[i].size()>max) {
//            max = words2[i].size();
//        }
//    }
//    if (min==max) {
//        cout << "vse slova odinakovoi dlini"<<endl;
//        for (i=0;i<=words.size();i++) {
//            cout<<words2[i]<<endl;
//        }
//        return 0;
//    }
//    cout <<"samie korotkie slova" << endl;
//    for (i=0;i<=words2.size();i++) {
//        if (min == words2[i].size()) {
//            cout<<words2[i]<<endl;
//        }     
//    }
//    cout <<"samie dlinnie slova" << endl;
//    for (i=0;i<=words2.size();i++) {
//        if (max == words[i].size()) {
//            cout<<words[i]<<endl;
//        }     
//    }
//    return 0;
//}