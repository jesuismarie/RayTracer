/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:11:59 by mnazarya          #+#    #+#             */
/*   Updated: 2024/06/07 13:02:08 by mnazarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static void	solve_cylinder(t_vector pos, t_vector ray, t_figure **obj, \
	t_equition *dot)
{
	t_vector	v;
	t_vector	u;
	t_vector	vec;

	(*obj)->point.dist = 0;
	vec = vector_sub(pos, (*obj)->cyl->center);
	v = vector_sub(ray, vector_prod((*obj)->cyl->axis, \
		vector_scalar_prod((*obj)->cyl->axis, ray)));
	u = vector_sub(vec, vector_prod((*obj)->cyl->axis, \
		vector_scalar_prod((*obj)->cyl->axis, vec)));
	dot->a = vector_scalar_prod(v, v);
	dot->b = 2 * vector_scalar_prod(v, u);
	dot->c = vector_scalar_prod(u, u) - pow((*obj)->cyl->radius, 2);
	dot->discr = pow(dot->b, 2) - 4 * dot->a * dot->c;
	if (dot->discr < 0)
		return ;
	dot->x1 = ((dot->b * (-1)) - sqrt(dot->discr)) / (2 * dot->a);
	dot->x2 = ((dot->b * (-1)) + sqrt(dot->discr)) / (2 * dot->a);
	find_hit_distance(obj, *dot);
}

int	solve_caps(t_vector pos, t_vector ray, t_vector p1, t_figure **obj)
{
	t_vector	surf;
	t_equition	dot;

	dot.x1 = caps_intersection(pos, ray, (*obj)->cyl->axis, p1);
	dot.x2 = caps_intersection(pos, ray, (*obj)->cyl->axis, \
		(*obj)->cyl->center);
	if (dot.x1 == -1 && dot.x2 == -1)
		return (0);
	if (dot.x1 < dot.x2)
		(*obj)->cyl->flag = 1;
	find_hit_distance(obj, dot);
	if ((*obj)->point.dist > 0)
	{
		(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
			(*obj)->point.dist));
		surf = vector_sub((*obj)->point.hit_pos, (*obj)->cyl->center);
		if ((*obj)->cyl->flag)
			surf = vector_sub((*obj)->point.hit_pos, p1);
		if (vector_scalar_prod(surf, surf) < pow((*obj)->cyl->radius, 2))
		{
			(*obj)->cyl->cap = 1;
			return (1);
		}
	}
	return (0);
}

double	cylinder_intersection(t_vector pos, t_vector ray, t_figure **obj)
{
	t_vector	p1;
	t_equition	dot;

	(*obj)->cyl->cap = 0;
	solve_cylinder(pos, ray, obj, &dot);
	p1 = vector_sum((*obj)->cyl->center, \
		vector_prod((*obj)->cyl->axis, (*obj)->cyl->height));
	(*obj)->point.hit_pos = vector_sum(pos, vector_prod(ray, \
		(*obj)->point.dist));
	dot.m1 = vector_scalar_prod((*obj)->cyl->axis, \
		vector_sub((*obj)->point.hit_pos, (*obj)->cyl->center));
	dot.m2 = vector_scalar_prod((*obj)->cyl->axis, \
		vector_sub((*obj)->point.hit_pos, p1));
	if (dot.m1 > 0 && dot.m2 < 0)
		return ((*obj)->point.dist);
	if (solve_caps(pos, ray, p1, obj))
		return ((*obj)->point.dist);
	return (0);
}
