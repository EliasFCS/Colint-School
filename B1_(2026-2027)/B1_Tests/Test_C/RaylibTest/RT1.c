#include "raylib.h" // Inclusion de la bibliothèque Raylib.


int main(void) {   // Début de la zone main. (Point d'entrée).
  
  const int screenWidth = 800;    // Fixe la largeur de la fenêtre avec une variable constante de type integer.
  const int screenHeight = 450;   // Fixe la hauteur de la fenêtre avec une variable constante de type integer.

  InitWindow(screenWidth, screenHeight, "Test Raylib"); // Initialise la fenêtre/l'écran  InitWindow(Largeur, Hauteur, "Titre de la fenêtre") avec les 2 variables précédement déclarés et définies.
  SetTargetFPS(60);   // Fixe le nombre d'images par secondes (FPS).

  Vector2 ballPosition = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f }; // Réglage de la position initiale du cercle en utilisant les 2 variables int qui permet de définir la taille de la fenêtre, dans un formule mathématique.

  
}