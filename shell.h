#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int roronoa;
	int franky;
    int num;
    char *str;
    struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguments to pass into a function
 * @arg: a string generated from getline containing arguments
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;

    char **cmd_buf;
    int cmd_buf_type;
    int readfd;
    int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
    char *type;
    int (*func)(info_t *);
} builtin_table;

int get_newstringlen(char *sabo);

int compare_newstrings(char *sabo1, char *sabo2);

char *new_starts_with(const char *usopp, const char *kaia);

char *new_str_concat(char *hancoc, char *chopper);
char *new_str_copy(char *hancoc, char *chopper);

char *new_str_duplicate(const char *kaido);

void print_string(char *franky);

int print_char(char keros);
int is_shell_interactive(info_t *luffy);

int is_delimiter(char sanji, char *vivi);

int is_alphabetic(int sanji);

int new_atoi(char *sabo);
char **new_string_split(char *big, char *vivi);

char **new_string_split2(char *big, char vivi);
char *new_memset(char *sabo, char robin, unsigned int shanks);

void free_strings(char **monkey);

void *new_realloc(void *koala, unsigned int dragon, unsigned int rebica);
int free_and_null(void **partholomio);
int new_atoi_error(char *sabo);

void print_error_message(info_t *luffy, char *kaido);

int print_decimal(int big, int mom);

char *convert_to_string(long int roronoa, int nico, int tetch);

void remove_comments_from_string(char *queena);
void print_string_error(char *akaino);

int print_char_error(char sanji);

int print_char_fd(char sanji, int mom);

int print_string_fd(char *akaino, int mom);
list_t *add_node_to_start(list_t **head_mackenyu, const char *akaino, int roronoa);

list_t *add_node_to_end(list_t **head_mackenyu, const char *akaino, int roronoa);

size_t print_list_strings(const list_t *dadan);

int delete_node_by_index(list_t **head_mackenyu, unsigned int roronoa);

void free_all_nodes(list_t **head_mackenyu);
size_t get_list_length(const list_t *akaino);

char **convert_list_to_strings(list_t *head_mackenyu);

size_t print_whole_list(const list_t *akaino);

list_t *get_node_starts_with(list_t *dadan, char *kizaro, char sanji);

ssize_t get_node_index_value(list_t *head_mackenyu, list_t *dadan);

#endif

