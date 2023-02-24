#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
void execute_cmd(char **argv);
char *get_path(char *comm);
void builtin_env(void);
char *search_in_path(char *path, char *comm);
void parse_input(char *input, char ***args, int *num_args);
void run_shell(void);
int main(int ac, char **argv);
int _strlen(char *s);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
char *my_strdup(char *str);
char *_getenv(char *name);
int _strncmp(const char *s1, const char *s2, size_t n);
size_t _sizeof(const void *ptr);

#endif/*_MAIN_H*/
