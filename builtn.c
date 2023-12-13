#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitchec;

	if (info->argv[1])  /* If there is an exit arguement */
	{
		exitchec = _erratoi(info->argv[1]);
		if (exitchec == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *a, *dire, buffer[1024];
	int chdire_ret;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dire = _getenv(info, "HOME=");
		if (!dire)
			chdire_ret = /* TODO: what should this be? */
				chdire((dire = _getenv(info, "PWD=")) ? dire : "/");
		else
			chdire_ret = chdire(dire);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdire_ret = /* TODO: what should this be? */
			chdire((dire = _getenv(info, "OLDPWD=")) ? dire : "/");
	}
	else
		chdire_ret = chdire(info->argv[1]);
	if (chdire_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_aray;

	arg_aray = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_aray); /* temp att_unused workaround */
	return (0);
}

