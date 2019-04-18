#include<bits/stdc++.h>
using namespace std;

#define nax 30
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()
#define pb push_back

typedef vector<int> vi;

vi v[nax],ans;
vector<string> str;
bool util[nax], imp = false;
int vis[nax];

void dfs(int node){
	vis[node] = 1;
	for(int child:v[node]){
		if(vis[child]==1){
			imp = true;
		}else if(vis[child]==0){
			dfs(child);
		}
	}
	vis[node] = 2;
	ans.pb(node+'a');
}

int main(){
	int n; cin>>n;
	string s;

	memset(util,0,sizeof util);
	cin>>s;
	str.pb(s);
	REP(i,n-1){
		cin>>s;
		str.pb(s);
		int k =0;
		while(sz(str[i])>k && sz(str[i+1])>k &&str[i][k]==str[i+1][k]) k++;
		
		if(k<sz(str[i]) && (k<sz(str[i+1]))){
			v[str[i][k]-'a'].pb(str[i+1][k]-'a');
			util[str[i][k]-'a'] = true;
			util[str[i+1][k]-'a'] = true;
		}else{
			if(sz(str[i])>sz(str[i+1])) imp = true;
		}
	}

	memset(vis,0,sizeof vis);
	REP(i,nax){
		if(util[i] && !vis[i]){
			dfs(i);
		}
	}

	if(imp){
		cout<<"Impossible";
	}else{
		reverse(all(ans));
		REP(i,sz(ans)){
			printf("%c",ans[i]);
		}
		for(char c = 'a';c<='z';c++){
			if(!util[c-'a']) cout<<c;
		}
	}
	
	return 0;
}
