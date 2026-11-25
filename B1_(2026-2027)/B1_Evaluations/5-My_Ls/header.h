#ifndef HEADER_H // Empêche la double inclusion de header.h.
#define HEADER_H // Définit la macro de garde d'inclusion.

#ifndef _DEFAULT_SOURCE // Vérifie si _DEFAULT_SOURCE n'est pas déjà défini.
#define _DEFAULT_SOURCE // Active les extensions POSIX/BSD dont st_mtim.
#endif // Fin de la condition #ifndef _DEFAULT_SOURCE.

#include <dirent.h> // Fournit opendir, readdir, closedir et struct dirent.
#include <stdio.h> // Fournit printf pour l'affichage.
#include <stdlib.h> // Fournit malloc, free et NULL.
#include <sys/stat.h> // Fournit stat, lstat, struct stat et S_ISDIR.
#include <sys/types.h> // Fournit les types système standards (time_t, etc.).
#include <time.h> // Fournit les types liés au temps.

typedef struct s_file // Début de la structure représentant une entrée de dossier.
{ // Ouverture du bloc de la structure s_file.
    char *name; // Nom de l'entrée du répertoire.
    time_t sec; // Secondes du timestamp de modification (st_mtim.tv_sec).
    long nsec; // Nanosecondes du timestamp de modification (st_mtim.tv_nsec).
} t_file; // Alias de type t_file pour struct s_file.

typedef struct s_operand // Début de la structure représentant un opérande CLI.
{ // Ouverture du bloc de la structure s_operand.
    char *name; // Chaîne passée en argument sur la ligne de commande.
    int is_dir; // Vaut 1 si l'opérande est un répertoire, 0 sinon.
    time_t sec; // Secondes du timestamp de modification.
    long nsec; // Nanosecondes du timestamp de modification.
} t_operand; // Alias de type t_operand pour struct s_operand.

void my_ls(int argc, char *argv[]); // Prototype de la fonction principale my_ls.

#endif // Fin de la garde d'inclusion HEADER_H.