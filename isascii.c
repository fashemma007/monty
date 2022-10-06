#include "monty.h"
/**
 * _isascii - checks if a given character is in ASCII
 * @chr: character to check
 * Return: int
 */
int _isascii(int chr)
{
return ((chr <= 127) && (chr >= 0));
}
