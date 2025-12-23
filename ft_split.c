#include "push_swap.h"

static int	is_space(char c)
{
	if ((c == 32) || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	free_split(char **arr, int i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
	free(arr);
}

static int	ft_count_word(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			count++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
			i++;
	}
	return (count);
}
char	*ft_fill(char *str)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	while (is_space(str[i]))
		i++;
	size = i;
	while (str[size] && !is_space(str[size]))
		size++;
	word = malloc(sizeof(char) * (size - i + 1));
	if (!word)
		return (NULL);
	size = 0;
	while (str[i] && !is_space(str[i]))
	{
		word[size] = str[i];
		i++;
		size++;
	}
	word[size] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_count_word(str) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		if (!is_space(str[i]))
		{
			arr[index++] = ft_fill(&str[i]);
			if (!arr[index])
			{
				free_split(arr, index);
				return (NULL);
			}
			while (str[i] && !is_space(str[i]))
				i++;
		}
		else
			i++;
	}
	arr[index] = NULL;
	return (arr);
}
