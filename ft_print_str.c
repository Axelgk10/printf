#include <stdio.h>
#include <unistd.h>

void	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

#include <unistd.h>

void ft_print_str(char *str);

int main(void)
{
    // Casos de prueba
    ft_print_str("Hola");       // Cadena normal
    write(1, "\n", 1);          // Salto de línea
    
    ft_print_str("");           // Cadena vacía
    write(1, "(empty)\n", 8);   // Indicador para cadena vacía
    
    ft_print_str("A");          // Un solo carácter
    write(1, "\n", 1);
    
    ft_print_str("12345");      // Cadena numérica
    write(1, "\n", 1);
    
    ft_print_str(" ");          // Espacio en blanco
    write(1, "(space)\n", 8);
    
    return 0;
}
