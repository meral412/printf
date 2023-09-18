#include "main.h"

/**
 * _printf - function of printf which is customed
 * flush_buffer - Prints the contents of the output buffer if it exists
 * @output_buffer: Array of characters
 * @buffer_index: Index at which to add next character, represents length
 *
 * Return: Number of characters printed
 */

void flush_buffer(char output_buffer[], int *buffer_index);

int _printf(const char *format, ...)
{
int i, printed_chars = 0, buffer_index = 0;
char output_buffer[BUFF_SIZE];
va_list args;
if (!format)
return (-1);
va_start(args, format);
for (i = 0; format && format[i]; i++)
{
if (format[i] != '%')
{
output_buffer[buffer_index++] = format[i];
if (buffer_index == BUFFER_SIZE)
flush_buffer(output_buffer, &buffer_index);
printed_chars++;
}
else
{
flush_buffer(output_buffer, &buffer_index);
i++;
int printed = handle_print(format, &i, args, output_buffer);
if (printed == -1)
return (-1);
printed_chars += printed;
}
}
flush_buffer(output_buffer, &buffer_index);
va_end(args);
return (printed_chars);
}

/**
 * flush_buffer - Prints the contents of the output buffer if it exists
 * @output_buffer: Array of characters
 * @buffer_index: Index at which to add next character, represents length
 */

void flush_buffer(char output_buffer[], int *buffer_index)
{
if (*buffer_index > 0)
write(1, &output_buffer[0], *buffer_index);
*buffer_index = 0;
}
