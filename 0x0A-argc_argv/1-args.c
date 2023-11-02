#include <stdio.h>

/**
 * main - print name, followed by a new line after
 * @argc: x args
 * @argv: arr args
 * Return: 0
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
if (argc > 0)
printf("%d\n", argc - 1);
return (0);
}
