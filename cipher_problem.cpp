#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 250;
char msg[MAX]={'\0'};
char cipher[MAX]={'\0'};
int keys[MAX];
int numk;

int main()
{ 
	while(cin>>numk && numk!=0){
		//parse numk
		//parse keys;
		int k;
		for(int i= 0; i< numk; ++i){
			cin >> k ;
			keys[i]=k;
		}
		int cycle[MAX]={0};
		//count cycles per element 
		for(int i=0; i< numk; ++i){
			//j= next position to go for ith element
			int j= keys[i]-1;
			while(keys[j]!= keys[i]){
				cycle[i]++;
				//next to next position to go for ith element
				j = keys[j]-1;
			}
			cycle[i]++;
		}
		//for(int i=0; i< numk; ++i)
		//	cout << cycle[i] <<" ";
		//cout << endl;
		//parse times;
		int times; 
		char c; 
		while(cin >> times&& times!=0){
			cin.ignore();
			cin.getline(msg,MAX,'\n');
			for(int k=strlen(msg); k< numk; ++k) msg[k] = ' ';
			//cout << msg << " times: "<< times <<endl;
			//encrypt the msg for times 
			int j;
			for(j=0; j< numk; ++j){
				int idx = j; 
				for(int i=0; i<	times%cycle[j]; ++i){
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
