#include<stdio.h>

struct node
{
  int data;
  int set;

}node[10];

int main()
{
  int arr[6][6] = {{0,7,99,8,99,99},{7,0,6,3,99,99},{99,6,0,4,2,5},{8,3,3,0,3,99},{99,99,99,3,0,2},{99,99,99,99,2,0}};
  int set_final = 10;
 for(int i = 0;i<6;i++)
 {
   node[i].data = i;
   node[i].set  = i;
   

 }
 for(int i =0;i<6;i++)
 {
   for(int j = 0;j<6;j++)
   { printf("%d\t",arr[i][j] );
   }
printf("\n");
 }
 int set_i =0;
 int set_j =0;
 int all_clear = 1;
 int min =arr[0][1];
 int min_i = 0;
 int min_j = 0;
 int status = node[0].set;
 int count = 1;
 for(;;)
 {
   for(int i = i;i<6;i++)
   {
 	if(status == node[i].set)
   	{
     	count= count +1;
   	}

   }
   if(count == 6)
 	{break;}

  min_i = 0;
  min_j = 0;

  min = arr[0][1];
   for(int i =0;i<6;i++)
   {
 	for(int j = i+1;j<6;j++)
 	{ //printf("i = %d j = %d val = %d\n", i,j, arr[i][j]);
    	if(arr[i][j]>0)
   	{
     	if(min>=arr[i][j])
       	{
         	min = arr[i][j];
         	min_i = i;
         	min_j = j;
       	}
   	}
 	}

   }

  // printf("MIN EDGE is BETWEEN %d and %d val = %d\n", min_i,min_j, arr[min_i][min_j]);

   if(node[min_i].set!= node[min_j].set)
   {
	//printf("Set 1 = %d and Set 2 = %d\n",node[min_i].set,node[min_j].set);
	printf("Edge between %d and %d\n", min_i,min_j);
	set_i = node[min_i].set;
	set_j = node[min_j].set;
set_final++;
	for(int m = 0;m<6;m++)
	{
  	if(node[m].set == set_i || node[m].set == set_j)
   	{
     	node[m].set = set_final;

   	}
	}
	node[min_i].set = node[min_j].set = set_final;

	{
  //  printf("Set_i = %d and set_j = %d\n", set_i,set_j);
  }
	//printf("Set 1 = %d and Set 2 = %d\n",node[min_i].set,node[min_j].set);
  //  set_final++;





   }


   arr[min_i][min_j] = 99;
   //if all equal break
  // //find_min_edge();
   //check different SET
  //add to same SET
   //set that edge to 99
 }


}

