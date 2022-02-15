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
	int		open_fd;
	char	*line;
	t_list	list_head;
	int		check;

	list_head.next = NULL;
	open_fd = open(filename, O_RDONLY, 0777);
	if (open_fd < 0)
		printf("%s is not exist\n", filename);
	while (get_next_line(open_fd, &line) > 0)
		add_new_list(&list_head, line);
	check = lexer_list(&list_head);

	printf("checker %d\n", check);
	for(int i=0;i<6;i++)
		printf("%d = [%s]\n",i,get_cub()->config[i]);


	clear_list(&list_head);
	return (check);
}
