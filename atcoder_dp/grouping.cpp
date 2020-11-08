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
const int L = (1<<17) + 5;
ll n;
ll a[17][17];
ll dp[L];
ll fx(ll mask, vector <ll> (&v)[17])
{
	ll idx = 0;
	for(int i=0;i<n;i++)
		idx += v[i].size();
	cout<<idx<<" "<<mask<<nl;
	if(idx == n)
		return 0;
	if(dp[mask] != -1e18)
		return dp[mask];
	for(int i=0;i<n;i++)
	{	
		ll score = 0;

		for(int j=0;j<v[i].size();j++)
		{
			if(idx == 2)
				cout<<v[i][j]<<" s\n";
			score += a[idx][v[i][j]];
		}
		if(idx == 2)
			cout<<score<<" ss  \n";
		v[i].pb(idx);
		dp[mask] = max(dp[mask], fx(mask | (1<<i), v) + score);
		v[i].pop_back();
	}
	return dp[mask];
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];
	for(i=0;i<L;i++)
		dp[i]=-1e18;
	vector <ll> v[17];
	cout<<fx(0, v)<<nl;
	return 0;
}