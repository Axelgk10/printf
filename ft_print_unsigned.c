#include <stdio.h>
#include <unistd.h>

int	ft_print_unsigned(unsigned int num)
{
	char	buffer[10];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (num == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}
	while (i > 0)
	{
		write (1, &buffer[--i], 1);
		count++;
	}
	return (count);
}

int main(void)
{
    unsigned int numbers[] = {0, 1, 123, 4294967295, 100, 999};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    int i;
    int chars_printed;

    i = 0;
    while (i < count)
    {
        chars_printed = ft_print_unsigned(numbers[i]);
        write(1, " (", 2);
        // Función simple para imprimir el número de caracteres impresos
        if (chars_printed >= 10)
            write(1, "2", 1); // Para nuestro caso de prueba, el máximo es 4294967295 (10 dígitos)
        else
            write(1, &(char){chars_printed + '0'}, 1);
        write(1, ")\n", 2);
        i++;
    }
    return (0);
}
