/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: murachid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:27:30 by murachid          #+#    #+#             */
/*   Updated: 2021/02/11 15:27:32 by murachid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define TILE_SIZE			64
# define LEFT				123
# define RIGHT				124
# define KEY_PRESS			2
# define KAY_RELEASE		3
# define ESC				53
# define A					0
# define S					1
# define W					13
# define D					2
# define PI					3.141592654
# define FOV_ANGLE			1.04719755133
# define WALL_STRIP_WIDTH	2
# define INT_MAX			2147483647
# define TOW_PI				6.283185307
# define TEXTURE_WIDTH		64
# define TEXTURE_HEIGHT		64
# define WIN_WMAX			2560
# define WIN_HMAX			1440
# define TWO_PI				6.28318530718

typedef	struct				s_sp
{
	float					w;
	float					perp_distance;
	float					sprite_height;
	float					sprite_width;
	float					sprite_top_y;
	float					sprite_bottom_y;
	float					sprite_angle;
	float					sprite_screen_pos_x;
	float					sprite_left_x;
	float					sprite_right_x;
	float					texel_width;
	int						distance_fromt_top;
	int						textureffset_y;
	int						textureffset_x;
	int						texel_color;
	float					angle;
	int						numvisiblesprites;
}							t_sp;

typedef	struct				s_textures
{
	void					*ptr[6];
	int						*data[6];
	int						bpp;
	int						line;
	int						endian;
	int						height[6];
	int						width[6];
}							t_textures;

typedef	struct				s_textures_sprite
{
	void					*ptr1;
	int						*data1;
	int						bpp1;
	int						line1;
	int						endian1;
	int						height1;
	int						width1;
}							t_textures_sprite;

typedef	struct				s_check_color
{
	int						res;
	int						west;
	int						south;
	int						north;
	int						sprite;
	int						ceilling;
	int						east;
	int						floor;
	int						set;
}							t_check_color;

typedef	struct				s_color
{
	int						r;
	int						g;
	int						bb;
	int						f;
	int						c;
}							t_color;

typedef	struct				s_direction
{
	float					xintercept;
	float					yintercept;
	float					xstep;
	float					ystep;
	int						foundhorzwallhit;
	float					horzwallhitx;
	float					horzwallhity;
	float					next_horz_touch_x;
	float					nexthorztouchy;
	int						foundvertwallhit;
	float					vertwallhitx;
	float					vertwallhity;
	float					nextverttouchx;
	float					nextverttouchy;
	float					horzhitdistance;
	float					verthitdistance;
}							t_direction;

typedef	struct				s_rays
{
	float					wallhitx;
	float					wallhity;
	float					distance;
	int						israyfacingdown;
	int						israyfacingup;
	int						israyfacingright;
	int						israyfacingleft;
	float					angle;
	int						washitvertical;
}							t_ray;

typedef	struct				s_cube
{
	int						walltoppixel;
	int						wallbottompixel;
	int						textureoffsetx;
	int						wallstripheight;
	float					perpdistance;
	float					distanceprojplane;
	float					projectedwallheight;
}							t_cube;

typedef	struct				s_player{
	float					x;
	int						pos;
	float					y;
	float					nx;
	float					ny;
	int						turndirection;
	int						walkdirection;
	float					rotationangle;
	float					movespeed;
	float					rotationspeed;
	float					i;
	float					j;
	float					found_player;
	float					position;
	int						saved;
}							t_player;

typedef	struct				s_dataa
{
	int						h;
	int						w;
	char					*no;
	char					*so;
	char					*we;
	char					*ea;
	char					*s;
	char					**map;
	char					*mapname;
	int						mapstart;
	int						plus_cver;
	int						horz;
	int						fcolor;
	int						ccolor;
	int						settings;
	int						vert;
}							t_ddata;

typedef	struct				s_data
{
	void					*img;
	char					*addr;
	void					*img1;
	char					*addr1;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
	int						width;
	int						height;
	void					*mlx;
	void					*mlx_win;
}							t_data;

typedef	struct				s_sptexture
{
	void					*img_sprite;
	int						*data;
	int						width;
	int						height;
}							t_sptexture;

typedef	struct				s_spriteone
{
	float					x;
	float					y;
	float					dst;
	float					size;
	float					x_ofst;
	float					y_ofst;
}							t_spriteone;

typedef	struct				s_sprite
{
	float					x;
	float					y;
	float					distance;
	float					angle;
	int						visible;
	int						texture;
}							t_sprite;

t_spriteone					g_spriteone[3500];
t_sprite					g_sprites[3500];
t_check_color				g_check_color;
t_sptexture					g_sptexture;
t_color						g_color;
t_ddata						g_data;
t_direction					g_verthorz;
t_ray						g_ray[3500];
t_player					g_ply;
t_textures					g_texture;
t_cube						g_cube;
int							g_nsprite;
t_textures_sprite			g_textures_sprite;
t_sp						g_sp;

void						error_msg_1(void);
void						error_msg_2(void);
void						array_free(char **tab);
void						error_msg(void);
int							check_len(char **s);
void						all_errors(void);
float						to_deg(float angle);
void						get_spriteimage(t_data *data);
void						sprite_put_pixels(t_data *data,
							int id, int i, int j);
void						draw_sprite(t_data *data, int id);
void						render_sprite(t_data *data, int id);
void						sort(void);
void						save_cordinate(int i, int j, int id);
void						get_sprite_pos();
void						sprite_util_one(int i, int j,
							t_sprite *visiblesprites);
int							len(char *s);
void						sprite_util(int x, int y, t_sprite
							*sprite, t_data *data);
int							ft_all_digit(char *str);
void						all_errors(void);
void						render3dprojectedwalls(t_data *data, int i);
void						error_color_masseg(void);
void						check_map(void);
void						ft_vert(int i);
void						renderspriteprojection(t_data *data);
void						ft_hort(int i);
void						ft_check_distence(int i);
void						test_texture(char **tab, int ab);
void						ft_initialize_player();
void						ft_initialize_ray(int i);
int							check_wall(float x, float y);
int							color(char **tab, int i1);
int							array_map(char **tab, int ab, int aa);
float						normalizeangle(float angle);
float						distancebetweenpoints(float x1, float y1,
							float x2, float y2);
void						ft_ray_cast(t_data *data);
int							read_file(void);
void						ft_resolution(char **tab, int i1);
void						init_texture(t_data *data);
void						ft_update(t_data *data);
void						ft_key_relese();
int							ft_key_press(int keycode, t_data *data);
void						ft_draw(t_data *data);
void						ft_map(t_data *data);
void						my_mlx_pixel_put(t_data *data, int x,
							int y, int color);
size_t						ft_strlen_l(const char *str);
char						*ft_strtrim1(char const *s1, char const *set);
void						screen_shot(t_data *data);
void						arg_check(char *s1);
void						arg_save_check(char *save);
void						open_txt(char *txt);
void						espac(int a, int i);
void						fonction(int i1, int a, char **tab);
void						espace_2(int a, int i, int b);
void						error_five(void);
void						error_six(void);
void						error_other(void);
void						error_three(void);
void						utile(t_data *data);
void						error_one(void);
char						**check_cub(char **tab);
void						ft_error_1(char **tab);
void						ft_error_(char **tab);
void						error_five_1(int a, int i, int b);
void						read_map(char **tab);
void						error_six_1(int a, int i);
int							ft_atoi_res(const char *str);
void						color_error_1(char **tab, int b, int i, int ab);
void						function_diretion(t_data *data, int x,
							int y, int textureffsety);
void						checkpathvalid(char *s1);
#endif
