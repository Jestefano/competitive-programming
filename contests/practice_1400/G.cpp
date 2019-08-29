/*
Map from rows to numbers. Then brute force
https://vjudge.net/contest/322571#problem/G
*/
#include <iostream>
#include<vector>
using namespace std;

#define nax 109
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()
#define pb push_back
#define sz(v) int(v.size())

typedef vector<long long> vi;


int main(){
	int t; cin>>t;
	int p = 1;

	vi v;
	while(t--){
		v.clear();
		int n; cin>>n;
		REP(i,n){
			string s; cin>>s;
			int w = 0;
			REP(j,n){
				if(s[j]=='1') w = j; 
			}
			v.pb(w+1);
		}

		int ans = 0;
		REP(i,n){
			if(v[i]<=i+1) continue;
			FOR(j,i+1,n){
				if(v[j]<=i+1){
					for(int k = j;k>i;k--){
						int aux = v[k];
						v[k] = v[k-1];
						v[k-1] = aux;
						ans++;
					}
					break;
				}
			}
		}
		
		cout<<"Case #"<<p++<<": ";
		cout<<ans<<endl;
	}

	return 0;
}
