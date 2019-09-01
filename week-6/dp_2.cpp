#include<bits/stdc++.h>
using namespace std;

#define nax 100009
#define FOR(i,n,m) for(int i =(n);i<(m);i++)
#define REP(i,n) FOR(i,0,n)

int main(){
	/*
	Consejos:
		dp(a,b,c,d,e) = ALGO
		- Listar todas las variables que aparecen en el problema
		y ver cuales pueden ser tus parametros:
			Ejemplo: En https://leetcode.com/problems/minimum-path-sum/
			se tiene la posicion en i y j (fila y columna), minima suma
		- Revisar los limites de dichos semiparametros (n<=100 o algo asi)
		- Que es lo que me importa hasta el estado con ciertos parametros
			-> En el ejemplo anterior lo que importa es la suma!
		- Define tu DP en palabras!
	*/


	int n,m; cin>>n>>m;
	int v[100][100];
	int dp[100][100];
	REP(i,n){
		REP(j,m){
			cin>>v[i][j];
			dp[i][j] = 0;
		}
	}

	REP(i,n){
		//i
		REP(j,m){// ... j-1, j, j+1 ...
			if(i==0 && j==0) dp[i][j] = v[i][j];
			else if(i==0) dp[i][j] = dp[i][j-1] + v[i][j];
			else if(j==0) dp[i][j] = dp[i-1][j] + v[i][j];
			else dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + v[i][j];
		}
	}//Recuerda que la complejidad de DP depende de tus parametros
	// Y de cuanto cueste la transicion de un parametro a otro

	cout<<dp[n-1][m-1];
	/*
	Si se tiene una funcion recursiva A VECES se puede escribir
	como iterativo
	//En caso RECURSIVO hay que poner 3 cosas:
		- Caso base
		- Caso sin calculo previo
		- Caso de algo ya calculado
	Ventaja:
		No tienes que pensar en que orden hacer las cosas
	//En caso iterativo hay que poner:
		- Caso base
		- Iteracion 
	No es necesario verificar si ya guardamos el dato anterior
	PERO eso debes verificarlo por tu cuenta (al hacer la iteracion)
	*/

	

	return 0;
}