#include <unistd.h>

int	ft_print_percent(void)
{
	return (write (1, "%", 1));
}

#include <stdio.h>
#include <unistd.h>

int ft_print_percent(void);

int main(void) {
    printf("=== Pruebas para ft_print_percent ===\n\n");
    
    // Prueba 1: Impresión básica
    printf("Prueba 1: Impresión simple del símbolo %%\n");
    printf("Resultado esperado: %%\n");
    printf("Resultado obtenido: ");
    int count1 = ft_print_percent();
    printf("\nCaracteres impresos: %d\n\n", count1);
    
    // Prueba 2: Verificación del valor de retorno
    printf("Prueba 2: Verificación del valor de retorno\n");
    int count2 = ft_print_percent();
    if (count2 == 1) {
        printf("✓ Valor de retorno correcto (1)\n");
    } else {
        printf("✗ Valor de retorno incorrecto. Esperado: 1, Obtenido: %d\n", count2);
    }
    
    // Prueba 3: Múltiples llamadas
    printf("\nPrueba 3: Múltiples llamadas a la función\n");
    printf("Resultado esperado: %%%%\n");
    printf("Resultado obtenido: ");
    int total_chars = 0;
    total_chars += ft_print_percent();
    total_chars += ft_print_percent();
    printf("\nTotal de caracteres impresos: %d\n", total_chars);
    
    // Prueba 4: Combinación con otros textos
    printf("\nPrueba 4: Combinación con texto normal\n");
    printf("Resultado esperado: Esto es un 100%% seguro\n");
    printf("Resultado obtenido: ");
    write(1, "Esto es un 100", 14);
    int count4 = ft_print_percent();
    write(1, " seguro\n", 8);
    printf("Caracteres del símbolo %% impresos: %d\n", count4);
    
    return 0;
}
