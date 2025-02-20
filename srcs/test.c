#include "map.h"
#include "structs.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (ac == 2)
	{
		init_data(data, av[1]);
		check_walls(data);
		int exit = get_exits(data);
		int start = get_start(data);
		int colls = get_colls(data);
		(void)exit;
		(void)start;
		(void)colls;
		free_map(data);
	}
	else
		free(data);
	return (0);
}
