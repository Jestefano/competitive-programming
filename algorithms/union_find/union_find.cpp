#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef pair<int,int> ii;

//Union find
int p[nax],r[nax];
vector<ii> edg;

int Parent(int a){
	return (p[a]==a)? a: p[a] = Parent(p[a]);
}

bool EqualSet(int a,int b){
	return Parent(a)==Parent(b);
}

void CreateSet(int n){
	p[n] = n; r[n] = 0;
}

void UnionFind(int a,int b){
	if(EqualSet(a,b)) return;
	int x = Parent(a), y = Parent(b);
	if(r[x]<r[y]){
		p[x] = y;
	}else if(r[x]==r[y]){
		p[x] = y; r[y]++;
	}else{
		p[y] = x;
	}
}

int main(){
	int n,m; cin>>n;

	REP(i,n) CreateSet(i);

	//And do what you need!
	
	return 0;
}
