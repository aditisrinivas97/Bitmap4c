#include <stdio.h>
#include "bitmap.h"

/* Compile using : 
    gcc -Wall -g test.c bitmap.c -o test
    ./test
*/

int main(void) {
    uint8_t * bitmap = NULL;
    uint64_t bitmap_size = 16;
    create_bitmap(&bitmap, &bitmap_size);
    set_bit(&bitmap, 13);
    set_bit(&bitmap, 0);
    printf("Setting bit at position 2\n");
    set_bit(&bitmap, 2);
    printf("Bit Status at position 2 : %llu\n", check_bit(bitmap, 2));
    print_bitmap(bitmap, bitmap_size);
    printf("First unset bit : %llu\n", get_first_unset_bit(bitmap, bitmap_size));
    printf("First set bit   : %llu\n", get_first_set_bit(bitmap, bitmap_size));
    printf("\nBitmap after clear bits : \n");
    clear_bit(&bitmap, 13);
    clear_bit(&bitmap, 2);
    print_bitmap(bitmap, bitmap_size);
    free_bitmap(&bitmap);
    return 0;
}