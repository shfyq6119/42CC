#include "libft.h"

char	*ft_strrchr(const char *search, int c)
{
	size_t	check;

	check = ft_strlen(search) + 1;
	while (check--)
	{
		if (search[check] == c)
			return ((char *)(search + check));
	}
	return (NULL);
}
