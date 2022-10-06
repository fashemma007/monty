#include "monty.h"

/**
* pop - pops the very top element of the stack
* @stack: stack given by main in start.c
* @line_cnt: line number for error messages
*
* Return: void
*/
void pop(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	free(*stack);
	*stack = tmp;
	if (!*stack)
		return; /* prevents errors cause next line might assign a NULL */
	(*stack)->prev = NULL;
}

/**
 * pall - prints the stack
 * @stack: stack given by main in start.c
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	print_stack(*stack);
}

/**
 * pchar - prints the int at the top of the stack as char
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	if (_isascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pstr - prints the contents of a stack_t stack as a string
 * @stack: stack given by main
 * @line_cnt: line counter for error messages
 *
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current)
	{
		if (current->n <= 0 || current->n > 127)
			break;
		putchar((char) current->n);
		current = current->next;
	}
	putchar('\n');
}

