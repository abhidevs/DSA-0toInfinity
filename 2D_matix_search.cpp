#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int target;

    cin>>n>>m;
    cin>>target;

    int matrix[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>matrix[i][j];
    }

    int row=0, col=m-1;
    bool found = false;

    while(row<n and col>=0)
    {
        if(matrix[row][col] == target)
        {
            found = true;
            break;
        }
        else if(matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    if (found)
    {
        cout<<"Element found at index "<<row<<", "<<col;
    } else
    {
        cout<<"Element "<<target<<" not found in the given matrix";
    }
    
    

    return 0;
}