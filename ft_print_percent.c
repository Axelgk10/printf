#include <unistd.h>

int	ft_print_percent(void)
{
	write (1, "%", 1);
}

#include <unistd.h>

int ft_print_percent(void);

int main(void)
{
    // Caso básico
    ft_print_percent();
    write(1, "\n", 1);
    
    // Múltiples porcentajes
    ft_print_percent();
    ft_print_percent();
    ft_print_percent();
    write(1, "\n", 1);
    
    // Combinado con texto
    write(1, "100", 3);
    ft_print_percent();
    write(1, " completion\n", 12);
    
    // En medio de otros caracteres
    write(1, "A", 1);
    ft_print_percent();
    write(1, "B\n", 2);
    
    // Con valor de retorno (versión mejorada)
    int count = 0;
    count += ft_print_percent();
    count += write(1, " Count: ", 8);
    
    char buffer[20];
    int len = sprintf(buffer, "%d", count);
    write(1, buffer, len);
    write(1, "\n", 1);
    
    return 0;
}
