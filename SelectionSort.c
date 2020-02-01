//Code for Selection Sort

#include<stdio.h>

int main()
{

int j= 0;
int n;
int min ;
int i= 1, k;
int count = 0;
printf("Enter the number of elements\n");
scanf("%d",&n);


int arr[n];
for( k=0;k<n;k++)
{
  printf("Enter the %d th element:\n",k+1 );
  scanf("%d",&arr[k]);

}

printf("Your input is :\n");
for(int l = 0; l<n;l++)
printf("%d\t",arr[l] );

printf("\n");
for(k=0;k<n;k++)
{ min = arr[k];
   for(i=k+1; i<n;i++)
  {
    if(arr[i]<min)
       { count++;
        j = i;
        min = arr[i];
         }
}

  if(min!=arr[k])
        {int temp = arr[k];
            arr[j] = arr[k];
            arr[k] =min; }
}
printf("count = %d\n",count);
printf("The sorted array is :");


for(int l = 0; l<n;l++)
{printf("%d\t",arr[l] );}

}

