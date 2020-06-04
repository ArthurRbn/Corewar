/*
** EPITECH PROJECT, 2020
** asm
** File description:
** bin_utils
*/

#include "bin_utils.h"

int swap_endianness(int val)
{
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF );
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

short swap_endianness_short(short val)
{
    return ((val >> 8) | (val << 8));
}
