#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void my_ls(int argc , char **argv)
{
  
}

int main(int argc, char **argv)
{
  my_ls(argc, argv);
  return 0;
}













/*

Submit directory: . Submit file: Makefile - *.c - *.h my_ls.c

Specifications
Write a programm called my_ls. Following the specifications of this man page.

Name
my_ls -- list directory contents

Synopsis
my_ls [-at] [file ...]

Description
For each operand that names a file of a type other than directory, my_ls displays its name as well as any requested, associated information. For each operand that names a file of type directory, my_ls displays the names of files contained within that directory, as well as any requested, associated information.

If no operands are given, the contents of the current directory are displayed. If more than one operand is given, non-directory operands are displayed first; directory and non-directory operands are sorted separately and in lexicographical order.

The following options are available:

        
-a Include directory entries whose names begin with a dot (.).
-t Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
        
Requirements
Your code must be compiled with the flags -Wall -Wextra -Werror.

Hint(s)
Watch out for memory leaks ! You can test your code against memory errors by compiling with the debugging flags -g3 -fsanitize=address Global variables are strictly FORBIDDEN tv_sec AND tv_nsec are used for the -t options ;-) st_mtime is not what you want to use. You want to use st_mtim

Technical information
you must create a Makefile, and the ouput is the command itself You can use:

malloc(3) free(3) printf(3) write(2) stat(2) lstat(2) opendir(2) closedir(2) readdir(2)

You can NOT use:

Any functions / syscalls which does not appear in the previous list Yes, it includes exit Multiline macros are forbidden Include another .c is forbidden Macros with logic (while/if/variables/...) are forbidden

Your output needs to be respecting the "sorting" criteria and in one column. It will be compared with: ls -1.

        
$>./my_ls > my_ls.output
$>ls -1 > ls.output
$>diff my_ls.output ls.output
$>
        
Tips
Check /dev What is the difference between stat and lstat?

//////////////
Les étapes clés pour coder ft_ls

1. Lecture des répertoires (opendir, readdir, closedir)
	• Tu dois parcourir un ou plusieurs dossiers passés en arguments (ou le répertoire courant "." par défaut).
	• Utiliser opendir() pour ouvrir le flux du répertoire, readdir() pour lire chaque entrée (struct dirent), puis closedir() à la fin. [1] (https://forum.hardware.fr/hfr/Programmation/C/coder-commande-sujet_138194_1.htm)
2. Récupération des métadonnées (stat, lstat)
	• Pour obtenir les permissions, la taille, le propriétaire, le groupe ou les dates, il faut appeler stat() ou lstat() (attention à bien utiliser lstat pour les liens symboliques afin de ne pas suivre la cible).
	• Gérer les erreurs (par exemple si un fichier ou dossier passé en paramètre n'existe pas ou n'est pas accessible, comme sur le Forum Hardware). [1] (https://www.developpez.net/forums/d5318/c-cpp/c/reprogrammer-commande-ls-partir-fonction-stat/), [2] (https://forum.hardware.fr/hfr/Programmation/C/coder-commande-sujet_138194_1.htm)
3. Gestion des options principales
	• Les options les plus courantes à implémenter sont souvent mtacnet/ft_ls: Projet 42 - Langage C - Commande ls - GitHub :
		• -a : Afficher les fichiers cachés (ceux commençant par un point .).
		• -l : Format long (permissions, nombre de liens, utilisateur, groupe, taille, date de modification, nom).
		• -R : Récursivité (parcourir les sous-répertoires).
		• -r : Inverser l'ordre du tri.
		• -t : Trier par date de modification (st_mtime) plutôt que par ordre alphabétique. [1] (http://debian-facile.org/doc:systeme:ls), [2] (https://blog.lesjeudis.com/commandes-linux-de-base), [3] (https://github.com/mtacnet/ft_ls)
4. Tri et stockage des données
	• Avant d'afficher, les entrées lues doivent être stockées (souvent dans une liste chaînée ou un tableau) puis triées selon le nom ou le timestamp. Discussions sur la méthode de tri sur OpenClassrooms. [1] (https://openclassrooms.com/forum/sujet/recoder-ls-l-comment-ordonner-l-affichage), [2] (https://github.com/mtacnet/ft_ls)


*/