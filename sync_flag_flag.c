#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*ptr;

	ptr = malloc(1);

/* flag : '-' && '0' */

	printf("%-0c\n", 'a');
	printf("%-0s\n", "str");
	printf("%-0p\n", ptr);
	printf("%-0d\n", 5);
	printf("%-0i\n", 5);
	printf("%-0u\n", 5);
	printf("%-0x\n", 5);
	printf("%-0X\n", 5);


/* flag : '-' && '*' */

	printf("%-*c\n", 6, 'a');
	printf("%-*s\n", 6, "str");
	printf("%-*p\n", 6, ptr);
	printf("%-*d\n", 6, 5);
	printf("%-*i\n", 6, 5);
	printf("%-*u\n", 6, 5);
	printf("%-*x\n", 6, 5);
	printf("%-*X\n", 6, 5);


/* flag : '-' && '.*' */

	printf("%-.*c\n", 6, 'a');
	printf("%-.*s\n", 6, "str");
	printf("%-.*p\n", 6, ptr);
	printf("%-.*d\n", 6, 5);
	printf("%-.*i\n", 6, 5);
	printf("%-.*u\n", 6, 5);
	printf("%-.*x\n", 6, 5);
	printf("%-.*X\n", 6, 5);



/* flag : '0' && '*' */

	printf("%0*c\n", 6, 'a');
	printf("%0*s\n", 6, "str");
	printf("%0*p\n", 6, ptr);
	printf("%0*d\n", 6, 5);
	printf("%0*i\n", 6, 5);
	printf("%0*u\n", 6, 5);
	printf("%0*x\n", 6, 5);
	printf("%0*X\n", 6, 5);


/* flag : '0' && '.*' */

	printf("%0.*c\n", 6, 'a');
	printf("%0.*s\n", 6, "str");
	printf("%0.*p\n", 6, ptr);
	printf("%0.*d\n", 6, 5);
	printf("%0.*i\n", 6, 5);
	printf("%0.*u\n", 6, 5);
	printf("%0.*x\n", 6, 5);
	printf("%0.*X\n", 6, 5);


/* flag : '*' && '.*' */

	printf("%*.*c\n", 6, 6, 'a');
	printf("%*.*s\n", 6, 6, "str");
	printf("%*.*p\n", 6, 6, ptr);
	printf("%*.*d\n", 6, 6, 5);
	printf("%*.*i\n", 6, 6, 5);
	printf("%*.*u\n", 6, 6, 5);
	printf("%*.*x\n", 6, 6, 5);
	printf("%*.*X\n", 6, 6, 5);

	return (0);
}
