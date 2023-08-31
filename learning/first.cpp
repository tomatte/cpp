#include <stdio.h>

namespace Test {
	int x = 1;
	int f(void){return 2;}
	char *hi(void){return "Hi!";}
}

namespace Eba {
	int x = 9999;
	void f(void) {printf("ayehaaaaaaaa\n");}
}

namespace Ole = Eba;

int x = 42;
int f(void){return -1;}

int main(void) {
	printf("x: %d\n", Test::x);
	printf("f: %d\n", Test::f());
	printf("hi: %s\n", Test::hi());

	printf("\nx: %d\n", Eba::x);
	Eba::f();

	Ole::f();

	printf("x: %d\n", x);
	printf("f: %d\n", f());
	printf("x: %d\n", ::x);
	printf("f: %d\n", ::f());
	return 0;
}
