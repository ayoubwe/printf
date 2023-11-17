#include "main.h"

/**
 * print_functions - print numbers
 * @types: arg
 * @buffer: handle print
 * @flags: flags
 * @width: get width 
 * @precision: Precision specification
 * @size: Size
 * Return: nb of char
 */

int print_functions(va_list types, char buffer[],int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
