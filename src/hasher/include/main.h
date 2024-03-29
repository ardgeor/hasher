#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <magic.h>

char const * LIB_SODIUM_LINK = "https://github.com/jedisct1/libsodium"; 
char const * LIB_SODIUM_GENERIC_HASHING_LINK = "https://download.libsodium.org/doc/hashing/generic_hashing"; 
char* prog_name;

void print_usage();
void info();

#endif /* MAIN_H */