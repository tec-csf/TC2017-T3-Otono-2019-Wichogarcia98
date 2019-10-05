
#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 


#define N 4 

bool preferencias(int prefiere[2*N][N], int m, int h, int h1) 
{ 
	
	for (int i = 0; i < N; i++) 
	{ 
		
		if (prefiere[m][i] == h1) 
			return true; 

		
		if (prefiere[m][i] == h) 
		return false; 
	} 
} 


void parejaEstable(int prefiere[2*N][N]) 
{ 
	
	int mujer[N]; 

	
	bool hombre[N]; 

	
	memset(mujer, -1, sizeof(mujer)); 
	memset(hombre, false, sizeof(hombre)); 
	int cont = N; 

	
	while (cont > 0) 
	{ 
		
		int h; 
		for (h = 0; h < N; h++) 
			if (hombre[h] == false) 
				break; 

		
		for (int i = 0; i < N && hombre[h] == false; i++) 
		{ 
			int m = prefiere[m][i]; 

			
			if (mujer[m-N] == -1) 
			{ 
				mujer[m-N] = m; 
				hombre[m] = true; 
				cont--; 
			} 

			else 
			{ 
				
				int h1 = mujer[m-N]; 

				 
				if (preferencias(prefiere, m, h, h1) == false) 
				{ 
					mujer[m-N] = h; 
					hombre[h] = true; 
					hombre[h1] = false; 
				} 
			} 
		}
	} 


	
	cout << "Mujer Hombre" << endl; 
	for (int i = 0; i < N; i++) 
	cout << " " << i+N << "\t" << mujer[i] << endl; 
} 


int main() 
{ 
	int prefiere[2*N][N] = { {7, 5, 6, 4}, 
		{5, 4, 6, 7}, 
		{4, 5, 6, 7}, 
		{4, 5, 6, 7}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
	}; 
	parejaEstable(prefiere); 

	return 0; 
} 

//Este código fue obtenido de: https://www.geeksforgeeks.org/stable-marriage-problem/
