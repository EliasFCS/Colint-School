



/*

Submit directory: . Submit file: my_readline.c

Name
char *my_readline(int fd);
Prolog
If you already played with another higher-level programming language, you know how easy it is to read a line from a file. For example in Python, you can even iterate through the file like for line in file:.

Unfortunately for you, this project will bring you back in the 1970s (again) when no such super power was available.

Fortunately for you, you will discover the concept of global variables and gain a deeper understanding of how the heap and the stack interact with each other.

Synopsis
The function my_readline reads a line from the stream represented by fd and returns it into an allocated string (heap or stack ?). It stops when either the newline character is read or when the end-of-file is reached, whichever comes first. The newline character is not copied to the string.

On success, a pointer to the string is returned. On error, a null pointer is returned. If the end-of-file occurs before any characters have been read, the string remains unchanged.

Number of characters read will be set by the global variable READLINE_READ_SIZE. You are allowed to maximum two global variables (one for your "storage" and one for READLINE_READ_SIZE). Be ready, we will change the value of READLINE_READ_SIZE.

Requirements
Your code must be compiled with the flags -Wall -Wextra -Werror.

Technical description
In order to start reading another file you will also produce a function: void init_my_readline() which will init (or reinitialize) your global variable.

In the case of reinitialize, you will, obviously, free allocated resources. :-)

Hint(s)
💡 Your function should work with any of streams, whether it be a file, standard input or a redirection...

💡 Your function should be able to be used in a loop to read an entire file (see example)

💡 Watch out for memory leaks! You can test your code against memory errors by compiling with the debugging flags -g3 -fsanitize=address

💡 Static variables are strictly FORBIDDEN

Authorized function(s)
malloc(3)   free   read   open   close
Unauthorized function(s):

lseek, fread, fopen, and any other functions or system calls.
Multiline macros are forbidden.
Include another .c is forbidden.
Macros with logic (while/if/variables/...) are forbidden.

Example 00 (In C)
int READLINE_READ_SIZE = 512;

int main(int ac, char **av)
{
  char *str = NULL;

  int fd = open("./file.txt", O_RDONLY);
  while ((str = my_readline(fd)) != NULL)
  {
      printf("%s\n", str);
      free(str);
  }
  close(fd);
  //
  //  Yes it's also working with stdin :-)
  //  printf("%s", my_readline(0));
  //

  return 0;
}
🧪 Test ideas to consider — My Readline
Input File "one\ntwo\nthree\n", read in a loop
Expected Return "one", "two", "three", then NULL (no '\n' in the strings)
Input File "one\ntwo" (last line without newline)
Expected Return "one", "two", then NULL
💡 Classic trap: forgetting to return what remains in the storage when read() returns 0
Input Empty file
Expected Return NULL on the first call
Input File "a\n\nb\n" (empty line in the middle)
Expected Return "a", "" (empty string, not NULL), "b", then NULL
💡 An empty line must not stop the reading loop
Input READLINE_READ_SIZE = 1
Expected Return Exactly the same lines as with 512
Input READLINE_READ_SIZE = 10000 (bigger than the whole file)
Expected Return Still one line per call
💡 Several lines arrive in a single read(): the surplus must be kept in your storage for the next calls
Input A single line longer than READLINE_READ_SIZE
Expected Return The full line, in one string
Input echo "hello" | ./a.out (fd = 0)
Expected Return "hello"
Input Read half of file A, init_my_readline(), then read file B
Expected Return Only lines from B, no leftover from A, no leak
Input my_readline(-1) (invalid fd)
Expected Return NULL (no crash)
Input Compile with -g3 -fsanitize=address and read a whole file
Expected Output No memory error, no leak report

*/