#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	dst = cub->img.data +
	(y * cub->img.line_size + x * (cub->img.bpp / 8));
	*(unsigned int*)dst = color;
}

int		get_pixel_color(t_cub *cub, int type, int x, int y)
{
	t_img	img;
	int		color;

	img.img = cub->textures.no;
	img.data = mlx_get_data_addr(img.img, &(img.bpp), &(img.line_size), &(img.endian));
	color = (int)*(img.data + (y * img.line_size + x * (img.bpp / 8)));
	return (color);
}
