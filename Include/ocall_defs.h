#ifndef OCALL_DEFS_H__
#define OCALL_DEFS_H__

#include <stdio.h>
#include <string.h>
#include <jansson.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <openssl/bio.h>
#include <openssl/err.h>

size_t generate_account_number()
{
	return 1000000000 + rand() / (RAND_MAX / (2000000000 - 1000000000 + 1) + 1);
}
void print_addr(void *addr)
{
	printf("Addr: %p\n", addr);
}

void print_string(const char *func_name, char *string, char *enc_string)
{
	printf("%s reached here...\n", func_name);
	printf("%s:\t%s\n\t%s\n", func_name, string, enc_string);
}

void enclave1_print_string(char *string)
{
	printf("Enclave 1 Unsecure Print: %s\n", string);
}

void enclave2_print_string(char *string)
{
	printf("Enclave 2 Unsecure Print: %s\n", string);
}

void ocall_printf(char *str)
{
	printf("%s\n", str);
}
big_int get_random_number()
{
	return generate_account_number();
}

void print_number(const char *func_name, big_int number)
{
	printf("%s: %lld\n", func_name, number);
}
#endif