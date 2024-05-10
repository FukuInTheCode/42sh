<img width="550" src="https://drive.google.com/uc?export=view&id=1Enwe0OW9wRdDQNePTdth3RHlzxgeDwnQ">


# 42sh
> Life, the universe, and especially the rest
 

## Documentation en français

### L'origine du projet 42sh :
Le 42sh est un projet d'études de fin de première année à **EPITECH**. Ce projet conclut une matière consacrée à la recréation d'un *Shell Unix*. <br>
Avant de faire ce projet, chaque membre de l'équipe a dû faire deux projets préliminaires qui sont le minishell1 et le minishell2. Ces projets initient à des principes fondamentaux pour créer un interpréteur de commandes et donc pour faire le 42sh. <br>

### Qu'est-ce qu'un Shell Unix ?
Un Shell Unix est un interpréteur de commandes destiné aux systèmes d'exploitation Unix et de type Unix qui permet d'accéder aux fonctionnalités internes du système d'exploitation. Il se présente sous la forme d'une interface en ligne de commande accessible depuis la console ou un terminal.
<div align="center">

<img width="550" src="https://drive.google.com/uc?export=view&id=19UqBuRf1DsLYB_LfDLTlobtPLCw37ofo">

</div>
    <br>
<h5> Et le TCSH ?</h5>
tcsh est un interpréteur de commandes (shell) pour les systèmes UNIX, similaire à bash (Bourne-Again Shell) ou zsh. Son nom complet est "Tenex C Shell". Il a été développé à l'origine par Ken Greer à l'Université de Californie à Berkeley dans les années 1970.

### Quel sont les objectifs du 42sh ?

Le but du 42sh est de recréer un Shell avec le tcsh pour référence, et d'y ajouter le maximum de fonctionalités possible. Pour cela, le groupe reprend les bases du minishell1 et du minishell2 pour faire le 42sh.

### L'équipe de ce 42sh :
L'équipe ayant travaillé sur ce projet est composé de ***Martin Bonte***, ***Yanis Monte***, ***Antoine Orange***, ***Tom Carlier*** et ***Emma Farineaux***, tous étudiants d'**Epitech Lille** (promo 2028).


### L'installation de ce programme :
Ce programme est destiné aux systèmes UNIX. <br>
Il suffit de cloner le dépositoire (ou répositoire) avec la commande suivante : <br>
`git clone git@github.com:Antoiix/42sh-mirror.git`

## Comment cela fonctionne ?

### Executer une commande système

Dans les systèmes Unix, il existe une multitude de commandes qui permettent de naviguer, modifier ou agir sur la machine. Cependant, nous n'avons bien évidemment pas recodé l'intégralité de ces commandes. C'est pour cela qu'on execute directement les commandes présentes dans le système.

# Guide d'utilisation des commandes shell dans tcsh

Ce document fournit un guide pratique pour utiliser les commandes shell sur tcsh, un shell Unix en ligne de commande. Les commandes mentionnées ci-dessous sont utiles pour naviguer dans le système de fichiers, manipuler des fichiers et des répertoires, ainsi que pour effectuer des tâches courantes en ligne de commande.

## Navigation dans le système de fichiers

### Afficher le répertoire courant
Pour afficher le répertoire courant, utilisez la commande :
```shell
pwd
```
Exemple de sortie :
```
/home/utilisateur
```

### Listage des fichiers et répertoires
Pour lister les fichiers et répertoires dans le répertoire courant, utilisez :
```shell
ls
```
Exemple de sortie :
```
fichier1.txt   fichier2.txt   repertoire1   repertoire2
```

Pour lister les fichiers avec plus de détails, utilisez :
```shell
ls -l
```
Exemple de sortie détaillée :
```
-rw-r--r-- 1 utilisateur users 1024 mai  10 10:00 fichier1.txt
-rw-r--r-- 1 utilisateur users 4096 mai  10 11:00 fichier2.txt
drwxr-xr-x 2 utilisateur users 4096 mai  10 09:00 repertoire1
drwxr-xr-x 2 utilisateur users 4096 mai  10 10:30 repertoire2
```

Pour afficher tous les fichiers, y compris ceux dont le nom commence par un point (fichiers cachés), utilisez :
```shell
ls -a
```
Exemple de sortie avec fichiers cachés :
```
.  ..  fichier1.txt  fichier2.txt  .cache  .bashrc
```

## Manipulation des fichiers et des répertoires

### Créer un répertoire
Pour créer un nouveau répertoire, utilisez la commande suivante en remplaçant `<nom-du-répertoire>` par le nom désiré :
```shell
mkdir nouveau_repertoire
```
Exemple de sortie : (pas de sortie en cas de succès)

### Changer de répertoire
Pour naviguer vers un autre répertoire, utilisez la commande `cd` suivie du chemin du répertoire souhaité :
```shell
cd chemin/vers/le/répertoire
```


### Copier des fichiers
Pour copier un fichier vers un autre emplacement, utilisez la commande `cp` avec le nom du fichier source et le chemin de destination :
```shell
cp fichier1.txt repertoire1/
```

### Supprimer des fichiers ou des répertoires
Pour supprimer un fichier, utilisez la commande `rm` suivie du nom du fichier :
```shell
rm fichier1.txt
```

Pour supprimer un répertoire et son contenu, utilisez la commande `rm` avec l'option `-r` :
```shell
rm -r repertoire2
```

## Commandes intégrées et variables

### Variables d'environnement
Pour afficher toutes les variables d'environnement :
```shell
env
```
Exemple de sortie :
```
HOME=/home/utilisateur
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
LANG=en_US.UTF-8
```

### Définir une variable d'environnement
Pour définir une variable d'environnement, utilisez `setenv` :
```shell
setenv NOM_VARIABLE valeur
```

### Supprimer une variable d'environnement
Pour supprimer une variable d'environnement, utilisez `unsetenv` :
```shell
unsetenv NOM_VARIABLE
```

### Afficher l'emplacement d'une commande
Pour savoir où se trouve une commande dans votre système, utilisez `where` :
```
where ls
```
Exemple de sortie :
```
/bin/ls
```

### Trouver le chemin complet d'une commande
Pour afficher le chemin complet d'une commande, utilisez `which` :
```shell
which ls
```
Exemple de sortie :
```
/bin/ls
```

### Répéter une commande
Pour répéter une commande précédente, utilisez `repeat` suivi du nombre de répétitions et de la commande :
```shell
repeat 5 ls
```
Exemple de sortie :
```
fichier1.txt   fichier2.txt   repertoire1   repertoire2
fichier1.txt   fichier2.txt   repertoire1   repertoire2
fichier1.txt   fichier2.txt   repertoire1   repertoire2
fichier1.txt   fichier2.txt   repertoire1   repertoire2
fichier1.txt   fichier2.txt   repertoire1   repertoire2
```

## Variables et historique

### Variables utilisateur
Pour définir une variable utilisateur, utilisez simplement le nom de la variable suivie de sa valeur :
```shell
NOM_VARIABLE=valeur
```

### Historique des commandes
Pour afficher l'historique des commandes précédemment exécutées, utilisez :
```shell
history
```
Exemple de sortie :
```
  1  ls
  2  cd repertoire1
  3  cp fichier1.txt fichier2.txt
  4  rm fichier1.txt
  5  env
  6  history
```


## Séparateurs de redirection

Les séparateurs de redirection sont des caractères spéciaux utilisés pour rediriger l'entrée/sortie standard d'une commande vers/despuis un fichier ou pour connecter la sortie d'une commande à l'entrée d'une autre.

### Redirection de la sortie (`>`)
Le séparateur `>` est utilisé pour rediriger la sortie standard d'une commande vers un fichier. Si le fichier spécifié n'existe pas, il est créé ; sinon, son contenu est écrasé. Par exemple :
```shell
commande > fichier_sortie.txt
```
Cela exécute `commande` et écrit la sortie dans `fichier_sortie.txt`.

### Redirection de la sortie en mode ajout (`>>`)
Le séparateur `>>` est similaire à `>`, mais au lieu d'écraser le contenu du fichier, il ajoute la sortie à la fin du fichier existant ou le crée s'il n'existe pas. Par exemple :
```shell
commande >> fichier_sortie.txt
```
Cela ajoute la sortie de `commande` à la fin de `fichier_sortie.txt`.

### Redirection de l'entrée (`<`)
Le séparateur `<` est utilisé pour rediriger l'entrée standard d'une commande depuis un fichier. Par exemple :
```shell
commande < fichier_entree.txt
```
Cela exécute `commande` en utilisant le contenu de `fichier_entree.txt` comme entrée.

### Pipe (`|`)
Le symbole `|` (pipe) est utilisé pour connecter la sortie d'une commande à l'entrée d'une autre commande. Cela permet de créer des pipelines où le résultat de la première commande devient l'entrée de la seconde. Par exemple :
```shell
commande1 | commande2
```
Cela exécute `commande1` et utilise sa sortie comme entrée pour `commande2`.

### Exemple combiné
Vous pouvez combiner plusieurs séparateurs de redirection pour des opérations plus complexes. Par exemple, pour exécuter `commande1` avec `fichier_entree.txt` comme entrée et écrire la sortie dans `fichier_sortie.txt`, vous pouvez faire :
```shell
commande1 < fichier_entree.txt > fichier_sortie.txt
```
Cela utilise `fichier_entree.txt` comme entrée pour `commande1` et écrit la sortie de `commande1` dans `fichier_sortie.txt`.
