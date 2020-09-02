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
ll dp[102][100005]; 
ll f(ll idx, ll wt)
{
	if(wt < 0)
		return -1e18;
	if(idx == n)
		return 0;
	if(dp[idx][wt] != -1)
		return dp[idx][wt];	
	return dp[idx][wt] = max(f(idx+1, wt), f(idx+1, wt-w[idx])+v[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>wt;
	ll i;
	for(i=0;i<n;i++)
		cin>>w[i]>>v[i];
	for(i=0;i<102;i++)
		for(int j=0;j<100005;j++)
			dp[i][j]=-1;
	cout<<f(0, wt)<<nl;
	return 0;
}
