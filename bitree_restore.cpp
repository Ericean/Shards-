#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;
const int MAX = 65550;
vector<int> midorder, postorder;
int ridx[MAX];
int btree[MAX];

//void dumpv(vector<int>& v){
//	for(auto& it: v)
//	cout << it << " ";
//	cout << endl;
//}

vector<int>::iterator poll(vector<int>& mo){
//we can make sure mo.size()>=2
	int max= ridx[mo.front()];
	auto i= mo.begin();
	for(auto it= mo.begin(); it< mo.end(); ++it){
		if(ridx[*it] > max){
			i= it;	max = ridx[*it];  
		}
	}	
	return i;
}


void restore(vector<int>& mo, int id){
	if(mo.empty()) return;
	if(mo.size()==1){
		//we use linear space to store btree
		//begin from index 0
		//so the left child of i is 2*i+1 and its right child is 2*(i+1)
		btree[id] = mo.back();
		return;
	}	
	auto it = poll(mo);
	btree[id] = *it;
	vector<int> lcd(mo.begin(), it);
	vector<int> rcd(++it, mo.end());
	restore(lcd, 2*id+1);
	restore(rcd, 2*id+2);

}

void previsit(int id){
	if(btree[id]==-1) return;
	cout << btree[id] <<" ";
	previsit(2*id+1);
	previsit(2*id+2);
}
	
int main()
{
	int label;
	string line;
	getline(cin, line);
	istringstream iss1(line);
	while(iss1 >> label) midorder.push_back(label);
	getline(cin, line);
	istringstream iss2(line);
	while(iss2 >> label) postorder.push_back(label);
	for(int i=0; i<postorder.size();++i)
	//we can assure item is at most MAX;
		ridx[postorder[i]]=i;
	for(int i=0; i<MAX;++i)
		btree[i] = -1;
	restore(midorder,0);
	previsit(0);
	cout << endl;

}



