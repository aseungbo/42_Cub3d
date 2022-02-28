#include "parsing.h"

static void	add_new_list(t_list *list_head, char *line)
{
	t_list	*new;
	char	*str;

	if (ft_strcmp(line, "") == 0)
		return ;
	str = ft_strdup(line);
	new = new_list(str);
	add_list(list_head, new);
}

int	parsing(char *filename)
{
	t_list	list_head;
	int		open_fd;
	char	*line;

	list_head.next = NULL;
	open_fd = open(filename, O_RDONLY, 0777);
	if (open_fd < 0)
	{
		printf("Error! %s is not exist\n", filename);
		return (FAILURE);
	}
	while (get_next_line(open_fd, &line) > 0)
	{
		add_new_list(&list_head, line);
		free(line);
	}
	free(line);
	if (lexer_list(&list_head) == FAILURE)
		return (FAILURE);
	clear_list(&list_head);
	return (SUCCESS);
}
