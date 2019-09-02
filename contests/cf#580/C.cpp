/*
First thing to notice: It is impossible for two consecutive sums to be equal
Then the opposite sides differ in one.
After that we think what happens if we change the order of the numbers 
(as arrows)
*/
#include<bits/stdc++.h>
using namespace std;
 
#define nax 1000
#define FOR(i,n,m) for(ll i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
#define sz(v) int(v.size())
#define all(v) v.begin() , v.end()
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
 
int main(){
	int n; cin>>n;
	if(n%2==0) cout<<"NO";
	else{
		vi v(2*n);
		REP(i,n){
			if(i%2==0){
				v[i] = 2*i+1;
				v[n+i] = 2*i+2;
			}else{
				v[i] = 2*i+2;
				v[n+i] = 2*i+1;
			}
		}
		cout<<"YES"<<endl;
		REP(i,2*n){
			if(i) cout<<" ";
			cout<<v[i];
		}
	}
 
	return 0;
}
