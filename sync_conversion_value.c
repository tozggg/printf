#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*void_ptr;
	int		*int_ptr;

	void_ptr = malloc(1);
	int_ptr = (int *)malloc(sizeof(int) * 1);

/* conversion : 'c' */

	printf("%c\n", 'a');
	printf("%c\n", "str");
	printf("%c\n", void_ptr);
	printf("%c\n", 5);
	printf("%c\n", 0);
	printf("%c\n", -5);
	printf("%c\n", NULL);
	printf("%c\n", 5);


/* conversion : 's' */

	printf("%s\n", 'a');
	printf("%s\n", "str");
	printf("%s\n", void_ptr);
	printf("%s\n", 5);
	printf("%s\n", 0);
	printf("%s\n", -5);
	printf("%s\n", NULL);
	printf("%s\n", int_ptr);



/* conversion : 'p' */

	printf("%p\n", 'a');
	printf("%p\n", "str");
	printf("%p\n", void_ptr);
	printf("%p\n", 5);
	printf("%p\n", 0);
	printf("%p\n", -5);
	printf("%p\n", NULL);
	printf("%p\n", int_ptr);


/* conversion : 'd' */

	printf("%d\n", 'a');
	printf("%d\n", "str");
	printf("%d\n", void_ptr);
	printf("%d\n", 5);
	printf("%d\n", 0);
	printf("%d\n", -5);
	printf("%d\n", NULL);
	printf("%d\n", int_ptr);


/* conversion : 'i' */

	printf("%i\n", 'a');
	printf("%i\n", "str");
	printf("%i\n", void_ptr);
	printf("%i\n", 5);
	printf("%i\n", 0);
	printf("%i\n", -5);
	printf("%i\n", NULL);
	printf("%i\n", int_ptr);


/* conversion : 'u' */

	printf("%u\n", 'a');
	printf("%u\n", "str");
	printf("%u\n", void_ptr);
	printf("%u\n", 5);
	printf("%u\n", 0);
	printf("%u\n", -5);
	printf("%u\n", NULL);
	printf("%u\n", int_ptr);


/* conversion : 'x' */

	printf("%x\n", 'a');
	printf("%x\n", "str");
	printf("%x\n", void_ptr);
	printf("%x\n", 5);
	printf("%x\n", 0);
	printf("%x\n", -5);
	printf("%x\n", NULL);
	printf("%x\n", int_ptr);


/* conversion : 'X' */
/*
	printf("%X\n", 'a');
	printf("%X\n", "str");
	printf("%X\n", void_ptr);
	printf("%X\n", 5);
	printf("%X\n", 0);
	printf("%X\n", -5);
	printf("%X\n", NULL);
	printf("%X\n", int_ptr);
*/

return (0);
}
