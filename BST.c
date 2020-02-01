#include<stdio.h>
#include<stdlib.h>


struct node
{
int data;
struct node*left,*right;
};

struct node*root=NULL;


void create(int x)
{struct node*cnode,*temp,*temp1;
cnode=(struct node*)malloc(sizeof(struct node));
  cnode->data=x;
  cnode->left=NULL;
  cnode->right=NULL;

  if(root==NULL)
    { 
     root=cnode;
  
    }
  else
    { temp=root;
     temp1=NULL;
        while(temp!=NULL)
             {temp1=temp;
                if(cnode->data<temp->data)
                  {
                    temp=temp->left;
                  }
               else
                  {
                  temp=temp->right;                
                  }
             
            }       
    
    
    
    
    if(cnode->data<temp1->data)
     {  
     temp1->left=cnode;
     }
     
    else
      { temp1->right=cnode;
      }
}

}

void inorder(struct node*temp3)
  {

  if(temp3!=NULL)
    {
      inorder(temp3->left);
       printf("%d\t",temp3->data);
      inorder(temp3->right);


    }



}
 void delete()
  {int  del ;
  struct node*temp3;
   struct node*temp4;
   printf("enter node to be deletde\n");
   scanf("%d",&del);
   struct node*temp=root;

   struct node*temp2=NULL;
   while(temp!=NULL)
     { 
       
     if(temp->data==del)
            { break;
            }
      
     temp2=temp;
            if(temp->data>del)
              {
                    temp=temp->left;
              }
      
      
           if(temp->data<del)
              {
                 temp=temp->right;
              }     
     
      
      
     }
   
  
     
   
   
   
  if(temp->left==NULL)
    { 
     
    if(temp2->data<temp->data)
          temp2->right=temp->right;
     else
       temp2->left=temp->right;
    free(temp);
    }
    
    
    
    if(temp->right==NULL)
    { 
     if(temp2->data<temp->data)
       temp2->right=temp->left;
      else
       temp2->left=temp->left;
    
    free(temp);
    }
    
    if((temp->left==NULL)&&(temp->right==NULL))
       { if(temp2->data<temp->data)
            temp=temp->right;
            else
            temp=temp->left;
            
            free(temp);
       }
     

else 
   { 

       
                    temp3=temp->right ;
                    temp4=temp ;
                    while(temp3->left!=NULL)
                        {
                            temp4=temp3 ;
                            temp3=temp3->left ;
                        }
                    
                    temp->data=temp3->data ;
                   if(temp4!=temp)
                        temp4->left=temp3->right ;
                    else
                        temp4->right=temp3->right ;
                  
   free(temp3);
   
   
   struct node *check = root;
 //  printf("%p\n",check);
    }




}
















int main()
{

int i,data;
 
 
do
 {

  printf("press 1 to add element and -1 to exit");
  scanf("%d",&i);
   if(i!=-1)
  { printf("enter the data\n");
   scanf("%d",&data);
   create(data);}
   }while(i!=-1);
printf("the binary tree is");
struct node*temp2 = root;
inorder(temp2);
delete();
struct node*temp4=root;

inorder(temp4);
return 0;
}

