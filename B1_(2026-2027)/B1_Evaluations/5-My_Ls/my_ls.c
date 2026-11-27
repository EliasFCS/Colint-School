#include "header.h" 

static int my_strlen(const char *str) 
{ 
    int len; 

    len = 0; 
    if (!str) 
        return 0; 
    while (str[len] != '\0') 
        len++; 
    return len; 
} 

static int my_strcmp(const char *s1, const char *s2) 
{ 
    size_t i; 

    i = 0; 
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) 
        i++; 
    return ((unsigned char)s1[i] - (unsigned char)s2[i]); 
} 

static char *my_strdup(const char *str) 
{ 
    char *dup; 
    int len; 
    int i; 

    len = my_strlen(str); 
    dup = malloc((size_t)len + 1); 
    if (!dup) 
        return NULL; 
    i = 0; 
    while (i < len) 
    { 
        dup[i] = str[i]; 
        i++; 
    } 
    dup[i] = '\0'; 
    return dup; 
}

static char *join_path(const char *dir, const char *name) 
{ 
    char *path; 
    int len_dir; 
    int len_name; 
    int need_slash; 
    int i; 
    int j; 

    len_dir = my_strlen(dir); 
    len_name = my_strlen(name); 
    need_slash = 0; 
    if (len_dir > 0 && dir[len_dir - 1] != '/') 
        need_slash = 1; 
    path = malloc((size_t)len_dir + (size_t)need_slash + (size_t)len_name + 1);
    if (!path) 
        return NULL; 
    i = 0; 
    while (i < len_dir) 
    { 
        path[i] = dir[i]; 
        i++; 
    } 
    if (need_slash) 
    { 
        path[i] = '/'; 
        i++; 
    } 
    j = 0; 
    while (j < len_name) 
    { 
        path[i] = name[j]; 
        i++; 
        j++; 
    } 
    path[i] = '\0'; 
    return path; 
} 

static int cmp_mtime_desc(time_t s1, long ns1, time_t s2, long ns2) 
{ 
    if (s1 > s2) 
        return -1; 
    if (s1 < s2) 
        return 1; 
    if (ns1 > ns2) 
        return -1; 
    if (ns1 < ns2) 
        return 1; 
    return 0; 
} 

static void sort_files(t_file *files, int count, int opt_t) 
{ 
    int i; 
    int j; 
    int cmp; 
    t_file tmp; 

    i = 0; 
    while (i < count) 
    { 
        j = 0; 
        while (j + 1 < count - i) 
        { 
            cmp = 0; 
            if (opt_t) 
            { 
                cmp = cmp_mtime_desc(files[j].sec, files[j].nsec, files[j + 1].sec, files[j + 1].nsec); 
                if (cmp == 0) 
                    cmp = my_strcmp(files[j].name, files[j + 1].name); 
            } 
            else 
                cmp = my_strcmp(files[j].name, files[j + 1].name); 
            if (cmp > 0) 
            { 
                tmp = files[j]; 
                files[j] = files[j + 1]; 
                files[j + 1] = tmp; 
            } 
            j++; 
        } 
        i++; 
    } 
} 

static void free_files(t_file *files, int count) 
{ 
    int i; 

    if (!files) 
        return; 
    i = 0; 
    while (i < count) 
    { 
        free(files[i].name); 
        i++; 
    } 
    free(files); 
} 

static int count_entries(const char *path, int opt_a) 
{ 
    DIR *dir; 
    struct dirent *entry; 
    int count; 

    dir = opendir(path); 
    if (!dir) 
        return -1; 
    count = 0; 
    entry = readdir(dir); 
    while (entry != NULL) 
    {
        if (opt_a || entry->d_name[0] != '.') 
            count++; 
        entry = readdir(dir);
    } 
    closedir(dir); 
    return count; 
} 

static void list_directory(const char *path, int opt_a, int opt_t) 
{ 
    DIR *dir; 
    struct dirent *entry; 
    struct stat st; 
    t_file *files; 
    char *full; 
    int total; 
    int i; 

    total = count_entries(path, opt_a); 
    if (total < 0) 
    { 
        printf("my_ls: cannot open directory '%s'\n", path); 
        return; 
    }
    if (total == 0) 
        return; 
    files = malloc(sizeof(t_file) * (size_t)total); 
    if (!files) 
        return; 
    dir = opendir(path); 
    if (!dir) 
    { 
        free(files); 
        return; 
    } 
    i = 0; 
    entry = readdir(dir); 
    while (entry != NULL && i < total) 
    { 
        if (opt_a || entry->d_name[0] != '.') 
        { 
            files[i].name = my_strdup(entry->d_name);
            full = join_path(path, entry->d_name);
            if (!files[i].name || !full || lstat(full, &st) != 0)
            { 
                files[i].sec = 0; 
                files[i].nsec = 0; 
            } 
            else 
            { 
                files[i].sec = st.st_mtim.tv_sec; 
                files[i].nsec = st.st_mtim.tv_nsec;
            } 
            free(full); 
            if (!files[i].name) 
            { 
                free_files(files, i); 
                closedir(dir); 
                return; 
            } 
            i++; 
        }
        entry = readdir(dir);
    } 
    closedir(dir); 
    sort_files(files, i, opt_t);
    i = 0;
    while (i < total) 
    { 
        printf("%s\n", files[i].name); 
        i++; 
    } 
    free_files(files, total);
} 

static void sort_operands(t_operand *ops, int count, int opt_t) 
{ 
    int i; 
    int j; 
    int cmp; 
    t_operand tmp; 

    i = 0; 
    while (i < count) 
    { 
        j = 0; 
        while (j + 1 < count - i)
        {
            cmp = 0;
            if (opt_t)
            {
                cmp = cmp_mtime_desc(ops[j].sec, ops[j].nsec, ops[j + 1].sec, ops[j + 1].nsec); 
                if (cmp == 0)
                    cmp = my_strcmp(ops[j].name, ops[j + 1].name);
            }
            else 
                cmp = my_strcmp(ops[j].name, ops[j + 1].name);
            if (cmp > 0)
            {
                tmp = ops[j];
                ops[j] = ops[j + 1];
                ops[j + 1] = tmp; 
            } 
            j++;
        }
        i++;
    }
}

static void parse_args(int argc, char *argv[], int *opt_a, int *opt_t, int *operand_start) 
{ 
    int i; 
    int j; 

    *opt_a = 0; 
    *opt_t = 0; 
    i = 1; 
    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0') 
    { 
        j = 1; 
        while (argv[i][j] != '\0')
        { 
            if (argv[i][j] == 'a') 
                *opt_a = 1; 
            else if (argv[i][j] == 't') 
                *opt_t = 1;
            j++; 
        } 
        i++; 
    } 
    *operand_start = i; 
} 

static void classify_operands(int argc, char *argv[], int start, t_operand *non_dirs, int *nd_cnt, t_operand *dirs, int *d_cnt)
{ 
    struct stat st; 
    int i; 

    *nd_cnt = 0; 
    *d_cnt = 0; 
    i = start; 
    while (i < argc) 
    { 
        if (lstat(argv[i], &st) == 0) 
        { 
            if (S_ISDIR(st.st_mode)) 
            { 
                dirs[*d_cnt].name = argv[i];
                dirs[*d_cnt].is_dir = 1;
                dirs[*d_cnt].sec = st.st_mtim.tv_sec; 
                dirs[*d_cnt].nsec = st.st_mtim.tv_nsec;
                (*d_cnt)++; 
            }
            else 
            { 
                non_dirs[*nd_cnt].name = argv[i]; 
                non_dirs[*nd_cnt].is_dir = 0; 
                non_dirs[*nd_cnt].sec = st.st_mtim.tv_sec; 
                non_dirs[*nd_cnt].nsec = st.st_mtim.tv_nsec; 
                (*nd_cnt)++; 
            } 
        } 
        else 
            printf("my_ls: cannot access '%s': No such file or directory\n", argv[i]); 
        i++; 
    } 
} 

void my_ls(int argc, char *argv[])
{ 
    int opt_a;
    int opt_t;
    int start;
    int op_total;
    int nd_cnt; 
    int d_cnt;
    int i;
    t_operand *non_dirs;
    t_operand *dirs;

    parse_args(argc, argv, &opt_a, &opt_t, &start);
    op_total = argc - start;
    if (op_total <= 0) 
    { 
        list_directory(".", opt_a, opt_t); 
        return; 
    } 
    non_dirs = malloc(sizeof(t_operand) * (size_t)op_total);
    dirs = malloc(sizeof(t_operand) * (size_t)op_total);
    if (!non_dirs || !dirs)
    { 
        free(non_dirs); 
        free(dirs); 
        return; 
    } 
    classify_operands(argc, argv, start, non_dirs, &nd_cnt, dirs, &d_cnt); 
    sort_operands(non_dirs, nd_cnt, opt_t); 
    sort_operands(dirs, d_cnt, opt_t); 
    i = 0; 
    while (i < nd_cnt) 
    { 
        printf("%s\n", non_dirs[i].name);
        i++; 
    } 
    i = 0; 
    while (i < d_cnt) 
    { 
        if (nd_cnt + d_cnt > 1)
            printf("%s:\n", dirs[i].name); 
        list_directory(dirs[i].name, opt_a, opt_t);
        i++;
    } 
    free(non_dirs); 
    free(dirs);
}