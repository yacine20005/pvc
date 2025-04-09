# Objectif principal

Créer un programme en C nommé pvc qui résout le problème du voyageur de commerce en utilisant une approche basée sur la programmation génétique.

## Étapes principales

1. Analyse et préparation

- [x] Lire et comprendre la spécification du problème.
- [x] Étudier les concepts de programmation génétique.
- [x] Définir les structures de données nécessaires (représentation des villes, cartes, solutions, etc.).
- [x] Identifier les modules nécessaires pour le projet.

## Modules à implémenter

### Lecture et gestion des données

- [x] Module de lecture de fichier :
  - Lire un fichier texte contenant les villes et leurs coordonnées.
  - Valider le format des données.
  - Stocker les données dans une structure adaptée.
- [x] Module de gestion des villes :
  - Représenter une ville (nom, coordonnées).
  - Représenter une carte (ensemble de villes).

### Calculs et algorithmes

- [ ] Module de calcul des distances :
  - Calculer la distance entre deux villes.
  - Calculer la longueur totale d'un chemin donné.
- [ ] Module de génération initiale :
  - Générer une population initiale de solutions (chemins aléatoires).
- [ ] Module de sélection :
  - Implémenter une méthode de sélection (par exemple, roulette ou tournoi).
- [ ] Module de croisement (crossover) :
  - Implémenter un opérateur de croisement pour combiner deux solutions.
- [ ] Module de mutation :
  - Implémenter un opérateur de mutation pour modifier une solution.
- [ ] Module d'évaluation :
  - Évaluer la qualité (fitness) d'une solution (longueur du chemin).

### Gestion du processus génétique

- [ ] Module de gestion des générations :
  - Implémenter la boucle principale de l'algorithme génétique.
  - Gérer la convergence (critères d'arrêt).
- [ ] Module de sauvegarde des résultats :
  - Sauvegarder la meilleure solution trouvée dans un fichier.

### Tests et validation

- [ ] Module de tests unitaires :
  - Tester chaque module individuellement.
- [ ] Module de tests d'intégration :
  - Vérifier le bon fonctionnement global du programme.

## Documentation

- [ ] Rédiger une documentation utilisateur pour expliquer comment utiliser le programme pvc.
- [ ] Documenter le code avec des commentaires clairs.
- [ ] Ajouter des pré-assertions et des fonctions de gestion d'erreurs.

## Déploiement

- [ ] Compiler le programme avec gcc et vérifier l'absence d'erreurs.
- [ ] Créer un script Makefile pour automatiser la compilation.
- [ ] Tester le programme avec plusieurs fichiers d'entrée.

## Améliorations potentielles

- [ ] Ajouter des visualisations (par exemple, tracer les chemins sur un plan).
- [ ] Optimiser les performances (parallélisation, optimisation des algorithmes).
- [ ] Permettre des formats d'entrée/sortie supplémentaires.

## Priorités

1. Lecture des données et gestion des villes.
2. Implémentation des calculs de distances et des algorithmes génétiques.
3. Tests unitaires et validation.
4. Documentation et déploiement.

## Suivi des tâches

- [ ] Initialisation du projet.
- [ ] Implémentation des modules prioritaires.
- [ ] Tests et corrections.
- [ ] Finalisation et livraison.
