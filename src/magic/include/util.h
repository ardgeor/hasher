#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stddef.h>

int to_hex(uint8_t *inputBuffer, size_t inputBufferLength, char* output);
void clear_char_array(char* arr, size_t arrLength);
void buffer_to_hex(uint8_t *buffer, size_t bufferLength, char* hex);

#endif /* UTIL_H */