#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct suc
{
	char denumire[10], producator[10], categorie[10],indulcitor[10],aroma[10],fructe[10];
	int pret, cantitate, termen, concentratie;
}S;

void citire(S *s, int *n)
{
	(*n)++;
	int i;
	for (i = 0; i <= *n; i++)
	{
		printf("Denumirea sucului:\n");
		scanf("%s", (s+*n)->denumire);
		printf("Producatorul:\n");
		scanf("%s", (s+*n)->producator);
		printf("Pretul:\n");
		scanf("%d", &(s + *n)->pret);
		printf("Cantitatea:\n");
		scanf("%d", &(s + *n)->cantitate);
		printf("Termen la care expira\n");
		scanf("%d", &(s + *n)->termen);
		printf("Categoria-carbogazoasa sau naturala:\n");
		scanf("%s", (s + *n)->categorie);
		if (strcmp((s + *n)->categorie, "carbogazoasa") == 0)
		{
			printf("Indulcitor:\n");
			scanf("%s", (s + *n)->indulcitor);
			printf("Aroma:\n");
			scanf("%s", (s + *n)->aroma);
		}
		if (strcmp((s + *n)->categorie, "naturala") == 0)
		{
			printf("Concentratie\n");
			scanf("%d",& (s + *n)->concentratie);
			printf("Fructe:\n");
			scanf("%s", (s + *n)->fructe);
		}

	}
		
}

void afisare(S *s, int *n)
{
	int i;
	for (i = 0; i <= *n; i++)
	{
		printf("%s %s %d %d %d %s\n", (s + i)->denumire, (s + i)->producator, (s + i)->pret, (s + i)->cantitate, (s + i)->termen, (s + i)->categorie);
		if (strcmp((s + *n)->categorie, "carbogazoasa") == 0)
			printf("%s %s\n", (s + i)->indulcitor, (s + i)->aroma);
		if (strcmp((s + *n)->categorie, "naturala") == 0)
			printf("%d %s\n", (s + i)->concentratie, (s + i)->fructe);
	}
}

void cautare_denumire(S *s, int *n,char denumire[10])
{
	int i;
	for(i=0;i<=*n;i++)
		if(strcmp((s+i)->denumire,denumire)==0) 
			printf("%s %s %d %d %d %s\n", (s + i)->denumire, (s + i)->producator, (s + i)->pret, (s + i)->cantitate, (s + i)->termen, (s + i)->categorie);
}

void sortared_pret(S *s, int *n)
{
	S aux;
	int i, k;
	do
	{
		k=1;
		for(i=0;i<=*n;i++)
		{
			if ((s + i)->pret < (s + i + 1)->pret)
			{
				aux = *(s + i + 1);
				*(s + i + 1) = *(s + i);
				*(s + i) = aux;
				k=0;
			}
		}
	}while(!k);
}
void main()
{
	S s[20];
	int n = -1, opt;
	char nume_suc[20];
	do
	{
		printf("0.Iesire\n");
		printf("1.Adaugare\n");
		printf("2.Afisare\n");
		printf("3.Cautare dupa denumire\n");
		printf("4.Sortare descrescatoare dupa pret\n");
		printf("Optiunea dumneavoastra e:\n");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0: 
			exit(0); 
			break;
		case 1:
			citire(s, &n);
			break;
		case 2: 
			afisare(s, &n);
			break;
		case 3:
		 	printf("Sucul pe care doriti sa il cautati: ");
			scanf("%s",nume_suc);
			cautare_denumire(s,&n,nume_suc);
			break;
		case 4:
		sortared_pret(s,&n);
		break;
		default: 
			printf("Optiunea dumneavoastra e gresita\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}
