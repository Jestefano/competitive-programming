/*
https://vjudge.net/contest/322571#problem/C
Simulation
*/
#include <iostream>
#include<vector>
using namespace std;

#define nax 109
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()
#define pb push_back
#define sz(v) int(v.size())

typedef vector<long long> vi;


int main(){
	int n; 
	

	while(cin>>n){

	vector<char> v(n);
		REP(i,n) cin>>v[i];

		int i = 0, j = n-1;

		string ans ="";
		while(i<j){
			if(v[i]<v[j]){
				ans+=v[i++];
			}else if(v[j]<v[i]){
				ans +=v[j--];
			}else{
				int k = 1;
				while(k<(j-i+2)/2 && v[i+k]==v[j-k]) k++;

				if(i+k<j && v[i+k]<v[j-k]){
					ans+=v[i++];
				}else if(i+k<j && v[i+k]>v[j-k]){
					ans+=v[j--];
				}else{
					ans+=v[i++];
				}
			}
		}
		ans+=v[i];

		FOR(i,1,n+1){
			cout<<ans[i-1];
			if(i%80==0) cout<<endl;
		}
	}

	return 0;
}
