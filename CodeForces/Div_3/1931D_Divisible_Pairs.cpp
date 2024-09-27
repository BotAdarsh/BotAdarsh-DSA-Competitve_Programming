#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,x,y;
    cin>>n>>x>>y;

    vector<int> a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    map<pair<int,int>,int> hash; // to store values 
    int ans = 0;

    for(int i = 0;i<n;i++){
        int add = a[i] % x;
        int sub = a[i] % y;

        ans += hash[{(x - add) % x,sub}];// add the number of complements exsist

        hash[{add,sub}]++;// increase the occurance of the key by one
    }

    cout<<ans<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
