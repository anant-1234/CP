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
 
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,i,j;
	cin>>n;
	ll a[n+2][3];
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	ll dp[n+2][3];
	for(i=0;i<3;i++)
		dp[0][i]=a[0][i];
	for(i=1;i<n;i++)
	{
		dp[i][0] = a[i][0]+max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = a[i][1]+max(dp[i-1][2], dp[i-1][0]);
		dp[i][2] = a[i][2]+max(dp[i-1][1], dp[i-1][0]);
	}
	cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<nl;
	return 0;
}