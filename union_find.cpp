#include<iostream>
#include <vector>

const int MAX =20;
int roots[MAX];
//root
//find until the very top 
int root(int item){
	while(item != roots[item]) item = roots[item];
	return roots[item];
}
//find 
//if the root index of two elements happens to be the same
//then we conclude they're in the same set 
//and returns true 
bool find(int p, int q){
	if(root(p) == root(q))return true;
	return false;
}

//union 
//set one root to be the other's root 
void unite(int p, int q)
{
	roots[root(p)] = root(q);
}
int main()
{
	for(int i=0; i< MAX; ++i)
		roots[i]= i;
	unite(2,3);
	unite(0,19);
	unite(0,2);
	unite(2,18);
	std::cout << "unite 2,3,0,19,2,18: check 3,19: " << find(3,19) << std::endl;
	std::cout << "unite 2,3,0,19,2,18: check 3,19: " << find(0,2) << std::endl;
	for(int i=0; i< MAX; ++i)
		std::cout << "roots at "<< i <<" : "<< roots[i] << std::endl;
}
