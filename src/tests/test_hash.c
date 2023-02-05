#include "test_hash.h"

#define MAX_INPUT_LEN 64

/** 
 * Test case structure
 */
typedef struct test_params{ 
    char in_str[MAX_INPUT_LEN]; 
    char out_hash[crypto_generichash_BYTES_MAX * 2 + 1];
} test_params_s; 


/** 
 * Execute test case
 */
void test_case(test_params_s t){        
    char hash_str[crypto_generichash_BYTES * 2 + 1];
    do_hash(t.in_str, hash_str);        
    assert(strncmp(t.out_hash, hash_str, crypto_generichash_BYTES * 2 + 1) == 0);    
}


/** 
 * Main function
 */
int main(void) {     
    // define tests cases
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

    // execute test cases
    for( i=0; i<2; i++ ) { 
        test_case(TESTS[i]);        
    } 
    return 0; 
} 