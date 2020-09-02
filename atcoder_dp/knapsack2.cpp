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
ll dp[2][100005];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,wt,i,j,ans;	
	cin>>n>>wt;
	ll w[n+2],v[n+2];
	for(i=0;i<n;i++)
		cin>>w[i]>>v[i];
	if(n==1)
	{
		cout<<v[0]<<nl;
		return 0;
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<=100005;j++)
			dp[i][j]=1e10;
	}
	dp[1][v[n-1]]=w[n-1];
	dp[1][0]=0;
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<100005;j++)
		{
			dp[0][j] = dp[1][j];
			if(j>=v[i])
			{
				dp[0][j] = min(dp[0][j], dp[1][j-v[i]] + w[i]);
			}
		}
		for(j=0;j<100005;j++)
			dp[1][j]=dp[0][j];
	}

	for(i=0;i<100005;i++)
	{
		if(dp[0][i] <= wt)
			ans = i;
	}
	cout<<ans<<nl;
	return 0;
}