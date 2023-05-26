#ifndef SHELL_H
#define SHELL_H
#define OUT 0
#define IN 1

/* --External Variables-- */
extern char **environ;
int innchld;

/* --Library Headers-- */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

/* --Address List-- */
/**
 * struct addresses - Structure of node which holds list of all addresses
 * @address: storage of address
 * @next: Pointer to the following node in list
 */
typedef struct addresses
{
	void *address;
	struct addresses *next;
} addr_t;

/* --Builtin Struct--*/
/**
 * struct builtins_s - Structure for built-in names & pointers to functions
 * @name: Name of built-in
 * @fanct: Pointer to function to call if the name is inputtted
 */
typedef struct builtins_s
{
	char *name;
	int (*fanct)();
} builtins_p;

/* --Help Struct --*/
/**
 * struct help_s - Structure for different info of built_ins
 * @name: specific built-in to get help from
 * @fanct: Pointer to function to call if the name is inputtted
 */
typedef struct help_s
{
	char *name;
	void (*fanct)();
} help_p;

/* --General Functions-- */
int wedcount(char *stri);
void loop(void);
char **mek_arrgz(char *inputt);
void output(char **arrgz);
char *tokenaiz(char *inputt, const char *delimie, char **servepotr);
void execute(char **arrgz);
int chek_argzz(char *fst_arg, char *arg0);
void siglhndler(int unsd_var);

/* --Memory Functions-- */
void *space_alloc(size_t size);
void array_free(char **array);

/* --Builtin Functions-- */
int star_printenv(char **arrgz);
int check_built_ins(char **arrgz, char *inputt);
int star_set_envir(char **arrgz);
int star_help(char **arrgz);
int star_exit(char **arrgz, char *inputt);
int star_unsatenviro(char **arrgz);

/* --Path Functions-- */
char **check_path(char **arrgz);
char *path_cnkat(char *st1, char *st2);
char *_kpypth(char *name);

/* --Env Functions-- */
int _unsatenviro(char *name);
char *_findenv(char *name);
int _addenv(char *newvar, char *name);

/* --Print Functions-- */
void _puts(char *stri);
int _putchar(char c);

/* --Help Functions-- */
void hellp_exit(void);
void hellp_env(void);
void helpp_set_envir(void);
void hellpp_unsatenviro(void);
void helped_help(void);
void print_helped(void);

/* --String Functions-- */
char *_stridpl(char *stri);
int _strilng(char *s);
char *_strchar(char *s, char c);
char *_strocbt(char *s, const char *admitt);
int _stsbpr(char *s, const char *admitt);
int _stricpr(char *st1, char *st2, int n);
char *_stri_cncat(char *st1, char *st2);
char *_strikpy(char *dst, char *src);

/* --Math Functions-- */
int _asti(char *stri);

#endif /* SHELL_H */

