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


/**
 * clear a char array
 * Note this function is INLINE, this has advantages against RE with respect to use memcpy
 * @param arr           : target array
 * @param arrLength     : length of the array
 */
void clearCharArray(char* arr, size_t arrLength) {
    for (int i = 0; i < arrLength; i++) {
        arr[i] = '\0';
    }
}


/**
 *
 * @param buffer to transform to a hex string
 * @param bufferLength
 * @param hex need to have a size of 2 * bufferLength + 1
 */
void bufferToHex(uint8_t *buffer, size_t bufferLength, char* hex) {
    clearCharArray(hex, 2*bufferLength + 1);
    toHex(buffer, bufferLength, hex);
}
