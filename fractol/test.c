#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int handle_expose(void *param) {
    void **params = (void **)param;
    void *mlx = params[0];
    void *win = params[1];

    // Draw a pixel at (400, 300) with the color white
    mlx_pixel_put(mlx, win, 400, 300, 0xFFFFFF);

    return 0;
}

int	main()
{
	int		width = 800;
	int		height = 600;
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, width, height, "ToTheWindow");

	if (mlx == NULL)
	{
		perror("Error mlx_init\n");
		exit(EXIT_FAILURE);	
	}
	if (win == NULL)
	{
		perror("Error no window only doors please gtfo\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		mlx_pixel_put(mlx, win, 400, 300, 0xFFFFFF);
		mlx_loop(mlx);
		void *params[] = {mlx, win};
    	mlx_expose_hook(win, handle_expose, params);
		return (0);
	}
}
