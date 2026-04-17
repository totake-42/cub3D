[1mdiff --git a/src/game/raycasting.c b/src/game/raycasting.c[m
[1mindex 274dbc1..6a3a205 100644[m
[1m--- a/src/game/raycasting.c[m
[1m+++ b/src/game/raycasting.c[m
[36m@@ -6,7 +6,7 @@[m
 /*   By: totake <totake@student.42tokyo.jp>         +#+  +:+       +#+        */[m
 /*                                                +#+#+#+#+#+   +#+           */[m
 /*   Created: 2026/02/20 16:00:00 by totake            #+#    #+#             */[m
[31m-/*   Updated: 2026/04/17 16:17:20 by totake           ###   ########.fr       */[m
[32m+[m[32m/*   Updated: 2026/04/17 16:38:34 by totake           ###   ########.fr       */[m
 /*                                                                            */[m
 /* ************************************************************************** */[m
 [m
[36m@@ -27,6 +27,12 @@[m
  *[m
  * Returns:[m
  *   t_ray_result containing collision and rendering data.[m
[32m+[m[32m *[m
[32m+[m[32m * wall_x:[m
[32m+[m[32m *   Exact hit position along the wall surface (range: 0.0 to 1.0).[m
[32m+[m[32m *   This value is calculated by taking the fractional part of the[m
[32m+[m[32m *   collision coordinate and is used for texture mapping.[m
[32m+[m[32m *   It determines which column of the texture to sample.[m
  */[m
 [m
 static t_ray_result	cast_single_ray(t_cub3d *app, double ray_x, double ray_y)[m
[36m@@ -48,7 +54,7 @@[m [mstatic t_ray_result	cast_single_ray(t_cub3d *app, double ray_x, double ray_y)[m
 		r.wall_x = app->player.pos_y + r.perp_wall_dist * ray_y;[m
 	else[m
 		r.wall_x = app->player.pos_x + r.perp_wall_dist * ray_x;[m
[31m-	r.wall_x -= floor(r.wall_x);[m
[32m+[m	[32mr.wall_x -= (int)r.wall_x;[m
 	return (r);[m
 }[m
 [m
