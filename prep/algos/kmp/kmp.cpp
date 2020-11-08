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
vector <ll> kmp(string s)
{
	ll i,n=s.length();
	vector <ll> f;
	f.pb(0);
	for(i=1;i<n;i++)
	{
		ll j = f[i-1];
		while(s[j]!=s[i] && j)
			j=f[j-1];
		if(s[i]==s[j])
			j++;
		f.pb(j);
	}
	return f;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string s,t;
	ll i,ans=0;
	cin>>s>>t;
	string str = s+"#"+t;
	vector <ll> f = kmp(str);
	for(i=s.length()+1;i<str.length();i++)
	{
		if(f[i]==s.length())
			ans++;
	}
	cout<<ans<<nl;
	return 0;
}