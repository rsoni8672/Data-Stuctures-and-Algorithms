#include <stdio.h>
#include <stdlib.h>
int n, distance[10][10], visited[10], total_cost=0;
int find_minimum(int c)
{
 int i, nc=99;
 int min=99,kmin;
 for(i=0;i < n;i++)
 {
  if((distance[c][i]!=0)&&(visited[i]==0))
   if(distance[c][i]+distance[i][c] < min)
   {
	min=distance[i][0]+distance[c][i];
	kmin=distance[c][i];
	nc=i;
   }
 }
 if(min != 99)
  total_cost += kmin;
 return nc;
}
void tsp(int city)
{
 int i,ncity;
 visited[city] = 1;
 printf("%d >> ",city + 1);
 ncity = find_minimum(city);
 if(ncity == 99)
 {
  ncity = 0;
  printf("%d", ncity+1);
  total_cost += distance[city][ncity];
  return;
 }
 tsp(ncity);
}
void main(){
 printf("Enter number of vertices:: ");
 scanf("%d", &n);
 printf("\nEnter distance matrix:: \n");
 for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
   scanf("%d", &distance[i][j]);
  }
  visited[i]=0;
 }
 printf("\nShortest path traced: \n");
 tsp(0);
 printf("\n\nMinimum total_cost:");
 printf("%d",total_cost);
}

