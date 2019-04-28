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
	ll n; cin>>n;
	string s; cin>>s;
	ll a = 0, b= 0, c = 0;
	REP(i,n){
		if(s[i] == 'A') a++;
		if(s[i] == 'B') b++;
		if(s[i] == 'C') c++;
	}

	ll at[3],bt[3],ct[3];
	memset(at,0,sizeof at);
	memset(bt,0,sizeof bt);
	memset(ct,0,sizeof ct);
	REP(i,n){
		if(i<a){
			if(s[i] == 'A') at[0]++;
			if(s[i] == 'B') bt[0]++;
			if(s[i] == 'C') ct[0]++;
		}else if(i<a+b){
			if(s[i] == 'A') at[1]++;
			if(s[i] == 'B') bt[1]++;
			if(s[i] == 'C') ct[1]++;
		}else{
			if(s[i] == 'A') at[2]++;
			if(s[i] == 'B') bt[2]++;
			if(s[i] == 'C') ct[2]++;
		}
	}//ABC

	//Aqui sale la config 1
	ll ans = n*n;
	REP(i,n){
		ll temp = 0;
		temp = bt[0]+ct[0]+at[1]+ct[1]+at[2]+bt[2];
		ans = min(ans,temp);

		//Transicion:
		//De A a B
		if(s[(i+a)%n] == 'A'){
			at[0]++; at[1]--;
		}
		if(s[(i+a)%n] == 'B'){
			 bt[0]++; bt[1]--;
		}
		if(s[(i+a)%n] == 'C'){
			ct[0]++; ct[1]--;
		}

		//De B a C
		if(s[(i+a+b)%n] == 'A'){
			at[1]++; at[2]--;
		}
		if(s[(i+a+b)%n] == 'B'){
			 bt[1]++; bt[2]--;
		}
		if(s[(i+a+b)%n] == 'C'){
			ct[1]++; ct[2]--;
		}

		//De C a A
		if(s[(i)%n] == 'A'){
			at[2]++; at[0]--;
		}
		if(s[(i)%n] == 'B'){
			 bt[2]++; bt[0]--;
		}
		if(s[(i)%n] == 'C'){
			ct[2]++; ct[0]--;
		}
	}

	//conf 2
	memset(at,0,sizeof at);
	memset(bt,0,sizeof bt);
	memset(ct,0,sizeof ct);
	REP(i,n){
		if(i<b){
			if(s[i] == 'A') at[0]++;
			if(s[i] == 'B') bt[0]++;
			if(s[i] == 'C') ct[0]++;
		}else if(i<a+b){
			if(s[i] == 'A') at[1]++;
			if(s[i] == 'B') bt[1]++;
			if(s[i] == 'C') ct[1]++;
		}else{
			if(s[i] == 'A') at[2]++;
			if(s[i] == 'B') bt[2]++;
			if(s[i] == 'C') ct[2]++;
		}
	}//BAC

	//Simulacion:
	//b, a, c
	REP(i,n){
		ll temp = 0;
		temp = at[0]+ct[0]+bt[1]+ct[1]+at[2]+bt[2];
		ans = min(ans,temp);

		//Transicion:
		//De B a A
		if(s[(i+b)%n] == 'A'){
			at[0]++; at[1]--;
		}
		if(s[(i+b)%n] == 'B'){
			 bt[0]++; bt[1]--;
		}
		if(s[(i+b)%n] == 'C'){
			ct[0]++; ct[1]--;
		}

		//De B a C
		if(s[(i+a+b)%n] == 'A'){
			at[1]++; at[2]--;
		}
		if(s[(i+a+b)%n] == 'B'){
			 bt[1]++; bt[2]--;
		}
		if(s[(i+a+b)%n] == 'C'){
			ct[1]++; ct[2]--;
		}

		//De C a A
		if(s[(i)%n] == 'A'){
			at[2]++; at[0]--;
		}
		if(s[(i)%n] == 'B'){
			 bt[2]++; bt[0]--;
		}
		if(s[(i)%n] == 'C'){
			ct[2]++; ct[0]--;
		}
	}

	cout<<ans<<endl;


	return 0;
}
