# Bitmap4c
A C library for creating and manipulating Bitmaps.

## API


The bitmap is maintained in a byte array of appropriate size. Hence, it's type should be `uint8_t *` or something similar.

___

    int create_bitmap(uint8_t ** bitmap, uint64_t * bitmap_size);

Used to create the bitmap. Since the bitmap is maintained as a byte array, it must be of type `uint8_t` or similar (might cause warnings).

---

    void print_bitmap(uint8_t * bitmap, uint64_t bitmap_size);

Used to print the bitmap to stdout. Each bit's value is printed.

---

    int free_bitmap(uint8_t * bitmap);

Used to free the heap memory taken up by the bitmap. This **does not** set `bitmap` to `NULL`.

---

    int clear_bit(uint8_t ** bitmap, uint64_t bitno);

Used to clear the bit at `bitno`, i.e, set it to 0. If `bitno` is larger than the bitmap's size, resulting behaviour is undefined.

---

    int set_bit(uint8_t ** bitmap, uint64_t bitno);

Used to set the bit at `bitno`, i.e, set it to 1. If `bitno` is larger than the bitmap's size, resulting behaviour is undefined.

---

    uint64_t get_first_set_bit(uint8_t * bitmap, uint64_t bitmap_size);

Used to get the first bit of `bitmap` that is set to 1.

---

    uint64_t get_first_unset_bit(uint8_t * bitmap, uint64_t bitmap_size); 

Used to get the first bit of `bitmap` that is set to 0.

---

## Primary Contributors

|   |   |
|:-:|:-:|
| <img src="https://github.com/aditisrinivas97.png" width="75"> | [Aditi Srinivas](https://github.com/aditisrinivas97) |
| <img src="https://github.com/avinashshenoy97.png" width="75"> | [Avinash Shenoy](https://github.com/avinashshenoy97) |
