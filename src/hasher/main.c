#include "main.h"


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
        "The hash computation relies on the generic hash functionality [1] \n"
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
 * Main function
 */
int main(int argc, char **argv) {

    prog_name = strrchr(argv[0], '/') + 1;

    // option structure
    static struct option long_options[] = {
        {"info",      no_argument,    NULL, 'i'  },
        {  NULL,                0,    NULL,  0   }
    };

    // process options
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
    
    // check number of arguments
    if (argc < 2){
        print_usage();
        exit(EXIT_FAILURE);
    }

    // call libmagic to print the hash
    char hash[HASH_SIZE * 2 + 1];
    do_hash (argv[1], hash);
}
