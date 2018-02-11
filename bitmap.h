#ifndef BITMAP_H
#define BITMAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <errno.h>

int create_bitmap(uint8_t ** bitmap, uint64_t * bitmap_size);
void print_bitmap(uint8_t * bitmap, uint64_t bitmap_size);
int free_bitmap(uint8_t * bitmap);
int clear_bit(uint8_t ** bitmap, uint64_t bitno);
int set_bit(uint8_t ** bitmap, uint64_t bitno);
uint64_t get_first_set_bit(uint8_t * bitmap, uint64_t bitmap_size);
uint64_t get_first_unset_bit(uint8_t * bitmap, uint64_t bitmap_size); 

#endif