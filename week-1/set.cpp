#include<bits/stdc++.h>
using namespace std;

int main(){
	//Set:
	//Propiedades:
	/*
	1) Si un elemento se repite, solamente se considera
	una vez
	2) Ordena los elementos
	*/

	set<int> s;

	//Se agrega:
	s.insert(12);
	s.insert(14);
	s.insert(10);
	s.insert(5);
	//No da error, pero no repite al elemento
	s.insert(12);
	//insert tome O(log(n)) -> n es tamanio del set

	//s.count -> 0, 1
	//s.count es O(log(n))
	if(s.count(10)){
		cout<<"El numero 10 pertenece al set"<<endl;
	}else{
		cout<<"El numero 10 no pertenece al set"<<endl;
	}

	//Eliminar
	//O(log(n))
	s.erase(12);
	//No hagas s.erase(1);

	//O(1)
	cout<<s.size()<<endl;
	cout<<s.empty()<<endl;

	for(auto it = s.begin();it!=s.end();it++){
		//Obtenemos los elementos ordenados
		cout<< *it <<endl;
	}


	return 0;
}