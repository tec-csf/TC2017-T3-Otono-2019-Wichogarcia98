
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define INF INT_MAX

int Solucion(int res[], int n);

void parrafo(int caracteres[], int n, int size){

 int espacio[n+1][n+1];
 int costo[n+1][n+1];
 int total[n+1];
 int res[n+1];
 int a, b;

 for (a = 1; a <= n; a++)
 {
	 espacio[a][a] = size - caracteres[a-1];
	 for (b = a+1; b <= n; b++)
		 espacio[a][b] = espacio[a][b-1] - caracteres[b-1] - 1;
 }

 for (a = 1; a <= n; a++)
 {
	 for (b = a; b <= n; b++)
	 {
		 if (espacio[a][b] < 0)
			 costo[a][b] = INF;
		 else if (b == n && espacio[a][b] >= 0)
			 costo[a][b] = 0;
		 else
			 costo[a][b] = espacio[a][b]*espacio[a][b];
	 }
 }

 total[0] = 0;
 for (b = 1; b <= n; b++)
 {
	 total[b] = INF;
	 for (a = 1; a <= b; a++)
	 {
		 if (total[a-1] != INF && costo[a][b] != INF &&
					 (total[a-1] + costo[a][b] < total[b]))
		 {
			 total[b] = total[a-1] + costo[a][b];
			 res[b] = a;
		 }
	 }
 }

 Solucion(res, n);
}

int Solucion(int res[], int n)
{
 int linea;
 if (res[n] == 1)
	 linea = 1;
 else
	 linea = Solucion(res, res[n]-1) + 1;

 cout << "\nNúmero de línea: " << linea << "\nDe la palabra número: " << res[n] << " a " << n << "\n\n";

 return linea;
}

int main()
{
 int caracteres[] = {9, 4, 4, 2};
 int n = sizeof(caracteres)/sizeof(caracteres[0]);
 int espacio = 6;

 parrafo(caracteres, n, espacio);

 return 0;
}

//Este código fue obtenido de: https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
