CC = gcc # Définition du compilateur C utilisé.
NAME = my_ls # Nom du programme exécutable demandé dans les consignes.
CFLAGS = -Wall -Wextra -Werror -D_DEFAULT_SOURCE # Options de compilation strictes + _DEFAULT_SOURCE pour st_mtim.
SRCS = main.c my_ls.c # Liste des fichiers sources C à compiler.
OBJS = $(SRCS:.c=.o) # Liste des fichiers objets (.o) générés à partir des fichiers .c.


# Règle principale qui déclenche la compilation de l'exécutable.
all: $(NAME)

# Règle d'édition de liens pour produire l'exécutable final.
$(NAME):$(OBJS)
	$(CC)$(CFLAGS) $(OBJS) -o$(NAME) 
# Lie les fichiers .o en my_ls.

# Règle générique pour compiler chaque .c en .o si header.h change.
%.o: %.c header.h
	$(CC)$(CFLAGS) -c $< -o$@ 
# Compile un fichier source en fichier objet.

# Règle pour supprimer les fichiers objets intermédiaires.
clean:
	rm -f $(OBJS) 
# Supprime tous les fichiers .o.

# Règle pour supprimer les fichiers objets et l'exécutable.
fclean: clean
	rm -f $(NAME) 
# Supprime l'exécutable my_ls.

# Règle pour recompiler entièrement le projet de zéro.
re: fclean all

# Déclare les cibles qui ne sont pas des noms de fichiers réels.
.PHONY: all clean fclean re