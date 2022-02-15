#ifndef PARSING_H
# define PARSING_H

# include "../include/cub3d.h"
# include <stdio.h>

# define ON 1
# define OFF 0

typedef enum e_type
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	MAP
}	t_type;

typedef struct s_list
{
	char			*str;
	t_type			type;
	struct s_list	*next;
}					t_list;

typedef struct s_size
{
	int		x_size;
	int		y_size;
}			t_size;


/* list */
void	add_list(t_list *list_head, t_list *new);
void	clear_list(t_list *list_head);
t_list	*last_list(t_list *list_head);
t_list	*new_list(char *string);
int	size_list(t_list *list_head);

/* get_next_line */
int			get_next_line(int fd, char **line);

/* lexer */
int	lexer_list(t_list *list_head);
int	init_map(t_list *list_ptr);

/* parsing */
int	parsing(char *filename);

#endif
