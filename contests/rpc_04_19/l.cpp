#include<bits/stdc++.h>
using namespace std;

#define nax 5
#define FOR(i,n,m) for(ll i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	string s[nax];

	REP(i,nax){
		cin>>s[i];
	}

	int m = 0;
	REP(i,nax){
		int tem = 1;
		REP(j,nax){
			if(i==j) continue;
			if(s[i][0]==s[j][0]){
				tem++;
			}
		}
		m = max(m,tem);
	}

	cout<<m<<endl;

	return 0;
}
