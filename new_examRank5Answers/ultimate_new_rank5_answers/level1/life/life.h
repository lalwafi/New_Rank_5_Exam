/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 03:20:24 by fbetul            #+#    #+#             */
/*   Updated: 2026/04/28 20:25:53 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE
#define LIFE

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


typedef struct s_game
{
	int width;
	int height;
	int iterations;
	char alive;
	char dead;
	int i;
	int j;
	int draw;
	char** board;
} t_game;

int init_game(t_game* game, char* argv[]);
void fill_board(t_game* game);
int play(t_game* game);
void print_board(t_game* game);
void free_board(t_game* game);


#endif
