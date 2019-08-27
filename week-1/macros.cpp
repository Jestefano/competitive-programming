/*
Prog competitiva:
- Disenio de algoritmos
- Implementarlo

C++ / Python

C++ 
//Problema para teoria de numeros
long long ->2^64 -> 10^18
factorial(n)
Ch(100,5)

//Python es mas lento, pero aguanta mas en tamanio


*/

/*
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<pair>
#include<stack>
#include<queue>
*/


#include<bits/stdc++.h>
//Cuidado: En algunos compiladores (raros) no compila
using namespace std;

//Macro
#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
//unsigned int

int main(){
	int x; 
	REP(i,10) cout<<i<<endl;
	
	vector<int> v;
	v.pb(10);
	cout<<sz(v);

	FOR(i,3,6) cout<<10-i<<endl;
}