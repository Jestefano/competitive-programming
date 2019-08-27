#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

//factorial
int f(int n){
	//Estoy asumiendo que n>=0 y n es entero
	if(n==0) return 1;
	else{
		return f(n-1)*n;
	}
}

int fibo(int n){
	if(n<=1) return 1;
	else{
		return fibo(n-1) + fibo(n-2);
	}
}

int main(){
	int n; cin>>n;
	vector<int> v(n);

	REP(i,n) cin>>v[i];//O(n)

	REP(i,n){//0...n
		FOR(j,i,n){//i...n
			cout<<i+j<<endl;//O(n^2)
			//A veces es necesario tener en cuenta la cte
		}
	}

	/*
	n<=10^4
	-> O(n^2) -> 10^8
	
	//C++ hace 10^8 operaciones en 1 seg.
	Tu cte tiene que ser < 10 
	9*n^2
	*/

	int m = 0; cin>>m;

	REP(i,n){
		REP(j,m){
			cout<<i+j;//m*n
		}
	}

	//Recursion:
	f(n)//Tiene complejidad O(n);

	fibo(n)//O(2^n)

	//pag 30 del pdf
	/*Centrate en el limite de n y que complejidades 
	permite*/
	
	return 0;
}