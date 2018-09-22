#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

const int MAX  = 200;

vector<int> key;
vector<vector<string> > blks;

void parse(vector<string>& blk){
	int num=0; 
	int inversions=0;
	//blk is empty
	if(blk.size() ==1) return;	
	num = stoi(blk[0]);

	int k,i=0;
	istringstream iss(blk[1]);
	while(iss>>k){
		key.push_back(k);
		if(k!= i+1) ++inversions;
		++i;
	}		 

	for(int i=2; i<blk.size(); ++i){
		int times;
		string t, orig_msg;
		bool isnum =true;
		for(auto& c: blk[i]){
			if(isnum && c ==' ') {isnum = false;continue;}
			if(isnum) t+=c;
			else orig_msg+=c;
		}
		times = stoi(t);
		times = times -(times/inversions)*inversions;
		orig_msg.resize(num,' ');
		//cout <<"Inversions: "<< inversions <<" be about to encrypt orig_msg: "<< orig_msg << " with size:  "<<orig_msg.size()<<"for "<<  times <<" times\n";
		string cipher_msg(num,' ');
		for(int i= 0; i< times; ++i){
			for(int j=0; j<num ; ++j){
				cipher_msg[key[j]-1] = orig_msg[j];
			}
			orig_msg.swap(cipher_msg);
		}
		cout << orig_msg <<endl;
	}
	key.clear();
}

int main()
{ 
	string line;
	bool inblock= false;
	vector<string> blk; 
	while(getline(cin,line)){
		//start read the first block;
		if(line.at(0) =='0'){
			if(inblock){
				//one block has been read completely
				inblock = false;
				blks.push_back(blk);
				blk.clear();
			}
			else break;
		}else{
			inblock = true;
			blk.push_back(line);
		}
	}
	for(auto& blk: blks) parse(blk);
}
