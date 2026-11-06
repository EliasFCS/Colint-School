#include "raylib.h" // Inclusion de la bibliothèque Raylib.


int main(void) {   // Début de la zone main. (Point d'entrée).
  

  // ---- 1. (Configuration des variables et de la fenêtre)  ---- 

  const int screenWidth = 800;    // Fixe la largeur de la fenêtre avec une variable constante de type integer.
  const int screenHeight = 450;   // Fixe la hauteur de la fenêtre avec une variable constante de type integer.

  InitWindow(screenWidth, screenHeight, "Test Raylib"); // Initialise la fenêtre/l'écran  InitWindow(Largeur, Hauteur, "Titre de la fenêtre") avec les 2 variables précédement déclarés et définies.
  SetTargetFPS(60);   // Fixe le nombre d'images par secondes (FPS).

  Vector2 ballPosition = { (float)screenWidth / 2.0f, (float)screenHeight / 2.0f }; // Réglage de la position initiale du cercle en utilisant les 2 variables int qui permet de définir la taille de la fenêtre, dans un formule mathématique.Définition de la variable ballPosition en type vector2. (ballPosition.x et ballPosition.y inclus automatiquement).





  // ---- 2. (Boucle Principale du jeu)  ---- 

  while (!WindowShouldClose())    // Boucle while qui s'éxécute en permanence tant que la fenêtre n'est pas en train de se fermer. (vérifie si on n'a pas appuyé sur la croix).
  {  // Début de la Boucle de jeu while.

    // ---- (Mise à jour en temps réel)  ---- 
    // Les contrôles (Déplacements du cercles avec des conditions if).

    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 4.0f;   // Vérifie si la flêche de droite est préssée ou maintenue enfoncé pour déplacer la boule à 4,0 vers la droite en augmentant la variable vector 2: "ballPosition.x".
    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 4.0f;   // Vérifie si la flêche de gauche est préssée ou maintenue enfoncé pour déplacer la boule à 4,0 vers la gauche en diminuant la variable vector 2: "ballPosition.x".
    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 4.0f;   // Vérifie si la flêche du bas est préssée ou maintenue enfoncé pour déplacer la boule à 4,0 vers le bas en diminuant la variable vector 2: "ballPosition.y".
    if (IsKeyDown(KEY_UP)) ballPosition.y -= 4.0F;   // Vérifie si la flêche du haut est préssée ou maintenue enfoncé pour déplacer la boule à 4,0 vers le haut en augmentant la variable vector 2: "ballPosition.y".


    // ---- (Dessin)  ----
    // Gère l'aspect visuel.
    
    BeginDrawing(); // Début zone de dessin.
      ClearBackground(RAYWHITE);    // Met la couleur de l'arrière plan en Blanc. 
      DrawText("Utilisez les flêches du clavier pour bouger le cercle !", 190, 40, 20, DARKGRAY);   // Affiche un texte en gris sombre (DARKGRAW) à des coordonnées définits.
      DrawCircleV(ballPosition, 50.0f, RED);   // Dessine le cercle rouge au centre qu'on va contrôler avec les touches qu'on a configuré precédement.
    
    EndDrawing(); // Fin zone de dessin.

  }   // Fin de la boucle de jeu while.

  // ---- 3. (Fermeture de la fenêtre et nettoyage)  ----
  CloseWindow();  // Ferme la fenêtre

  return 0;   // Permet d'empêcher des érreurs.

}  // Fin de la zone main.