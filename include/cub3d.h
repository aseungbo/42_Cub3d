#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include "../parsing/parsing.h"

# include <fcntl.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct s_cub
{
	int			**map;
	char		*config[6];
}				t_cub;

t_cub	*get_cub();

#endif
