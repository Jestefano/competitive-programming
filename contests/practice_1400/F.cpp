/*
https://vjudge.net/contest/322571#problem/F
Exchange argument
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define nax 109
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()

typedef vector<long long> vi;

bool comp(int a,int b){
	return a>b;
}

int main(){
	int n; 

	while(cin>>n){
	
		vi v(n),w(n);
		REP(i,n) cin>>v[i];
		REP(i,n) cin>>w[i];
	
		sort(all(v));
		sort(all(w),comp);
	
		long long m = 0;
		REP(i,n) m+=v[i]*w[i];
		cout<<m<<endl;
		
	}
	return 0;
}
