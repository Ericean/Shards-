#include <iostream>
using namespace std;

void move(int pidx, char from, char to){
	cout<<pidx<<":"<<from<<"->"<<to<<"\n"; 
}

void hanoi(int n, char from, char via, char to){

	if(n==1) move(1, from, to); 
	else {
		//we need to figure out a way to move first (n-1)th plates 
		//from a to b via c
		hanoi(n-1, from, to, via);
		move(n, from, to);
		hanoi(n-1, via,from, to);
	}
}
int main()
{
	int num; char from, via,to;
	cin>> num>>from>>via>>to;
        hanoi(num, from, via, to);
}
