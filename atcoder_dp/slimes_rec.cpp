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
ll cum[402][402];
ll dp[402][402];
ll n;
ll fx(ll i, ll j)
{
	if(i>=n || j>=n)
		return dp[i][j] = 1e18;
	if(dp[i][j] != 1e18)
		return dp[i][j];
	for(int k=i;k<j;k++)
	{
		ll su = cum[i][k] + cum[k+1][j];
		if(i!=k)
			su += fx(i, k);
		if(k+1!=j)
			su += fx(k+1, j);
		dp[i][j] = min(dp[i][j], su);
	}
	return dp[i][j];
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll i,j,k;
	cin>>n;
	ll a[n+2];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			for(k=i;k<=j;k++)
				cum[i][j] += a[k];
	for(i=0;i<402;i++)
		for(j=0;j<402;j++)
			dp[i][j] = 1e18;
	cout<<fx(0, n-1)<<nl;
	return 0;
}