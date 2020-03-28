#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct store
{
    int id, quantity, price;
    char name[20],features[20];
}S;

void add(S *s, int *n)
{
    (*n)++;
    printf("Id: ");
    scanf("%d",&(s+*n)->id);
    printf("Name: ");
    scanf("%s",(s+*n)->name);
    printf("Features: ");
    scanf("%s",(s+*n)->features);
    printf("Quantity: ");
    scanf("%d",&(s+*n)->quantity);
    printf("Price: ");
    scanf("%d",&(s+*n)->price);
}

void list(S *s, int *n)
{
    int i;
    for(i=0;i<=*n;i++)
    printf("Id :%d\nName: %s\nFeatures: %s\nQuantity: %d\nPrice: %d\n",(s+i)->id,(s+i)->name,
    (s+i)->features,(s+i)->quantity,(s+i)->price);
}

void tvalue(S *s, int *n)
{
    int i,val=0;
    for(i=0;i<=*n;i++)
    val=val+(s+i)->price;
    printf("Total value of products: %d\n",val);
}

void search_id(S *s, int *n, int *id)
{
    int i;
    for(i=0;i<=*n;i++)
    if((s+i)->id==*id) 
    printf("Id :%d\nName: %s\nFeatures: %s\nQuantity: %d\nPrice: %d\n",(s+i)->id,(s+i)->name,
    (s+i)->features,(s+i)->quantity,(s+i)->price);
}

void search_name(S *s, int *n, char *namep)
{
    int i;
    for(i=0;i<=*n;i++)
    if(strcmp((s+i)->name,namep)==0)
    printf("Id :%d\nName: %s\nFeatures: %s\nQuantity: %d\nPrice: %d\n",(s+i)->id,(s+i)->name,
    (s+i)->features,(s+i)->quantity,(s+i)->price);
}

void cheapest(S *s, int *n)
{
    int i, min=(s+0)->price;
    for(i=0;i<=*n;i++)
    if((s+i)->price<min) min=(s+i)->price;
    for(i=0;i<=*n;i++)
    if((s+i)->price==min)
    printf("The cheapest product is: Id :%d\nName: %s\nFeatures: %s\nQuantity: %d\nPrice: %d\n",
    (s+i)->id,(s+i)->name, (s+i)->features,(s+i)->quantity,(s+i)->price);
}

void supply(S *s, int *n)
{
    int i;
    for(i=0;i<=*n;i++)
    if((s+i)->quantity==0) 
    printf("Product that needs supply: Id :%d\nName: %s\nFeatures: %s\nQuantity: %d\nPrice: %d\n",
    (s+i)->id,(s+i)->name, (s+i)->features,(s+i)->quantity,(s+i)->price);
}

void modification(S *s, int *n)
{
    int idp,i,qt,opt;
    printf("What do you want to modify? 0-price, 1-quantity, 2-both: ");
    scanf("%d",&opt);
    printf("The id of the product: ");
    scanf("%d",&idp);
    switch(opt)
    {
        case 0:
        for(i=0;i<=*n;i++)
        if((s+i)->id==idp) 
        scanf("%d",&(s+i)->price);
        break;
        case 1:
        for(i=0;i<=*n;i++)
        if((s+i)->id==idp)
        scanf("%d",&(s+i)->quantity);
        break;
        case 2:
        for(i=0;i<=*n;i++)
        if((s+i)->id==idp)
        scanf("%d %d",&(s+i)->price,&(s+i)->quantity);
    }
}

void delete(S *s, int *n)
{
    int i,idp,j,k=0;
    printf("The id: ");
    scanf("%d",&idp);
    for(i=0;i<=(*n-k);i++)
    if((s+i)->id==idp)
    {
        k++;
        for(j=i;j<=(*n-k);j++)
        *(s+j)=*(s+j+1);
        i--;
    }
    *n=*n-k;
}

int main()
{
    S s[20];
    int n=-1,opt,idp;
    char namep[20];
    do
    {
        printf("1.Add a product\n");
        printf("2.List products\n");
        printf("3.Total value\n");
        printf("4.Search by id\n");
        printf("5.Search by name\n");
        printf("6.The cheapest product\n");
        printf("7.Products that need supply\n");
        printf("8.Modify the price or the quantity of a product\n");
        printf("9.Delete a product identified by id\n");
        printf("0.Exit\n");
        printf("Your option: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            add(s,&n);
            break;
            case 2:
            list(s,&n);
            break;
            case 3:
            tvalue(s,&n);
            break;
            case 4:
            printf("The id of the product: ");
            scanf("%d",&idp);
            search_id(s,&n,&idp);
            break;
            case 5:
            printf("The name of the product: ");
            scanf("%s",namep);
            search_name(s,&n,namep);
            break;
            case 6:
            cheapest(s,&n);
            break;
            case 7:
            supply(s,&n);
            break;
            case 8:
            modification(s,&n);
            list(s,&n);
            break;
            case 9:
            delete(s,&n);
            break;
            case 0:
            exit(0);
            break;
            default:
            printf("Option does not exist!\n");
            break;
        }
    } while (1);
    return 0;
}