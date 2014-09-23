#ifndef BITSTREAM_H
#define BITSTREAM_H

void bitstream_init(
    char *b,
    unsigned int size);

/**
 * Write out byte value to bitstream. Increment b by 1 */
void bitstream_write_byte(
    char **b,
    char value);

/**
 * Write out uint32 value to bitstream. Increment b by 4 */
void bitstream_write_uint32(
    char **b,
    uint32_t value);

/**
 * Write out bit value to bitstream.
 * Only increment b by 1 when bit_pos will be 8
 * @param bit_pos Current bit offset within bitstream */
void bitstream_write_bit_from_bitoffset(
    char **b,
    const uint32_t val,
    unsigned int* bit_pos
);

/**
 * Write out up to 32bits to bitstream.
 * Increment b according to bit_pos
 *
 * @param val value to be written
 * @param nbits number of bits to be written 
 * @param bit_pos Current bit offset within bitstream */
void bitstream_write_uint32_from_bitoffset(
    char **b,
    const uint32_t val,
    const unsigned int nbits,
    unsigned int* bit_pos);

/**
 * Write out string to bitstream. Increment b by length of string
 * @param string The string to be written
 * @param len Length of string */
void bitstream_write_string(
    char **b,
    const char* string,
    unsigned int len);

/**
 * Read uint32 from bitstream.
 * Increment b by 4 
 * @param bit_pos Current bit offset within bitstream */
void bitstream_read_uint32_from_bitoffset(
    char **b,
    uint32_t * val,
    const unsigned int nbits,
    unsigned int* bit_pos);

/**
 * Read one bit from bitstream.
 * Only increment b by 1 when bit_pos will be 8
 * @param bit_pos Current bit offset within bitstream
 * @return bit's value */
int bitstream_read_bit(
    char **b,
    unsigned int* bit_pos);

/**
 * Read string from bitstream.
 * Increment by len
 * @param bit_pos Current bit offset within bitstream */
void bitstream_read_string(
    char **b,
    char* out_string,
    unsigned int len);

/**
 * Read byte from bitstream
 * Increment b by 1
 * @param byte value */
char bitstream_read_byte(
    char **b);

/**
 * Read uint32 from bitstream.
 * Increment by 4 bytes
 * @return value of uint32 */
uint32_t bitstream_read_uint32(
    char **b);

void bitstream_write_byte_from_bitoffset(
    char **b,
    char value,
    unsigned int* bit_pos);

#endif /* BITSTREAM_H */
