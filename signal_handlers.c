#include "main.h"

/**
* signal_handler - Handle the control-c signal
*
*@sig: Signal
*
*Return: None
*/
void signal_handler(int sig)
{
	char *prompt = "\n$ ";

	if (sig == SIGINT)
		display_prompt(prompt);
}
