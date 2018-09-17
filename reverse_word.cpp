#include <iostream>
#include <string>
using namespace std;

string reverse(string word){
	string tmp(word);
	int len= tmp.length();
	for(int i=0; i< len; ++i)
		tmp[len-i-1]= word[i];
	return tmp;
}
int main()
{	
	string stnce; getline(cin, stnce);
	string w;
	for(int i=0; i<stnce.length();++i){
		char c = stnce[i];
		if(c!=' ') w+=c;
		if(c ==' '|| i+1==stnce.length()){
			cout << reverse(w) <<" ";
			w.clear();
		}
	}

}
