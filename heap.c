#include<stdio.h>
#include<stdlib.h>

int size1;
int left(int i)
{
	return 2*i ;
}

int right(int i)
{
	return (2*i + 1);
}

int parent(int i){
	return (i/2);
}

int maxHeap(int heap[] , int i , int size)
{
	int l,r,largest ,temp ;
	int * p;
	
	l = left(i);
	r = right(i);
	
	if(( l <= size ) && ( heap[l] > heap[i]))
		largest = l;
	
	else 
		largest = i;
		
	if(( r<= size ) && ( heap[r] > heap[largest]))
		largest = r;
		
	if(largest != i)
	{
		temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		maxHeap(heap , largest , size);
		
		
	}	
	
}




void main()
{
	int size,i,temp ;
	int *h;
	
	printf("Enter the no of elements\n");
	scanf("%d",&size);
	size1 = size;
	int heap[size + 1];
	
	for(i=1 ; i<=size ; i++)
	{
		printf("Enter element %d : ",i);
		scanf("%d",&heap[i]);
		
	}
	
	for(i = size/2 ; i>=1;i--)
	{
		 maxHeap(heap , i , size );
	
	}
	
	printf("The MaxHeap formed is\n");
	
	for(i=1 ; i<= size ; i++)
	{
		printf("%d\n",heap[i]);
		
		
	}	
		
	
	
	for(i=size ; i>=2;i--)
	{
		temp = heap[1];
		heap[1] = heap[i];
		heap[i] = temp;
		size1--;
		maxHeap(heap,1,size1);
		
		
	
	}
	
	printf("\n");
	
	printf("The Sorted Heap is\n");
	
	for(i=1 ; i<= size ; i++)
	{
		printf("%d\n",heap[i]);
		
	}	
		
		
	
	
}
