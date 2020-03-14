#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct carti
{
	char titlu[20], autor[20], domeniu[20];
	int an, nrpag;
}C;

void citire(C *ca, int *n)
{
	(*n)++;
	printf("Titlul:\n"); scanf("%s", (ca + *n)->titlu);
	printf("Autorul:\n"); scanf("%s", (ca + *n)->autor);
	printf("Domeniul:\n"); scanf("%s", (ca + *n)->domeniu);
	printf("Anul aparitiei:\n"); scanf("%d", &(ca + *n)->an);
	printf("Numarul de pagini:\n"); scanf("%d", &(ca + *n)->nrpag);
}
void afisare(C *ca, int *n,char domeniu[20])
{
	int i;
	for (i = 0; i <= *n; i++)
	{
		if(strcmp((ca+i)->domeniu,domeniu)==0)
		printf("%s %s %s %d %d\n", (ca + i)->titlu, (ca + i)->autor, (ca + i)->domeniu, (ca + i)->an, (ca + i)->nrpag);
	}
}
void cautare_titlu(C *ca, int *n, char titlu[20])
{
	int i;
	for (i = 0; i <= *n; i++)
		if (strcmp((ca + i)->titlu, titlu) == 0)
			printf("%s %s %s %d %d\n", (ca + i)->titlu, (ca + i)->autor, (ca + i)->domeniu, (ca + i)->an, (ca + i)->nrpag);
}
void cautare_an(C *ca, int *n, int an)
{
	int i;
	for(i=0;i<=*n;i++)
	if((ca+i)->an==an) printf("%s %s %s %d %d\n", (ca + i)->titlu, (ca + i)->autor, (ca + i)->domeniu, (ca + i)->an, (ca + i)->nrpag);
}
void stergere(C *ca, int *n,char titlu[20])
{
	int i, k=0,j;
	for (i = 0; i <= (*n - k); i++)
		if(strcmp((ca+i)->titlu,titlu)==0)
	{
		k++;
		for (j = 0; j <= (*n - k); j++)
			*(ca + j) = *(ca + j + 1);
		i--;
	}
	*n = *n - k;
}
void sortare_domeniu(C *ca, int *n, char domeniu[20])
{
	int i, k;
	C aux;
	do
	{
		k=1;
		for (i = 0; i <= *n; i++)
		{
			if (strcmp((ca + i)->domeniu, domeniu) == 0)
				{
					k = 1;
				for (i = 1; i <= *n; i++)
				{
					if (strcmp((ca + i)->titlu, (ca + i - 1)->titlu) < 0)
					{
						aux = *(ca + i);
						*(ca + i) = *(ca + i - 1);
						*(ca + i - 1) = aux;
						k = 0;
					}
				}
			} 
		}
	} while(!k);
}
int main()
{
	int n = -1,an,opt;
	C ca[20];
	char domeniu[20],titlu[20];
	do
	{
		printf("0.Iesire\n");
		printf("1.Adaugare carte noua\n");
		printf("2.Afisare carti\n");
		printf("3.Cautarea unei carti dupa titlu\n");
		printf("4.Cautarea unei carti dupa anul aparitiei\n");
		printf("5.Stergerea unei carti\n");
		printf("6.Sortarea dupa titlu a cartilor dintr-un domeniu\n");
		printf("Dati optiunea dumneavoastra\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1: citire(ca, &n); break;
		case 2: 
			printf("Dati domeniul din care doriti sa afisati carti\n");
			scanf("%s", domeniu);
			afisare(ca, &n,domeniu); break;
		case 3: 
			printf("Dati un titlu\n");
			scanf("%s", titlu);
			cautare_titlu(ca, &n, titlu);
			break;
		case 4:
			printf("Dati anul aparitiei\n");
			scanf("%d", &an);
			cautare_an(ca, &n, an);
			break;
		case 5: 
			printf("Dati titlul cartii pe care doriti sa o stergeti\n");
			scanf("%s", titlu);
			stergere(ca, &n, titlu);
			break;
		case 6:
			printf("Dati domeniul cartilor pe care doriti sa le sortati\n");
			scanf("%s", domeniu);
			sortare_domeniu(ca, &n, domeniu);
			break;
		case 0: exit(0); break;
		default: printf("Optiune gresita!\n"); break;
		}
	} while (1);
	
	return 0;
}