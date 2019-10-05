#include <bits/stdc++.h> 

int max(int a, int b); 


int scm(char* A, char* B, int x, int y) 
{ 
	int L[x + 1][y + 1]; 
	int i, j; 

	
	for (i = 0; i <= x; i++) { 
		for (j = 0; j <= y; j++) { 
			if (i == 0 || j == 0) 
				L[i][j] = 0; 

			else if (A[i - 1] == B[j - 1]) 
				L[i][j] = L[i - 1][j - 1] + 1; 

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
		} 
	} 

	
	return L[x][y]; 
} 


int max(int a, int b) 
{ 
	return (a > b) ? a : b; 
} 


int main() 
{ 
	char A[] = "PLLOCM"; 
	char B[] = "LRORPCM"; 

	int x = strlen(A); 
	int y = strlen(B); 

	printf("El tamaño de subsecuencia común mayor es %d\n", scm(A, B, x, y)); 

	return 0; 
} 

// Este código fue obtenido de: https://www.geeksforgeeks.org/cpp-program-for-longest-common-subsequence/
