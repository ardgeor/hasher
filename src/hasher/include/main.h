#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>

char* prog_name;

void print_usage();
void info();
void do_hash (char* data_to_hash);

#endif /* MAIN_H */