<p align="center">
  <img 
    src="https://github.com/JorisLne/42-project-badges/blob/main/covers/cover-push_swap-bonus.png?raw=true" 
    alt="Bannière push swap" 
    width="80%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-brightgreen?style=flat-square" alt="Score du projet 125/100" />
  <img src="https://img.shields.io/badge/Langage-C-blue.svg?style=flat-square&logo=c" alt="Langage C" />
</p>

<p align="center">
  <img src="https://github.com/JorisLne/42-project-badges/blob/main/badges/push_swapm.png?raw=true" alt="Badge push swap">
</p>

</p>

# 🌀 push_swap

## 🧩 Objectif

> Trier la pile `a` en ordre croissant en déplaçant des éléments vers/depuis une pile auxiliaire `b`, en utilisant les instructions autorisées.
---

### 📚 Structure de Données : Liste doublement chaînée

Chaque pile (`a`, `b`) est représentée par une **liste doublement chaînée circulaire**, permettant un accès rapide à la tête, la fin, et facilitant les rotations.

```text
    a: [ 3 ] <-> [ 2 ] <-> [ 1 ]
```

---

### 🔄 Logique du Tri

- **Cas simples (2 ou 3 éléments)** : tri direct par permutations (`sa`, `ra`, `rra`)
- **Cas complexes (≥ 4 éléments)** :
  - Transfert des éléments vers la pile `b`
  - Calcul de **l’élément cible** et du **coût d’opération**
  - Sélection du **cheapest node** à déplacer (calcul de coût)
  - Application d’une stratégie de rotation synchronisée ou alternée
  - Remontée des éléments dans `a` pour finaliser le tri

---

## 🔧 Instructions disponibles

| Instruction | Effet sur les piles         |
|-------------|-----------------------------|
| `sa` / `sb` | Swap des deux premiers éléments |
| `pa` / `pb` | Push entre les piles          |
| `ra` / `rb` | Rotation vers le haut         |
| `rra` / `rrb` | Rotation vers le bas         |
| `ss` / `rr` / `rrr` | Doubles opérations |

---

## 📦 Compilation

```bash
make        # Compile
make clean  # Supprime les .o
make fclean # Supprime les .o et l’exécutable
make re     # Recompile tout
```

---

## 🚀 Utilisation

```bash
./push_swap 3 2 1
```

Exemple :

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

---

## 🧪 Validation

Utiliser `checker_OS` :

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker_OS $ARG
OK
```
- **Optimisation** : minimiser les coûts de mouvement
- **Heuristiques** : choix du chemin le plus court
- **Stratégies de tri** : adaptation au contexte (taille, ordre)

---
