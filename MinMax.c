#include <stdio.h>


void minmax(int arr[],int left, int right,int *max,int *min){
	if(left==right){
		*max=*min=arr[left];
	}
	else if(left == (right-1)){
		if(arr[left]>arr[right]){
			*max=arr[left];
			*min=arr[right];
		}
		else{
				*max=arr[right];
				*min=arr[left];
		}
	}
	else{

		int leftmax,rightmax,leftmin,rightmin;
		int mid=(left+right)/2;
		minmax(arr,left,mid,&leftmax,&leftmin);
		minmax(arr,mid+1,right,&rightmax,&rightmin);

		if(leftmax>rightmax){
			*max=leftmax;
		}
		else{
			*max=rightmax;
		}

		if(leftmin>rightmin){
			*min=rightmin;
		}
		else{
			*min=leftmin;
		}



	}
}

void main(){
	int max,min;
	int size;
	// int arr[]={0,0,0,0,0,-1};
	printf("Enter the Size of Array:\n");
	scanf("%d",&size);
	int arr[size];
	printf("Enter %d element\n",size );
	for (int i = 0; i < size; i++) {
		/* code */
		scanf("%d",&arr[i]);

	}

	minmax(arr,0,size-1,&max,&min);
	printf("Max=%d Min=%d \n",max ,min);

	

	int TraMax,TraMin=arr[0];

	for(int i=0;i<size;i++){
		if(arr[i]>TraMax){
			TraMax=arr[i];

		}
		else if(arr[i]<TraMin){
			TraMin=arr[i];
			}
	}

}


