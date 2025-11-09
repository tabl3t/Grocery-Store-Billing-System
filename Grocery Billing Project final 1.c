#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main(){
    int choice;

    while(1){
            if(choice==5){
                setColor(10);
                printf(">>Thank you for using the system<<");
                setColor(7);
                break;
            }


    setColor(10);
    printf("\t\t-------------------------------\n");
    printf("\t\t[SIMPLE GROCERY BILLING SYSTEM]\n");
    printf("\t\t===============================\n");
    setColor(7);

    setColor(10);
    printf("\n\n1. Add new item.");
    printf("\n\n2. View items in your cart.");
    printf("\n\n3. Generate bill.");
    printf("\n\n4. Delete item.");
    printf("\n\n5. Exit.");
    setColor(7);

    setColor(15);
    printf("\nEnter your choice: ");
    setColor(7);
    scanf("%d",&choice);

    switch(choice){
    case 1: add_item();
            break;
    case 2: view_item();
            break;
    case 3: generate_bill();
            break;
    case 4: delete_item();
            break;
    default:
            if(choice!=5){
            setColor(4);
            printf("Invalid choice!\n");
            setColor(10);
            printf("Try again please.\n");
            setColor(7);
            }


    }
    }

    return 0;
}


void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}


void add_item(){
    char itemname[20];
    unsigned int itemprice,itemquantity,UID;

    FILE *additem;

    additem = fopen("additem.txt","a");
    if(additem==NULL){
        printf("File not found!");
    }
    else{
        setColor(10);
        printf("\t\t\t------------------------\n");
        printf("\t\t\t[ADD ITEMS TO YOUR CART]\n");
        printf("\t\t\t========================\n");
        setColor(7);

        setColor(15);
        printf("Enter the name of item:");
        scanf("%s",&itemname);

        printf("Enter items UID:");
        scanf("%d",&UID);

        printf("Enter unit price:");
        scanf("%d",&itemprice);

        printf("Enter quantity:");
        scanf("%d",&itemquantity);
        setColor(7);

        fprintf(additem,"Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",itemname,UID,itemprice,itemquantity);
        setColor(10);
        printf("Item added successfully\n");
        setColor(7);

    }

    fclose(additem);
    printf("\nPress any key to continue\n");
    setColor(7);
    getch();
}

void view_item(){
    char itemname[20];
    int itemprice,itemquantity,UID;

    FILE *additem;
    additem = fopen("additem.txt","r");

    if(additem==NULL){
        printf("File not found!");
    }
    else{
        setColor(10);
        printf("\t\t\t--------------------\n");
        printf("\t\t\t[ITEMS IN YOUR CART]\n");
        printf("\t\t\t====================\n");
        setColor(7);
        while(!feof(additem)){
        fscanf(additem,"Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",&itemname,&UID,&itemprice,&itemquantity);
        setColor(3);
        printf("Item name: %s\n",itemname);
        printf("Item UID: %d\n",UID);
        printf("Unit price: %d\n",itemprice);
        printf("Quantity: %d\n\n",itemquantity);

        }



    }
    fclose(additem);
    setColor(15);
    printf("\nPress any key to continue\n");
    setColor(7);
    getch();

}

void generate_bill(){
    char itemname[20];
    int itemprice,itemquantity,UID,total,grandtotal=0;

    FILE *additem;
    additem= fopen("additem.txt","r");

    if(additem==NULL){
        printf("File not found!");
    }
    else{
        setColor(10);
        printf("\t\t\t------------\n");
        printf("\t\t\t[TOTAL BILL]\n");
        printf("\t\t\t============\n");
        setColor(3);
        printf("UID\tItem Name\tUnit price\tQty\tTotal\n");
        printf("---\t---------\t----------\t---\t-----\n\n");
        setColor(7);
        while(!feof(additem)){

        fscanf(additem,"Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",&itemname,&UID,&itemprice,&itemquantity);

        total = itemprice * itemquantity;
        int temp= total;
        grandtotal += temp;
        setColor(15);
        printf("%d\t%s\t\t%d\t%d Pc\t%d Tk\n",UID,itemname,itemprice,itemquantity,total);

        if(feof(additem)){
            setColor(3);
            printf("----------------------------------------------------\n");
            setColor(12);
            printf("Grand total:\t\t\t\t%d Tk",grandtotal);
            setColor(7);
        }

        }



    }
    fclose(additem);

    printf("\nPress any key to continue\n");
    getch();

}

void delete_item(){
        char itemname[20];
        unsigned int itemprice,itemquantity,UID,dltUID,choice2;
        int found=0;

        FILE *additem;
        FILE *temp;
        additem = fopen("additem.txt","r");
        temp = fopen("temp.txt","w");

        if(additem==NULL || temp==NULL){
            printf("File not found!");
        }
        else{
        setColor(10);
        printf("\t\t\t-----------------------------\n");
        printf("\t\t\t[DELETE ITEMS FROM YOUR CART]\n");
        printf("\t\t\t=============================\n");
        setColor(7);

        printf("Enter your items UID to delete(1XX):");

        scanf("%d",&dltUID);

        while(!feof(additem)){
            fscanf(additem,"Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",itemname,&UID,&itemprice,&itemquantity);
        if(dltUID!=UID){

            fprintf(temp,"Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",itemname,UID,itemprice,itemquantity);
        }
        else{
            setColor(10);
            printf("Deleting the folowing item:\n\n");
            setColor(7);
            printf("Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",itemname,UID,itemprice,itemquantity);
            setColor(4);
            printf("Are you sure you want to delete this?\n");
            printf("1.Yes\n");
            setColor(10);
            printf("2.No\n");
            setColor(7);
            printf("Your choice: ");
            scanf("%d",&choice2);

            if(choice2!=1 && choice2!=2){
                printf("invalid choice!\n");
                break;
            }
            else{
                if(choice2==2){
                    fprintf(temp,"Item name: %s\nItem UID: %d\nUnit price: %d Tk\nQuantity: %d Pc\n\n",itemname,UID,itemprice,itemquantity);
                }
                else{
                found = 1;
                continue;
                }
            }

        }


        }

        }


    fclose(additem);
    fclose(temp);
    if(choice2==1){
    remove("additem.txt");
    rename("temp.txt","additem.txt");
    }
    if(found==1 && choice2==1){
        setColor(10);
        printf("Item deleted successfully\n");
        setColor(7);
    }
    else if(found==0 && choice2<2){
        setColor(4);
        printf("Item with %d UID not found\n",dltUID);
        setColor(7);
    }
    if(choice2==2){
        setColor(10);
        printf("Following item remains in your cart.\n");
        setColor(7);
    }
    printf("\nPress any key to continue\n");
    getch();

}


