#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,nrlin = 0,e,el,a[10][10]; 
	char opt;
	printf("Cate linii si coloane?\n"); scanf("%d", &n);
	do
	{
		printf("\n\t a.Citire matrice\n");
		printf("\t b.Afisare matrice\n");
		printf("\t c.Cautarea unui element\n");
		printf("\t d.Nr de linii pe care se gaseste elementul\n");
		printf("\t e.Iesire\n");
		getchar();
		printf("Dati optiunea "); scanf("%c", &opt);
		switch (opt)
		{
		case 'a':
			for(i=0;i<n;i++)
				for (j = 0; j< n; j++)
				{
					printf("a[%d][%d]=",i,j); scanf("%d", &a[i][j]);
				}
			printf("\n");
			break;
		case 'b':
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
					printf("%d", a[i][j]);
				printf("\n");
			}
			
			break;
		case 'c':
					printf("Dati elementul pe care doriti sa il cautati"); scanf("%d", &e);
					for (i = 0; i < n; i++)
						for (j = 0; j < n; j++)
						
							if (a[i][j] == e) printf("Elementul exista si se afla pe linia=%d, coloana=%d\n",i,j);
						
						
					break;
		case 'd':

			printf("Dati elementul pe care doriti sa il cautati\n"); scanf("%d", &el);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (a[i][j] == el) nrlin = nrlin + 1;
			printf("Elementul se gaseste pe %d linii\n", nrlin);
			break;
		case 'e': 
			exit(0);
			break;
		default: printf("Optiune gresita\n"); break;
		}




	} while (1);
	system("pause");
	return 0;
}