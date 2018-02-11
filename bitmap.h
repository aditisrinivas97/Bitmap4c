#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>

uint8_t * bitmap = NULL;
uint64_t bitmap_size = 0;

int create_bitmap(uint64_t n);
int clear_bit(uint64_t bitno);
int set_bit(uint64_t bitno);
uint64_t get_first_unset_bit();
uint64_t get_first_set_bit();
void print_bitmap();
int free_bitmap();

#endif