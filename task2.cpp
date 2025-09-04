#include<iostream>
using namespace std;

#define N 9
void printgrid(int grid[N][N])

{
    cout<<"-------------------------------"<<endl;
    for(int row = 0; row < N; row++)
    {
        cout<<"| ";
        for(int col = 0; col < N; col++)
        {
            if(grid[row][col] == 0)
                cout<<". ";
            else
                cout<<grid[row][col]<<" ";
            if((col + 1) % 3 == 0)
                cout<<"| ";
        }
        cout<<endl;
        if((row + 1) % 3 == 0)
            cout<<"-------------------------------"<<endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    for(int x = 0; x < N; x++)
        if(grid[row][x] == num || grid[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(grid[i + startRow][j + startCol] == num)
                return false;
    return true;
}


bool solveSudoku(int grid[N][N])
{
    for(int row = 0; row < N; row++)
    {
        for(int col = 0; col < N; col++)
        {
            if(grid[row][col] == 0)
            {
                for(int num = 1; num <= 9; num++)
                {
                    if(isSafe(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if(solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
}

bool iscompleteAndValid(int g[N][N])
{
    for(int i=0;i<9;i++){
        bool r[10]={0},c[10]={0};
        for(int j=0;j<9;++j){
            int a=g[i][j],b=g[j][i];
            if(a<1 || a>9 || b<1 || b>9 )return false;
            if(r[a] || c[b])return false;
            r[a]=c[b]=true;
        }
    }
    for(int br=0;br<3;br++){
        for(int bc=0;bc<3;bc++){
            bool seen[10]={0};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int v=g[br*3+i][bc*3+j];
                    if(seen[v])return false;
                    seen[v]=true;
                }
            }
        }
    }
    return true;
}

bool isSolutionValid(int original[N][N], int solved[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(original[i][j] != 0 && original[i][j] != solved[i][j])
                return false;
        }
    }
    return iscompleteAndValid(solved);
}

int main()
{
    int grid[N][N],original[N][N];
    cout<<"Enter the Sudoku puzzle (use 0 for empty cells):"<<endl;
    for(int i = 0; i < N; i++){
        cout<<"Enter row "<<i+1<<": ";
        for(int j = 0; j < N; j++){
            cin>>grid[i][j];
            original[i][j]=grid[i][j];
        }
    }
    cout<<"\nHere is the puzzle you Entered:"<<endl;
    printgrid(grid);
    cout<<"\nDo you want to solve this puzzle? (Yes/No): ";
    string choice;
    cin>>choice;
    if(choice == "Yes" ){
        if(solveSudoku(grid) && iscompleteAndValid(grid)){
            cout<<"\nSolution Found:"<<endl;
            printgrid(grid);
        }
        else{
            cout<<"\nSolver Failed ?"<<endl;
        }
        
    }
    else{
            cout<<"Okay,You can try solving it on your own!"<<endl;
        }
    int usergrid[N][N];
    cout<<"\nPlease enter your completed Sudoku solution(9x9): "<<endl;
    for(int i = 0; i < N; i++){
        cout<<"Enter row "<<i+1<<": ";
        for(int j = 0; j < N; j++){
            cin>>usergrid[i][j];
        }
    }
    if(isSolutionValid(original, usergrid)){
        cout<<"\nCongratulations! Your solution is correct."<<endl;
    }
    else{
        cout<<"\nSorry, your solution is incorrect."<<endl;
        cout<<"\nThe correct solution is:"<<endl;
        if (solveSudoku(grid)) {
            printgrid(grid);
        } else {
            cout << "No solution exists." << endl;
        }
    }
return 0;
        
}