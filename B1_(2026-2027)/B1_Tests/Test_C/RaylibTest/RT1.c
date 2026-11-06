#include "raylib.h" // Inclusion de la bibliothèque Raylib.


int main(void) {   // Début de la zone main. (Point d'entrée).
  

  // ---- 1. (Configuration des variables et de la fenêtre)  ---- 

  const int screenWidth = 800;    // Fixe la largeur de la fenêtre avec une variable constante de type integer.
  const int screenHeight = 450;   // Fixe la hauteur de la fenêtre avec une variable constante de type integer.

  InitWindow(screenWidth, screenHeight, "Test Raylib"); // Initialise la fenêtre/l'écran  InitWindow(Largeur, Hauteur, "Titre de la fenêtre") avec les 2 variables précédement déclarés et définies.
  SetTargetFPS(60);   // Fixe le nombre d'images par secondes (FPS).

  Vector2 ballPosition = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f }; // Réglage de la position initiale du cercle en utilisant les 2 variables int qui permet de définir la taille de la fenêtre, dans un formule mathématique.





  // ---- 2. (Boucle Principale du jeu)  ---- 

  while (!WindowShouldClose())    // Boucle while qui s'éxécute en permanence tant que la fenêtre n'est pas en train de se fermer. (vérifie si on n'a pas appuyé sur la croix).
  {
    // ---- (Mise à jour en temps réel)  ---- 
    // Les contrôles (Déplacements du cercles avec des conditions if).

    if (IsKey)
    if ()
    if ()
    if ()
    
    

  }
}