/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:54:54 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/09/08 17:18:53 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_flags
{
	int				width;
	int				precision;
	int				len;
	unsigned char	spec;
	unsigned char	space_d;
	unsigned char	hash;
	unsigned char	minus;
	unsigned char	space;
	unsigned char	zero;
	unsigned char	dot;
	unsigned char	h_flag;
	int				l_flag;
}					t_flag;

int					ft_abs(int i);
char				*flag_null(char *s, int i);

int					razrad(long long int m);

int					check_x_x(t_flag *flags);

int					check_flags(t_flag *flags);

int					check_hesh_x_x(t_flag *flags);

int					ft_printf(const char *format, ...);
int					check_zero_hash(t_flag *flags, long long i);

int					ft_print_d_i(va_list args, t_flag *flags);
int					ft_printf_o_u(va_list args, t_flag *flags);
int					ft_print_x_x(va_list args, t_flag *flags);
int					ft_print_f(va_list args, t_flag *flags);
int					ft_printf_c(va_list args, t_flag *flags);
int					ft_printf_s(va_list args, t_flag *flags);
int					ft_printf_p(va_list args, t_flag *flags);
int					ft_printf_percent(t_flag *flags);

int					ft_x_x(long long i, t_flag *flags);
int					ft_init_procent(char *str, int i,
					va_list args, t_flag *flags);
int					ft_d_i_six(int len_str, char *str, t_flag *flags);
int					ft_d_i_five(int len_str, char *str, t_flag *flags);
int					ft_d_i_four(int len_str, char *str, t_flag *flags);
int					ft_d_i_seven(int len_str, char *str, t_flag *flags);
int					ft_d_i_three(int len_str, char *str, t_flag *flags);

int					ft_init_num(const char *str, int i, t_flag *flags);

int					ft_init_spec(char spec, va_list args, t_flag *flags);
int					ft_o_u(int len, long long i, char *str, t_flag *flags);

int					ft_o_u_four(long long i, int len_str,
					char *str, t_flag *flags);
int					ft_o_u_three(long long i, int len_str,
					char *str, t_flag *flags);

int					ft_x_x_six(int len_str, char *str, t_flag *flags);
int					ft_o_u_six(int len_str, char *str, t_flag *flags);
int					ft_x_x_four(int len_str, char *str, t_flag *flags);
int					ft_x_x_five(int len_str, char *str, t_flag *flags);
int					ft_x_x_seven(int len_str, char *str, t_flag *flags);
int					ft_x_x_three(int len_str, char *str, t_flag *flags);
int					ft_o_u_five(long long i, int len_str,
					char *str, t_flag *flags);
int					ft_o_u_seven(long long i, int len_str,
					char *str, t_flag *flags);

int					ft_analazer_flags(const char *str, int i,
										t_flag *flags, va_list args);

int					ft_print_f_one(char *str, t_flag *flags);
char				*double_number(long double num);
char				*ft_itoa_c(long long int n, int *a);
char				*ft_itoa_frac(long long int n, int a);
char				*f_with_zero(int sign, long long int n,
					double num, int i);
char				*rounding(char *s, int n);

char				*ft_lltoa_base(unsigned long long n, int base);
char				*ft_lltoa_base_x_x(unsigned long long n, int base, int x_x);
size_t				ft_atoi_pres(const char *s, int i);
size_t				ft_countdigit(unsigned long long n, int base, size_t count);

int					ft_write(unsigned char str);
#endif
