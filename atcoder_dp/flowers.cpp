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
ll dp[100003];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,i,j;
	cin>>n;
	ll h[n+2], b[n+2];
	for(i=0;i<n;i++)
		cin>>h[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	dp[n-1] = b[n-1];
	ll ans = b[n-1];
	for(i=n-2;i>=0;i--)
	{
		for(j=i+1;j<n;j++)
		{
			if(h[j]>h[i])
			{
				dp[i]=max(dp[i], dp[j] + b[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout<<ans<<nl;
	return 0;
}