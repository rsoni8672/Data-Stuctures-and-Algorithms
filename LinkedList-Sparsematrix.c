#include<stdio.h>
#include <stdlib.h>

typedef struct headNodes{
  int row, column;
  struct headNodes *next, *down, *right;

}hnode;

hnode *head = NULL;

typedef struct dataNodes{
  int row, column, value;
  struct dataNodes *down, *right;
}dnode;



void makeHead(int m, int n){
    int i;
    if(m > n) i = m;
    else i = n;

    for(int j = 0; j <= i; j++){

        hnode *temp, *p;
        p = (hnode*)malloc(sizeof(hnode));

        if(head == NULL){
            p->row = m;
            p->column = n;
            p->next = NULL;
            p->right = head;
            p->down = head;
            head = p;
            temp = p;
        }else{
            p->row = j;
            p->column = j;
            p->right = p;
            p->down = p;
            if(j == i) p->next = head;
            else p->next = NULL;
            temp->next = p;

            temp = p;
        }


    }
}



void addDataNode(int r, int c, int data){
    dnode *tempr;
    tempr = (dnode*)malloc(sizeof(dnode));

    tempr->row = r;
    tempr->column = c;
    tempr->value = data;
    hnode *temp = head->next, *temp1 = head->next, *tempHeadRow, *tempHeadColumn;
    while(temp->row != r) temp = temp->next;
    while(temp1->column != c) temp1 = temp1->next;
    tempHeadRow = temp;

    tempHeadColumn = temp1;

    // For row insertion
    if(temp->right == tempHeadRow){
        temp->right = tempr;
        tempr->right = tempHeadRow;

    }else{
        hnode *previous = temp;
        temp = temp->right;

        while(c>temp->column){

            temp = temp->right;
            previous = previous->right;

            if(temp == tempHeadRow) break;
        }

        previous->right = tempr;
        tempr->right = temp;
        printf("\n\nr,c,data %d,%d,%d done\n\n",tempr->row,tempr->column,tempr->value );
    }
    // For column insertion
    if(temp1->down == tempHeadColumn){
        temp1->down = tempr;
        tempr->down = tempHeadColumn;

    }else{
        hnode *previous = temp1;
        temp1 = temp1->down;

        while(r>temp1->row){

            temp1 = temp1-> down;
            previous = previous->down;

            if( temp1 == tempHeadColumn)
                break;
        }

        previous->down = tempr;
        tempr->down = temp1;
    }

}



void printMatrix(int r, int c){
    hnode *t = head;
    dnode *temp;
    printf(" _  ");
    for(int i = 0; i < c; i++) printf("     ");
    printf("_\n");
    for(int i = 0; i < r; i++){
        t = t->next;
        if(i == r - 1)printf("|_");
        else printf("|");
        temp = t;temp = temp->right;
        for(int j = 1; j <= c; j++){

            //printf("%d,%d,%d",temp->row,temp->column,temp->value);
            if(temp->column == j && temp != (dnode*)t){
                if(i == r - 1 && j == 1) printf("%4d",temp->value);
                else printf("%5d",temp->value);
                temp = temp->right;
            }else{
                if(i == r - 1 && j == 1) printf("%4d",0 );
                else printf("%5d",0 );
            }
        }
        if(i == r - 1) printf("   _|\n");
        else printf("    |\n");
    }
}

void main(){
    int m , n  , x , r, c, data;
    printf("Enter number of rows : ");
    scanf("%d",&m);
    printf("Enter number of columns : ");
    scanf("%d",&n);
    printf("Enter number of non-zero elements : " );
    scanf("%d",&x);

    makeHead(m,n);

    for(int i = 0; i < x; i++){
        printf("Enter row : ");
        scanf("%d",&r );
        printf("Enter column : ");
        scanf("%d",&c );
        printf("Enter data : ");
        scanf("%d",&data );
        addDataNode(r,c,data);


    }

    printMatrix(m,n );

}
