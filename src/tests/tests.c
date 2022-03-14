#include "tests.h"

#define MAX_LEN 64


typedef struct test_params{ 
    char in_str[MAX_LEN]; 
    char out_hash[crypto_generichash_BYTES_MAX * 2 +1];
} test_params_s; 


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


void do_hash (char* data_to_hash, char* hashStr) {
    unsigned char hash[crypto_generichash_BYTES];
    
    
    printf("[*] hashing '%s'\n", data_to_hash);
    crypto_generichash(hash, sizeof(hash),
        data_to_hash, strlen(data_to_hash),
        NULL, 0);

    bufferToHex(hash, crypto_generichash_BYTES, hashStr);
    printf("'%s'\n", hashStr);

}

void testCase(test_params_s t){
    // printf( "in_str : %s | out_hash : %s\n", t.in_str, t.out_hash);
    char hashStr[crypto_generichash_BYTES * 2 + 1];
    do_hash(t.in_str, hashStr);
    printf( "in_str : %s | expected_hash : %s, | hash : %s\n", t.in_str, t.out_hash, hashStr);
    printf("cmp: %d\n", strncmp(t.out_hash, hashStr, crypto_generichash_BYTES) == 0);    
    assert(strncmp(t.out_hash, hashStr, crypto_generichash_BYTES) == 0);

}

int main() {     
    test_params_s TESTS[] = {
        {
            .in_str = "hello",
            .out_hash = "324dcf027dd4a30a932c441f365a25e86b173defa4b8e58948253471b81b72cf"
        },
        {
            .in_str = "this is awesome",
            .out_hash = "b7566140f51b935484f010d26a8efaee9a8103312dd41cdbf3910c679d5ede23"
        }
    }; 

    int i; 

    for( i=0; i<2; i++ ) { 
        testCase(TESTS[i]);
        // printf( "in_str : %s | out_hash : %s\n", TESTS[i].in_str, TESTS[i].out_hash); 
    } 
    return 0; 
} 