#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
 
typedef struct calculatoare
{
	char procesor[20], monitor[20];
	int  memorie, hdd,serie;
}C;

void citire(C *calc, int *n)
{
	(*n)++;
	printf("Serie calculator\n"); 
	scanf("%d", &(calc + *n)->serie);
	printf("Procesor\n");
	scanf("%s", (calc + *n)->procesor);
	printf("Monitor\n");
	scanf("%s", (calc + *n)->monitor);
	printf("Memorie\n");
	scanf("%d", &(calc + *n)->memorie);
	printf("HDD\n");
	scanf("%d", &(calc + *n)->hdd);	
}
void afisare(C *calc, int *n)
{
	int i;
	for (i = 0; i <= *n; i++)
		printf("%d %s %s %d %d\n", (calc + i)->serie, (calc + i)->procesor, (calc + i)->monitor, (calc + i)->memorie, (calc + i)->hdd);
}
void afisare_procesor(C *calc, int *n, char procesor[20])
{
	int i;
	for (i = 0; i <= *n; i++)
	{
		if(strcmp((calc+i)->procesor,procesor)==0)
			printf("%d %s %s %d %d\n", (calc + i)->serie, (calc + i)->procesor, (calc + i)->monitor, (calc + i)->memorie, (calc + i)->hdd);
	}
}
void cautare_serie(C *calc, int *n, int serie)
{
	int i;
	for (i = 0; i <= *n; i++)
	{
		if((calc+i)->serie==serie) printf("%d %s %s %d %d\n", (calc + i)->serie, (calc + i)->procesor, (calc + i)->monitor, (calc + i)->memorie, (calc + i)->hdd);
	}
}
void stergere_serie(C *calc, int *n, int serie)
{
	int i, k = 0, j;
	for (i = 0; i <= (*n - k); i++)
	{
		if ((calc + i)->serie == serie)
		{
			k++;
				for (j = i; j <= (*n - k); j++)
					*(calc + j) = *(calc + j + 1);
				i--;
		}
	}
	*n = *n - k;
}
void stergere_hdd_memorie(C *calc, int *n, int hdd, int memorie)
{
	int i, k = 0, j;
	for(i=0;i<=(*n-k);i++)
		if ((calc + i)->hdd == hdd&&(calc+i)->memorie==memorie)
		{
				k++;
				for (j = i; j <= (*n - k); j++)
					*(calc + j) = *(calc + j + 1);
				i--;
		
		}
	*n = *n - k;
}
void sortare_procesor_memorie(C *calc, int *n)
{
	C aux;
	int i, k;
	{
			do
			{
				k = 1;
				for (i = 1; i <= *n; i++)
				{
					if (strcmp((calc + i)->procesor, (calc + i - 1)->procesor) < 0)
					{
						aux = *(calc + i);
						*(calc + i) = *(calc + i - 1);
						*(calc + i - 1) = aux;
						k = 0;
					}
				}
			} while (!k);

		do
		{
					k = 1;
					for (i = 1; i <= *n; i++)
					{
						if ((calc + i)->memorie, (calc + i - 1)->memorie < 0)
						{

							aux = *(calc + i);
							*(calc + i) = *(calc + i - 1);
							*(calc + i - 1) = aux;
						}
					}

				} while (!k);
		
	}
}


int main()
{
	C calc[20];
	int n = -1,opt,hdd,memorie,serie;
	char monitor[20], procesor[20];
	do
	{
		printf("0.Iesire\n");
		printf("1.Citire\n");
		printf("2.Afisare\n");
		printf("3.Afisare dupa procesor\n");
		printf("4.Cautare dupa serie\n");
		printf("5.Stergere dupa serie\n");
		printf("6.Stergere dupa hdd si memorie\n");
		printf("7.Sortare dupa procesor si monitor\n");
		printf("Optiunea dvs este:\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			citire(calc, &n);
			break;
		case 2:
			afisare(calc, &n);
			break;
		case 3:
			printf("Dati procesorul dupa care doriti sa afisati\n");
			scanf("%s", procesor);
			afisare_procesor(calc, &n, procesor);
			break;
		case 4:
			printf("Dati seria dupa care doriti sa cautati\n");
			scanf("%d", &serie);
			cautare_serie(calc, &n, serie);
			break;
		case 5:
			printf("Dati seria dupa care doriti sa stergeti\n");
			scanf("%d", &serie);
			stergere_serie(calc, &n, serie);
			break;
		case 6:
			printf("Dati hdd si memoria dupa care doriti sa stergeti\n");
			scanf("%d %d", &hdd, &memorie);
			stergere_hdd_memorie(calc, &n, hdd, memorie);
			break;
		case 7: 
			sortare_procesor_memorie(calc, &n);
			break;
		case 0:
			exit(0);
			break;
		default: printf("Optiune gresita!\n");
		}
	} while (1);
	system("pause");
	return 0;
}