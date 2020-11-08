#include <bits/stdc++.h>
using namespace std;

struct node {
	int x,y;
};
class A{
public:
	static node n;
};
node A::n={1,2};
// A::x++;
int A()
{
	static int x = 10;
	x += 20;
	cout<<x<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cout<<A::n.x<<A::n.y<<endl;
	A();

	return 0;
}

// static vs global (file scope "extern" makes global accessible across other files in the modules)

// static and global both get initialized during compile time.
// in-class static cannot be initialized in class definition.
// https://www.geeksforgeeks.org/memory-layout-of-c-program/ 

// static and global go to Data segements (initialized or uninitialized)

// dynamic memory allocation happens in Heap (new, malloc, etc.)
// other allocation happens in the stack
