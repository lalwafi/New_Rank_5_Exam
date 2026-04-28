#ifndef LIFE_H
#define LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_game
{
	char	**grid;
	int		wid;
	int		hei;
	int		ite;
	int		x;
	int		y;
	int		draw;
} t_game;

#endif

// Assignment name : life
// Expected files : *.c *.h
// Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free
// --------------------------------------------------------------------------------
// You must write a program that will simulate a game of life.
// The prototype of this program is the following:
// ./life width height iterations
// Width and height are the dimensions of the board and iterations is the number of
// iterations of the game of life.
// the initial configuration of the board will be drawn by a sequence of commands
// in the standard input.
// Imagine a pen starting in the top left corner of the board.
// Each command is one of these characters:

// w a s d -> move the pen up, left, bottom, and right.
// x -> lift or lower the pen in order to start or stop drawing.

// Once end of file is reached, your program must simulate a game of life on this
// board and print the result in stdout (each cell alive will be represented by
// the character 'O' and each dead cell will be represented by a space)
// each cell outside of the array will be considered dead
// Example:
// $> echo 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
//      $
//  000 $
//  0 0 $
//  000 $
//      $
// $> echo 'sdxssdswdxddddsxaadwxwdxwaa' | ./a.out 10 6 0 | cat -e
//           $
//  0   000  $
//  0     0  $
//  000  0   $
//   0  000  $
//           $
// $> echo 'dxss' | ./a.out 3 3 0 | cat -e
//  0 $
//  0 $
//  0 $
// $> echo 'dxss' | ./a.out 3 3 1 | cat -e
//    $
// 000$
//    $
// $> echo 'dxss' | ./a.out 3 3 2 | cat -e
//  0 $
//  0 $
//  0 $