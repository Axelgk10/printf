#include <stdio.h>
#include <unistd.h>

int ft_print_hex_lower(unsigned int num)
{
    char    buffer[8];
    char    *digits;
    int     count;
    int     i;

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

int main(void)
{
    unsigned int numbers[] = {0, 15, 16, 255, 256, 4095, 65535, 12345678};
    int num_count = sizeof(numbers) / sizeof(numbers[0]);
    int count_chars;
    int i;

    printf("=== Prueba de ft_print_hex_lower ===\n");
    for (i = 0; i < num_count; i++)
    {
        printf("Decimal: %u\n", numbers[i]);
        printf("printf: %x\n", numbers[i]);
        printf("ft_print_hex_lower: ");
        count_chars = ft_print_hex_lower(numbers[i]);
        printf("\nCaracteres impresos: %d\n\n", count_chars);
    }

    // Prueba adicional con input del usuario
    unsigned int user_num;
    printf("Introduce un número para convertir a hexadecimal (o 0 para salir): ");
    scanf("%u", &user_num);
    while (user_num != 0)
    {
        printf("ft_print_hex_lower: ");
        count_chars = ft_print_hex_lower(user_num);
        printf("\nCaracteres impresos: %d\n\n", count_chars);
        printf("Introduce otro número (o 0 para salir): ");
        scanf("%u", &user_num);
    }

    return (0);
}
