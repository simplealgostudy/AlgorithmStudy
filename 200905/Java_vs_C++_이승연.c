/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3613.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 09:14:57 by marvin            #+#    #+#             */
/*   Updated: 2020/09/04 09:14:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    change_to_cpp(char *str) //모두 소문자일것.
{
    int i;
    int n;

    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            ft_putchar('_');
            str[i] = str[i] + 32;
        }
        ft_putchar(str[i]);
        i++;
    }
}

void    change_to_java(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == '_')
        {
            str[i+1] = str[i+1] - 32;
            i++;
        }
        ft_putchar(str[i]);
        i++;
    }
}

int main(int argc, char *argv[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[1][i] != '\0') 
    {
        if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') //c++이 아닌 경우
        {
            change_to_cpp(argv[1]);
            j++;
        }
        i++;
    }
    if (j == 0)
    {
        change_to_java(argv[1]);
    }
    return (0);
}
