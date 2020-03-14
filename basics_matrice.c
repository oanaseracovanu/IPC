#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j, n, p = 1, s = 0, aux, a[10][10], min, max;
	char opt;
	printf("Dati nr de linii si coloane\n");
	scanf("%d", &n);
	do
	{
		printf("\n\t a.Citire matrice\n");
		printf("\t b.Afisare matrice\n");
		printf("\t c.Maxim\n");
		printf("\t d.Minim\n");
		printf("\t e.Diagonala principala\n");
		printf("\t f.Diagonala secundara\n");
		printf("\t g.Deasupra diagonala principala\n");
		printf("\t h.Sub diagonala principala\n");
		printf("\t i.Deasupra diagonala secundara\n");
		printf("\t j.Sub diagonala secundara\n");
		printf("\t k.Suma elemente de pe pozitie para\n");
		printf("\t l.Produs elemente impare\n");
		printf("\t o.Iesire\n");
		getchar();
		printf("Dati optiunea\n"); 
		scanf("%c", &opt);
		switch (opt)
		{
		case 'a':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++) {
					printf("a[%d][%d]=", i, j);
					scanf("%d", &a[i][j]);
				}
			break;
		case 'b':
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					printf("%d ", a[i][j]);
				printf("\n");
			}
			break;
		case 'c':
			max = a[0][0];
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (a[i][j] > max) max = a[i][j];
			printf("%d ", max);
			break;
		case 'd':
			min = a[0][0];
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (a[i][j] < min) min = a[i][j];
			printf("%d ", min);
			break;
		case 'e':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i == j) printf("%d ", a[i][j]);
				}
			break;
		case 'f':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i + j == n - 1) printf("%d ", a[i][j]);
				}
			break;
		case 'g':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i < j) printf("%d ", a[i][j]);
				}
			break;
		case 'h':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i > j) printf("%d ", a[i][j]);
				}
			break;
		case 'i':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i + j < n - 1) printf("%d ", a[i][j]);
				}
			break;
		case 'j':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (i + j > n-1) printf("%d ", a[i][j]);
				}
			break;
		case 'k':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (j % 2 == 0) s=s+a[i][j];
			printf("%d ", s);
			break;
		case 'l':
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (a[i][j] % 2 != 0) p = p * a[i][j];
			printf("%d ", p);
			break;
		case 'o':
			exit(0);
			break;
		default:
			printf("Optiune gresita\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}
	

	
