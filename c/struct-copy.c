#include <stdio.h>

struct example
{
	int value;
	char name[10];
};

void process(struct example se)
{
	se.value = 100;
	se.name[0] = 'X';
 	printf("  %d, %s\n",se.value, se.name);
}

void processPointer(struct example* se)
{
	se->value = 100;
	se->name[0] = 'X';
 	printf("  %d, %s\n",se->value, se->name);
}

int main()
{
 	struct example foo;
 	foo.value = 25;
 	foo.name[0] = 98;
 	foo.name[1] = 97;
 	foo.name[2] = 114;

 	printf("Initial values\n");
 	printf("  %d, %s\n",foo.value, foo.name);
 	printf("Processing without a pointer\n");
 	process(foo);
 	printf("After processing without a pointer\n");
 	printf("  %d, %s\n",foo.value, foo.name);
 	printf("Processing with a pointer\n");
 	processPointer(&foo);
 	printf("After processing with a pointer\n");
 	printf("  %d, %s\n",foo.value, foo.name);
 	return 0;
}
