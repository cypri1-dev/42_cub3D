/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 08:38:59 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/07 11:40:36 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_lib.h"

void	free_duplicate_data(t_data *data)
{
	int	i;

	i = ZERO_INIT;
	while (i < data->file->line_data)
	{
		free(data->file->infos[i]);
		i++;
	}
	free(data->file->infos);
	i = 0;
	while (i < data->file->line_map)
	{
		free(data->file->map[i]);
		i++;
	}
	free(data->file->map);
}

int	free_close_windows(void *data)
{
	t_data	*ptr;

	ptr = (t_data *)data;
	free(ptr->file->path->path_ea);
	free(ptr->file->path->path_no);
	free(ptr->file->path->path_so);
	free(ptr->file->path->path_we);
	free_split(ptr->file->tab_data);
	free(ptr->file->path);
	free(ptr->file->color);
	free(ptr->file->map_line_cpy);
	free_duplicate_data(ptr);
	free(ptr->file);
	free_resources(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = ZERO_INIT;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_file_struct(t_data *data)
{
	free(data->file->map_line_cpy);
	free_split(data->file->tab_data);
	free(data->file->color);
	free(data->file->path->path_ea);
	free(data->file->path->path_no);
	free(data->file->path->path_so);
	free(data->file->path->path_we);
	free(data->file->path);
	free_duplicate_data(data);
	free(data->file);
}
