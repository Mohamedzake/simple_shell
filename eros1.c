#include "shell.h"

/**
 * new_atoi_error - converts a string to an integer
 * @sabo: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int new_atoi_error(char *sabo)
{
	int zoro = 0;
	unsigned long int kid = 0;

	if (*sabo == '+')
		sabo++;

	for (zoro = 0; sabo[zoro] != '\0'; zoro++)
	{
		if (sabo[zoro] >= '0' && sabo[zoro] <= '9')
		{
			kid *= 10;
			kid += (sabo[zoro] - '0');
			if (kid > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (kid);
}

/**
 * print_error_message - prints an error message
 * @luffy: the parameter & return luffy struct
 * @kaido: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error_message(info_t *luffy, char *kaido)
{
	print_string_error(luffy->fname);
	print_string_error(": ");
	print_decimal(luffy->line_count, STDERR_FILENO);
	print_string_error(": ");
	print_string_error(luffy->argv[0]);
	print_string_error(": ");
	print_string_error(kaido);
}

/**
 * print_decimal - function prints a decimal (integer) number (base 10)
 * @big: the input
 * @mom: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int big, int mom)
{
	int (*_putchar)(char) = _putchar;
	int roronoa, charlotte = 0;
	unsigned int vinsmoke, smoker;

	if (mom == STDERR_FILENO)
		_putchar = print_char_error;

	if (big < 0)
	{
		vinsmoke = -big;
		_putchar('-');
		charlotte++;
	}
	else
		vinsmoke = big;

	smoker = vinsmoke;

	for (roronoa = 1000000000; roronoa > 1; roronoa /= 10)
	{
		if (vinsmoke / roronoa)
		{
			_putchar('0' + smoker / roronoa);
			charlotte++;
		}
		smoker %= roronoa;
	}

	_putchar('0' + smoker);
	charlotte++;

	return (charlotte);
}

/**
 * *convert_to_string - converter function, a clone of itoa
 * @roronoa: number
 * @nico: base
 * @tetch: argument flags
 *
 * Return: string
 */
char *convert_to_string(long int roronoa, int nico, int tetch)
{
	static char *nakama;
	static char tashigi[50];
	char keros = 0;
	char *koala;
	unsigned long rebica = roronoa;

	if (!(tetch & CONVERT_UNSIGNED) && roronoa < 0)
	{
		rebica = -roronoa;
		keros = '-';
	}

	nakama = tetch & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	koala = &tashigi[49];
	*koala = '\0';

	do {
		*--koala = nakama[rebica % nico];
		rebica /= nico;
	} while (rebica != 0);

	if (keros)
		*--koala = keros;
	return (koala);
}

/**
 * remove_comments_from_string - function replaces
 * the first instance of '#' with '\0'
 * @queena: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments_from_string(char *queena)
{
	int mackenyu;

	for (mackenyu = 0; queena[mackenyu] != '\0'; mackenyu++)
	{
		if (queena[mackenyu] == '#' && (!mackenyu || queena[mackenyu - 1] == ' '))
		{
			queena[mackenyu] = '\0';
			break;
		}
	}
}

