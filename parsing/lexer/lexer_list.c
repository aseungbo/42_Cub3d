#include "../parsing.h"

static t_type	check_identifier(char *iden)
{
	if (ft_strcmp(iden, "NO") == 0)
		return (NO);
	else if (ft_strcmp(iden, "SO") == 0)
		return (SO);
	else if (ft_strcmp(iden, "WE") == 0)
		return (WE);
	else if (ft_strcmp(iden, "EA") == 0)
		return (EA);
	else if (ft_strcmp(iden, "F") == 0)
		return (F);
	else if (ft_strcmp(iden, "C") == 0)
		return (C);
	else
		return (-1);
}

static void	fill_config(char *str, int *flag)
{
	t_cub	*cub;
	char	*iden;
	char	*path;
	int		i;
	t_type	type;

	cub = get_cub();
	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	iden = ft_strndup(str, i);
	while (str[i] == ' ')
		i++;
	path = ft_strdup(str + i);
	type = check_identifier(iden);
	printf("iden = %s path = %s\n", iden, path);
	free (iden);
	if (type < 0)
	{
		free(path);
		return ;
	}
	cub->config[type] = path;
	flag[type] = ON;
	return ;
}

static int		check_flags(int *flag)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (flag[i] == 0)
			return (1);
		i++;
	}
	return (0);
}

int	lexer_list(t_list *list_head)
{
	t_list	*list_ptr;
	int		flag[6];

	ft_memset(&flag, OFF, 6);
	list_ptr = list_head->next;
	while (list_ptr != NULL && check_flags(flag))
	{
		fill_config(list_ptr->str, flag);
		list_ptr = list_ptr->next;
	}
	if (check_flags(flag) == 1)
		return (FAILURE);		// flag remained
	if (list_ptr == NULL)
		return (FAILURE);		// map doesn't exist
	// check = init_map(list_ptr);
	// if (init_map < 0)
	// 	return (1);		// invalid map
	return (SUCCESS);
}
