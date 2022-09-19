int main()
{
	void *mlx = mlx_init();
	void *mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
	t_img img;
	int x;
	int y;
	img.img_data = mlx_new_image(mlx, 1920, 1030);
	img.addr = mlx_get_data_addr(img.img_data,
								 &img.bits_per_pixel, &img.line_length, &img.endian);
	img.img_data = mlx_xpm_file_to_image(mlx, "textures/dark_wall.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, img.img_data, 0, 0);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_mlx mlx;
	(void)ac;
	(void)av;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "lol");
	int x; int y;
	mlx.img.img_data = (mlx_xpm_file_to_image(mlx.ptr, "textures/white_wall.xpm", &x, &y));
	mlx.img.addr = mlx_get_data_addr(mlx.img.img_data, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	char	*pxl;
	pxl = mlx.img.addr + (30 * mlx.img.line_length + 960 * (mlx.img.bits_per_pixel / 8));
	*(int *)pxl = PXL;
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.img_data, 0, 0);
	mlx_loop(mlx.ptr);
}
