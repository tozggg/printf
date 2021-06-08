#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define TYPE "abcd"
#define DEC_STR "0123456789"
#define HEX_STR_U "0123456789ABCDEF"
#define HEX_STR_L "0123456789abcdef"

int		get_size(long long n)
{
	int		ret;
	
	if (n == 0)
		return (1);
	ret = 0;
	while (n > 0)
	{
		printf("whiy");
		n /= 10;
		++ret;
	}
	return (ret);
}

void	assign_str(char *str, long long n, int size)
{
	long long tmp;

	str[size] = 0;
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	tmp = n;
	while (tmp > 0)
	{
		str[--size] = DEC_STR[tmp % 10];
		tmp /= 10;
	}
}

char	*ft_itoa(long long n, int *len)
{
	char	*ret;
	int		size;

	if (n < 0)
		n = -n;
	printf("==lld==%lld\n", n);
	size = get_size(n);
	printf("====%d\n", size);
	if (!(ret = (char *)malloc(sizeof(size + 1))))
	{
		*len = 0;
		return (NULL);
	}
	assign_str(ret, n, size);
	*len = size;
	return (ret);
}

char 	*make_padding(char c, int size)
{
	char	*ret;
	int		i;

	if (size < 0)
		size = 0;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
	{
		ret[i] = c;
		++i;
	}
	ret[i] = 0;
	return (ret);
}

int		main()
{
	int num = -50000;
	int tmp1 = 10;
	int tmp2 = -3;

	char str2[10] = "apple";

	char c = 'a';

	int n = printf("%.d", 0);
	int m = write(1, "", 1);

	void *p = malloc(1);

	int nn = printf("%.p", 0);
	printf("\n%d", nn);

	printf("========================\n");

	char *strr = make_padding('0', 5);
	printf("\n%s\n", strr);

	return 0;
}
