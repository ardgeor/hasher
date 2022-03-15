#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stddef.h>

int toHex(uint8_t *inputBuffer, size_t inputBufferLength, char* output);
void clearCharArray(char* arr, size_t arrLength);
void bufferToHex(uint8_t *buffer, size_t bufferLength, char* hex);

#endif /* UTIL_H */