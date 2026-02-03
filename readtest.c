/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readtest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolnat <ccolnat@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 09:20:59 by ccolnat           #+#    #+#             */
/*   Updated: 2026/02/03 11:05:30 by ccolnat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void empty_buffer(void)
{
    char c;
    int res;

    c = 0;
    res = 0;
    printf("Bonjour\n");
    while(c != '\n')
    {
        res = read(0, &c, 1);
        if (res <= 0)
            break;
    }
    printf("Input to long, input croped\n");
}

int read_test(const int word_size, const int nb_words)
{
    printf("Parameters are :\nSize of word = %d\nNumber of word = %d\n", word_size, nb_words);
    int i;
    char   *read_buffer;
    ssize_t read_count;
    ssize_t read_total_count;
    ssize_t max_size;

    read_total_count = 0;
    read_count = 0;
    max_size = ((word_size) * nb_words);
    i = 1;
    read_buffer = malloc((max_size + 1) *sizeof(char));
    if (!read_buffer)
        return (-2);
    while(i != (nb_words + 1))
    {
        printf("\033[33mThe program is waiting for word nb %d out of %d\033[0m\n", i, nb_words);
        read_count = read(0, (read_buffer + read_total_count), word_size + 1);
        if (read_count == -1)
        {
            free(read_buffer);
            printf("\033[36mMemory freed :D\033[0m\n");
            return (-1);
        }
        read_total_count += read_count;
        if ((read_buffer[read_count - 1]) == '\n')
        {
            printf("\033[32mRead ok !\033[0m\n");
            read_total_count--;
        }
        else if (read_count < word_size + 1)
        {
            printf("\033[32mRead ok (short)!\033[0m\n");
            read_total_count--;
        }
        else
        {
            empty_buffer();
            read_total_count--;
        }
        
        printf("Total char read = %ld \n", read_total_count);
        read_count = 0;
        i++;
        
    }
    if (read_total_count > 0)
    {
        read_buffer[read_total_count] = '\0';
        printf("\033[34mResult is : %s\033[0m\n", read_buffer);
        free(read_buffer);
        printf("\033[36mMemory freed :D\033[0m\n");
        return (read_total_count);
    }
    else
    {
        free(read_buffer);
        printf("\033[36mMemory freed :D\033[0m\n");
        return (-3);
    }
}
int main(int argc, char **argv)
{
    int res;
    res = 0;
    int r_t1;
    int r_t2;
    if(argc != 3)
    {
        printf("\033[31mError, wrong number of args\033[0m\n");
        return (1);
    }
    else
    {
        if((argv[1][0] < 49) || (argv[1][0] > 57))
        {
            printf("\033[31mError, word size is not betwen 1 and 9\033[0m\n");
            return (1);
        }
        if((argv[2][0] < 49) || (argv[2][0] > 57))
        {
            printf("\033[31mError, word number is not betwen 1 and 9\033[0m\n");
            return (1);
        }
        r_t1 = (argv[1][0]) - 48;
        r_t2 = (argv[2][0]) - 48;
        res = read_test(r_t1 ,r_t2);
        if(res == -1)
        {
            printf("\033[31mError, read went wrong in read_test :c\033[0m\n");
            return (1);
        }
        if(res == -2)
        {
            printf("\033[31mError, Malloc went wrong in read_test :c\033[0m\n");
            return (1);
        }
        if(res == -3)
        {
            printf("\033[31mError, read_test detected no input :c\033[0m\n");
            return (1);
        }
        if(res > 0)
        {
            printf("\033[32mSucces !\033[0m\n");
            return (0);
        }
    }
}
