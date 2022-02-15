#include "../parsing.h"

void	get_mapsize(t_list *list_ptr, t_size *size)
{
	int		x_size;
	int		y_size;
	int		len;

	x_size = 0;
	y_size = size_list(list_ptr);
	while (list_ptr != NULL)
	{
		len = ft_strlen(list_ptr);
		if (len > x_size)
			x_size = len;
		list_ptr = list_ptr->next;
	}
	size->x_size = x_size;
	size->y_size = y_size;
}

void	allocate_size(t_cub *cub, t_size *size)
{
	int		i;

	i = 0;
	cub->map = (int **)malloc(sizeof(int *) * size->y_size);
	while (cub->map[i] < size->y_size)
	{
		cub->map[i] = (int*)malloc(sizeof(int) * size->x_size);
		i++;
	}
	return ;
}

int	init_map(t_list *list_ptr)
{
	t_size	size;
	t_cub	*cub;

	cub = get_cub();
	get_mapsize(list_ptr, &size);
	allocate_size(cub, &size);
	fill_map(cub, list_ptr);
}
