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
		free_map(data->map);
		free(data);
	}
	return (0);
}
