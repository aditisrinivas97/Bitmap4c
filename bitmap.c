#include "bitmap.h"

int create_bitmap(uint64_t n) {
    bitmap = (uint8_t *)calloc(sizeof(uint8_t), n / 8);
    
    if(!bitmap)
        return -ENOMEM;
    
    bitmap_size = n / 8;

    return 0;
}

int clear_bit(uint64_t bitno) {
    uint64_t index = bitno / 8;
    int bit_index = bitno % 8;

    int val = (int)pow(2, bit_index);
    bitmap[index] = bitmap[index] & ~(val);

    return 0;
}

int set_bit(uint64_t bitno) {
    uint64_t index = bitno / 8;
    int bit_index = bitno % 8;

    int val = (int)pow(2, bit_index);
    bitmap[index] = bitmap[index] | (val);

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

uint64_t get_first_set_bit() {
    uint64_t index = 0;
    int bit_index = 0;
    int val, found = 0;

    while(index < bitmap_size) {
        bit_index = 0;
        while(bit_index < 8) {
            val = (int)pow(2, bit_index);
            
            if(bitmap[index] & val) {
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

void print_bitmap(){
    printf("Little Endian\n");
    int index = 0, bit_index = 0;
    for(index = 0; index < bitmap_size; index++){
        for (bit_index = 0; bit_index < 8; bit_index++) {
            printf("%d", !!((bitmap[index] << bit_index) & 0x80));
        }
        printf(" ");
    }
    printf("\n");
}

int free_bitmap(){
    free(bitmap);
    return 0;
}

int main(void) {
    create_bitmap(16);
    set_bit(1);
    set_bit(2);
    set_bit(3);
    set_bit(4);
    set_bit(5);
    set_bit(6);
    set_bit(7);
    set_bit(13);
    set_bit(15);
    int x = get_first_set_bit();
    int y = get_first_unset_bit();
    print_bitmap();
    printf("\nfirst set bit : %d\nfirst unset bit : %d\n", x, y);
    clear_bit(13);
    printf("\nBitmap after clear bit : \n\n");
    print_bitmap();
    free_bitmap();
    return 0;
}