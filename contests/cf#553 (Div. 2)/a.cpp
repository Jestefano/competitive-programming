#include<bits/stdc++.h>
using namespace std;

#define nax 60
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

const int mod = 1000000007;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

int mini[nax][4];

int main(){
	int n; cin>>n;
	string s; cin>>s;

	string gen = "ACTG";
	REP(i,n){
		REP(j,4){
			int rpta = 0;
			int aux = s[i],k = 0;
			while(aux!=gen[j]){
				if(aux=='A') aux = 'Z';
				else aux--;
				k++;
			}
			rpta = k;
			k = 0;
			aux = s[i];
			while(aux!=gen[j]){
				if(aux=='Z') aux = 'A';
				else aux++;
				k++;
			}
			rpta = min(rpta,k);

			mini[i][j] = rpta;
		}
	}

	int w =1e9;
	REP(i,sz(s)-3){
		int aux = mini[i][0] + mini[i+1][1] + mini[i+2][2] + mini[i+3][3];
		w= min(w,aux);
		
	}

	cout<<w<<endl;

	return 0;
}
