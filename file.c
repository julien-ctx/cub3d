int main()
{
	(void)ac;
	(void)av;
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
