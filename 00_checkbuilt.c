#include "shell.h"

/**
 * help_builtin - display info on the shell builtin commands
 */
void help_builtin(void)
{
	char *message = "help: help\n\tSee all possible Shell builtin commands.\n";

	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "\n     help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "builtin command.\n";
	write(STDOUT_FILENO, message, custom_strlen(message));
}

/**
 * display_help_exit - display info about the exit command
 */
void display_help_exit(void)
{
	char *message = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = " exit 0.\n";
	write(STDOUT_FILENO, message, custom_strlen(message));
}

/**
 * display_help_all - display info about all builtin commands
 */
void display_help_all(void)
{
	char *message = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, message, custom_strlen(message));
}

/**
 * display_help_cd - display info about the cd command
 */
void display_help_cd(void)
{
	char *message = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, message, custom_strlen(message));
	message = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "after a change of directory.\n";
	write(STDOUT_FILENO, message, custom_strlen(message));
}

/**
 * display_help_alias - display info about the alias command
 */
void display_help_alias(void)
{
	char *message = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, message, custom_strlen(message));
	message = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, message, custom_strlen(message));
}
