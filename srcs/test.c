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
		free_map(data);
	}
	return (0);
}
