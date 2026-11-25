#include "header.h" // Inclut header.h et les types/prototypes nécessaires.

static int my_strlen(const char *str) // Calcule la longueur d'une chaîne.
{ // Début de my_strlen.
    int len; // Compteur de caractères.

    len = 0; // Initialise la longueur à 0.
    if (!str) // Vérifie si le pointeur est NULL.
        return 0; // Retourne 0 si la chaîne est NULL.
    while (str[len] != '\0') // Parcourt jusqu'au caractère nul de fin.
        len++; // Incrémente le compteur.
    return len; // Retourne la longueur trouvée.
} // Fin de my_strlen.

static int my_strcmp(const char *s1, const char *s2) // Compare deux chaînes ASCII.
{ // Début de my_strcmp.
    size_t i; // Index de parcours des chaînes.

    i = 0; // Initialise l'index à 0.
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) // Avance tant qu'ils sont égaux.
        i++; // Passe au caractère suivant.
    return ((unsigned char)s1[i] - (unsigned char)s2[i]); // Retourne la différence non signée.
} // Fin de my_strcmp.

static char *my_strdup(const char *str) // Alloue et copie une chaîne de caractères.
{ // Début de my_strdup.
    char *dup; // Pointeur vers la nouvelle chaîne allouée.
    int len; // Longueur de la chaîne source.
    int i; // Index de copie.

    len = my_strlen(str); // Calcule la longueur de str.
    dup = malloc((size_t)len + 1); // Alloue la mémoire incluant '\0'.
    if (!dup) // Vérifie l'échec d'allocation mémoire.
        return NULL; // Retourne NULL si malloc échoue.
    i = 0; // Initialise l'index à 0.
    while (i < len) // Copie chaque caractère de str.
    { // Début de la boucle de copie.
        dup[i] = str[i]; // Copie le caractère courant.
        i++; // Passe au caractère suivant.
    } // Fin de la boucle de copie.
    dup[i] = '\0'; // Ajoute le terminateur nul.
    return dup; // Retourne la chaîne dupliquée.
} // Fin de my_strdup.

static char *join_path(const char *dir, const char *name) // Concatène un dossier et un nom.
{ // Début de join_path.
    char *path; // Chaîne résultante du chemin complet.
    int len_dir; // Longueur du chemin du dossier.
    int len_name; // Longueur du nom de l'entrée.
    int need_slash; // Indique s'il faut insérer un '/'.
    int i; // Index de parcours dans path.
    int j; // Index de parcours dans name.

    len_dir = my_strlen(dir); // Calcule la longueur de dir.
    len_name = my_strlen(name); // Calcule la longueur de name.
    need_slash = 0; // Initialise l'absence de slash supplémentaire.
    if (len_dir > 0 && dir[len_dir - 1] != '/') // Vérifie si dir ne finit pas déjà par '/'.
        need_slash = 1; // Active l'ajout d'un séparateur '/'.
    path = malloc((size_t)len_dir + (size_t)need_slash + (size_t)len_name + 1); // Alloue le chemin.
    if (!path) // Vérifie l'échec de malloc.
        return NULL; // Retourne NULL en cas d'échec.
    i = 0; // Initialise l'index d'écriture.
    while (i < len_dir) // Copie le chemin du répertoire.
    { // Début de la copie de dir.
        path[i] = dir[i]; // Copie le caractère de dir.
        i++; // Avance dans path.
    } // Fin de la copie de dir.
    if (need_slash) // Ajoute '/' si nécessaire.
    { // Début de l'ajout de '/'.
        path[i] = '/'; // Insère le séparateur de chemin.
        i++; // Avance dans path.
    } // Fin de l'ajout de '/'.
    j = 0; // Initialise l'index de name.
    while (j < len_name) // Copie le nom du fichier/dossier.
    { // Début de la copie de name.
        path[i] = name[j]; // Copie le caractère de name.
        i++; // Avance dans path.
        j++; // Avance dans name.
    } // Fin de la copie de name.
    path[i] = '\0'; // Termine la chaîne par '\0'.
    return path; // Retourne le chemin complet.
} // Fin de join_path.

static int cmp_mtime_desc(time_t s1, long ns1, time_t s2, long ns2) // Compare deux dates (récent d'abord).
{ // Début de cmp_mtime_desc.
    if (s1 > s2) // Si le premier est plus récent en secondes.
        return -1; // Place le premier avant le second.
    if (s1 < s2) // Si le premier est plus ancien en secondes.
        return 1; // Place le premier après le second.
    if (ns1 > ns2) // Si égalité en secondes, compare les nanosecondes.
        return -1; // Place le plus récent en nanosecondes avant.
    if (ns1 < ns2) // Si le premier a moins de nanosecondes.
        return 1; // Place le premier après le second.
    return 0; // Dates strictement identiques.
} // Fin de cmp_mtime_desc.

static void sort_files(t_file *files, int count, int opt_t) // Trie un tableau de t_file.
{ // Début de sort_files.
    int i; // Compteur de passe du tri à bulles.
    int j; // Index de comparaison adjacente.
    int cmp; // Résultat de comparaison entre deux éléments.
    t_file tmp; // Variable temporaire pour l'échange.

    i = 0; // Initialise la passe à 0.
    while (i < count) // Répète jusqu'à count passes.
    { // Début de la boucle externe.
        j = 0; // Initialise l'index interne à 0.
        while (j + 1 < count - i) // Compare les paires non encore triées.
        { // Début de la boucle interne.
            cmp = 0; // Réinitialise le résultat de comparaison.
            if (opt_t) // Si l'option -t est active.
            { // Début du tri par date.
                cmp = cmp_mtime_desc(files[j].sec, files[j].nsec, files[j + 1].sec, files[j + 1].nsec); // Compare les dates.
                if (cmp == 0) // En cas d'égalité de date.
                    cmp = my_strcmp(files[j].name, files[j + 1].name); // Départage par ordre lexicographique.
            } // Fin du tri par date.
            else // Sans l'option -t.
                cmp = my_strcmp(files[j].name, files[j + 1].name); // Compare par ordre lexicographique.
            if (cmp > 0) // Si files[j] doit venir après files[j + 1].
            { // Début de l'échange.
                tmp = files[j]; // Sauvegarde files[j].
                files[j] = files[j + 1]; // Déplace files[j + 1] en position j.
                files[j + 1] = tmp; // Place l'ancien files[j] en position j + 1.
            } // Fin de l'échange.
            j++; // Passe à la paire suivante.
        } // Fin de la boucle interne.
        i++; // Passe à la passe suivante.
    } // Fin de la boucle externe.
} // Fin de sort_files.

static void free_files(t_file *files, int count) // Libère les noms et le tableau t_file.
{ // Début de free_files.
    int i; // Index de parcours.

    if (!files) // Si le pointeur est déjà NULL.
        return; // Ne fait rien.
    i = 0; // Initialise l'index à 0.
    while (i < count) // Parcourt les éléments alloués.
    { // Début de la boucle de libération.
        free(files[i].name); // Libère le nom dupliqué.
        i++; // Passe à l'élément suivant.
    } // Fin de la boucle de libération.
    free(files); // Libère le tableau lui-même.
} // Fin de free_files.

static int count_entries(const char *path, int opt_a) // Compte les entrées à afficher dans un dossier.
{ // Début de count_entries.
    DIR *dir; // Flux du répertoire ouvert.
    struct dirent *entry; // Entrée courante lue par readdir.
    int count; // Nombre d'entrées retenues.

    dir = opendir(path); // Ouvre le répertoire path.
    if (!dir) // Vérifie si opendir a échoué.
        return -1; // Retourne -1 en cas d'erreur d'ouverture.
    count = 0; // Initialise le compteur à 0.
    entry = readdir(dir); // Lit la première entrée.
    while (entry != NULL) // Boucle tant qu'il reste des entrées.
    { // Début de la boucle de comptage.
        if (opt_a || entry->d_name[0] != '.') // Inclut tout si -a, sinon exclut les noms commençant par '.'.
            count++; // Incrémente le nombre d'entrées.
        entry = readdir(dir); // Lit l'entrée suivante.
    } // Fin de la boucle de comptage.
    closedir(dir); // Ferme le descripteur de répertoire.
    return count; // Retourne le nombre total d'entrées.
} // Fin de count_entries.

static void list_directory(const char *path, int opt_a, int opt_t) // Liste et affiche un répertoire.
{ // Début de list_directory.
    DIR *dir; // Flux du répertoire.
    struct dirent *entry; // Entrée courante.
    struct stat st; // Métadonnées récupérées via lstat.
    t_file *files; // Tableau dynamique des entrées.
    char *full; // Chemin complet de l'entrée courante.
    int total; // Nombre d'entrées attendues.
    int i; // Index de remplissage et d'affichage.

    total = count_entries(path, opt_a); // Compte les entrées à traiter.
    if (total < 0) // Si le répertoire n'a pas pu être ouvert.
    { // Début du traitement d'erreur.
        printf("my_ls: cannot open directory '%s'\n", path); // Affiche un message d'erreur.
        return; // Quitte la fonction.
    } // Fin du traitement d'erreur.
    if (total == 0) // Si aucune entrée n'est à afficher.
        return; // Retourne immédiatement sans allouer inutilement.
    files = malloc(sizeof(t_file) * (size_t)total); // Alloue le tableau de structures t_file.
    if (!files) // Vérifie si malloc a échoué.
        return; // Quitte si la mémoire est insuffisante.
    dir = opendir(path); // Rouvre le répertoire pour lire les entrées.
    if (!dir) // Vérifie si la réouverture échoue.
    { // Début de gestion d'erreur de réouverture.
        free(files); // Libère le tableau alloué.
        return; // Quitte la fonction.
    } // Fin de gestion d'erreur de réouverture.
    i = 0; // Initialise l'index à 0.
    entry = readdir(dir); // Lit la première entrée.
    while (entry != NULL && i < total) // Parcourt les entrées dans la limite de total.
    { // Début de lecture des entrées.
        if (opt_a || entry->d_name[0] != '.') // Filtre les fichiers cachés si opt_a vaut 0.
        { // Début du traitement d'une entrée retenue.
            files[i].name = my_strdup(entry->d_name); // Duplique le nom de l'entrée.
            full = join_path(path, entry->d_name); // Construit le chemin complet.
            if (!files[i].name || !full || lstat(full, &st) != 0) // Vérifie allocations et lstat.
            { // Début du repli en cas d'erreur sur l'entrée.
                files[i].sec = 0; // Valeur par défaut des secondes.
                files[i].nsec = 0; // Valeur par défaut des nanosecondes.
            } // Fin du repli.
            else // Si lstat a réussi.
            { // Début de lecture des timestamps.
                files[i].sec = st.st_mtim.tv_sec; // Enregistre les secondes de modification.
                files[i].nsec = st.st_mtim.tv_nsec; // Enregistre les nanosecondes de modification.
            } // Fin de lecture des timestamps.
            free(full); // Libère le chemin temporaire full.
            if (!files[i].name) // Si la duplication du nom a échoué.
            { // Début d'arrêt sur échec mémoire.
                free_files(files, i); // Libère les éléments déjà créés.
                closedir(dir); // Ferme le répertoire.
                return; // Quitte la fonction.
            } // Fin d'arrêt sur échec mémoire.
            i++; // Passe à l'entrée suivante.
        } // Fin du traitement d'une entrée retenue.
        entry = readdir(dir); // Lit l'entrée suivante.
    } // Fin de lecture des entrées.
    closedir(dir); // Ferme le répertoire.
    sort_files(files, i, opt_t); // Trie les entrées selon -t et l'ordre lexicographique.
    i = 0; // Réinitialise l'index pour l'affichage.
    while (i < total) // Affiche chaque nom sur une seule colonne (comme ls -1).
    { // Début de la boucle d'affichage.
        printf("%s\n", files[i].name); // Affiche le nom suivi d'un saut de ligne.
        i++; // Passe à l'entrée suivante.
    } // Fin de la boucle d'affichage.
    free_files(files, total); // Libère toute la mémoire allouée pour files.
} // Fin de list_directory.

static void sort_operands(t_operand *ops, int count, int opt_t) // Trie les opérandes CLI.
{ // Début de sort_operands.
    int i; // Compteur de passe.
    int j; // Index de comparaison.
    int cmp; // Résultat de comparaison.
    t_operand tmp; // Variable temporaire d'échange.

    i = 0; // Initialise i à 0.
    while (i < count) // Boucle externe de tri.
    { // Début de la boucle externe.
        j = 0; // Initialise j à 0.
        while (j + 1 < count - i) // Compare les éléments adjacents.
        { // Début de la boucle interne.
            cmp = 0; // Réinitialise cmp.
            if (opt_t) // Si -t est actif.
            { // Début du tri chronologique des opérandes.
                cmp = cmp_mtime_desc(ops[j].sec, ops[j].nsec, ops[j + 1].sec, ops[j + 1].nsec); // Compare les dates.
                if (cmp == 0) // En cas d'égalité de date.
                    cmp = my_strcmp(ops[j].name, ops[j + 1].name); // Départage lexicographiquement.
            } // Fin du tri chronologique.
            else // Sans l'option -t.
                cmp = my_strcmp(ops[j].name, ops[j + 1].name); // Trie lexicographiquement.
            if (cmp > 0) // Si l'ordre doit être inversé.
            { // Début de l'échange.
                tmp = ops[j]; // Sauvegarde ops[j].
                ops[j] = ops[j + 1]; // Déplace ops[j + 1].
                ops[j + 1] = tmp; // Place l'ancien ops[j].
            } // Fin de l'échange.
            j++; // Passe à l'élément suivant.
        } // Fin de la boucle interne.
        i++; // Passe à la passe suivante.
    } // Fin de la boucle externe.
} // Fin de sort_operands.

static void parse_args(int argc, char *argv[], int *opt_a, int *opt_t, int *operand_start) // Analyse les options.
{ // Début de parse_args.
    int i; // Index d'argument.
    int j; // Index de caractère d'option.

    *opt_a = 0; // Initialise -a à faux.
    *opt_t = 0; // Initialise -t à faux.
    i = 1; // Commence après argv[0] (le nom du programme).
    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0') // Parcourt les arguments d'options.
    { // Début de la boucle d'options.
        j = 1; // Commence après le tiret '-'.
        while (argv[i][j] != '\0') // Parcourt chaque lettre de l'option groupée (ex: -at).
        { // Début de la boucle sur les caractères.
            if (argv[i][j] == 'a') // Détecte l'option 'a'.
                *opt_a = 1; // Active l'option -a.
            else if (argv[i][j] == 't') // Détecte l'option 't'.
                *opt_t = 1; // Active l'option -t.
            j++; // Passe au caractère suivant.
        } // Fin de la boucle sur les caractères.
        i++; // Passe à l'argument suivant.
    } // Fin de la boucle d'options.
    *operand_start = i; // Enregistre l'index du premier opérande fichier/dossier.
} // Fin de parse_args.

static void classify_operands(int argc, char *argv[], int start, t_operand *non_dirs, int *nd_cnt, t_operand *dirs, int *d_cnt) // Classe fichiers et dossiers.
{ // Début de classify_operands.
    struct stat st; // Structure pour récupérer les infos du fichier.
    int i; // Index de parcours des opérandes.

    *nd_cnt = 0; // Initialise le compteur de non-répertoires.
    *d_cnt = 0; // Initialise le compteur de répertoires.
    i = start; // Démarre au premier opérande après les options.
    while (i < argc) // Parcourt tous les opérandes fournis.
    { // Début de la boucle sur les opérandes.
        if (lstat(argv[i], &st) == 0) // Récupère les informations de l'opérande.
        { // Début si lstat réussit.
            if (S_ISDIR(st.st_mode)) // Vérifie si c'est un répertoire.
            { // Début branche répertoire.
                dirs[*d_cnt].name = argv[i]; // Stocke le nom du répertoire.
                dirs[*d_cnt].is_dir = 1; // Marque is_dir à 1.
                dirs[*d_cnt].sec = st.st_mtim.tv_sec; // Stocke les secondes de modification.
                dirs[*d_cnt].nsec = st.st_mtim.tv_nsec; // Stocke les nanosecondes de modification.
                (*d_cnt)++; // Incrémente le compteur de répertoires.
            } // Fin branche répertoire.
            else // Sinon, c'est un fichier non-répertoire.
            { // Début branche non-répertoire.
                non_dirs[*nd_cnt].name = argv[i]; // Stocke le nom du fichier.
                non_dirs[*nd_cnt].is_dir = 0; // Marque is_dir à 0.
                non_dirs[*nd_cnt].sec = st.st_mtim.tv_sec; // Stocke les secondes de modification.
                non_dirs[*nd_cnt].nsec = st.st_mtim.tv_nsec; // Stocke les nanosecondes de modification.
                (*nd_cnt)++; // Incrémente le compteur de non-répertoires.
            } // Fin branche non-répertoire.
        } // Fin si lstat réussit.
        else // Si l'opérande n'existe pas ou est inaccessible.
            printf("my_ls: cannot access '%s': No such file or directory\n", argv[i]); // Affiche l'erreur.
        i++; // Passe à l'opérande suivant.
    } // Fin de la boucle sur les opérandes.
} // Fin de classify_operands.

void my_ls(int argc, char *argv[]) // Fonction principale orchestrant my_ls.
{ // Début de my_ls.
    int opt_a; // Flag pour l'option -a.
    int opt_t; // Flag pour l'option -t.
    int start; // Index du premier opérande.
    int op_total; // Nombre total d'opérandes valides.
    int nd_cnt; // Nombre d'opérandes non-répertoires.
    int d_cnt; // Nombre d'opérandes répertoires.
    int i; // Index de boucle.
    t_operand *non_dirs; // Tableau des fichiers non-répertoires.
    t_operand *dirs; // Tableau des répertoires.

    parse_args(argc, argv, &opt_a, &opt_t, &start); // Analyse les options et trouve le début des opérandes.
    op_total = argc - start; // Calcule le nombre d'arguments restants après les options.
    if (op_total <= 0) // S'il n'y a aucun opérande (ex: ./my_ls ou ./my_ls -at).
    { // Début cas sans opérande.
        list_directory(".", opt_a, opt_t); // Affiche le contenu du répertoire courant ".".
        return; // Termine my_ls.
    } // Fin cas sans opérande.
    non_dirs = malloc(sizeof(t_operand) * (size_t)op_total); // Alloue le tableau des non-répertoires.
    dirs = malloc(sizeof(t_operand) * (size_t)op_total); // Alloue le tableau des répertoires.
    if (!non_dirs || !dirs) // Vérifie l'échec d'allocation.
    { // Début gestion d'erreur malloc.
        free(non_dirs); // Libère non_dirs si alloué.
        free(dirs); // Libère dirs si alloué.
        return; // Quitte la fonction.
    } // Fin gestion d'erreur malloc.
    classify_operands(argc, argv, start, non_dirs, &nd_cnt, dirs, &d_cnt); // Sépare fichiers et dossiers.
    sort_operands(non_dirs, nd_cnt, opt_t); // Trie séparément les opérandes non-répertoires.
    sort_operands(dirs, d_cnt, opt_t); // Trie séparément les opérandes répertoires.
    i = 0; // Initialise l'index à 0.
    while (i < nd_cnt) // Affiche d'abord tous les opérandes non-répertoires.
    { // Début affichage non-répertoires.
        printf("%s\n", non_dirs[i].name); // Affiche le nom sur une ligne.
        i++; // Passe au suivant.
    } // Fin affichage non-répertoires.
    i = 0; // Réinitialise l'index à 0.
    while (i < d_cnt) // Affiche ensuite le contenu de chaque répertoire.
    { // Début affichage répertoires.
        if (nd_cnt + d_cnt > 1) // Affiche l'en-tête "nom:" s'il y a plusieurs opérandes.
            printf("%s:\n", dirs[i].name); // Affiche le nom du répertoire suivi de ':'.
        list_directory(dirs[i].name, opt_a, opt_t); // Liste le contenu du répertoire.
        i++; // Passe au répertoire suivant.
    } // Fin affichage répertoires.
    free(non_dirs); // Libère le tableau non_dirs.
    free(dirs); // Libère le tableau dirs.
} // Fin de my_ls.