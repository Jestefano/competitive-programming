#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(), v.end()

bool comp(int a, int b){
	return a>b;
}// Ordenamiento TOTAL

bool comp2(pair<int,int> a , pair<int,int> b ){
	return a.first - b.second > a.second;
}

int main(){
	int n; cin>>n;
	vector<int> v(n);

	REP(i,n) cin>>v[i];
	sort(all(v));//O(nlog(n))

	//Si quieres ordenar de otra forma:
	sort(all(v),comp);

	REP(i,n) cout<<v[i];

	//otro tipo de dato:
	vector<pair<int,int> > w(n);
	REP(i,n) cin>>w[i].first >> v[i].second;
	sort(all(w));

	REP(i,n) cout<<w[i].fst<<" "<<w[i].second<<endl;

	/*
	Orden de diccionario:
	//vector<string> usa esto
	aba
	abe
	*/

	sort(w,comp2);

	return 0;
}