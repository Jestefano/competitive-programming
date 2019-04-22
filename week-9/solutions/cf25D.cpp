#include<bits/stdc++.h>
using namespace std;

#define nax 1009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

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
	
	int x = Parent(a), y = Parent(b);
	if(r[x]<r[y]){
		p[x] = y;
	}else{
		p[y] = x;
		if(r[x]==r[y]) r[x]++;
	}
}

int main(){
	int n; cin>>n;

	REP(i,n) CreateSet(i);

	REP(i,n-1){
		int a,b; cin>>a>>b;
		a--;b--;
		if(EqualSet(a,b)){
			edg.pb(mp(a,b));
		}else{
			UnionFind(a,b);
		}
	}

	if(edg.size()==0){
		cout<<0; return 0;
	}
	cout<<edg.size()<<endl;
	int w = 0;
	REP(i,n-1){
		if(!EqualSet(i,i+1)){
			cout<<edg[w].fst+1<<" "<<edg[w].snd+1<<" ";
			cout<<i+1<<" "<<i+2<<endl;
			w++;
			UnionFind(i,i+1);
		}
	}

	return 0;
}
