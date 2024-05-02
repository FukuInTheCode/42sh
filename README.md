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

Dans les systèmes Unix, il existe une multitude de commandes qui permettent de naviguer, modifier ou agir sur la machine. Cependant, nous n'avons bien évidemment pas recodé l'intégralité de ces commandes. C'est pour cela qu'on execute directement les commandes présentes dans le système. <br>
Pour cela, nous utilisons les fonctions suivantes : 

`fork` : 

`execve` : 