#define _CRT_SECURE_NO_WARNINGS
#define citire(x); scanf("%d",&x);
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char sir[20],opt;
	int i;
	do 
	{
		printf("\n\t 1.Citire sir\n");
		printf("\t 2.Afisare sir\n");
		printf("\t 3.Toate caracterele 'a' devin '*'\n");
		printf("\t 4.Iesire\n");
		printf("Dati optiunea"); citire(opt);
		switch (opt)
		{
		case 1:
			printf("Introduceti sirul:");
			getchar();
			gets(sir);
			break;
		case 2:
			puts(sir);
				break;
		case 3:
			for (i = 0; i < strlen(sir); i++)
				if (sir[i] == 'a') sir[i] = '*';
			puts(sir);
			break;
		case 4:
			exit(0);
			break;
		default: printf("Optiune gresita"); break;
		}

	} while (1);
	system("pause");
	return 0;
}