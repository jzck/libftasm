/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:36:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 18:27:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "libft.h"

# define FG_BLACK		"\x1b[30m"
# define FG_RED			"\x1b[31m"
# define FG_GREEN		"\x1b[32m"
# define FG_YELLOW		"\x1b[33m"
# define FG_BLUE		"\x1b[34m"
# define FG_MAGENTA		"\x1b[35m"
# define FG_CYAN		"\x1b[36m"
# define FG_DEFAULT		"\x1b[0m"

# define BG_BLACK		"\x1b[40m"
# define BG_RED			"\x1b[41m"
# define BG_GREEN		"\x1b[42m"
# define BG_YELLOW		"\x1b[43m"
# define BG_BLUE		"\x1b[44m"
# define BG_MAGENTA		"\x1b[45m"
# define BG_CYAN		"\x1b[46m"
# define BG_DEFAULT		"\x1b[49m"

void	ft_color_reset(void);
void	ft_color_set(char *fg, char *bg);

#endif
