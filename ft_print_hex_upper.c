#include <stdio.h>
#include <unistd.h>

int     ft_print_hex_upper(unsigned int num)
{
        char    buffer[8];
        char    *digits;
        int             i;
        int             count;

        digits = "0123456789ABCDEF";
        i = 0;
        count = 0;
        if (num == 0)
        {
                count += write (1, "0", 1);
                return (count);
        }
        while (num != 0)
        {
                buffer[i++] = digits[num % 16];
                num /= 16;
        }
        while (i > 0)
                count += write (1, &buffer[--i], 1);
        return (count);
}

int main(void)
{
    unsigned int test_numbers[] = {0, 1, 15, 16, 255, 256, 4095, 65535, 12345678};
    int num_count = sizeof(test_numbers) / sizeof(test_numbers[0]);
    
    printf("=== Pruebas ft_print_hex_upper ===\n\n");
    
    for (int i = 0; i < num_count; i++)
    {
        printf("Decimal: %u\n", test_numbers[i]);
        printf("printf %%X: %X\n", test_numbers[i]);
        printf("ft_print_hex_upper: ");
        int count = ft_print_hex_upper(test_numbers[i]);
        printf("\nCaracteres impresos: %d\n\n", count);
    }
    
    // Prueba interactiva
    unsigned int user_num;
    printf("Introduce números para convertir (0 para salir):\n");
    while (1)
    {
        printf("> ");
        scanf("%u", &user_num);
        if (user_num == 0) break;
        
        printf("ft_print_hex_upper: ");
        int count = ft_print_hex_upper(user_num);
        printf("\nCaracteres: %d\n", count);
        printf("printf %%X: %X\n\n", user_num);
    }
    
    return 0;
}
