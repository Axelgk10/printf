#include <stdio.h>
#include <unistd.h>

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}
int ft_print_str(char *str);

int main(void) {
    printf("=== Pruebas para ft_print_str ===\n\n");
    
    // Casos de prueba
    char *test_cases[] = {
        "Hola mundo",    // String normal
        "",               // String vacío
        NULL,             // NULL pointer
        "Carácter especial \t\n",  // Con caracteres especiales
        "1234567890",     // Solo números
        "Espacios     ",  // Múltiples espacios
        "ñáéíóú",         // Caracteres no ASCII
        "Largo\0hidden"   // String con \0 en medio
    };
    
    const char *test_names[] = {
        "String normal",
        "String vacío",
        "NULL pointer",
        "Caracteres especiales",
        "Solo números",
        "Múltiples espacios",
        "Caracteres no ASCII",
        "String con \\0 en medio"
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_tests; i++) {
        printf("\nPrueba %d: %s\n", i + 1, test_names[i]);
        printf("Entrada: %s\n", test_cases[i] ? test_cases[i] : "(null)");
        
        printf("Esperado: ");
        if (test_cases[i] == NULL) {
            printf("(null)");
        } else {
            printf("%s", test_cases[i]);
        }
        printf("\n");
        
        printf("Obtenido: ");
        int count = ft_print_str(test_cases[i]);
        
        printf("\nCaracteres impresos: %d", count);
        
        // Verificación
        int expected = test_cases[i] ? strlen(test_cases[i]) : 6;
        if (count == expected) {
            printf(" ✓ (CORRECTO)");
        } else {
            printf(" ✗ (ERROR: esperado %d)", expected);
        }
    }
    
    // Prueba adicional: string muy largo
    char long_str[1001];
    memset(long_str, 'a', 1000);
    long_str[1000] = '\0';
    
    printf("\n\nPrueba adicional: String de 1000 caracteres\n");
    printf("Caracteres impresos: ");
    int long_count = ft_print_str(long_str);
    printf("%d", long_count);
    if (long_count == 1000) {
        printf(" ✓ (CORRECTO)");
    } else {
        printf(" ✗ (ERROR: esperado 1000)");
    }
    
    printf("\n\n=== Fin de las pruebas ===\n");
    
    return 0;
}
