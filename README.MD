Sure! Here's a more colorful and emoji-rich README for your project:

# 🌟 Projet SAS : Gestion des Réclamations 🌟

## 🎉 Introduction

Bienvenue dans le projet **SAS : Gestion des Réclamations**! Cette application console est conçue pour faciliter la gestion des réclamations des clients. 📋💬 Vous pouvez soumettre, traiter et suivre l'état de vos réclamations tout en accédant à des statistiques précieuses sur celles-ci.

## 📖 Contexte du projet

L'application propose un menu principal permettant d'accéder à différentes fonctionnalités :

### 1. 🧑‍🤝‍🧑 Gestion des utilisateurs

- **Inscription (Sign Up)** : Créez un compte en fournissant un identifiant, un mot de passe et d'autres informations pertinentes. ✍️
  - **Contraintes de mot de passe** :
    - 🔒 Longueur minimale : 8 caractères
    - Doit contenir :
      - 🔠 Une lettre majuscule
      - 🔡 Une lettre minuscule
      - 🔢 Un chiffre
      - 🔑 Un caractère spécial (ex. : !@#$%^&*)
    - Ne doit pas contenir le nom d'utilisateur 🚫

- **Connexion (Sign In)** : Connectez-vous avec votre identifiant et mot de passe. 🔑

- **Système de verrouillage** : Verrouillage de compte après plusieurs tentatives de connexion échouées. 🚫🔒

- **Rôles des utilisateurs** :
  - **Administrateur** : Accès complet pour gérer les réclamations, les utilisateurs et générer des statistiques. 🛠️
  - **Agent de Réclamation** : Peut gérer et traiter les réclamations sans gérer les utilisateurs. 👨‍💼
  - **Client** : Soumet et consulte uniquement ses propres réclamations. 👤

### 2. 📂 Gestion des réclamations

- **Ajouter une réclamation** :
  - 📌 ID unique généré automatiquement
  - 📝 Motif
  - 🖊️ Description
  - 📊 Catégorie
  - ✅ Statut (en cours, résolu, rejeté)
  - 📅 Date de soumission (automatiquement insérée)

- **Afficher la liste des réclamations** : Accessible aux administrateurs et agents de réclamation. 📋

- **Modifier ou supprimer une réclamation** : 
  - 🔧 Les administrateurs et agents peuvent modifier ou supprimer toute réclamation.
  - 🕒 Les clients peuvent modifier ou supprimer leurs réclamations sous certaines conditions.

- **Traiter une réclamation** : 
  - 📥 Les administrateurs et agents peuvent marquer une réclamation comme "en cours", "résolue" ou "fermée".

- **Rechercher une réclamation** : 
  - 🔍 Recherche par identifiant, nom du client, date de soumission, statut ou catégorie.

- **Système de priorité** : 
  - 🚦 Attribution automatique d'une priorité basée sur des mots-clés dans la description.

- **Afficher les réclamations par priorité** : 
  - 📊 Triées par priorité pour faciliter le traitement.

### 3. 📊 Statistiques et Rapports

- **Nombre total de réclamations** : Accessible uniquement aux administrateurs. 📈

- **Taux de résolution** : Rapport sur les réclamations résolues comparé au nombre total soumis. ✅

- **Délai moyen de traitement** : Analyse du temps nécessaire pour traiter une réclamation. ⏳

- **Rapport journalier** : Génération d'un rapport texte quotidien sur les nouvelles réclamations et celles résolues. 🗓️

## 💻 Installation

Pour exécuter cette application, clonez le dépôt et utilisez l'environnement de votre choix pour compiler et exécuter le code source.

```bash
git clone https://github.com/zoubjd/Sas_Gestion_des_reclamations.git
cd Sas_Gestion_des_reclamations
# Instructions d'installation spécifiques (si nécessaire)
```

## 🚀 Utilisation

Après l'installation, exécutez l'application via votre console pour accéder au menu principal et commencer à gérer les réclamations.

!! gcc doit etre installe en avance. !!

```bash
# Commande d'exécution
gcc main.c -o manager
./manager || ./manager.exe
```

## 🤝 Contribution

Les contributions sont les bienvenues ! N'hésitez pas à soumettre un problème ou une demande de tirage. 💡

## 📄 Licence

Ce projet est realiser par Zouhair Bajdouri, sous la supervision du formateur Hamza Bouchikhi.

---

Merci d'avoir consulté le projet **SAS : Gestion des Réclamations**. Pour toute question ou suggestion, envoyer un message ou ouvrir une pull request. 💬✨