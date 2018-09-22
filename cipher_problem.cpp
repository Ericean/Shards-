#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
const int MAX = 201;
char msg[MAX];
char cipher[MAX];
int keys[MAX];
int numk;
int inversions=0;

int main()
{ 
	while(cin>>numk && numk!=0){
		//parse numk
		//parse keys;
		int k;
		for(int i= 0; i< numk; ++i){
			cin >> k ;
			keys[i]=k;
			if(k!= i+1) ++inversions;
		}
		//parse times;
		int times; 
		char c; 
		while(cin >> times&& times!=0){
			getchar();
			gets(msg);
			for(int k=strlen(msg); k< numk; ++k) msg[k] = ' ';
			//cout << msg << " times: "<< times <<endl;
			//encrypt the msg for times 
			int j;
			for(j=0; j< numk; ++j){
				int idx = j; 
				for(int i=0; i<	times%inversions; ++i){
					idx = keys[idx] -1; 
				}
				cipher[idx] =msg[j];

			}
			cipher[j]= '\0';
			cout << cipher << endl;
		}
		cout << endl;

	}
}
