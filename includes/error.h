/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eujeong <eujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:09:22 by eujeong           #+#    #+#             */
/*   Updated: 2023/01/06 15:00:21 by eujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_ARG_IS_INVALID			11
# define ERROR_FILE_OPEN_FAIL			12
# define ERROR_MAP_READ_FAIL			13
# define ERROR_MAP_IS_INVALID			14
# define ERROR_MAP_IS_NOT_CLOSED_WALLS	15
# define ERROR_MAP_IS_NOT_RECTANGULAR	16
# define ERROR_PATH_IS_INVALID			17
# define ERROR_GHOST_MALLOC_FAIL		18

int	error(int code);

#endif