#include <unistd.h>

int	ft_print_char(int c)
{
	write (1, &c, 1);
}

#include <unistd.h>

int ft_print_char(int c);

int main(void)
{
    // Casos de prueba normales
    ft_print_char('H');
    ft_print_char('o');
    ft_print_char('l');
    ft_print_char('a');
    ft_print_char('\n');
    
    // Caracteres especiales
    ft_print_char('\t');  // Tabulación
    ft_print_char(' ');   // Espacio
    ft_print_char('!');
    ft_print_char('\n');
    
    // Límites de char
    ft_print_char(0);     // Null character (no visible)
    ft_print_char(127);   // Último ASCII estándar
    ft_print_char('\n');
    
    // Caracteres numéricos
    ft_print_char('2');
    ft_print_char('5');
    ft_print_char('\n');
    
    return 0;
}
