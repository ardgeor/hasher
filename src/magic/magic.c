#include "magic.h"


/**
 * Hash string and print the output
 * @param data_to_hash is the string to be hashed
 * @param hash_str is the buffer where to store the resulting hex string
 * size of hash_str must be (2 * size of data_to_hash + 1)
 */
void do_hash (char* data_to_hash, char* hash_str) {
    unsigned char hash[crypto_generichash_BYTES];
    
    printf("[*] hashing '%s'\n", data_to_hash);
    crypto_generichash(hash, sizeof(hash),
        (const unsigned char*) data_to_hash, strlen(data_to_hash),
        NULL, 0);

    bufferToHex(hash, crypto_generichash_BYTES, hash_str);
    printf("'%s'\n", hash_str);
}


