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
ll nex[102][100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>wt;
	ll i,j;
	for(i=0;i<n;i++)
		cin>>w[i]>>v[i];
	for(i=0;i<102;i++)
		for(int j=0;j<100005;j++)
			dp[i][j]=-1;
	for(i=0;i<=wt;i++)
	{
		dp[n-1][i] = (i<w[n-1])?0:v[n-1];
		nex[n-1][i] = (i<w[n-1])?0:1;
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=wt;j>=0;j--)
		{
			dp[i][j] = dp[i+1][j];
			nex[i][j] = 0;
			if(j >= w[i] && dp[i+1][j-w[i]] + v[i] > dp[i][j])
			{
				dp[i][j] = dp[i+1][j-w[i]] + v[i];
				nex[i][j] = 1;
			}
		}
	}
	cout<<dp[0][wt]<<nl;
	vector <ll> lis;
	ll id = 0, wt_ = wt;
	while(id<n)
	{
		if(nex[id][wt_] == 1)
		{
			lis.pb(v[id]);
			wt_ -= w[id];
			id++;
		}
		else
			id++;
	}
	ll ans = 0;
	for(i=0;i<lis.size();i++)
	{
		cout<<lis[i]<<" ";
		ans += lis[i];
	}
	cout<<nl;
	cout<<ans<<nl;
	return 0;
}
