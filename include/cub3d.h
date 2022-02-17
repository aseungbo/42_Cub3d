#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include "../parsing/parsing.h"

# include <fcntl.h>
# include <stdio.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct s_size
{
	int		x_size;
	int		y_size;
}			t_size;

typedef struct s_cub
{
	int			**map;
	char		*config[6];
	t_size		*size;
}				t_cub;

# define NULL_SPACE 9

t_cub	*get_cub();

#endif
