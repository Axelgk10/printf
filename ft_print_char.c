#include <stdio.h>
#include <unistd.h>  // Necesario para la función write()



int	ft_print_char(int c)
{
	return (write (1, &c, 1));
}


int main(void)
{
    int count;

    // Test 1: Imprimir un carácter normal
    count = ft_print_char('A');
    printf("\nCaracteres impresos: %d\n", count);

    // Test 2: Imprimir un número como carácter
    count = ft_print_char(65); // Debería imprimir 'A'
    printf("\nCaracteres impresos: %d\n", count);

    // Test 3: Imprimir un carácter especial
    count = ft_print_char('\n');
    printf("Caracteres impresos: %d\n", count);

    // Test 4: Imprimir un carácter no imprimible
    count = ft_print_char('\t');
    printf("Caracteres impresos: %d\n", count);

    return (0);
}
