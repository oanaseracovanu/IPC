#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, v[20], s = 0,n;
	char opt;
	printf("Dati dimensiune vector\n"); scanf("%d", &n);
	do
	{
		printf("\n\t a.Citire vector\n");
		printf("\t b.Afisare vector\n");
		printf("\t c.Elementele pare din vector\n");
		printf("\t d.Suma elementelor divizibile cu 5\n");
		printf("\t e.Iesire\n");
		getchar();
		printf("Dati optiunea\n");
		scanf("%c", &opt);
		switch (opt)
		{
		case 'a':
			for (i = 0; i < n; i++)
			{
				printf("v[%d]= ", i); scanf("%d", &v[i]);
			}
			break;
		case 'b':
			for (i = 0; i < n; i++)
				printf("%d ", v[i]);
			break;
		case 'c':
			for (i = 0; i < n; i++)
			{
				if (v[i] % 2 == 0)  printf("%d ", v[i]);
			}
			break;
		case 'd':
			for (i = 0; i < n; i++)
			{
				if (v[i] % 5 == 0) s = s + v[i]; 
			}
			printf("Suma este=%d ", s);
			break;
		case 'e': exit(0); break;
		default: printf("Optiune gresita"); break;
		}

	} while (1);
	system("pause");
	return 0; 
}