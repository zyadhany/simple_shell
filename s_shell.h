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

/**
 * struct List - linked list of 2 strings
 * @str: first string
 * @str2: second string
 * @next: pointer to the next node
*/
typedef struct List
{
	char *str;
	char *str2;
	struct List *next;
} list_t;


/**
 * struct function - structure of a function pointer
 * @name: function name
 * @func: pointer to function with void argument
*/
struct function
{
	char *name;
	int (*func)(void);
};


/**
 * struct INFO - structure of command details.
 * @command_count: position of command entry
 * @STD: stdout or stderr
 * @status: a
 * @argc: a
 * @argv: name of the program.
 * @parent_dir: a
 * @input: a
 * @command: command entered.
 * @commands_To_run:  a
 * @enviroment_changed: a
 * @environ: a
 * @buffer_index: a
 * @buffer: a
 * @functions: a
 * @envp: a
 * @alias: a
 * @exit: a
*/
struct INFO
{
	u_int64_t command_count;
	int status;
	int STD;

	int argc;
	char **argv;

	char *parent_dir;

	char *input;
	char **command;
	char ***commands_To_run;

	int enviroment_changed;
	char **environ;

	int buffer_index;
	char *buffer;

	struct function functions[7];

	list_t *envp;
	list_t *alias;

	int exit;
};


/*Custom Functions*/
int s_shell(void);
int execute_Command(void);
int Get_path(char **coma);
int path_check(char **path, char *coma);

/* Geting Command Functions*/
int get_input(void);
int check_comments(char **str);
int break_command(void);
int **get_Command(void);

/*Shell Functions*/
/*1*/
int set_info(void);
int set_fuction(void);
int set_buffer(void);
void command_error(char *error_massage[]);
void FreeInfo(void);
/*2*/
int _getcwd(char **str);
int _cd(void);
int Buff_Flush(void);
void _exitS(void);
int _exitShell(void);
/*3*/
void cd_error_massage(void);

/* enviroment functions */
/*1*/
int set_envp(void);
int _setenv(char *var, char *value);
int _Mysetenv(void);
int _unsetenv(char *var);
int _Myunsetenv(void);
/*2*/
char **get_environ(void);
char *env_val(char *str);
int _getEnvp(char *var);
int _envp(void);
/*3*/
char *get_env_val(char *var);
int _strcnt_env(char *str);
char **_strtok_env(char *str);
int separate_to_enviroment(char ***args, char *str);
int replace_to_env(char **str);

/*alias Functions*/
void put_alias(list_t *alias_element);
int print_alias(void);
int alias_read(char *var);
int alias_write(char *elem);
int alias_shell(void);

/*Print functions*/
int _putchar(char c);
void _puts(char *str);
void print_int(int n);
int _getline(char **lineptr, int *len, int fd);

/* List Functions */
/*1*/
size_t print_list(const list_t *lis);
size_t list_len(const list_t *lis);
list_t *add_node(list_t **lis, char *str);
int delete_node_at_index(list_t **lis, int k);
void free_list(list_t *lis);
/*2*/
char **list_to_strings(list_t *lis);
list_t *add_node2(list_t **lis, char *str1, char *str2);
list_t *get_node_elem(list_t *lis, char *str);
int get_node_index(list_t *lis, char *str);
char *get_node(list_t *lis, int k);

/* Int Functons */
int _isInt(char *s);
char *int_to_string(int n);
u_int64_t _stoi(char *s);

/*String Functions*/
/*1*/
int _strlen(char *str);
int str_find(char *str, char c);
int _strcnt(char *str, char *drl);
char **_strtok(char *str, char *drl);
void freeString(char **str);
/*2*/
int _strcpy(char **str1, char *str2);
int _lcp(char *str1, char *str2);
void _appendStr(char **str1, char *str2);
int _strcomp(char *str1, char *str2);
void _reverse(char *s);
/*3*/
int _sstrlen(char **str);
char *_strSuffix(char *str, int index);
int _strassemb(char **str, char **s);
void free_2d_String(char ***str);


#endif
