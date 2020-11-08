#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld double
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define pll pair <ll,ll>
#define nl "\n"
const int L = 1<<22 + 5;
ll n;
ll a[22][22];
ll dp[L];
ll fx(ll mask)
{
	ll idx = __builtin_popcount(mask);
	if(idx == n)
	{
		if(mask == (1<<n) - 1)
			return dp[mask]=1;
		else
			return dp[mask]=0;
	}
	if(dp[mask] != -1)
		return dp[mask];
	ll su = 0;
	for(int i=0;i<n;i++)
	{
		if(mask&(1<<i))
			continue;
		if(a[idx][i])
		{
			if(dp[mask | (1<<i)] != -1)
				su = (su + dp[mask | (1<<i)])%mod;
			else
				su = (su + fx(mask | (1<<i)))%mod;
		}
	}
	return dp[mask] = su;
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	for(i=0;i<L;i++)
		dp[i]=-1;
	cout<<fx(0)<<nl;
	return 0;
}