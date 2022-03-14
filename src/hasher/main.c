#include "main.h"


void print_usage() {
    printf("Usage:  %s [-i] <input string> \n", prog_name);
    printf("\n");
    printf("options:\n");
    printf("    -i  info\n\n");
}

void info() {    
    printf("Info\n");    
}

void do_hash (char* data_to_hash) {
    printf("Do hash for %s\n", data_to_hash);    
}

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
