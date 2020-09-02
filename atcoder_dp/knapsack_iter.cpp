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
ll n,wt;
ll w[102], v[102];
ll dp[2][100005]; 
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>wt;
	ll i,j;
	for(i=0;i<n;i++)
		cin>>w[i]>>v[i];
	for(i=0;i<2;i++)
		for(int j=0;j<100005;j++)
			dp[i][j]=-1;
	if(n==1)
	{
		cout<<v[0]<<nl;
		return 0;
	}
	for(i=0;i<=wt;i++)
		dp[1][i] = (i<w[n-1])?0:v[n-1];
	for(i=n-2;i>=0;i--)
	{
		for(j=wt;j>=0;j--)
		{
			dp[0][j] = dp[1][j];
			if(j >= w[i])
				dp[0][j] = max(dp[1][j-w[i]] + v[i], dp[0][j]);
			dp[1][j] = dp[0][j];
		}
	}
	cout<<dp[0][wt]<<nl;
	return 0;
}