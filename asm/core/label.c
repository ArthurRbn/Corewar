/*
** EPITECH PROJECT, 2020
** asm
** File description:
** label
*/

#include "label.h"
#include "bin_utils.h"
#include "prog_size.h"

unsigned int get_label_address(token_t **tokens, char const *label)
{
    return (swap_endianness(get_prog_size(tokens, label)));
}
