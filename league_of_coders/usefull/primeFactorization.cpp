
#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int n)
{
    int N = n;
    vector<int> ans;
    int c = 2;
    while (n > 1 && c*c <= N)
    {
        if (n % c == 0)
        {
            ans.push_back(c);
            while (n%c == 0)
                n /= c;
        }
        else
            c++;
    }
    if (n != 1)
        ans.push_back(n);
    return ans;
}
/* Driver code */
int main()
{
    int n = 315;
    primeFactors(n);
    return 0;
}