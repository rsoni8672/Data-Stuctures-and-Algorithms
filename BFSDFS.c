#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
struct node*next;};

struct queue
{int data;
struct queue*next;};

struct stack
{ int data;
struct stack*next;};

struct queue*front,*rear;
int main()
{int n,i,v,j,k,l,m,e,a,d,z,w,y,flag[n],flag2[n],arr[n],start,u,x;
printf("enter the no of nodes \n ");
scanf("%d%d",&n,&e);

void *arr2[n];


for(i=0;i<n;i++)
{struct node*head=NULL;
  arr2[i]=head;}
 

for(j=0;j<n;j++)
{      k=j+1;
       printf("enter the %dth node\n",j+1);
       scanf("%d",&arr[j]);
    
        printf("enter the no of nodes of %d\n",arr[j]);
         scanf("%d",&m);
         for(d=1;d<=m;d++)
            {
                 printf("enter the value of the connected node");
                 scanf("%d",&a);
       struct node*temp=(struct node*)malloc(sizeof(struct node));
                  temp->next=arr2[j];
                  arr2[j]=temp;
                  temp->data=a;              
            }
}






printf("enter the starting node\n");
scanf("%d",&start);
u=0;
  while(arr[u]!=start)
    {u++;}
printf("bfs\n");
flag[u]=1;
 struct node*add1=(struct node*)malloc(sizeof(struct node));
 add1->next=NULL;
 add1->data=start;
 front=add1;
 rear=add1;

 
struct node*temp5;
struct queue*delete;

while(front!=NULL)
{   u=0;
 
       while(arr[u]!=front->data)
       { u++;}
  temp5=arr2[u];
  
      while(temp5!=NULL)
           { v=0;
             while(arr[v]!=temp5->data)
             { v++;}
               
            if(flag[v]!=1)
              {struct queue*add=(struct queue*)malloc(sizeof(struct queue));
               add->data=temp5->data;
               add->next=NULL;
               rear->next=add;
               rear=add;
              flag[v]=1;
          
              }               
            temp5=temp5->next;

          }
     delete =front;
     printf("%d\t",front->data);		
     front=front->next;
     free(delete);
}
printf("\n");

z=0;
while(arr[z]!=start)
{ z++;}

   struct stack*t=(struct stack*)malloc(sizeof(struct stack));
   struct node*temp3;
   t->next=NULL;
   t->data=start;
struct node*top,*pop;
  top=t;
  temp3=top;
   printf("dfs\n");
 
while(top!=NULL)
{ z=0;

     while(arr[z]!=top->data)
      {z++;}

    temp3=arr2[z];
   
     pop=top;
printf("%d\t",top->data);
     top=top->next;
     free(pop);
    
    
    while(temp3!=NULL)
       {    w=0;
           while(arr[w]!=temp3->data)
              {w++;}
              
           if(flag2[w]!=1)
               { struct stack*push =(struct stack*)malloc(sizeof(struct stack));
                  push->data=temp3->data;
                  push->next=top;
                  top=push;
                  flag2[w]=1;
               
               }          
           temp3=temp3->next; 
       }

}
return 0;
}
