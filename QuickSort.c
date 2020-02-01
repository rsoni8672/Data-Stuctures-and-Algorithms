//Code for Quick Sort
#include<stdio.h>
int n;
int swap=0,comp=0;
void quicksort(int arr[],int l,int h){
	int i,j;
	int temp;

	if(l>h)
		return;

	i = l+1;
	j = h;

	while(1){
		while(arr[i]<arr[l]){
comp++;
			if(i<h)
				i++;
else
break;
		}
while(arr[j]>arr[l]){
comp++;
if(j>l)
j--;
else
break;
}

		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;

			swap++;

		}
		else{
			temp = arr[l];
			arr[l] = arr[j];
			arr[j] = temp;

swap++;
			quicksort(arr,l,j-1);
			quicksort(arr,j+1,h);

			break;
		}
	}
}

void main(){
	int l,h;
	int num;
	printf("Enter size : ");
	scanf("%d",&n);
	int arr[n];

	for(int i=0;i<n;i++){
		printf("Enter no : ");
		scanf("%d",&arr[i]);
	}

printf("\nGiven array : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

quicksort(arr,0,n-1);

	printf("\nSorted array : ");
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

	printf("\nSwaps : %d",swap);
	printf("\nComparisons : %d",comp);
}



void main(){
	int a[30],n,i;
	printf("Enter no of elements:");
	scanf("%d",&n);

	for(i=0;i<n;i++){
printf("Enter element :");
		scanf("%d",&a[i]);
	}
	printf("\nGiven array :");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}

	mergesort(a,0,n-1);

	printf("\nSorted array :");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}

	printf("\nSwaps : %d",swap);
	printf("\nComparisons : %d",comp);
}

