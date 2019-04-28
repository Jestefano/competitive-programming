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

ii trans(string s){
	int m = (s[0]-'0')*10 + s[1]-'0';
	int d = (s[3]-'0')*10 + s[4]-'0';
	return mp(m,d);
}

int trans2(ii w){
	int dias = 0;
	if(w.fst>1) dias+=31;
	if(w.fst>2) dias+=28;
	if(w.fst>3) dias+=31;
	if(w.fst>4) dias+=30;
	if(w.fst>5) dias+=31;
	if(w.fst>6) dias+=30;
	if(w.fst>7) dias+=31;
	if(w.fst>8) dias+=31;
	if(w.fst>9) dias+=30;
	if(w.fst>10) dias+=31;
	if(w.fst>11) dias+=30;
	if(w.fst>12) dias+=31;
	dias+=w.snd;
	return dias;
}

void trans3(int num){
	int dias = num, m = 1;
	int t = 1;
	if(num==0){
		cout<<"12-31"<<endl;
		return;
	}
	while(t--){
		if(dias>31){//1
			dias-=31; m++;
		}else break;
		if(dias>28){//2
			dias-=28; m++;
		}else break;
		if(dias>31){//3
			dias-=31; m++;
		}else break;
		if(dias>30){//4
			dias-=30; m++;
		}else break;
		if(dias>31){//5
			dias-=31; m++;
		}else break;
		if(dias>30){//6
			dias-=30; m++;
		}else break;
		if(dias>31){//7
			dias-=31; m++;
		}else break;
		if(dias>31){//8
			dias-=31; m++;
		}else break;
		if(dias>30){//9
			dias-=30; m++;
		}else break;
		if(dias>31){//10
			dias-=31; m++;
		}else break;
		if(dias>30){//11
			dias-=30; m++;
		}
		else break;
		if(dias>31){//12
			dias-=31; m++;
		}else break;
	}
	printf("%02d-%02d\n",m,dias);
}

//Despues de 27 de octubre
int main(){
	int n; cin>>n;
	string s1,s2;

	set<int> s;
	REP(i,n){
		cin>>s1>>s2;
		s.insert(trans2(trans(s2)));
	}

	vi v;

	for(set<int>::iterator it = s.begin();it!=s.end();it++){
		v.pb(*it);
	}

	int m = 0;
	REP(i,sz(v)){
		m = max((v[(i+1)%sz(v)]-v[i]+365)%365,m);
	}
	int w = 0;
	while(w<sz(v)&&v[w]<=301){
		w++;
	}

	REP(i,sz(v)){
		if((365+v[(i+w)%sz(v)]-v[(i+w+sz(v)-1)%sz(v)])%365==m){
			trans3(v[(i+w)%sz(v)]-1);
			break;
		}
	}

	return 0;
}
