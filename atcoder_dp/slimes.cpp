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
ll cum[401][401];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,i,j,k;
	cin>>n;
	ll a[n+2];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			for(k=i;k<=j;k++)
				cum[i][j] += a[k];
	ll dp[n+2][n+2];	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j] = 1e18;
	for(i=0;i<n;i++)
		dp[i][i] = 0;
	for(i=n-1;i>=0;i--)
		for(j=0;j<n;j++)
			for(k=i;k<j;k++)
			{
				ll su = cum[i][k] + cum[k+1][j];
				if(i!=k)
					su += dp[i][k];
				if(k+1!=j)
					su += dp[k+1][j];
				dp[i][j] = min(dp[i][j], su);
			}
	cout<<dp[0][n-1]<<nl;
	return 0;
}