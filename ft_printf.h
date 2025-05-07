#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);

/* Función principal */
int ft_printf(const char *format, ...);

/* Funciones para cada especificador de conversión */

// %c - Imprime un carácter
int	ft_print_char(char c);

// %s - Imprime una cadena de caracteres (string)
int	ft_print_str(char *str);

// %p - Imprime un puntero en hexadecimal (dirección de memoria)
int	ft_print_ptr(void *ptr);

// %d / %i - Imprime un número decimal (entero con signo)
int	ft_print_int(int num);

// %u - Imprime un número decimal sin signo
int	ft_print_unsigned(unsigned int num);

// %x - Imprime un número hexadecimal en minúsculas
int	ft_print_hex_lower(unsigned int num);

// %X - Imprime un número hexadecimal en mayúsculas
int	ft_print_hex_upper(unsigned int num);

// %% - Imprime el símbolo de porcentaje
int	ft_print_percent(void);

/* Funciones auxiliares (utils) */

// Convierte un número a una cadena en la base especificada
char	*ft_itoa_base(unsigned long num, unsigned int base, bool uppercase);

// Imprime un número recursivamente (para evitar límite de itoa)
int	ft_putnbr_base(unsigned long num, char *base, unsigned int base_len);
