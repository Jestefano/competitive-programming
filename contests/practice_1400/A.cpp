/*
https://vjudge.net/contest/322571#problem/A
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()

typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int t; scanf("%d",&t);
	
	while(t--){
		int a,b; 
		scanf("%d%d",&a,&b);
		vi v(b);
		REP(i,b) scanf("%d",&v[i]);

		sort(all(v));
		int k = lower_bound(all(v),a/2)-v.begin();
		int aux1 = min(a-v[k],v[k]);
		int aux2 = min(v[k-1],a-v[k-1]);
		printf("%d ",max(aux1,aux2));
		
		printf("%d\n",max(max(a-v[0],v[0]),max(v[b-1],a-v[b-1])));
	}
	/*
  Think about the effect of an ant that takes contact with another one.
  */
  
	return 0;
}
