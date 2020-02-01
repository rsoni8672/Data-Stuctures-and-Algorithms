//Code using Linear Probing

#include<stdio.h>
#include<string.h>

struct node
{
char name[20];
int uid;
}e[20];




int main()
{ int arr2[20],arr1[20];
  char na[20];
   int s,i,j,k,l,m,n;


   for(s=0;s<20;s++)
   {
     arr2[s]=0;
   } 




for(i=0;i<5;i++)
 {
      printf("enter the number and name");
      scanf("%d",&j);
      scanf("%s",na);
      l=j%20;
      n=l;


       for(m=0;m<i;m++)
         {  if(arr2[n]==0)
               {
                 break;
                }
     
          if(arr2[n]==1)
            {      n++;  
                if(n==19)
                 {
                  n=0;
                 }
             }
         }

    
 strcpy(e[n].name,na);
 e[n].uid=j;
 arr1[n]=j;
 arr2[n]=1;
 
 
 
  }
  
  
int a,b,c;  
printf("enter the number to be searched\n");
scanf("%d",&a);
b=a%20;

if(arr1[b]==a)
    {printf("The number you searched is %d\n with name %s\n",e[b].uid,e[b].name);
    }
else
  {
    while(arr1[b]!=a)
    {
      b++;  
      if(arr1[b]==a)
      { printf("The number you searched is %d\n with name %s\n",e[b].uid,e[b].name);
        break;
      }
      if(b==19)
      {
      b=0;
      }

    }

  }



return 0;
} 

//Code for Quadratic Probing

#include<stdio.h>
#include<string.h>

struct node
{
char name[20];
int uid;
}e[20];




int main()
{ int arr2[19],arr1[19];
  char na[20];
   int s,i,j,k,l,m,n;

int y;
   for(s=0;s<19;s++)
   {
     arr2[s]=0;
   } 




for(i=0;i<5;i++)
 {
      printf("enter the number and name");
      scanf("%d",&j);
      scanf("%s",na);

y=l;
         for(m=0;m<i;m++)
            {   
                y=(j+m^m)%19;
                   if(arr2[y]==0)
                       { break;
                        }
            }
arr2[y]=1;
e[y].uid=j;
strcpy(e[y].name,na);            
            
            
          }
  int u,z,v;      
printf("enter the number to be searched\n");
scanf("%d",&u);

if(e[v].uid==u)
   {}
for(z=0;z<19;z++)
{
  v=(u+z^z)%19;
if(e[v].uid==u)
   {printf("the number you searched is %d with name %s\n",e[v].uid,e[v].name);
   break;
   }
        

}
         
          
          
          
          
          
          
          
return 0;
          }  

