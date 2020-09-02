#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair <ll,ll>
#define nl "\n"
 
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,i,j,k;
	cin>>n>>k;
	ll h[n+2];
	for(i=0;i<n;i++)
		cin>>h[i];
	ll dp[n+2];
	dp[0]=0;
	for(i=1;i<n;i++)
	{
		ll mini = 1e18;
		for(j=i-1;j>=max(0ll, i-k);j--)
		{
			mini = min(mini, dp[j] + abs(h[j]-h[i]));
		}
		dp[i]=mini;
	}
	cout<<dp[n-1]<<nl;
	return 0;
}