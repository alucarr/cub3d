/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:35:52 by hbay              #+#    #+#             */
/*   Updated: 2024/04/19 12:35:52 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_raycast
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			key_w;
	int			key_s;
	int			key_left;
	int			key_right;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltadistx;
	double		deltadisty;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	int			wall;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			tex_x;
	int			texnum;
	double		texstep;
	double		texpos;
	int			key_a;
	int			key_d;
}				t_raycast;

typedef struct s_objs
{
	int		size;
	void	*no;
	int		*no_data;
	int		no_bpp;
	int		no_size_line;
	int		no_endian;		
	int		*so_data;
	int		so_bpp;
	int		so_size_line;
	int		so_endian;		
	int		*we_data;
	int		we_bpp;
	int		we_size_line;
	int		we_endian;		
	int		*ea_data;
	int		ea_bpp;
	int		ea_size_line;
	int		ea_endian;		
	void	*so;
	void	*we;
	void	*ea;
}		t_objs;

typedef struct s_cub3d
{
	struct s_data	*data;
	void			*mlx_init;
	void			*mlx_window;
	void			*mlx_object;
	int				*mlx_object_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void			*mlx_img;
	int				width;
	int				height;

}			t_cub3d;

typedef struct s_data
{
	struct s_cub3d		*cub3d;
	struct s_objs		*objs;
	struct s_raycast	*raycast;
	char				**map;
	char				**c_map;
	char				*file;
	char				*no;
	char				*ea;
	char				*we;
	char				*so;
	int					no_flag;
	int					ea_flag;
	int					we_flag;
	int					so_flag;
	int					floor_flag;
	int					ceil_flag;
	int					floor_color;
	int					ceil_color;
	char				*f_for_tmp;
	char				*c_for_tmp;
	char				**colors;
	char				*just_map;
	int					map_len;
	int					start_location;
	int					player;
	short				c_color[3];
	short				f_color[3];
	char				user_type;
	int					map_flag;
	int					c_flag;
}			t_data;

void	ft_free(t_data *data);
int		ft_strlen1(char *c);
void	ray_casting(t_data *data);
void	map_counter(t_data *data, int *i);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup1(char *s1);
void	get_file(char **av, t_data *data);
char	*ft_strjoin1(char *s1, char *s2);
void	ft_error(t_data *data, char *message);
void	error_case(char *message);
void	get_we_textures(t_data *data, int *i);
void	get_no_textures(t_data *data, int *i);
void	get_ea_textures(t_data *data, int *i);
void	get_so_textures(t_data *data, int *i);
void	texture_control(t_data *data, char *path);
void	map_counter(t_data *data, int *i);
void	get_ceil(t_data *data, int *i);
void	get_floor(t_data *data, int *i);
void	control_and_set(t_data *data, char *str, int j);
char	*ft_substr(char *s, size_t start, size_t len);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str, t_data *data);
void	other_case_for_direction(t_data *data, int **i, int *tmp, int value);
int		name_control(char *av);
int		is_exist(char *str);
void	get_map(t_data *data, char **av);
int		is_true_value(t_data *data);
int		control_for_map(t_data *data, int **i);
void	get_direction(t_data *data, char **av);
void	init_tex(t_data *data);
int		control_map(t_data *data, int **i);
void	check_spaces(t_data *data);
void	up_wall_control(t_data *data);
void	down_wall_control(t_data *data);
int		down_wall(t_data *data, int i);
int		check_walls(t_data *data, char c);
void	left_wall_control(t_data *data);
void	right_wall_control(t_data *data);
int		right_wall(t_data *data, int i, int y);
void	flood_fill(t_data *data);
void	flood_fill2(t_data *data);
void	loop(t_data *data, int i, int j);
int		player(char c);
void	render(t_data *data);
void	set_variables(t_data *data);
void	set_images(t_data *data);
void	set_player_information(t_data *data);
void	cam_options(t_data *data);
void	cam_options2(t_data *data);
void	control(t_data *data);
int		render_loop(t_data *data);
void	clear_screen(t_data *data);
void	ceil_other_func(t_data *data);
void	floor_other_func(t_data *data);
void	set_fc_color(t_data *data);
int		press(int k, void *dataa);
int		rele(int k, t_data *data);
void	ray_caster(t_data *data);
void	calculate_all_rc(t_data *data, int n);
void	nswe(t_data *data);
void	texture(t_data *data, int num);
void	set_rc_value(t_data *data);
void	wall(t_data *data);
void	calculate_ray(t_data *data);
void	maneuver(t_data *data);
void	key_right(t_data *data);
void	key_left(t_data *data);
void	key_d1(t_data *data);
void	key_a1(t_data *data);
int		close_window(int key, void *cub3d);
void	check_space(t_data *data);
void	check_all_map(t_data *data, int i);
void	other_case2(t_data *data, int i, int j);
void	right_wall_other_case(t_data *data, int i);
void	get_direction_other_case(t_data *data, int *i);
void	get_direction_other_case2(t_data *data, char **av, int i);
int		no_case(t_data *data, int *i);
int		so_case(t_data *data, int *i);
int		ea_case(t_data *data, int *i);
int		we_case(t_data *data, int *i);
int		floor_case(t_data *data, int *i);
int		ceil_case(t_data *data, int *i);
void	other_case_floor_color(t_data *data, int **i, int *tmp, int flag);
void	other_case_floor_color1(t_data *data, int **i, int *tmp, int flag);
void	control_line(t_data *data, char *str);
#endif
