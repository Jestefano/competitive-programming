#include<bits/stdc++.h>
using namespace std;

#define nax 4
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
	int s[nax], p=0;

	REP(i,nax){
		cin>>s[i];
		p+=s[i];
	}
	double p_ = p*1.0/2;

	double d = sqrt((p_-s[0]*1.0)*(p_-s[1]*1.0)*(p_-s[2]*1.0)*(p_-s[3]*1.0));

	printf("%.10f\n",d);

	return 0;
}
