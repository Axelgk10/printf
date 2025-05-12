#include <stdio.h>
#include <unistd.h>

int	ft_print_hex_lower(unsigned int num)
{
	char	buffer[8];
	char	*digits;
	int		count;
	int		i;

	i = 0;
	digits = "0123456789abcdef";
	count = 0;
	if (num == 0)
	{
		count += write (1, "0", 1);
		return (count);
	}
	while (num != 0)
	{
		buffer[i++] = digits [num % 16];
		num /= 16;
	}
	while (i > 0)
	{
		count += write (1, &buffer[--i], 1);
	}
	return (count);
}


int ft_print_hex_lower(unsigned int num);

int main(void)
{
    unsigned int tests[] = {0, 1, 10, 15, 16, 255, 1024, 123456, UINT_MAX};
    int test_count = sizeof(tests) / sizeof(tests[0]);
    int count;
    int i;

    printf("=== Pruebas ft_print_hex_lower ===\n\n");
    
    for (i = 0; i < test_count; i++)
    {
        printf("Prueba %d: %u\n", i + 1, tests[i]);
        printf("Esperado: %x\n", tests[i]);
        printf("Obtenido: ");
        count = ft_print_hex_lower(tests[i]);
        printf("\nCaracteres impresos: %d\n\n", count);
    }

    // Caso adicional: número muy grande
    printf("Prueba adicional: 3735928559\n");
    printf("Esperado: deadbeef\n");
    printf("Obtenido: ");
    count = ft_print_hex_lower(3735928559);
    printf("\nCaracteres impresos: %d\n", count);

    return (0);
}
