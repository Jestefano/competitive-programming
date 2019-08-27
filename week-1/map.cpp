#include<bits/stdc++.h>
using namespace std;



int main(){
	//map
	map<int,int> m;
	/*
	(key, value)
	1)Los key deben ser unicos!!!
	  Si es que intentas que no sean unicos
	  reemplaza al anterior!
	2) Ordena los elementos (key)
	*/

	//Agregar elementos:
	m.insert(make_pair(10,30));
	m.insert(make_pair(4,2));

	//Forma alternativa:
	m[3] = 20;
	m[3] = 18;

	cout<<m[3]<<endl;
	//18

	//Si tu usas un elemento que no estaba declarado 
	//previamente, ese elemento se agrega al mapa
	//con valor de defecto
	cout<<m[1]<<endl;

	cout<<m.size()<<endl;
	cout<<m.empty()<<endl;

	if(m.count(2)){
		cout<<m[2]<<endl;
	}

	m.erase(3);

	//Imprime todos los elementos
	for(auto it = m.begin();it!=m.end();it++){
		cout<< (it->first)<<" "<<(it->second)<<endl;
	}

	/*

	*/

	return 0;
}