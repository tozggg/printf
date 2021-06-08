#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	void	*ptr;

	ptr = malloc(1);

/* flag : '-' */

	printf("%-c\n", 'a');
	printf("%-s\n", "str");
	printf("%-p\n", ptr);
	printf("%-d\n", 5);
	printf("%-i\n", 5);
	printf("%-u\n", 5);
	printf("%-x\n", 5);
	printf("%-X\n", 5);


/* flag : '0' */

	printf("%0c\n", 'a');
	printf("%0s\n", "str");
	printf("%0p\n", ptr);
	printf("%0d\n", 5);
	printf("%0i\n", 5);
	printf("%0u\n", 5);
	printf("%0x\n", 5);
	printf("%0X\n", 5);


/* flag : '*' with 양수 */

	printf("%*c\n", 5, 'a');
	printf("%*s\n", 5, "str");
	printf("%*p\n", 5, ptr);
	printf("%*d\n", 5, 5);
	printf("%*i\n", 5, 5);
	printf("%*u\n", 5, 5);
	printf("%*x\n", 5, 5);
	printf("%*X\n", 5, 5);


/* flag : '*' with 0 */

	printf("%*c\n", 0, 'a');
	printf("%*s\n", 0, "str");
	printf("%*p\n", 0, ptr);
	printf("%*d\n", 0, 5);
	printf("%*i\n", 0, 5);
	printf("%*u\n", 0, 5);
	printf("%*x\n", 0, 5);
	printf("%*X\n", 0, 5);


/* flag : '*' with 음수 */

	printf("%*c\n", -5, 'a');
	printf("%*s\n", -5, "str");
	printf("%*p\n", -5, ptr);
	printf("%*d\n", -5, 5);
	printf("%*i\n", -5, 5);
	printf("%*u\n", -5, 5);
	printf("%*x\n", -5, 5);
	printf("%*X\n", -5, 5);


/* flag : '.*' with 양수 */

	printf("%.*c\n", 5, 'a');
	printf("%.*s\n", 5, "str");
	printf("%.*p\n", 5, ptr);
	printf("%.*d\n", 5, 5);
	printf("%.*i\n", 5, 5);
	printf("%.*u\n", 5, 5);
	printf("%.*x\n", 5, 5);
	printf("%.*X\n", 5, 5);


/* flag : '.*' with 0 */

	printf("%.*c\n", 0, 'a');
	printf("%.*s\n", 0, "str");
	printf("%.*p\n", 0, ptr);
	printf("%.*d\n", 0, 5);
	printf("%.*i\n", 0, 5);
	printf("%.*u\n", 0, 5);
	printf("%.*x\n", 0, 5);
	printf("%.*X\n", 0, 5);


/* flag : '.*' with 음수 */

	printf("%.*c\n", -5, 'a');
	printf("%.*s\n", -5, "str");
	printf("%.*p\n", -5, ptr);
	printf("%.*d\n", -5, 5);
	printf("%.*i\n", -5, 5);
	printf("%.*u\n", -5, 5);
	printf("%.*x\n", -5, 5);
	printf("%.*X\n", -5, 5);


	return (0);
}
