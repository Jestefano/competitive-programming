#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(v) int(v.size())
 
int main(){
	int b,p,f,h,c;
 
	int op1,op2,op3,op4;
 
	int cases; cin>>cases;
 
	int aux1,aux2;
	while(cases--){
		cin>>b>>p>>f>>h>>c;
 
		op1 = (b/2-p>=0)? p*h+c*min(b/2-p,f) : 0;
		op2 = (b/2-f>=0)? h*min(b/2-f,p) + f*c : 0;
		op3 = h*min(b/2,p);
		op4 = c*min(b/2,f);
 
		cout<<max(max(op1,op2),max(op3,op4))<<endl;
	}
	
	return 0;
}
