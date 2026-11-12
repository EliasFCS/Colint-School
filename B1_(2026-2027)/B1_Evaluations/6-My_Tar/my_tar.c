











/*

Submit directory: . Submit files: Makefile - *.c - *.h

Command Name
my_tar

Description
my_tar is a command to manipulate tape archive. The first option to tar is a mode indicator from the following list:

Option	Mode
-c	Create a new archive containing the specified items.
-r	Like -c, but new entries are appended to the archive. The -f option is required.
-t	List archive contents to stdout.
-u	Like -r, but new entries are added only if they have a modification date newer than the corresponding entry in the archive. The -f option is required.
-x	Extract to disk from the archive. If a file with the same name appears more than once in the archive, each copy will be extracted, with later copies overwriting (replacing) earlier copies.
In -c, -r, or -u mode, each specified file or directory is added to the archive in the order specified on the command line. By default, the contents of each directory are also archived.

Unless specifically stated otherwise, options are applicable in all operating modes:

-f file  Read the archive from or write the archive to the specified file.
         The filename can be standard input or standard output.
my_tar will not handle file inside subdirectory.

Exit Status
The tar utility returns 0 on success, and >0 if an error occurs.

Hint(s)
💡 Tip: GNU tar — Basic Tar Format

Technical information
You must create a Makefile, and the output is the command itself.

You can use (the number is the man page):

chmod       close(2)    free(3)     fstat(2)
getpwuid    getgrgid    getxattr    listxattr
lseek(2)    major       malloc(3)   minor
mkdir(2)    open(2)     opendir     read(2)
readdir     readlink    stat(2)     lstat(2)
symlink     unlink(2)   time        ctime
utime       write(2)
No other functions or system calls are allowed.

Global variables are strictly FORBIDDEN.

Example
The following creates a new archive called file.tar that contains two files source.c and source.h:

$> ./my_tar -cf file.tar source.c source.h
To view a detailed table of contents for this archive:

$> ./my_tar -tf file.tar
source.c
source.h
Errors handling
Errors will be written on STDERR.

Case	Message
File not found (provided file is: i_don_t_exist)	my_tar: i_don_t_exist: Cannot stat: No such file or directory
Error with the tarball file (provided file is: tarball.tar)	my_tar: Cannot open tarball.tar
🧪 Test ideas to consider — My Tar
Input ./my_tar -cf file.tar source.c source.h
Expected Output file.tar created, nothing printed, exit status 0
Input ./my_tar -tf file.tar
Expected Output
source.c
source.h
Input tar -tf file.tar (the real tar reading YOUR archive)
Expected Output Same listing, no warning
💡 Best compatibility check: 512-byte headers, correct checksum, and two empty 512-byte blocks at the end of the archive
Input ./my_tar -cf file.tar i_don_t_exist
Expected Output my_tar: i_don_t_exist: Cannot stat: No such file or directory (on STDERR, exit > 0)
Input ./my_tar -tf tarball.tar (archive does not exist)
Expected Output my_tar: Cannot open tarball.tar (on STDERR, exit > 0)
Input ./my_tar -rf file.tar other.c then ./my_tar -tf file.tar
Expected Output source.c, source.h, other.c (appended at the end)
💡 Appending means overwriting the two end-of-archive empty blocks, not writing after them
Input ./my_tar -uf file.tar source.c (source.c not modified)
Expected Output No new entry. After touch source.c, the same command adds a new entry
Input ./my_tar -xf file.tar (in an empty directory)
Expected Output Files restored, identical content (check with diff) and same permissions
💡 If a name appears twice in the archive, the last copy must win
Input ./my_tar -r source.c (without -f)
Expected Output Error on STDERR, exit > 0 (-f is required for -r and -u)

*/