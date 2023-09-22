#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Write your code here
    string str;
    cin >> str;
    long long int cnt = 0;
    long long maxr = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == str[i + 1])
        {
            cnt++;
        }
        else
        {
            maxr = max(cnt, maxr);
            cnt = 0;
        }
    }
    maxr = max(cnt, maxr);
    cout << maxr + 1 << endl;
    return 0;
}
