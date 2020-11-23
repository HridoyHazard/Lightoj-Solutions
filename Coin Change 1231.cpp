#include <bits/stdc++.h>
#define ll long long
#define mod 100000007

using namespace std;

ll coins[52], times[52];
ll n,k;
ll dp[52][1008];

ll call(ll pos, ll feas)
{
    if(feas==0) return 1;
    if(pos==n) return 0;

    if(dp[pos][feas]!=-1) return dp[pos][feas];

    ll res=0;

    for(ll j=0; j<=times[pos] && feas-j*coins[pos]>=0 ;j++)
    {
        res+= call(pos+1,feas-j*coins[pos])%mod;
    }
    return dp[pos][feas]=res%mod;
}

int main()
{
    ll T,cs=0;
    scanf("%lld", &T);
    while(T--)
    {
        memset(dp, -1, sizeof dp);

        scanf("%lld%lld", &n, &k);
        for(ll i=0;i<n;i++)cin>>coins[i];
        for(ll i=0;i<n;i++)cin>>times[i];

        cout<<"Case "<<++cs<<": "<<call(0,k)<<endl;
    }
    return 0;
}
