#include<bits/stdc++.h>
using namespace std;

#define max_ 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vi v[max_];
bool vis[max_],art[max_];
int low[max_],timer[max_],t=0,child_num = 0,art_points = 0;

void mini(int &a,int b){
	a = min(a,b);
}

void dfs(int node, int parent = -1){
	vis[node] = true;
	low[node] = timer[node] = t++;

	bool art_t = false;
	for(int child:v[node]){
		if(child==parent) continue;
		if(vis[child]){
			mini(low[node],timer[child]);
		}else{
			dfs(child,node);
			mini(low[node],low[child]);
			if(low[child]>=timer[node] && parent!=-1){
				art[node] = true;
				art_t = true;
			}
			if(parent==-1) child_num++;
		}
	}
	if(parent==-1 && child_num>1){
		art[node] = true;
		art_points++;
	}
	if(art_t==true){
		art_points++;
	}
}

int main(){
	int a,b,cont = 1;
	map<int,string> m;
	map<string,int> m_;

	while(cin>>a,a){
		if(cont!=1) cout<<endl;
		m.clear();
		m_.clear();
		REP(i,a){
			string s; cin>>s;
			m[i] = s;
			m_[s] = i;
			v[i].clear();
		}
		cin>>b;
		REP(i,b){
			string s1,s2; cin>>s1>>s2;
			int a1=m_[s1],a2 = m_[s2];
			v[a1].pb(a2);
			v[a2].pb(a1);
		}

		memset(vis,0,sizeof vis);
		memset(art,0,sizeof art);
		art_points = 0;
		REP(i,a){
			if(!vis[i]){
				t = 0; child_num = 0;
				dfs(i);
			}
		}

		cout<<"City map #"<<cont<<": "<<art_points<<" camera(s) found"<<endl;
		int fs = 0;
		REP(i,a){
			if(art[i]){
				if(fs){
					cout<<endl;
				}
				fs = 1;
				cout<<m[i];
			}
		}
		cont++;
	}

	return 0;
}
