#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prajitura
{
	char nume[20], faina[10];
	int bucati, pret,calorii;
}P;

void citire(P *pr, int *n)
{
	(*n)++;
	printf("Denumirea prajiturii:\n");
	scanf("%s", (pr + *n)->nume);
	printf("Tipul de faina folosita pentru prajitura:\n");
	scanf("%s", (pr + *n)->faina);
	printf("Nr de bucati disponibile:\n");
	scanf("%d", &(pr + *n)->bucati);
	printf("Pretul prajiturii:\n");
	scanf("%d", &(pr + *n)->pret);
	printf("Nr de calorii:\n");
	scanf("%d", &(pr + *n)->calorii);
}

void afisare(P *pr, int *n)
{
	int i;
	for (i = 0; i <= *n; i++)
		printf("%s %s %d %d %d\n", (pr + i)->nume, (pr + i)->faina, (pr + i)->bucati, (pr + i)->pret, (pr + i)->calorii);
}

void afisare_faina(P *pr, int *n, char faina[20])
{
	int i;
	for(i=0;i<=*n;i++)
		if(strcmp((pr+i)->faina,faina)==0) printf("%s %s %d %d %d\n", (pr + i)->nume, (pr + i)->faina, (pr + i)->bucati, (pr + i)->pret, (pr + i)->calorii);
}

void sortare_bucati(P *pr, int *n)
{
	int i,k;
	P aux;
	do
	{
		k=1;
		for (i = 1; i <= *n; i++)
			if ((pr + i)->bucati < (pr + i - 1)->bucati)
			{
				aux = *(pr + i);
				*(pr + i) = *(pr + i - 1);
				*(pr + i - 1) = aux;
				k=0;
	     	}
	}while(!k);
}

void stergere_calorii(P *pr, int *n, int calorii)
{
	int i, k = 0, j;
	for(i=0;i<=(*n-k);i++)
		if ((pr + i)->calorii == calorii)
		{
			k++;
			for (j = i; j <= (*n - k); j++)
				*(pr + j) = *(pr + j + 1);
			i--;
		}
	*n = *n - k;
}

void matrice_pret(P *pr, int *n,int m)
{
	int i, j,p[10][10];
	for (i = 0; i <= *n; i++)
		for (j = 0; j < m; j++)
			if (i == j) p[i][j] = (pr + i)->pret;
			else
				p[i][j] = 0;
	for (i = 0; i <= *n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%d", p[i][j]);
		printf("\n");
	}
}

void pret_maxim(P *pr, int *n)
{
	int i, max;
	max = (pr + 0)->pret;
	for (i = 0; i <= *n; i++)
		if ((pr + i)->pret > max) max = (pr + i)->pret;
	printf("Pretul maxim este: %d\n",max);
}

void total_bucati(P *pr, int *n)
{
	int i, s = 0;
	for (i = 0; i <= *n; i++)
		s = (pr + i)->bucati + s;
	printf("Nr total de bucati este: %d", s); 
}

void main()
{
	P *pr[20];
	int n = -1, opt,m,bucati,calorii;
	char faina[20];
	do
	{
		printf("0.Iesire\n");
		printf("1.Adaugare prajitura noua\n");
		printf("2.Afisare toate prajiturile\n");
		printf("3.Afisare prajituri dupa tipul de faina\n");
		printf("4.Sortarea prajiturilor dupa nr de bucati si calorii\n");
		printf("5.Stergerea prajiturilor dupa tipul de faina\n");
		printf("6.Matrice cu preturile prajiturilor pe diagonala\n");
		printf("7.Pretul maxim\n");
		printf("8.Nr total de bucati\n");
		printf("Optiunea dvs este:\n");
		scanf("%d", &opt);
		switch(opt)
		{
		case 0: 
			exit(0);
			break;
		case 1:
			citire(pr, &n);
			break;
		case 2:
			afisare(pr, &n);
			break;
		case 3:
			printf("Dati tipul de faina dupa care doriti sa afisati\n");
			scanf("%s", faina);
			afisare_faina(pr, &n, faina);
			break;
		case 4:
			sortare_bucati(pr, &n);
			break;
		case 5:
			printf("Dati caloriile dupa care doriti sa stergeti\n");
			scanf("%d", &calorii);
			stergere_calorii(pr, &n, calorii);
			break;
		case 6:
			printf("Dati nr de linii si coloane\n");
			scanf("%d", &m);
			matrice_pret(pr, &n,m);
			break;
		case 7: 
			pret_maxim(pr, &n);
			break;
		default: printf("Optiune gresita\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}