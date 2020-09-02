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
ll n,k;
ll a[102];
ll dp[102][100005];
ll vis[102][100005];
vector <ll> v;
ll fx(ll idx, ll k)
{
	// cout<<idx<<" "<<k<<nl;
	if(idx==n)
	{
		if(k==0)
			return dp[idx][k]=1;
		else
			return dp[idx][k]=0;
	}
	if(dp[idx][k]!=-1)
		return dp[idx][k];
	ll su=0;
	for(int i=0;i<=min(a[idx],k);i++)
	{
		if(dp[idx+1][k-i]!=-1)
			su = (su + dp[idx+1][k-i])%mod;
		else
			su = (su + fx(idx+1, k-i))%mod;
	}
	return dp[idx][k]=su;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll i,j;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<102;i++)
		for(j=0;j<100005;j++)
			dp[i][j]=-1;
	cout<<fx(0,k)<<nl;
	// for(i=0;i<=k;i++)
	// 	dp[n-1][i] = (i<=a[n-1])?1:0;
	// for(i=n-2;i>=0;i--)
	// {
	// 	ll su=0;
	// 	for(j=k;j>=max(0ll, k-a[i]);j--)
	// 		su = (su + dp[i+1][j])%mod;
	// 	dp[i][k] = su;
	// 	for(j=k-1;j>=0;j--)
	// 	{
	// 		su = (su - dp[i+1][j+1] + mod)%mod;
	// 		if(j-a[i]>=0)
	// 			su = (su + dp[i+1][j-a[i]])%mod;
	// 		dp[i][j] = su;
	// 	}
	// }
	// cout<<dp[0][k]<<nl;
	return 0;
}