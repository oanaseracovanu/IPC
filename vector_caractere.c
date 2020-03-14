#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char v[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		printf("Dati caracter %d ",i);
		scanf("%c ", &v[i]);
	}

	for (i = 0; i < 10; i++) 
	{ 
		printf("%c ", v[i]); 
	}
	return 0;
}