#include "test_hash.h"

#define MAX_LEN 64


typedef struct test_params{ 
    char in_str[MAX_LEN]; 
    char out_hash[crypto_generichash_BYTES_MAX * 2 +1];
} test_params_s; 


void test_case(test_params_s t){    
    char hash_str[crypto_generichash_BYTES * 2 + 1];
    do_hash(t.in_str, hash_str);
    printf( "in_str : %s | expected_hash : %s, | hash : %s\n", t.in_str, t.out_hash, hash_str);
    printf("cmp: %d\n", strncmp(t.out_hash, hash_str, crypto_generichash_BYTES) == 0);    
    assert(strncmp(t.out_hash, hash_str, crypto_generichash_BYTES) == 0);

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
        test_case(TESTS[i]);        
    } 
    return 0; 
} 