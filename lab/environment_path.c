#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

static int	ft_countword(const char *s, char c)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			count++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	word_len(const char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char	*create_word(const char *s, char c)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = word_len(s, c);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	*free_all(char **res, int last)
{
	while (last >= 0)
		free(res[last--]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_countword(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			res[i] = create_word(s, c);
			if (!res[i])
				return (free_all(res, i - 1));
			i++;
			s += word_len(s, c);
		}
	}
	res[i] = NULL;
	return (res);
}

//int main(int argc, char **argv, char **envp)
//{
//    for (int i = 0; envp[i] != NULL; i++)
//        printf("%s\n", envp[i]);
//    return 0;
//}

//int main(void)
//{
//    int permi = access("data-text.txt",R_OK);
//    if (permi != -1)
//        printf("This files has fully access\n");
//    else
//        printf("This files has no access\n");
    
//}

//int main(int ac, char **av , char **evp)
//{
//    char **args = ft_split(av[1], ' ');
//    execve("/bin/ls", args, NULL);
////  exceve(env-path, argument, end);
//    printf("This line will not be executed.\n");

//    return (0);
//}

int main(void)
{

}
