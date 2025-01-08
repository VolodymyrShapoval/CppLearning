#include <iostream>
#include <string>

#ifndef PI
#define PI 3.14
#endif

#define tab "\t"
#define FOO1(x, y) ((x)*(y)+5)

using namespace std;

int main()
{
#ifdef FOO
	cout << FOO(23, 61) << endl;
#elif defined(FOO1)
	int a = -1;
	int b = FOO1(PI, a);
	string res = a < b ? "Cool!" : "Interesting!";
	cout << res << endl;
#endif

	return 0;
}

#undef PI
#undef tab
#undef FOO1