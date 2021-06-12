#include <bits/stdc++.h>
using namespace std;

void helper(int r, int c, vector<vector<char>> &s, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col)
{
    if(r == 9) {
        for(auto it: s) {
            for(auto i: it)
                cout<<i<<" ";
            cout<<endl;
        }

        cout<<endl;
        return;
    }

    if(c == 9) {
        helper(r+1, 0, s, mp, row, col);
        return;
    }
    if(s[r][c] != '.') {
        helper(r, c+1, s, mp, row, col);
        return;
    }
    
    for(int i=1; i<=9; i++) {
        int rw = r/3, cl = c/3;
        if(!mp[{rw, cl}][i] && !row[r][i] && !col[c][i]) {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            s[r][c] = i+'0';
            helper(r, c+1, s, mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            s[r][c] = '.';
        }
    }
}

void solveSoduku(vector<vector<char>> &s)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (s[i][j] != '.')
            {
                mp[{i / 3, j / 3}][s[i][j] - '0'] = 1;
                row[i][s[i][j] - '0'] = 1;
                col[j][s[i][j] - '0'] = 1;
            }
        }
    }

    helper(0, 0, s, mp, row, col);
}

int main()
{

    vector<vector<char>> soduku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSoduku(soduku);

    return 0;
}