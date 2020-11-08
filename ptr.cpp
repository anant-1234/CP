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
struct A{
	int a,b;
};
int main()
{
	ios_base::sync_with_stdio(false);
	int x = 10;
	int *y = &x;
	cout<<*y<<" "<<y<<endl;
	*y = 13;
	cout<<x<<endl;
	int **z = &y;
	cout<<z<<" "<<*z<<" "<<**z<<endl;
	void *all = NULL;
	A node = {1,2};
	A* head = &node;
	cout<<(*head).a<<" "<<head->a<<endl;

	int a[3]={0,1,2};
	int *b= a;
	cout<<b<<" "<<*b<<" "<<*(b+1)<<" "<<*(b+2)<<endl;
	cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<nl;
	b+=2;
	cout<<b<<" "<<*b<<nl;

	int *xx = new int[20];
	xx[0]=1;
	cout<<*xx<<endl;
	delete[] xx;

	// new int() initialised acc. to standard vals. new int is uninitialised.

	A *r = new A;
	A *rr = new A();
	cout<<r->a<<" "<<rr->a<<endl;

	// list of strings

	char *names[] = {"abc", "cde"};
	cout<<names<<" "<<*(names)<<" "<<*(names+1)<<endl;
	cout<<*names[0]<<" "<<*(names[0]+1)<<endl;


	return 0;
}