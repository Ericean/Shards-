#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool is_stack_order(vector<int> xs)
{
	vector<int> aux;
	int recentidx = 1;
	bool isinorder = true;
	for(auto item: xs){
		if(recentidx <= item){
			for(int i= recentidx; i<= item ; ++i)
				aux.push_back(i);	
		   recentidx = item+1; 
		}

		//cout << "recent: "<< recentidx << " item: "<< item <<endl;
		//you need to pop
		//first check if the top matches
		if(aux.back() == item )
			aux.pop_back();
		else{
			isinorder= false;
			break;
		}
	}
	return isinorder;

}

int main()
{ 
	int nsamples; cin >>  nsamples;
	int nums_per_sample ; 
	vector<int> xs;
	vector<bool> rets;
	for(size_t j=0; j< nsamples; ++j){
		cin >> nums_per_sample;
		for(size_t i=0 ; i<  nums_per_sample; ++i){
			int d ; cin >> d;
			xs.push_back(d);
		}
		rets.push_back(is_stack_order(xs));
		xs.clear();
	}
	for(auto s: rets)
		if(s) cout << "yes"<< endl;
		else cout <<"no"<< endl;
}

