#ifndef BSQ_H
#define BSQ_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>


typedef struct s_chars
{
	char	empty;
	char	obstacle;
	char	full;
}	t_chars;

typedef struct s_map
{
	int	wid;
	int	hei;
	char	**grid;
	t_chars	chars;
}	t_map;

typedef struct s_sq
{
	int	x;
	int	y;
	int	size;
}	t_sq;

#endif

// Assignment name              : bsq
// Expected files               : *.c *.h
// Allowed functions and globals: malloc, calloc, realloc, free, fopen, fclose,
// getline, fscanf, fputs, fprintf, printf, stdout, stdin
// --------------------------------------------------------------------------------

// The aim of this program is to find the biggest square on a map, avoiding obstacles.
// A file containing the map will be provided. It'll have to be passed as an argument for your program.
// The first line of the map contains information on how to read the map:
//  - The number of lines on the map;
//  - The "empty" character;
//  - The "obstacle" character;
//  - The "full" character.
// The map is made up of '"empty" characters', lines and '"obstacle" characters'.
// The aim of the program is to replace '"empty" characters' by '"full" characters' in order to represent the biggest square possible.
// In the case that more than one solution exists, we'll choose to represent the square that's closest to the top of the map, then the one that's most to the left.
// Your program will receive only one map as argument.
// Should there be no passed arguments, your program must be able to read on the standard input.

// Definition of a valid map :
//  - All lines must have the same length.
//  - There's at least one line of at least one cell.
//  - At each end of line, there's a line break.
//  - The characters on the map can only be those introduced in the first line.
//  - The map is invalid if a character is missing from the first line, or if two characters (of empty, full and obstacle) are identical, or extra characters on the first line.
//  - The characters can be any printable character, even numbers.
//  - In case of an invalid map, your program should display "Error: invalid map" on the standard output followed by a line break.
//  - In case of other errors, display "Error:" followed by a meaningful message.

// %>cat example_file
// 9.ox
// ...........................
// ....o......................
// ............o..............
// ...........................
// ....o......................
// ...............o...........
// ...........................
// ......o..............o.....
// ..o.......o................
// %>./bsq example_file
// .....xxxxxxx...............
// ....oxxxxxxx...............
// .....xxxxxxxo..............
// .....xxxxxxx...............
// ....oxxxxxxx...............
// .....xxxxxxx...o...........
// .....xxxxxxx...............
// ......o..............o.....
// ..o.......o................
// %>
