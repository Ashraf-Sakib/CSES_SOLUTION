#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long rsum=1LL*n*(n+1)/2;
    vector<int> a;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
  long long int sum=0;
   for(int i=0;i<n-1;i++)
   {
    sum+=a[i];
   }
   //cout<<sum<<endl;
  long long int ans=rsum-sum;
   cout<<ans<<endl;
    return 0;
}
