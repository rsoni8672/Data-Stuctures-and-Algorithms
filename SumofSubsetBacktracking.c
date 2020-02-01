#include<stdio.h>


int count,d=5,a[10];
int w[]= {1,3,4,5,7};
void Sum_Subset(int sum,int index,int Remaining_sum)
{
	int i;
	a[index]=1;
	if(sum+w[index]==d)
    	{
        	printf("\n Solution = %d: ",++count);
        	for(i=0; i<=index; i++)
            	{
                	if(a[i]==1)
                    	printf(" %d",w[i]);
            	}
    	}
	else if(sum+w[index]+w[index+1] <=d)
    	Sum_Subset(sum+w[index],index+1,Remaining_sum-w[index]);
	if((sum+Remaining_sum-w[index]>=d)&&(sum+w[index+1])<=d)
    	{
        	a[index]=0;
        	Sum_Subset(sum,(index+1),Remaining_sum-w[index]);
    	}
}

int main()
{
	int sum=0,i,n;
	n=5;

	for(i=0; i<n; i++)
    	sum +=w[i];
	if(sum < d)
    	{
        	printf("\n There is no solution");
    	}
	printf("\n The solution Exists");
	count =0;
	Sum_Subset(0,0,sum);
	return 0;
}

