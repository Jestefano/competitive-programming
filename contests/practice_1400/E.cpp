/*
https://vjudge.net/contest/322571#problem/E
Solution: Huffman coding
Greedy. Think the problem in reversal order.
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 3009
#define FOR(i,n,m) for(int i=(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	int n; cin>>n;

	set<ii> s;
	REP(i,n){
		int a; cin>>a;
		s.insert(mp(a,i));
	}

	ll tot = 0;
	while(sz(s)>2){
		ii w = *(s.begin());
		s.erase(w);
		ii k = *(s.begin());
		s.erase(k);

		tot*=2;
		tot+=w.fst+k.fst;
		s.insert(mp(w.fst+k.fst,k.snd));
	}

	cout<<tot<<endl;

	return 0;
}
