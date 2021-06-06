#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int num) 
{
    int ans = 0;
    int x = 1;

    while(num>0)
    {
        int y = num%10;
        ans += x*y;
        x*=2;
        num/=10;
    }

    return ans;
}

int octalToDecimal(int num)
{
    int ans = 0;
    int x = 1;

    while(num>0)
    {
        int y = num%10;
        ans += x*y;
        x*=8;
        num/=10;
    }

    return ans;
}

int hexadecimalToDecimal(string num)
{
    int ans = 0;
    int x = 1;
    int s = num.size();

    for(int i=s-1; i>=0; i--){
        if(num[i] >= '0' && num[i] <= '9')
        {
            ans += x*(num[i] -'0');
        } else if(num[i] >= 'A' && num[i] <= 'F')
        {
            ans += x*(num[i] - 'A' + 10);
        }
        x*=16;
    }

    return ans;
}

int decimalToBinary(int num)
{
    int x = 1;
    int ans = 0;
    
    while(x <= num)
        x *= 2;
    x /= 2;

    while (x>0)
    {
        int lastDigit = num/x;
        num -= lastDigit*x;
        x /= 2;
        ans = ans*10 + lastDigit;
    }

    return ans;
}

int decimalToOctal(int num)
{
    int x = 1;
    int ans = 0;
    
    while(x <= num)
        x *= 8;
    x /= 8;

    while (x>0)
    {
        int lastDigit = num/x;
        num -= lastDigit*x;
        x /= 8;
        ans = ans*10 + lastDigit;
    }

    return ans;
}

string decimalToHexadecimal(int num)
{
    int x = 1;
    string ans = "";

    while (x <= num)
        x *= 16;
    x /= 16;

    while (x>0)
    {
        int lastDigit = num/x;
        num -= lastDigit*x;
        x /= 16;

        if(lastDigit <= 9)
            ans = ans + to_string(lastDigit);
        else
        {
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);
        }
    }
    return ans;
}

int main() {
    
    int n;
    cin>>n;

    cout<<decimalToHexadecimal(n)<<endl;
    return 0;
}