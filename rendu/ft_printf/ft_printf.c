#include <unistd.h>
#include <stdarg.h>

void    ft_putchar(char c, int *len) {
    write(1, &c, 1);
    (*len)++;
}

void    ft_putstr(char *s, int *len) {
    if (!s) s = "(null)";
    while (*s) ft_putchar(*s++, len);
}

void    ft_putnbr(long n, int *len) {
    if (n < 0) {
        ft_putchar('-', len);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10, len);
    ft_putchar(n % 10 + '0', len);
}

void    ft_puthex(unsigned int n, int *len) {
    char *hex = "0123456789abcdef";
    if (n >= 16)
        ft_puthex(n / 16, len);
    ft_putchar(hex[n % 16], len);
}

int     ft_printf(const char *format, ...) {
    int len = 0;
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 's') ft_putstr(va_arg(args, char *), &len);
            else if (*format == 'd') ft_putnbr(va_arg(args, int), &len);
            else if (*format == 'x') ft_puthex(va_arg(args, unsigned int), &len);
            else if (*format == 'c') ft_putchar(va_arg(args, int), &len);
            else if (*format == '%') ft_putchar('%', &len);
            format++;
        } else {
            ft_putchar(*format++, &len);
        }
    }
    va_end(args);
    return (len);
}
