/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolnat <ccolnat@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 07:16:36 by ccolnat           #+#    #+#             */
/*   Updated: 2026/01/31 07:52:44 by ccolnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
    return;
}

void    ft_put_number(long long nb)
{
    if(nb < 0)
    {
        nb = -nb;
            write(1, "-", 1);

    }
    if(nb < 10)
    {
        ft_putchar(nb + '0');
    }
    if(nb > 10)
    {
        ft_put_number(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
}
int main(int argc, char** argv)
{
    if(argc != 1)
    {
        write(1, "error", 5);
        return(1);
    }
    else
    {
        ft_put_number(2);
        write(1, "\n", 1);
        ft_put_number(-2);
        write(1, "\n", 1);
        ft_put_number(0);
        write(1, "\n", 1);
        ft_put_number(11);
        write(1, "\n", 1);
        ft_put_number(-11);
        write(1, "\n", 1);
        ft_put_number(22222444499999);
        write(1, "\n", 1);
        ft_put_number(-22222444499999);
        write(1, "\n", 1);
        return(0);
    }
}
