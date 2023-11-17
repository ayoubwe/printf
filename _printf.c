#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            putchar(format[i]);
            count++;
        } else {
            i++; // skip '%'
            char c = va_arg(args, int);
            switch (format[i]) {
                case 'c':
                    putchar(c);
                    count++;
                    break;
                case 's':
                    {
                        char *s = va_arg(args, char *);
                        while (*s != '\0') {
                            putchar(*s);
                            s++;
                            count++;
                        }
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                default:
                    break;
            }
        }
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, World! %c%c%c\n", 'A', 'B', 'C');
    _printf("Sum: %d + %d = %d\n", 1, 2, 1 + 2);
    return 0;
}
