#include <string>
#include <iostream>
#include <vector>

using namespace std;



void printSudoku(int arr[9][9])
{
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++)
        {
            cout << arr[r][c] << " " ;
        }
        cout << endl;
    }
    cout << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
}

bool canPlace(int arr[9][9] , int row, int col, int n)
{
    if(arr[row][col]!= 0) return false;
    bool status = true;
    int gridx = (col / 3) * 3, gridy = ( row / 3 ) * 3; 

    for(int i = 0; i < 9; i++)
    {
        if(arr[row][i] == n) { status = false; break;}
        if(arr[i][col] == n) { status = false; break;}
        if(arr[gridy + i / 3][gridx + i % 3] == n) 
        { 
            status = false; break;
        }

        return false;
    }
}

vector<int> findPlacebles(int arr[9][9], int r, int c)
{
    vector<int> cps= {};
    for(int i = 0; i <= 9; i++)
    {
        if(canPlace(arr, r,c,i))
            cps.push_back(i); // ajoute a la fin des elements du vecteur 
    }
    return cps;

}

bool solveSudoku(int arr[9][9], int row, int col)
{
    if( row > 8 ) return true;

    vector<int> placeables = findPlacebles(arr, row, col);

    if( placeables.size() == 0 ) return false;

    bool status = false;

    

    return status;




}


int main()
{
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    printSudoku(board);

    return 0;
}