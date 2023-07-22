#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int char_count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                // Handle the 'c' conversion specifier
                char c = (char)va_arg(args, int);
                putchar(c);
                char_count++;
            } else if (*format == 's') {
                // Handle the 's' conversion specifier
                char *str = va_arg(args, char*);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    char_count++;
                }
            } else if (*format == '%') {
                // Handle the '%' conversion specifier
                putchar('%');
                char_count++;
            }
        } else {
            // Regular character, print it
            putchar(*format);
            char_count++;
        }

        format++;
    }

    va_end(args);
    return char_count;
}

int main() {
    _printf("Hello, %s! The character is %c. This is a percent sign: %%.\n", "John", 'A');
    return 0;
}

