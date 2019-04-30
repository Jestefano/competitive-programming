#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main(){
	int n,k; cin>>n>>k;
	vector<int> v(n);
	REP(i,n) cin>>v[i];

	int l = 0,r =1;
	int m = 0;
	int cont = (v[0]==0)?1:0;

	int posi = 0, posf =0;

	if(k==0){
		int aux = 0;
		REP(i,n){
			if(v[i]){
				aux++;
				m = max(m,aux);
			}else aux =0;
		}
		cout<<m<<endl;
		REP(i,n){
			if(i) cout<<" ";
			cout<<v[i];
		}
		return 0;
	}

	m = 1;
	while(r<n){
		if(v[r]==0){
			if(cont==k){
				if(v[l]==0) cont--;
				l++;
			}else{
				cont++;
				if(m<r-l+1){
					m = r-l+1;
					posf = r; posi = l;
				}
				r++; 
			}
		}else{
			if(m<r-l+1){
				m = r-l+1;
				posf = r; posi = l;
			}
			r++;
		}
	}

	cout<<m<<endl;
	REP(i,n){
		if(i) cout<<" ";
		if(i<posi||i>posf) cout<<v[i];
		else cout<<1;
	}
	cout<<endl;

	return 0;
}
