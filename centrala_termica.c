#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct centrale
{
	char tip[20], tiraj[20];
	int suprafata,pret;
}C;
void citire(C *ce, int *n)
{
	(*n)++;
	printf("Tipul centralei:\n");
	scanf("%s", (ce + *n)->tip);
	printf("Tiraj centrala:\n");
	scanf("%s", (ce + *n)->tiraj);
	printf("Suprafata de incalzit a centralei:\n");
	scanf("%d", &(ce + *n)->suprafata);
	printf("Dati pretul centralei\n");
	scanf("%d", &(ce + *n)->pret);
}
void afisare(C *ce, int *n)
{
	int i;
	for (i = 0; i <= *n; i++)
		printf("%s %s %d %d\n", (ce + i)->tip, (ce + i)->tiraj, (ce + i)->suprafata,(ce+i)->pret);
}
	void sortare_tiraj(C *ce, int *n)
{
	int i, k;
	C aux;
	for (i = 1; i <= *n; i++)
	{
		do
		{
			k = 1;
			if (strcmp((ce + i)->tiraj, (ce + i - 1)->tiraj) < 0)
			{
				aux = *(ce + i);
				*(ce + i) = *(ce + i - 1);
				*(ce + i - 1) = aux;
				k = 0;

			}
		} while (!k);
	}
}
void stergere_tip(C *ce, int *n, char tip[20])
{
	int i, k = 0, j;
	for (i = 0; i <= (*n - k); i++)
	{
		if (strcmp((ce + i)->tip, tip) == 0)
		{
			for (j = i; j <= (*n - k); j++)
			{
				k++;
				*(ce + j)->tip = *(ce + j + 1)->tip;
				i--;
			}
		}
		*n = *n - k;
	}
}
void matrice(C *ce, int *n, int m)
{
	int i, j,p[10][10];
	for (i = 0; i <= *n; i++)
		for (j = 0; j < m; j++)
			

		if (i==j) p[i][j] = (ce + i)->pret;
		else
			p[i][j] = 0;

	
	for (i = 0; i <= *n; i++)
		{
			for (j = 0; j < m; j++)
				printf("%d", p[i][j]);
			printf("\n");
		}


}
void pret_maxim(C *ce, int *n)
{
	int i, max;
	max = (ce + 0)->pret;
	for (i = 0; i <= *n; i++)
		if ((ce + i)->pret > max) max = (ce + i)->pret;
	printf("Pretul maxim este de %d lei\n", max);

}


void main()
{
	int n = -1,opt,m;
	C ce[20];
	char tip[20], tiraj[20];
	do
	{
		printf("0.Iesire\n");
		printf("1.Adaugare element nou\n");
		printf("2.Afisare toate centralele\n");
		printf("3.Afisare in ordine crescatoare dupa tiraj\n");
		printf("4.Stergere dupa tipul precizat\n");
		printf("5.Matrice preturi\n");
		printf("6.Pret maxim\n");
		printf("Optiunea dumneavoastra este:\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: exit(0); break;
		case 1: citire(ce, &n); break;
		case 2: afisare(ce, &n); break;
		case 3:
			sortare_tiraj(ce, &n); break;
		case 4: 
			printf("Dati tipul\n");
			scanf("%s", tip);
			stergere_tip(ce, &n, tip);
			break;
		case 5: 
			printf("Dati nr linii si coloane\n"); scanf("%d", &m);
			matrice(ce, &n, m);
		case 6:
			pret_maxim(ce, &n);
		default: printf("Optiune gresita\n"); break;
		}
	} while (1);
	system("pause");
	return 0; 
}