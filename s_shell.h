#ifndef S_SHELL
#define S_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/*Global variable*/
extern char **environ;

/*Custom Functions*/
int s_shell(void);
char **get_Command(void);
int execute_Command(char **command);
int Get_path(char **coma);
int _getEnvp(char *var);
int path_check(char **path, char *coma);


/*Print functions*/
int _putchar(char c);
void _puts(char *str);

/*String functions*/

/*1*/
int _strlen(char *str);
int str_find(char *str, char c);
int _strcnt(char *str, char *drl);
char **_strtok(char *str, char *drl);
void freeString(char **str);

/*2*/
void _strcpy(char **str1, char *str2);
int _lcp(char *str1, char *str2);
void _appendStr(char **str1, char *str2);

#endif
