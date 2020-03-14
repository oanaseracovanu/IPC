#define _CRT_SECURE_NO_WARNINGS
#define citire(x); scanf("%d",&x);
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, v[20], n, aux, j,k;
	char opt;
	printf("Dati dimensiunea vectorului"); citire(n);
	do {

		printf("\n\t 1.Citire vector\n");
		printf("\t 2.Afisare vector\n");
		printf("\t 3.Sortare vector\n");
		printf("\t 4.Inversare vector\n");
		printf("\t 5.Iesire\n");
		getchar();
		printf("Dati optiunea\n"); citire(opt);
		switch (opt)
		{
		case 1:
			for (i = 0; i < n; i++)
			{
				printf("v[%d]= ", i + 1); citire(v[i]);

			}
			break;
		case 2:
			for (i = 0; i < n; i++)
				printf("%d ", v[i]);
			printf("\n");
			break;
		case 3:
		do
		{
			k=1;
			for (i = 1; i < n; i++)
				if (v[i - 1] > v[i])
				{
					aux = v[i];
					v[i] = v[i - 1];
					v[i - 1] = aux;
					k=0;
				}
		}while(!k);	
		for(i=0;i<n;i++)
		printf("%d ",v[i]);
			break;
		case 4:
			for (i = n-1; i >= 0; i--) printf("%d ", v[i]);		
			break;
		case 5: exit(0);
			break;
		default: printf("Optiune gresita");
			break;


		}
	} while (1);
	system("pause");
	return 0;
}
