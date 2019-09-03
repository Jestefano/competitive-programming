#include<bits/stdc++.h>
using namespace std;

#define nax 100
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)
#define all(v) v.begin(),v.end()

int main(){
	int low = 0, high = n-1;
	//Se asume que el vector esta ordenado

	bool encontrado = false;
	while(low<=high){
		mid = low + (high-low)/2;
		if(v[mid]==target){
			cout<<mid<<endl;
			encontrado =true;
		}else if(v[mid]<target){
			low = mid + 1;
		}else{
			top = mid-1;
		}
	}
	if(encontrado==false){
		cout<<-1;
	}

	//Si necesitas unicamente usar busqueda binaria clasica:
	//v
	int pos1 = lower_bound(all(v),target) - v.begin();
	//Lo anterior busca la posicion >= target
	//Ojo: Puede salirse del arreglo
	//pos1<v.size() ya que si target es mayor a todos los elementos
	//te devuelve int(v.size()) 
	//v[pos1]==target -> existe!
	//v[pos1]!=target -> No esta!

	int pos2 = upper_bound(all(v),target) - v.begin();
	//O(log(n))

	return 0;
}