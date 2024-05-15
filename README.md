# Breakout Game

## Compilation

```bash
make
```

## Execution

```bash
bin/breakout-game
```

## Structure

### Fichiers

- `src/`: Fichiers cpp
- `include/`: Fichiers headers
- `bin/`: Fichier executable
- `level/`: Niveaux : au format ascii et en .lvl
- `assets/`: Images et polices

### Classes

- `Game`: Classe principale
- `Config`: Constantes du jeu
- `SDL_Wrapper`: Encapsulation de la SDL
- `Vector2D`: Classe pour les vecteurs utilisés pour le déplacement des objets
- `Screen`: Classe pour la gestion de l'écran : écran d'accueil, écran de sélection des niveaux, écran de jeu.
- `ScreenManager`: Gestionnaire d'écran (navigation entre les écrans)
- `Entity`: Classe mère de tous les objets du jeu : balle, raquette, brique
- `GameManager`: Gestionnaire de jeu : gestion des collisions, des déplacements
