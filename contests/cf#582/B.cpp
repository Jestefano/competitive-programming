/*
Start from the end
If it is not the min number -> We add one
If it is a new min, we update the previous min
*/

#include<bits/stdc++.h>
using namespace std;

#define nax 3009
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vi v(n);
		REP(i,n) cin>>v[i];
		
		int cont = 0;
		int m = v[n-1];
		for(int i = n-1;i>=0;i--){
			if(v[i]>m){
				cont++;
			}else m = v[i];
		}
		cout<<cont<<endl;
	}


	return 0;
}
