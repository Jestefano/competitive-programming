#include<bits/stdc++.h>
using namespace std;

int main(){
	//Par ordenado
	pair<int,int> p;

	//Asi se guarda un dato
	p = make_pair(10,10);
	
	cout<<p.first<<endl;
	cout<<p.second<<endl;

	/*
	pair<int,pair<int,int> > p;
	p.first; p.second.first; p.second.second;
	*/

	return 0;
}