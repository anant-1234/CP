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
string s,t;
ll dp[3050][3050];
ll fx(ll i, ll j)
{
	if(i == s.length() || j == t.length())
	{
		return dp[i][j]=0;
	}
	if(dp[i][j]!=-10	)
		return dp[i][j];
	if(s[i] == t[j])
	{
		return dp[i][j] = 1 + fx(i+1, j+1);
	}
	else
	{
		return dp[i][j] = max(fx(i+1, j), fx(i, j+1));
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>s>>t;
	ll i,j;
	for(i=0;i<s.length()+10;i++)
	{
		for(j=0;j<t.length()+10;j++)
		{
			dp[i][j]=-10;
		}
	}
	fx(0,0);
	i=0, j=0;
	string ans = "";
	while(i<s.length() && j<t.length())
	{
		if(s[i]==t[j])
			ans += s[i], i++, j++;
		else if(dp[i+1][j] == dp[i][j])
			i++;
		else 
			j++;
	}
	cout<<ans<<nl;
	return 0;
}