#include <stdio.h>  // Para comparar con printf estándar
#include <limits.h> // Para INT_MAX, etc.
#include <unistd.h>


int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_format(args, format[i]);
		}
		else
			count += write (1, &fortmat[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_handle_format(va_list args, char specifier)
{
	count = 0;
	if (specifer == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count = ft_print_ptr(ca_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		count = ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		count = ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count = ft_print_hex_lower(va_arg(args, unsigned int));
	else if (specifer == 'X')
		count = ft_print_hex_upper(va_arg(args, unsigned int));
	else if (specifier == '%')
		count = ft_print_percent();
	return (count);
}

#include <stdio.h>  // Para comparar con printf estándar
#include <limits.h> // Para INT_MAX, etc.

int ft_printf(const char *format, ...);

int main(void)
{
    int ft_count;
    int std_count;

    // Prueba 1: Caracteres y strings
    ft_count = ft_printf("1. Char: %c, String: %s\n", 'A', "Hola Mundo");
    std_count = printf("1. Char: %c, String: %s\n", 'A', "Hola Mundo");
    printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

    // Prueba 2: Números
    ft_count = ft_printf("2. Decimal: %d, Entero: %i, Unsigned: %u\n", -42, 123, 456u);
    std_count = printf("2. Decimal: %d, Entero: %i, Unsigned: %u\n", -42, 123, 456u);
    printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

    // Prueba 3: Hexadecimal y puntero
    int x = 255;
    ft_count = ft_printf("3. Hex lower: %x, Hex upper: %X, Ptr: %p\n", x, x, &x);
    std_count = printf("3. Hex lower: %x, Hex upper: %X, Ptr: %p\n", x, x, &x);
    printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

    // Prueba 4: Porcentaje y casos especiales
    ft_count = ft_printf("4. %% sign, NULL string: %s, Char: %c\n", NULL, 0);
    std_count = printf("4. %% sign, NULL string: %s, Char: %c\n", NULL, 0);
    printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

    // Prueba 5: Límites
    ft_count = ft_printf("5. INT_MIN: %d, INT_MAX: %d, UINT_MAX: %u\n",
                        INT_MIN, INT_MAX, UINT_MAX);
    std_count = printf("5. INT_MIN: %d, INT_MAX: %d, UINT_MAX: %u\n",
                      INT_MIN, INT_MAX, UINT_MAX);
    printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

    // Prueba 6: Caracteres no reconocidos
    ft_count = ft_printf("6. Unknown: %k, %z\n");
    std_count = printf("6. Unknown: %k, %z\n");
    printf("ft_printf: %d, printf: %d\n\n", ft_count, std_count);

    return 0;
}
