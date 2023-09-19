#include "main.h"
/**
 * _printf - Custom print function
 * @format: Format string
* @...: arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case'%':
count += _write((char) va_arg(args, int));
break;
case 's':
count += _write((char *) va_arg(args, char *));
break;
case '%':
count += _write('%');
break;
case 'd':
case 'i':
count += printf("%d", va_arg(args, int));
break;
default:
break;
}
}
else
{
count += _write(*format);
}
format++;
}
va_end(args);

return (count);
}
