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

#define BUFFER_SIZE 1024

/**
 * struct INFO - structure of command details
 * @command_count: position of command entry
 * @command: command entered
 * @argv: name of the program
*/
struct INFO
{
	u_int64_t command_count;

	char **command;
	char **argv;
};
#define INFO_INIT { 1, NULL, NULL}




/*Global variable*/
extern char **environ;

/*Custom Functions*/
int s_shell(struct INFO info);
char **get_Command(void);
int execute_Command(struct INFO info);
int Get_path(char **coma);
int _getEnvp(char *var);
int path_check(char **path, char *coma);


/*Print functions*/
int _putchar(char c);
void _puts(char *str);
void print_int(int n);

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
int _strcomp(char *str1, char *str2);
void _reverse(char *s);



#endif
