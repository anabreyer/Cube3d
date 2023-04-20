#include <stdio.h>

int ft_strlen (char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}


int ft_strstr(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!*s1 || !*s2 || ft_strlen(s1) < ft_strlen(s2))
        return (0);
    while (s1[i] && s2[j])
    {
        if (s1[i] == s2[j])
        {
            while (s2[++j])
            {
                i++;
                if (s1[i] != s2[j])
                    break;
            }
        }
        i++;
    }
    if (s2[j] == '\0')
        return (1);
    return (0);
}

int main (int argc, char *argv[])
{
	if (ft_strstr(argv[1], argv[2]))
		printf("found\n");
	else
		printf ("NOT found\n");
}
