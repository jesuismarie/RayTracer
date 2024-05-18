/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:34:01 by mnazarya          #+#    #+#             */
/*   Updated: 2024/05/16 19:25:26 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_cone	*new_cone(t_vector coord, t_vector axis, double r, double h)
{
	t_cone	*cone;

	cone = ft_calloc(1, sizeof(t_cone));
	error_exit(!cone, MALLOC_ERR);
	cone->top = coord;
	cone->axis = axis;
	cone->radius = r;
	cone->height = h;
	return (cone);
}
