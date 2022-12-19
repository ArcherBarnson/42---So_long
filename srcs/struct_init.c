/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:00:11 by bgrulois          #+#    #+#             */
/*   Updated: 2022/08/31 11:06:54 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite_groups(t_sprites *sprites)
{
	int	i;

	i = 0;
	sprites->player = malloc(sizeof(t_data) * 3);
	sprites->exit = malloc(sizeof(t_data) * 2);
	sprites->collectible = malloc(sizeof(t_data) * 3);
	sprites->ennemy = malloc(sizeof(t_data) * 3);
	if (!sprites->player || !sprites->exit
		|| !sprites->collectible || !sprites->ennemy)
		return ;
	while (i < 2)
	{
		sprites->player[i] = NULL;
		sprites->exit[i] = NULL;
		sprites->ennemy[i] = NULL;
		sprites->collectible[i] = NULL;
		i++;
	}
	sprites->player[i] = NULL;
	sprites->ennemy[i] = NULL;
	sprites->collectible[i] = NULL;
	return ;
}

void	reset_all(t_mlx_global *game)
{
	game->map_dimensions[0] = 0;
	game->map_dimensions[1] = 0;
	game->player_pos[0] = 0;
	game->player_pos[1] = 0;
	game->p = 0;
	game->e = 0;
	game->c = 0;
	game->map_fd = 0;
	game->step_count = 0;
	game->ennemy_count = 0;
	game->ennemypos = NULL;
	game->map_line = NULL;
	game->map = NULL;
	game->spd = NULL;
	game->sps = 0;
}

t_sprites	*sprites_init(void)
{
	t_sprites	*sprites;

	sprites = malloc(sizeof(t_sprites));
	if (!sprites)
		return (NULL);
	init_sprite_groups(sprites);
	sprites->ground = NULL;
	sprites->wall = NULL;
	sprites->img_width = 0;
	sprites->img_height = 0;
	sprites->framerate_ctl = 0;
	sprites->anim_stage = 0;
	return (sprites);
}

t_mlx_global	*struct_init(void)
{
	t_mlx_global	*game;

	game = malloc(sizeof(t_mlx_global));
	if (!game)
		return (NULL);
	game->mlx = NULL;
	game->window = NULL;
	reset_all(game);
	game->sprites = sprites_init();
	return (game);
}
