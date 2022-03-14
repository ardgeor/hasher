#include <util.h>


/**
 * Produce a string with the hexadecimal representation of a buffer
 * @param inputBuffer       : buffer at the input
 * @param inputBufferLength : buffer length
 * @param output            : string at the output
 * @return
 */
int toHex(uint8_t *inputBuffer, size_t inputBufferLength, char* output) {
    char hexDigits[] = {'0', '1', '2', '3',
                        '4', '5', '6', '7',
                        '8', '9', 'a', 'b',
                        'c', 'd', 'e', 'f'};
    uint8_t num;

    for(int i = 0; i < inputBufferLength; i++) {
        num = inputBuffer[i];
        output[2 * i] = hexDigits[num >> 4];
        output[2 * i + 1] = hexDigits[num & 0xF];
    }
    return 0;
}


