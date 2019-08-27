#include<bits/stdc++.h>
using namespace std;
 
#define nax 30
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define sz(v) int(v.size())
 
typedef long long ll;
typedef vector<ll> vi;
 
int main(){
	string s,t; cin>>s>>t;
	int c1[nax],c2[nax];
 
	memset(c1,0,sizeof c1);
	memset(c2,0,sizeof c2);
	REP(i,sz(s)){
		c1[s[i]-'a']++;
	}
	REP(i,sz(t)){
		c2[t[i]-'a']++;
	}
 
	bool x = true;
	REP(i,nax){
		if(c1[i]<c2[i]){
			cout<<"need tree";
			return 0;
		}
		if(c1[i]>c2[i]){
			x = false;
		}
	}
 
	if(x){
		cout<<"array";
		return 0;
	}
 
	int w = 0;
	REP(i,sz(s)){
		if(w<sz(t) && s[i]==t[w]){
			w++;
		}
		if(w==sz(t)) break;
	}
 
	if(w==sz(t)) cout<<"automaton";
	else cout<<"both";
  //Compare character by character
 
	return 0;
}
