#include "main.h"
#include <util.h>


/**
 * Print usage of the program
 */
void print_usage() {
    printf("Usage:  %s [-i] <input string> \n", prog_name);
    printf("\n");
    printf("options:\n");
    printf("    -i  info\n\n");
}

/**
 * Show information related to the program
 */
void info() {
    printf("\n");
    printf("INFO\n====\n\n");
    printf(
        "This tool is a command-line program which performs a hash \n"
        "of a string given as a parameter.\n"
        "The hash relies on the generic hash functionality [1] \n"
        "provided by the libsodium library [2]."
        "\n\n"
        "[1] %s\n"
        "[2] %s\n\n",
        LIB_SODIUM_LINK,
        LIB_SODIUM_GENERIC_HASHING_LINK);
        
    printf("\n");
    print_usage();
    printf("\n");
}

/**
 * Hash string and print the output
 * @param data_to_hash is the string to be hashed
 */
void do_hash (char* data_to_hash) {
    unsigned char hash[crypto_generichash_BYTES];
    char hashStr[crypto_generichash_BYTES * 2 + 1];
    
    printf("[*] hashing '%s'\n", data_to_hash);
    crypto_generichash(hash, sizeof(hash),
        data_to_hash, strlen(data_to_hash),
        NULL, 0);

    toHex(hash, crypto_generichash_BYTES, hashStr);
    printf("'%s'\n", hashStr);

}


/**
 * Main function
 */
int main(int argc, char **argv) {

    prog_name = strrchr(argv[0], '/') + 1;

    static struct option long_options[] = {
        {"info",      no_argument,    NULL, 'i'  },
        {  NULL,                0,    NULL,  0   }
    };

    int opt = 0;
    int long_index =0;
    while ((opt = getopt_long(argc, argv,"i", 
            long_options, &long_index )) != -1) {
        switch (opt) {
            case 'i' : info();
                exit(0);
                break;            
            default: print_usage(); 
                exit(EXIT_FAILURE);
        }
    }
    
    if (argc < 2){
        print_usage();
        exit(EXIT_FAILURE);
    }

    do_hash(argv[1]);
}
