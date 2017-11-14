#include<bits/stdc++.h>

using namespace std;
#define N 8
void printSolution(int board[N][N])
{
    static  int k = 1;
    printf("%d-\n",k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}
 

bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 

bool solveNQUtil(int board[N][N], int col)
{
   
    if (col == N )
    {
        printSolution(board);
        return true;
    }
 
 
    for (int i = 0; i < N; i++)
    {
        
        if ( isSafe(board, i, col) )
        {
           
            board[i][col] = 1;
 		    solveNQUtil(board, col + 1) ;
	       board[i][col] = 0;
        }
    }
 
   
    return false;
}
 

void solveNQ()
{
    int board[N][N] = { 
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0},
        {0, 0, 0, 0,0, 0, 0, 0}
    };
 
    if (solveNQUtil(board, 0))
    {
        printf("Solution does not exist");
        return ;
    }
 
    return ;
}
 
int main()
{
    solveNQ();
    return 0;
}
