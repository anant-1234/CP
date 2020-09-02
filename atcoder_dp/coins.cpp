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
ld dp[3000][3000];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.precision(10);
	ll n,i,j;
	cin>>n;
	ld p[n+2],ans=0;
	for(i=0;i<n;i++)
		cin>>p[i];
	dp[0][0] = 1;
	for(i=1;i<=n;i++)
		for(j=0;j<=i;j++)
		{
			dp[i][j] = dp[i-1][j]*(1-p[i-1]); 
			if(j)
				dp[i][j] += dp[i-1][j-1]*p[i-1];
			if(i==n && j>=(n+1)/2)
			ans += dp[i][j];
		}
	cout<<ans<<nl;
	return 0;
}