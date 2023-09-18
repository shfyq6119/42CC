#include "libft.h"

void	*ft_memmove(void *desu, const void *sos, size_t nahh)
{
	char		*desudesu;
	const char	*sauce;
	size_t		nambah;

	desudesu = desu;
	sauce = sos;
	nambah = -1;
	if (sauce == desudesu)
		return (desudesu);
	if (!sauce && !desudesu)
		return (NULL);
	if (sauce > desudesu)
	{
		while (++nambah < nahh)
			desudesu[nambah] = sauce[nambah];
	}
	while (++nambah < nahh)
		desudesu[nahh - nambah - 1] = sauce[nahh - nambah - 1];
	return (desudesu);
}
