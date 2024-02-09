#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str)
{
    while (*str)            // while (*str != '\0'). Iterates through the string until the null terminator is reached.
    {
        write(1, str, 1);   // write to the file descriptor 1 (stdout) the character pointed to by str.
        str++;              // move the pointer to the next character in the string.
    }
}

void	ft_putnbr(int nb)
{
	char	c;
	int		mod_result;
	int		div_result;
    
    if(nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	div_result = nb / 10;
	mod_result = nb % 10;
	if (nb < 10 && nb >= 0)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
	else if (div_result != 0)
	{
		c = mod_result + '0';
		ft_putnbr(div_result);
		write(1, &c, 1);
	}
}

int main(void)
{

    char num_str[4];
    int num;

    num = 1;

    while (num <= 100)
    {
        if (num % 3 == 0 && num % 5 == 0)
        {
            ft_putstr("fizzbuzz\n");
        }
        else if (num % 3 == 0)
        {
            ft_putstr("fizz\n");
        }
        else if (num % 5 == 0)
        {
            ft_putstr("buzz\n");
        }
        else
        {
            ft_putnbr(num);
            ft_putstr("\n");
        }
        num++;
    }
    return (0);
}