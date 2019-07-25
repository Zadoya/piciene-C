/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:23:35 by jeckhard          #+#    #+#             */
/*   Updated: 2019/07/19 22:23:38 by jeckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		longest(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

int		btree_level_count(t_btree *root)
{
	int i;

	i = 0;
	if (!root)
		return (i);
	if (root->left)
		i = longest(i, btree_level_count(root->left));
	if (root->right)
		i = longest(i, btree_level_count(root->right));
	return (i + 1);
}
