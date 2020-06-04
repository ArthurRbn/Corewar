/*
** EPITECH PROJECT, 2020
** asm
** File description:
** array_utils
*/

#pragma once

int array_len(void **arr);
void custom_free_array(void **arr, void (*func)(void *));
void free_array(void **arr);
