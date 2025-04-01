#include <stdio.h>
#include <stdarg.h>

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++; // Avança para o próximo caractere após '%'
            
            switch (*format) {
                case 's': { // String
                    char *s = va_arg(args, char*);
                    printf("%s", s);
                    break;
                }
                case 'd': { // Inteiro
                    int d = va_arg(args, int);
                    printf("%d", d);
                    break;
                }
                case 'c': { // Caractere
                    int c = va_arg(args, int); // Promovido para int
                    printf("%c", c);
                    break;
                }
                case '%': { // Literal '%'
                    putchar('%');
                    break;
                }
                default: { // Especificador desconhecido
                    putchar('%');
                    putchar(*format);
                    break;
                }
            }
        } else {
            putchar(*format); // Caracteres normais
        }
        format++;
    }

    va_end(args);
}
