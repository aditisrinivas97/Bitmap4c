#include "bitmap.h"

int create_bitmap(uint64_t n) {
    bitmap = (uint8_t *)calloc(sizeof(uint8_t), n / 8);
    
    if(!bitmap)
        return -ENOMEM;
    
    bitmap_size = n / 8;

    return 0;
}

int clear_bit(uint64_t bitno) {
    int index = bitno / 8;
    int bit_index = bitno % 8;

    int val = (int)pow(2, bit_index);
    bitmap[index] = bitmap[index] & ~(val);

    return 0;
}

uint64_t get_first_unset_bit() {
    uint64_t index = 0;
    int bit_index = 0;
    int val, found = 0;

    while(index < bitmap_size) {
        bit_index = 0;
        while(bit_index < 8) {
            val = (int)pow(2, bit_index);
            
            if( !(bitmap[index] & val) ) {
                found = 1;
                break;
            }
            bit_index++;
        }

        if(!found)
            index++;
        else
            break;
    }

    if(found)
        return (index * 8 + bit_index);
    else
        return -1;
}
