#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int ft_convert_hexa(char a, char b)
{
    int result;
    char *hexa;
    int i;
    int x;
    int r;

    a = ft_tolower(a);
    b = ft_tolower(b);
    hexa = "0123456789abcdef";
    x = 0;
    i = 0;
    r = 0;
    while(hexa[r++] != '\0')
    {
        if (hexa[r] == a)
            i = r;
        if (hexa[r] == b)
            x = r;
    }
    result = (i * 16) + (x * 1);
    return (result); 
}

int main()
{
    int a;

    a = ft_convert_hexa('0', '0');
    printf("%d\n", a);
}