<!-- 𝓣𝓱𝓲𝓼 𝓹𝓻𝓸𝓳𝓮𝓬𝓽 𝓱𝓪𝓼 𝓫𝓮𝓮𝓷 𝓬𝓻𝓮𝓪𝓽𝓮𝓭 𝓪𝓼 𝓹𝓪𝓻𝓽 𝓸𝓯 𝓽𝓱𝓮 𝟒𝟐 𝓬𝓾𝓻𝓻𝓲𝓬𝓾𝓵𝓾𝓶 𝓫𝔂 <𝓱𝓸𝓮𝓵-𝓱𝓪𝓻>


Description :
Ce projet a pour but de reproduire le fonctionnement de la commande bash < file1 cmd1 | cmd2 > file2 En lisant depuis le fichier infile et en ecrivant dans le fichier outfil.
Dans un premier temps avec seulement deux commande puis dans un second temps n nombre de commande. 
Dans un troisieme temps nous avons aussi reproduis le fonctionnemet de la commande heredoc.

Instruction :
Pour reproduire le comportement de pipe il faut veiller a avoir au minimum un fichier dentree les deux commandes que lont veut executer et enfin le fichier de sortie ou le resultat sera affiche.
Pour bien utilise heredoc il faut preciser "here_doc" le mot que lon veut utiliser comme limiter, les deux commandes que lon veut appliquer et finir par le fichier de sortie ou le resultat sera stocke.

Ressources :
Pour ce projet je me suis aide des videos de code vault qui ma permis de comprendre de maniere globale le fonctionnemetn des differents fonctions dont jaurais besoin , jai completer les inforamation en regardant le forum internet develloppez.net qui ma permit de repoondre aux situation plus complexe et plus specifiques que je ne trouvais pas dans lqpproche generale de la premiere ressource.
 -->


*This project has been created as part of the 42 curriculum by <hoel-har>.*

## Description

Pipex is a project that aims to reproduce the behavior of the shell pipe mechanism in C. The goal is to replicate the functionality of the following shell command: < file1 cmd1 | cmd2 > file2
The program reads from an input file (`file1`), passes the output of `cmd1` as input to `cmd2` through a pipe, and writes the final result into an output file (`file2`).

As a bonus, the project also handles:
- **Multiple pipes**: chaining an arbitrary number of commands (`cmd1 | cmd2 | cmd3 ... | cmdn`).
- **Here_doc**: reproducing the behavior of the `<<` (heredoc) and `>>` (append) shell operators.

## Instructions

### Execution

**Mandatory usage (2 commands):**

./pipex file1 "cmd1" "cmd2" file2

Equivalent to: `< file1 cmd1 | cmd2 > file2`

**Examples:**

./pipex infile "ls -l" "wc -l" outfile
./pipex infile "grep a1" "wc -w" outfile

**Bonus — Multiple pipes:**

./pipex file1 "cmd1" "cmd2" "cmd3" ... "cmdn" file2

Equivalent to: `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

**Bonus — Here_doc:**

./pipex here_doc LIMITER "cmd" "cmd1" file

Equivalent to: `cmd << LIMITER | cmd1 >> file`

## Resources

- **[CodeVault — Unix Processes in C (YouTube)](https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=nLRgE17Fk33p6UJN)**: Video series that helped me understand the overall functioning of `pipe`, `fork`, `dup2`, `execve`, and other system calls used in this project.
- **[Developpez.net](https://www.developpez.net/)**: French developer forum used to find answers to more specific and complex situations not covered by the general approach of the video tutorials.