#include<bits/stdc++.h>
using namespace std;

int main(){
	//TODAS LAS OPERACIONES SON EN O(1)

	//Declaracion
	queue<int> q;

	q.push(10);
	q.push(14);
	q.push(16);
	//10, 14, 16.

	//Tamanio
	cout<<q.size()<<endl;

	//Verificar si esta vacio o no
	if(q.empty()==false){
		//Saber quien esta al frente de la cola
		cout<<q.front()<<endl;

		//Para sacar al primero
		q.pop();
	}
	
	cout<<q.front()<<endl;

	/*
	NO PUEDES SABER QUIEN ES FRONT SI LA COLA ESTA VACIA
	NO PUEDES HACER POP SI LA COLA ESTA VACIA
	*/

	//STACK:
	stack<int> s;

	s.push(10);
	s.push(14);
	s.push(12);
	//12, 14, 10

	cout<<s.size()<<endl;

	if(s.empty()==false){
		cout<<s.top()<<endl;

		s.pop();
	} 

	cout<<s.top()<<endl;

	//Para imprimir todo:
	while(!q.empty()){
		cout<<q.front();
		q.pop();
	}
	
	return 0;
}