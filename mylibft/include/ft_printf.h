/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:46:31 by skimura           #+#    #+#             */
/*   Updated: 2025/05/25 18:17:18 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef DIGITS_10
#  define DIGITS_10 "0123456789"
# endif

# ifndef DIGITS_16
#  define DIGITS_16 "0123456789abcdef"
# endif

# ifndef DIGITS_16X
#  define DIGITS_16X "0123456789ABCDEF"
# endif

int	ft_printf(const char *format, ...);
int	ft_put_c(char c);
int	ft_put_s(char *s);
int	ft_put_p(void *p);
int	ft_put_d_i(long long n);
int	ft_put_u_hex(unsigned long long n, char spec);
int	ft_unsigned_nbr_base(unsigned long long n, int base, const char *digits);

#endif
