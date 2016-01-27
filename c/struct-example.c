#include <stdio.h>
int main()
{

	struct example1
	{
		int value;
		char name[10];
	};

	struct example2
	{
		int value;
		char name[10];
		char foo[10];
	};

	struct example3
	{
		int value;
		char name[10];
		char foo[10];
		char bar[1];
	};

	printf("sizeof example1 (int, 10 char array)                              = %lu\n", sizeof(struct example1));
	printf("sizeof example2 (int, 10 char array, 10 char array)               = %lu\n", sizeof(struct example2));
	printf("sizeof example3 (int, 10 char array, 10 char array, 1 char array) = %lu\n", sizeof(struct example3));

	return 0;
}