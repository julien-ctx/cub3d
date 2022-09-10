#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *line(char *ref)
{
	char	*str;
	int		i;
	str = malloc(4 * sizeof(char));
	for (i = 0; ref[i]; i++)
		str[i] = ref[i];
	str[i] = 0;
	return (str);
}

void	using_line(char *str)
{
	int i;
	for(i = 0; str[i]; i++);
	printf("Length: %d\n", i);
}

int main(void)
{
	char	ref[] = "Hey";
	char	*str = line(ref);
	using_line(str);
	system("leaks a.out");
	return (0);
}
