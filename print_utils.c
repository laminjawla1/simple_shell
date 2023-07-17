#include "main.h"

/**
* print_error_msg - Prints an error message to fd
*
*@fd: File descriptor
*@error_msg: Error message to be printed
*
*Return: None
*/
void print_error_msg(int fd, char *error_msg)
{
	write(fd, error_msg, strlen(error_msg));
}
