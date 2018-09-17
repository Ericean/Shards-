#include<iostream>
#include<string>
//When the Gale-Shapley algorithm runs, there are at least two kinds of info needs to tracked
//1. A certain man is free or not 
//2. Next woman a certain man is gonna propose

const int C = 4;

int M2W[C][C] ={{3,1,2,0}, {1,0,2,3}, {0,1,2,3},{3,1,2,0}};
int W2M[C][C] ={{0,1,2,3},{0,1,2,3},{0,1,2,3},{3,1,2,0}};

int m2w[C][C];
int w2m[C]= { -1, -1, -1, -1};

bool is_a_free(int man)
{
	for(int i=0; i< C; ++i) if(m2w[man][i] == 1)return false;
	return true;
}


//if none returns -1 orelse returns idx of the free man 
int man_is_free(){
	for(int i= 0; i<C;  ++i)
		if(is_a_free(i))return i;
	return -1;
}

//if none returns -1 or else returns idx of the next woman the man shoule propose to
//stable marriage guarantee whenever there is a free man, there has to be some woman he has not proposed to 
int woman_not_being_proposed_for_certain(int man){
	int idx = 0;
	for(; idx < C; ++idx){
		if(m2w[man][idx]==0) break;
	}
	return idx;
}

//returns true on engaged  
bool propose(int man, int woman){
	//if woman is not engaged 
	if(w2m[woman]==-1)return true;

	int idxp=0, idxc=0;
	for(; idxp<C; ++idxp) 
		if(W2M[woman][idxp] == w2m[woman])break;
	for(; idxc<C; ++idxc) 
		if(W2M[woman][idxc] == man)break;

	//if the newly man has a lower prio
	if(idxp< idxc) return false;
	else{
		//unengaged with the old man
		for(int i=0; i< C; ++i)
			if(m2w[w2m[woman]][i] ==1)  m2w[w2m[woman]][i] =-1;
		return true;
	} 

}

int main()
{
	int m;
	while((m=man_is_free())!=-1){
		std::cout << m << " is free\n";
		for(int w = woman_not_being_proposed_for_certain(m); w<C  ; ++w){
			//onece engaged, stop proposing to any other
			if (propose(m, M2W[m][w])){
				m2w[m][w] = 1;// engaged
				w2m[M2W[m][w]] = m;
				break;
			}
			m2w[m][w] =-1; //proposed already
		}
	}
	for(int i=0; i<C; ++i) std::cout<< i << " : "<< w2m[i] << "\n";
}	
