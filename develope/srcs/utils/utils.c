#include "cub3d.h"

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
