/*
Idea: We are trying to find the distance (BS)
Then, given a distance, we apply two pointers, whether it's possible or not.
*/
#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define sz(v) int(v.size())
#define snd second
#define fst first

typedef vector<int> vi;

int main(){
	int n; cin>>n;
	vi v(n);

	map<int,int> check;
	REP(i,n) cin>>v[i];


	bool pos = false;
	int l = 0, t = n;
	while(t-l>1){
		int m = (l+t)/2;
		check.clear();

		REP(i,n) check[v[i]]++;
		//We start proving with size m:
	
		pos = false;
		int cont = 0;
		REP(i,m){
			check[v[i]]--;
			if(check[v[i]]==0) check.erase(v[i]);
		}

		for(auto it = check.begin();it!=check.end();it++){
			if(it->snd>1) cont++;
		}
		
		if(cont==0){
			pos = true;
		}else{
			REP(i,n){
				if(check[v[i]]==1) cont++;
				check[v[i]]++;
				
				if(i+m<n){
					if(check[v[i+m]]==2) cont--;
					check[v[i+m]]--;
				}
	
				if(cont==0){
					pos = true; break;
				}
			}
		}

		if(pos) t = m;
		else l = m;
	}

	//Se intenta con l
	check.clear();

	REP(i,n) check[v[i]]++;
	//We start proving with size m:

	pos = false;
	int cont = 0;
	REP(i,l){
		check[v[i]]--;
	}

	for(auto it = check.begin();it!=check.end();it++){
		if(it->snd>1) cont++;
	}
	
	if(cont==0){
		pos = true;
	}else{
		REP(i,n-l+1){
			check[v[i]]++;
			if(check[v[i]]>1) cont++;
			
			if(i+l<n){
				check[v[i+l]]--;
				if(check[v[i+l]]==1) cont--;
			}

			if(cont==0){
				pos = true; break;
			}
		}
	}
	if(pos) cout<<l<<endl;
	else cout<<t<<endl;

	return 0;
}
