#include <stdio.h>

#define TYPE "abcd"

int		main()
{
	int num = 5;
	int tmp1 = 10;
	int tmp2 = 5;

	char str[10] = "apple";

	printf("%.*-d", tmp2, num);
	return 0;
}
