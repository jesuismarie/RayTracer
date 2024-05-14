/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gehovhan <gehovhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:38:50 by gehovhan          #+#    #+#             */
/*   Updated: 2024/05/14 19:32:36 by gehovhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_ptoken_type ft_get_ptype(char *type)
{
	if (!ft_strcmp(type, P_CAMERA_D))
		return P_CAMERA;
	if (!ft_strcmp(type, P_LIGHT_D))
		return P_LIGHT;
	if (!ft_strcmp(type, P_SPHERE_D))
		return P_SPHERE;
	if (!ft_strcmp(type, P_AMB_LIGHT_D))
		return P_AMB_LIGHT;
	if (!ft_strcmp(type, P_PLANE_D))
		return P_PLANE;
	if (!ft_strcmp(type, P_CYLINDER_D))
		return P_CYLINDER;
	if (!ft_strcmp(type, P_CONE_D))
		return P_CONE;
	return P_UNKNOWN;
}

// char *ft_get_ptype_(t_ptoken_type ptoken)
// {
// 	if (ptoken == P_CAMERA)
// 		return P_CAMERA;
// 	if (ptoken == P_LIGHT)
// 		return P_LIGHT;
// 	if (ptoken == P_SPHERE)
// 		return P_SPHERE;
// 	if (ptoken == P_AMB_LIGHT)
// 		return P_AMB_LIGHT;
// 	if (ptoken == P_PLANE)
// 		return P_PLANE;
// 	if (ptoken == P_CYLINDER)
// 		return ft_strdup();
// 	if (ptoken == P_CONE_D)
// 		return P_CONE;
// 	return P_UNKNOWN;
// }