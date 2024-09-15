#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
    int n;
    cin>>n;

   vector<int> x(n),y(n);
   for(int i = 0;i<n;i++) cin>>x[i];
   for(int i = 0;i<n;i++) cin>>y[i];

   vector<pair<int,int>> diff(n);
   for(int i = 0;i<n;i++){
    diff[i].first = y[i] - x[i];
    diff[i].second = i;
   }

   sort(diff.begin(),diff.end());

   int i = 0,j = n-1,ans = 0;
   while(j > i){
    while(j > i && diff[i].first + diff[j].first < 0){
        i++;
    }

    if(j <= i)break;

    ans++;
    j--;
    i++;
   }

   cout<<ans<<"\n";
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
