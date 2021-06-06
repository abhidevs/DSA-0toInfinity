#include<bits/stdc++.h>
using namespace std;

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            // code for swapping
            int temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}