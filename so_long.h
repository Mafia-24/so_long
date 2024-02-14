/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:03:30 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:27:43 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 10
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_map
{
	int		height;
	int		weight;
	char	**components;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game_play
{
	int		movements;
	int		collected;
	int		total_colls;
	t_point	portal_pos;
	char	player_direction;
}	t_game_play;

typedef struct s_partrol
{
	t_point	pos;
	char	direction;
	int		img_number;
}	t_partrol;

typedef struct s_images
{
	void	*r_dino_imgs[4];
	void	*l_dino_imgs[4];
	void	*r_enmy_imgs[4];
	void	*l_enmy_imgs[4];
	void	*bg_img;
	void	*wall_img;
	void	*coll_img;
	void	*cld_exit;
	void	*open_exit;
}	t_images;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_point		player_pos;
	t_map		map;
	t_game_play	party;
	t_images	game_images;	
	t_partrol	*patrols;
}	t_vars;

int		has_wall_boundaries(char *line, int line_length);
int		is_all_walls(char *line);
t_map	read_and_check_bonds(int fd);
void	remove_nl(char **line);
void	check_rest_of_lines(char *line, int fd, int *lines_num,
			int line_length);
int		valide_ber_file(char *file_name);
int		check_components(char *line);
void	read_and_store_map(t_map *map, int fd);
int		contain_necessary_components(t_map map, int i, int j);
void	check_map(char *file_name);
void	colorise(t_map map, int x, int y);
int		check_colored_map(t_map sub_map);
void	flood_fill(t_map map, t_point pos);
int		find_valid_path(t_map map);
void	find_player_position(t_map map, t_point *player);
void	find_portal_position(t_map map, t_point *player);
void	find_dinau_position(t_map map, t_point *player);
int		can_pass_thrue(char c);

void	invalid_extension(void);
void	cant_open_file(char *file_name);
void	no_data_in_file(void);
void	invalid_map(char *line);
void	failed_allocation(void);
void	invalid_component(void);
void	absent_valid_path(void);
void	missing_components(void);

int		ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strrchr(char *str, int c);

char	*get_next_line(int fd);
int		allocating(char **buffer, char **fl, char **st);
int		reader(int fd, char **buffer, char **fl, char **stat);
void	*freeing(char **st, char **buffer, char **fl, int type);
size_t	gnl_ft_strlen(char *str, int type);
int		cont_nl(char *str);
int		fill_st(char *buffer, int stop, char **st);
int		fill_fl(char *buffer, int stop, char **fl);
int		init_fill_full(char **st, char **fl);

void	free_2d(char **arr);
void	exit_free(t_vars *vars);
void	free_allocated_vars(t_vars *vars);

int		count_partolls(t_map map);
int		count_colls(t_map map);

void	short_put_img_to_window(t_vars *vars, int x, int y, void *img);
void	change_images_up(t_vars *vars, int i);
void	change_images_down(t_vars *vars, int i);
void	change_images_right(t_vars *vars, int i);
void	change_images_left(t_vars *vars, int i);
void	move_enemy_right(t_vars *vars, int i);
void	move_enemy_left(t_vars *vars, int i);
void	move_enemie(t_vars *vars, int i);
void	put_steps_number(t_vars *vars);
int		handle_keyrelease(int keysym, t_vars *vars);
int		exit_game(t_vars *vars);
void	set_patrol_image(t_vars *vars, int i, int j);
void	set_collectible_image(t_vars *vars, int i, int j);
void	set_dinosor_image(t_vars *vars, int i, int j);
void	set_wall_image(t_vars *vars, int i, int j);
void	set_exit_image(t_vars *vars, int i, int j);
void	set_background_image(t_vars *vars, int i, int j);
void	map_to_image(t_map map, t_vars *vars);
void	reset_image(t_vars *vars, int x, int y);
void	check_portal(t_vars *vars);
int		move_enemies(t_vars *vars);
void	move_player_up(t_vars *vars);
void	move_player_down(t_vars *vars);
void	move_player_right(t_vars *vars);
void	move_player_left(t_vars *vars);
void	initialize_map(t_map map);
void	find_dinau_position(t_map map, t_point *player);
int		move_dinau(t_vars *vars);
void	find_portal_position(t_map map, t_point *player);
void	mlx_error(t_vars *vars);
void	safe_put_image(t_vars *vars, void *img, int i, int j);
void	set_images(t_vars *vars);
void	set_portal_imgs(t_vars *vars);
void	set_other_images(t_vars *vars);

#endif