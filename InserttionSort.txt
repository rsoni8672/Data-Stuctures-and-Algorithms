//Code for Insertion Sort:
#include<stdio.h>

int  main()
{
int n, count =0;
printf("Enter the no of elements");
scanf("%d",&n);
int arr[n];
for(int k=0;k<n;k++ )
{
  printf("Enter the %d th element\n",k+1 );
  scanf("%d",&arr[k]);
}

  for(int i = 0;i<n; i++ )
  {
    for(int j =i+1; j>0; j--)
    {
      if(arr[j]<arr[j-1])
      { count++;
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
      }
      else
      break;
    }
  }

printf("Comparisions = %d\n", count);
printf("The sorted array is\n");
  for(int l = 0; l<n;l++)
printf("%d\t",arr[l] );

  return 0;
}
