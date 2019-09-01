#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

typedef vector<ll> vi;

long long dp[100];

long long fibo(int n){
	if(n<2) return 1LL;
	else if(dp[n]!=-1) return dp[n];
	else{
		long long aux = fibo(n-1) + fibo(n-2);
		dp[n] = aux;
		return dp[n];
	}
}

int main(){
	/*
	Dado un problema recursivo con subproblemas que se repiten ->
	Lo guardamos en memoria:
		- Factorial: No clasifica como DP
		- Fibonacci: Si clasifica como DP

	Es util:
		- Conteo
		- Optimizacion: Minimo o maximo
		- Si/No (Juego)
		Empezar con una estrategia greedy -> DP
	
	Fibonacci:
	*/
	REP(i,100) dp[i] = -1LL;
	cout<<fibo(4);

	//fibo(6)
	long long dpIt[100];
	dpIt[0] = 1;
	dpIt[1] = 1;
	FOR(i,2,6+1){
		dpIt[i] = dpIt[i-1] + dpIt[i-2];
	}

	cout<<dpIt[6];


	return 0;
}