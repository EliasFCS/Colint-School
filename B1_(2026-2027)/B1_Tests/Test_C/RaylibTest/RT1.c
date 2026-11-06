#include "raylib.h" // Inclusion de la bibliothèque Raylib.


int main(void) {   // Début de la zone main. (Point d'entrée).
  
  const int screenWidth = 800;    // Fixe la largeur de la fenêtre avec une variable constante de type integer.
  const int screenHeight = 450;   // Fixe la hauteur de la fenêtre avec une variable constante de type integer.

  InitWindow(screenWidth, screenHeight, "Test Raylib"); // Initialise la fenêtre/l'écran  InitWindow(Largeur, Hauteur, "Titre de la fenêtre") avec les 2 variables précédement déclarés et définies.
  SetTargetFPS(60);   // Fixe le nombre d'images par secondes (FPS).



}