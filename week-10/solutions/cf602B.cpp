#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i = (n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back

typedef long long ll;
typedef vector<ll> vi;

int main(){
	int n; cin>>n;
	vi v(n);
	REP(i,n){
		cin>>v[i];
	}
	int min_ = v[0], max_ = v[0];
	int lmin = 0, lmax = 0;
	int ans = 1;

	int l =0, r =1;
	while(r<n){
		if(max_-min_==1){
			if(v[r]<=max_ && v[r]>=min_){
				if(v[r]==max_) lmax = r;
				else lmin = r;
				ans = max(r-l+1,ans);
			}else{
				if(v[r]>max_){
					l = lmin+1;
					min_ = max_;
					lmin = lmax;
					max_ = v[r];
					lmax = r;
				}else{
					l = lmax + 1;
					max_ = min_;
					lmax = lmin;
					min_ = v[r];
					lmin = r;
				}
			}
		}else{
			//max_==min_
			if(v[r]>max_){
				max_ = v[r];
				lmax = r;
			}else if(v[r]<max_){
				min_ = v[r];
				lmin = r;
			}else{
				lmin = r;
				lmax = r;
			}
			ans = max(ans,r-l+1);
		}
		r++;
	}

	cout<<ans<<endl;

	return 0;
}
