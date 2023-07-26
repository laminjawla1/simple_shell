#include "main.h"

/**
* print_error_msg - Prints an error message to fd
*
*@s_name: Name of the shell program
*@p_name: Name of the program to be run
*@ec: Exit code
*@count: Number of commands executed
*
*Return: None
*/
void print_error_msg(char *s_name, char *p_name, char *ec, size_t count)
{
	char error_msg[1024];

	if (ec)
		snprintf(error_msg, 1024, "%s: %ld: %s: Illegal number: %s\n",
			s_name, count, p_name, ec);
	else
		snprintf(error_msg, 1024, "%s: %ld: %s: not found\n",
			s_name, count, p_name);
	write(STDERR_FILENO, error_msg, _strlen(error_msg));
}
