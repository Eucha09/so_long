/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:30:43 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/04 20:24:43 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error(int code)
{
	ft_printf("Error\n");
	if (code == ERROR_ARG_IS_INVALID)
		ft_printf("Arg is invalid\n");
	else if (code == ERROR_FILE_OPEN_FAIL)
		ft_printf("File open fail\n");
	else if (code == ERROR_MAP_READ_FAIL)
		ft_printf("Map read fail\n");
	else if (code == ERROR_MAP_IS_INVALID)
		ft_printf("Map is invalid\n");
	else if (code == ERROR_MAP_IS_NOT_CLOSED_WALLS)
		ft_printf("Map is not closed walls\n");
	else if (code == ERROR_MAP_IS_NOT_RECTANGULAR)
		ft_printf("Map is not rectangular\n");
	else if (code == ERROR_PATH_IS_INVALID)
		ft_printf("Path is invalid\n");
	else if (code == ERROR_GHOST_MALLOC_FAIL)
		ft_printf("Ghost malloc fail\n");
	return (1);
}
