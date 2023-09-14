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

/*Global variables*/
extern char **environ;
extern struct INFO info;
#define PROMPT "s_shell$ "
#define MODE 10000000000
#define BUFFER_SIZE 1024


typedef struct List
{
	char *str;
	struct List *next;
} list_t;


struct function
{
	char *name;
	int (*func)(void);
};


/**
 * struct INFO - structure of command details.
 * @command_count: position of command entry.
 * @command: command entered.
 * @argv: name of the program.
*/
struct INFO
{
	u_int64_t command_count;
	int status;

	int argc;
	char **argv;
	char **command;

	int buffer_index;
	char *buffer;

	struct function functions[6];

	list_t *envp;

	int exit;
};
#define INFO_INIT { 1, 0, 0, NULL, NULL, 0, NULL, {{NULL, NULL}}, NULL, 0}



/*Custom Functions*/
int s_shell(void);
char **get_Command(void);
int execute_Command(void);
int Get_path(char **coma);
int path_check(char **path, char *coma);

/*Shell Functions*/
/*1*/
int set_info(void);
int set_fuction(void);
int set_buffer(void);
void command_error(char *error_massage[]);
void FreeInfo(void);
/*2*/
int _cd(void);
int Buff_Flush(void);
void _exitS(void);
int _exitShell(void);

/* enviroment functions */
/*1*/
int set_envp(void);
int _setenv(char *var, char *value);
int _Mysetenv(void);
int _unsetenv(char *var);
int _Myunsetenv(void);
/*2*/
int _getEnvp(char *var);
int _envp(void);

/*Print functions*/
int _putchar(char c);
void _puts(char *str);
void print_int(int n);
int _getline(char **lineptr, int *len, int fd);

/* List Functions */
/*1*/
size_t print_list(const list_t *lis);
size_t list_len(const list_t *lis);
list_t *add_node(list_t **lis, char *s);
int delete_node_at_index(list_t **lis, int k);
void free_list(list_t *lis);
/*2*/
char *get_node(list_t *lis, int k);

/* Int Functons */
int _isInt(char *s);
u_int64_t _stoi(char *s);

/*String Functions*/
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
/*3*/
int _sstrlen(char **str);


#endif
