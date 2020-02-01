#include<stdio.h>
#include<stdbool.h>
int N =8;
int board[8][8] =
{
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};

bool is_safe(int row, int col)
{

  for(int i = 0;i<col;i++)
  {
	if(board[row][i] == 1)
     	return false;

  }
int m,n;


  for(m =row, n = col; m >= 0 && n >= 0 ; m--,n--)
  {
	if(board[m][n]== 1)
  	return false;
  }

  int a,b;

  for(a = row, b = col; a<8 && b>=0 ; a++, b--)
 	{
   	if(board[a][b] == 1)
     	return false;
 	}
return true;
}

bool solve_queen( int col)
{
 if(col>=8)
  return true;
for(int i = 0; i<8; i++)
{
  if(is_safe(i,col) == true)
  {
	board[i][col] = 1;

	if(solve_queen( col+1) == true)
  	return true;
	board[i][col] = 0;
  }
}
return false;
}


int main()
{

if(solve_queen(0) == true)
 {printf("Solution exist\n");
 for(int i =0; i<8;i++)
 {
   for(int j =0;j<8;j++)
   {printf("%d\t",board[i][j]);
 }
 printf("\n");
 }
}

else
printf("Fail");
return 0;
}


