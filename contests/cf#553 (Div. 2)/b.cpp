#include<bits/stdc++.h>
using namespace std;

#define nax 509
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int main(){
	long long  n,m,tab[nax][nax];
	cin>>n>>m;

	long long aux;
	REP(i,n){
		REP(j,m){
			cin>>tab[i][j];
			if(i==0 && j==0) aux = tab[i][j];
			if(i!=0 && j==0) aux ^= tab[i][j];
		}
	}

	if(aux!=0){
		cout<<"TAK"<<endl;
		REP(i,n){
			if(i) cout<<" ";
			cout<<1;
		}
		return 0;
	}

	long long pos = 1,pos_,w;

	REP(i,n){
		long long temp = aux^tab[i][0];
		
		REP(j,m){
			w = temp;
			w ^= tab[i][j];
			if(w!=0){
				pos = j; pos_ = i;
				break;
			}
		}
		if(w!=0) break;
	}

	if(w!=0){
		cout<<"TAK"<<endl;
		REP(i,n){
			if(i==pos_) cout<<pos+1<<" ";
			else cout<<1<<" ";
		}
	}else{
		cout<<"NIE";
	}

	return 0;
}
