#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct range{
public:
	int  s, e;
	range(){}
	range(int s, int e):s{s}, e{e}{}
	bool operator<(const range& r) const{
		return s <= r.s;
			
	}
};

ostream& operator<<(ostream& os, const range& r){
	os<< r.s << " " <<r.e;
	return os;

}

bool canmergewith(const range& f , const range& s){
	return s.s <= f.e;
}

range merge(const range& f , const range&  s){
	int mergede= max(f.e, s.e);
	return range(f.s, mergede);
}

int main()
{
	vector<range> xs;
	int num; cin >> num;
	int s, e;
	for(int i=0; i< num; ++i){
		cin >> s >> e;
		xs.push_back(range(s, e));
	}
	sort(xs.begin(), xs.end());
	range last = xs.front();	
	range current;
	bool merged = true;
	for(int i=1 ; i< xs.size(); ++i){
		current = xs[i];
		if(!canmergewith(last, current)) {
			merged = false;
		}
		last =  merge(last, current);
	}
	if(merged)cout << last <<endl;
	else cout << "no" << endl; 

}
