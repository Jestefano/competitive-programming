#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

int main(){
	//Casos variados de BS:
	//f(x) monotona, continua en [a,b] que contiene a la rpta
	/*
	Problema con double:
	No se puede usar ==
		------------------
		eps = 1e-9
		Se usa en su lugar abs(ans-valor_busq_bin)<eps
		------------------
		Poner un numero de iteraciones fijo, por ejemplo,
		40 iteraciones.
	*/

	//Main theorem:
	/*
	S: conjunto totalmente ordenado -> Piensenlo como una recta
	f:S -> {0,1} ... Piensa en una pregunta -> Si/no
	Existe un x0 tal que f(x) = 1 para x < x0
	y f(x) = 0 para x > x0
	Entonces se puede aplicar busqueda binaria!!
	*/

	/*
	binary_search(lo, hi, p):
	   while lo < hi:
	      mid = lo + (hi-lo)/2
	      if p(mid) == true:
	         hi = mid
	      else:
	         lo = mid+1
	          
	   if p(lo) == false:
	      complain                // p(x) is false for all x in S!
	      
	   return lo      
	*/

	return 0;
}