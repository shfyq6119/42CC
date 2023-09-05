char    *ft_strchr(const char *str, int c)
{
        while (*str)
        {
                if (*str == c)
                        return ((char *)str);
                str++;
        }
        if (c == '\0')
                return ((char *)str);
        return (0);
}

#include <stdio.h>
int main(int argc, char **argv)
{
        if (argc != 1)
                printf("%s\n", (ft_strchr(argv[1], 99)));
        return (0);
}
