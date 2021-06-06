#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin>>n;
    cin.ignore();

    char sentence[n+1];

    cin.getline(sentence, n);
    cin.ignore();

    int i=0;
    int currentLen = 0, maxLen = 0;
    int st = 0, maxSt = 0;

    while(1)
    {
        if(sentence[i] == ' ' || sentence[i] == '\0')
        {
            maxLen = max(maxLen, currentLen);
            maxSt = max(st, maxSt);
            currentLen = 0;
            st = i+1;
        }
        else
        {
            currentLen++;
        }

        if(sentence[i] == '\0')
            break;
        i++;
    }

    cout<<maxLen<<endl;

    for(int i=0; i<maxLen; i++)
        cout<<sentence[maxSt+i];

    return 0;
}