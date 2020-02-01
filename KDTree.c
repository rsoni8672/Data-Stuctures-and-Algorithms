#include<stdio.h>
#include<stdlib.h>


struct node
{
  int x,y;
  struct node*left,*right;

};

struct node*root= NULL;
void create(int x,int y)
  { struct node*temp,*temp1;
  int j=0,k;
   struct node*cnode= (struct node*)malloc(sizeof(struct node));
   cnode->x=x;
   cnode->y=y;
   cnode->right= NULL;
   cnode->left=NULL;
   if(root==NULL)
   {
    root= cnode;
  
   }  
   
 
      
      
      
       else
    { temp=root;
     temp1=NULL;
     j=0;
        while(temp!=NULL)
             {temp1=temp;
                 
             k=j; 
             if(k%2==0)
              { 
               
               if(cnode->x<temp->x)
                  {
                    temp=temp->left;
                  }
               else
                  {
                  temp=temp->right;                
                  }
             }
             
             if(k%2!=0)
              {
              if(cnode->y<temp->y)
                  {
                    temp=temp->left;
                  }
               else
                  {
                  temp=temp->right;                
                  }
             }
             j++;
            }       
    
    
    
    if(j%2==0)
  {  
  if(cnode->x<temp1->x)
     { 
     temp1->left=cnode;
     }
     
    else
      { temp1->right=cnode;
      }
      
    }  
      
        if(j%2!=0)
   { 
   if(cnode->y<temp1->y)
     {  
     temp1->left=cnode;
     }
     
    else
      { temp1->right=cnode;
      }
   }
}

      

      
      }
   
   void display(struct node*temp)
       {
       if(temp!=NULL)
           {
             display(temp->left);
             printf("(%d,%d)",temp->x,temp->y);
             display(temp->right);
          
          
          }
       
       
       }
    
  
  
  
  
  
  
  
  


int main()
{
 
 int i,n,j,k,l;
 printf("enter the number of nodes");
 scanf("%d",&n);
 int x,y;
 struct node*temp1;
 for(i=0;i<n;i++)
 { 
 printf("Enter the values of xand y");
 scanf("%d%d",&x,&y);
 create(x,y);
 
}
temp1=root;

display(temp1);
return 0;
}



