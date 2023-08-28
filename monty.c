#include "monty.h"

/**
 * main - Entry point for the Monty interpreter program
 * @argc: Number of arguments
 * @argv: Array of argument strings
 *
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char **argv)
{
FILE *file;
char *line = NULL;
size_t line_length = 0;
ssize_t read;
if (argc != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
file = fopen(file_name, "r");
if (file == NULL)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_name);
	exit(EXIT_FAILURE);
}
data.file = file;
while ((read = getline(&line, &line_length, file)) != -1)
{
	data.line_number++;
	data.line = line;
	if (is_empty_line(data.line) == 1)
		execute_line(my_data.line, my_data.line_number);
}
free_stack(my_data.stack);
fclose(file);
free(line);
return (0);
}
