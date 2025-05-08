#include "printf.h"

int ft_print_ptr(void   *ptr)
{
    unsigned long   address;
    int             count;

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

int ft_print_hex(unsigned long num, int uppercase)
{
    char    buffer[16];
    char    *digits;
    int     i;
    int     count;

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

#include <stdio.h>

int ft_print_ptr(void *ptr);
int ft_print_hex(unsigned long num, int uppercase);

int main(void)
{
    int number = 42;
    int *ptr = &number;
    char *str = "Hola mundo";
    void *null_ptr = NULL;
    int count;

    // Test 1: Imprimir dirección de un entero
    printf("\nTest 1: Dirección de un entero\n");
    printf("printf: %p\n", (void *)ptr);
    printf("ft_print_ptr: ");
    count = ft_print_ptr(ptr);
    printf("\nCaracteres impresos: %d\n", count);

    // Test 2: Imprimir dirección de un string
    printf("\nTest 2: Dirección de un string\n");
    printf("printf: %p\n", (void *)str);
    printf("ft_print_ptr: ");
    count = ft_print_ptr(str);
    printf("\nCaracteres impresos: %d\n", count);

    // Test 3: Imprimir puntero nulo
    printf("\nTest 3: Puntero nulo\n");
    printf("printf: %p\n", null_ptr);
    printf("ft_print_ptr: ");
    count = ft_print_ptr(null_ptr);
    printf("\nCaracteres impresos: %d\n", count);

    return 0;
}
