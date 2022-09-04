#include <stdio.h>
void displayItems(char items[]);
void displayInventory(char items[],int prices[],int quantities[]);
int inventoryValue(int prices[]);
int lowestPrice(int prices[]);
int highestPrice(int prices[]);
///StoreProgram Browse or shopping
int main(){
    char items[10]={'a','b','c','d','e','f','g','h','i','j'};
    int price[10]={11,2,3,4,5,6,7,8,9,10};
    int quantity[10]={2,3,4,5,8,5,10,15,24,14};
    int option;
    printf("1.Browse,2.Purchase: ");
    scanf("%d",&option);
    if (option==1)
    {
        int choice;
        do
        {
            printf("1.Display Items\n");
            printf("2.Display item,prices and quantities\n");
            printf("3.Display total inventory value\n");
            printf("4.Display lowest value\n");
            printf("5.Display highest value\n");
            printf("6.Exit\n");
            printf("Choose an option: ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                     displayItems(items);
                     printf("\n");break;
                case 2:
                     displayInventory(items,price,quantity);
                     break;
                case 3:
                     printf("%d\n",inventoryValue(price));break;
                case 4:
                     printf("%d \n",lowestPrice(price));break;
                case 5:
                     printf("%d\n",highestPrice(price));break;
                default:
                     break;
            }
        }while (choice!=6);
    }else if(option==2){
        char purchasing='y';
        while (purchasing=='y')
        {
            char itemChoice;
            int selectedItem=0;
            int wantedQuantity=0;
            displayItems(items);
            printf("\nSelect an item to purchase (one at a time): ");
            scanf(" %c",&itemChoice);
            for(int i=0;i<10;i++){
                if(items[i]==itemChoice){
                    selectedItem=i;
                }
            }
            printf("Available quantity: %d\n",quantity[selectedItem]);
            if(quantity[selectedItem]<=0){
                printf("Insufficient quantity!\n");
                break;
            }
            printf("Price for one: %d\n",price[selectedItem]);
            printf("Enter the quantity you want: ");
            scanf("%d",&wantedQuantity);
            if(quantity[selectedItem]<wantedQuantity){
                printf("Insuffient quanity!\n");
                break;
            }
            printf("Cost: %d\n",wantedQuantity*price[selectedItem]);
            quantity[selectedItem]-=wantedQuantity;
            printf("Still buying?y/n: ");
            scanf(" %c",&purchasing);
        }
    }else{
        printf("Invalid input!");
    }
    return 0;
}

//functions

void displayItems(char items[]){
    for(int i=0;i<10;i++){
        printf("item:%c ",items[i]);
    };
}

void displayInventory(char items[],int prices[],int quantities[]){
    for(int i=0;i<10;i++){
        printf("item: %c",items[i]);
        printf(" ");
        for (int j=0;j<1;j++){
            printf("quantity: %d",quantities[i]);
            printf(" ");
            printf("price: %d\n",prices[i]);
        }
                    
    }
}

int inventoryValue(int prices[]){
    int total=0;
    for(int i=0;i<10;i++){
        total+=prices[i];
    }
    return total;
}

int lowestPrice(int prices[]){
    int value=prices[0];
    for(int i=0;i<10;i++){
        if(prices[i]<value){
            value=prices[i];
        }
    }
    return value;
}

int highestPrice(int prices[]){
    int value=prices[0];
    for (int i = 0; i < 10; i++)
    {
        if(prices[i]>value){
            value=prices[i];
        }
    }
    return value;
    
}

