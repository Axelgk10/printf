#include <stdio.h>
#include <unistd.h>  // Necesario para la función write()

int	ft_print_hex(unsigned long num, int uppercase)
{
	char	buffer[16];
	char	*digits;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (num == 0)
		write (1, "0", 1);
	while (num > 0)
	{
		buffer[i++] = digits[num % 16];
		num /= 16;
	}
	while (i > 0)
	{
		count += write (1, &buffer[--i], 1);
	}
	return (count);
}

int	ft_print_ptr(void	*ptr)
{
	unsigned long	address;
	int				count;

	count = 0;
	if (!ptr)
	{
		count += write (1, "nil", 3);
		return (count);
	}
	address = (unsigned long)ptr;
	count += write (1, "0x", 2);
	count += ft_print_hex(address, 0);
	return (count);
}


int ft_print_hex(unsigned long num, int uppercase);
int ft_print_ptr(void *ptr);

int main(void) {
    int x = 42;
    char c = 'A';
    void *null_ptr = NULL;
    int count;

    // Prueba ft_print_hex
    write(1, "Pruebas ft_print_hex:\n", 21);
    write(1, "0 en minúsculas: ", 17);
    count = ft_print_hex(0, 0);
    write(1, "\n", 1);

    write(1, "255 en minúsculas: ", 19);
    count = ft_print_hex(255, 0);
    write(1, "\n", 1);

    write(1, "255 en mayúsculas: ", 19);
    count = ft_print_hex(255, 1);
    write(1, "\n\n", 2);

    // Prueba ft_print_ptr
    write(1, "Pruebas ft_print_ptr:\n", 21);
    write(1, "Puntero NULL: ", 14);
    count = ft_print_ptr(null_ptr);
    write(1, "\n", 1);

    write(1, "Dirección de x: ", 17);
    count = ft_print_ptr(&x);
    write(1, "\n", 1);

    write(1, "Dirección de c: ", 17);
    count = ft_print_ptr(&c);
    write(1, "\n", 1);

    // Puntero a función (caso especial)
    write(1, "Dirección de main: ", 19);
    count = ft_print_ptr(&main);
    write(1, "\n", 1);

    return 0;
}
