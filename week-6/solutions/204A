#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

typedef unsigned long long ll;

ll calc(ll n){
	ll tam_n = 0, n_;
	n_ = n;
	
	if(n<10){
		return n; 
	}
	if(n<100){
		return 9 + n/11;
	}

	while(n_!=0){
		n_=(n_/10); tam_n++;
	}

	ll rpta = 9, aux = 1;
	
	FOR(tam,2 ,tam_n){
		rpta += aux * 9;
		aux *= 10;
	}
	
	ll fin  = 0;
	FOR(i,2,11){
		if(i * (10 * aux) > n){
			fin = i;
			break;
		}else{
			rpta += aux;
		}
	}
	aux*=10;
	if((fin-1)<=(n%10)){
		rpta +=(n%aux)/10;
		rpta++;
	}else if(fin-1<n%aux){
		rpta +=(n%aux)/10;
	}
	
	return rpta;
}

int main(){
	ll a,b;

	//This is a brute force solution to the problem
  cin>>a>>b;
	cout<<calc(b)-calc(a-1);
	
	return 0;
}
