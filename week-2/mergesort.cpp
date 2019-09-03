#include<bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

vector<int> v;

void merge(int low, int mid, int top){
	vector<int> aux(top-low+1);
	int i = low, j = mid+1, k =0;
	while(i<=mid && j<=top){
		if(v[j]<v[i]){
			aux[k] = v[j];
			k++; j++;
		}else{
			aux[k] = v[i];
			k++; i++;
		}
	}

	while(j<=top){
		aux[k] = v[j];
		k++;j++;
	}
	while(i<=mid){
		aux[k] = v[i];
		i++;k++;
	}

	int w = low;
	while(w<=top){
		v[w] = aux[w-low];
		w++;
	}
}

void mergesort(int low, int top){
	if(low<top){
		int mid = (low+top)/2;
		mergesort(low,mid);
		mergesort(mid+1,top);
		merge(low,mid,top);
	}//low==top
}

int main(){
	int n; cin>>n;
	v.resize(n);
	REP(i,n) cin>>v[i];
	mergesort(0,n-1);
	
	REP(i,n) cout<<v[i];
	
	/*
	1. Familiarizarse con el metodo 'divide y venceras'
		Partes el problema en subproblemas de la misma naturaleza (mergesort)
		Y luego mezclas las soluciones para llegar al resultado
		final. (merge)
		//En DP los subproblemas se entrelazan entre ellos. En Div&Venc
		//NO se entrelazan
	2. La funcion merge sirve para otros problemas
	3. A veces hay problemas que se solucionan con modificaciones de ordenamiento.
	4. Ayuda a entender segment tree.
	*/
	
	return 0;
}