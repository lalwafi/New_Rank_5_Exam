#include <stdio.h>

int main()
{
	fprintf(stderr, "error 1\n");
	fprintf(stderr, "error 2\n");
	fprintf(stdout, "yes\n");
	fprintf(stdout, "no\n");
	return -1;
}