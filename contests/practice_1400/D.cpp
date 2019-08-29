/*
https://vjudge.net/contest/322571#problem/D
Binary search + Simulation
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
#define snd second
#define fst first
#define all(v) v.begin(),v.end()

typedef vector<int> vi;

int main(){
	int n,r;

	while(cin>>r>>n){
		if(n==-1&&r==-1) continue;
		vi v(n);
		REP(i,n) cin>>v[i];

		sort(all(v));
		int w = 0, cont = 0;
		while(w<n){
			int pos = upper_bound(all(v),v[w]+r)-v.begin();
			pos--;
			int final = upper_bound(all(v),v[pos]+r)-v.begin();
			final--;
			w = final+1;
			
			cont++;
		}
		cout<<cont<<endl;
	}


	return 0;
}
