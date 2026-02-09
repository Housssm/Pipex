/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/09 12:32:59 by hoel-har         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* int	acces(const char *pathname, int mode)
{
	//CHeck if the program can acces the file pathname

	// specifies the accessibility checks to be performed
	//F_OK WR/W/X_OK pour les autorisations
	// Tout est OK ---->  returned
	// ERROR --> nib 1 bit returned
	// ERROR --> -1 
}

int	dup2(int oldfd, int newfd)
{
	//newfd is a copy of oldfd ---> make the copy

	//oldfd valid fd + newfd == oldfd return newfd
	//oldfd not valid fd calls fails and newfd NOT CLOSED
	// Error --> return -1

	//Attention share file offset and file status flags, if onee of them is modified by lseek() the offset also changed for the ohter
}

int pipe(int pipefd[2])
{
	//The array pipefd is used to return two file descriptors referring to the ends of the pipe. 
	

	//succes --> 0
	// Error --> -1 and errno set appropriatly
}

pid_t	fork(void)
{
	//create a new process by duplicating the calling process

	// child == parents except for some point becareful to check th exeptions
}

pid_t	waitpid(pid_t pid, int *status, int options)
{
	//call suspends executioin of the calling process until a child SPECIFIED by pid argument has changed state
	//basically wait oonly for terminated children 
}

pid_twait(int *status)
{
	// like waitpid but untils ONE of its children
}

int	execve(const char *filename, char *const argv[], char *const envp[])
{
	// calling process is replaced by the executed filename
	//All OK ? --> no return 
}

int	unlink(const char *pathname)
{
	//delete name from file systeme
	// last link and no process have the fil open ? ---> file deleted and space available to reuse
	// last link BUT any process still have the file open ---> file remain in existance unti the last fil descripto refering to it is closed

	// success = 0, 
	//Error = -1 and errno set appropriately
} */

#include <unistd.h>
#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>

char	*extract_args(int ac, char **av)
{
	char	*arg;
	int		i;
	size_t	len;
	
	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		i++;	
	}
	arg = malloc(sizeof(char) * (len + 1 + ac));
	if (!arg)
		return NULL;
	arg[0] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strlcat(arg, av[i], len + 1);
		ft_strlcat(arg, "|", len + 1);
		i++;
	}
	return (arg);
}



int	main(int ac, char **av)
{
	char *arg;
	char **input;
	
	if (ac < 5)
		return (1);
	arg = extract_args(ac, av);
	input = ft_split(arg, '|');
	free(arg);
	free_split(input);
		return 0;
}
	// int	id;
	// int	fd[2];
	// if ( pipe(fd) == -1)
	// {
	// 	printf("Erreur openniung the pipe");
	// 	return (1);
	// }
    // id = fork();
	// if (id == -1)
	// return (1); // erreur fork
	// if (id == 0)
	// {
	// 	close (fd[0]);
	// 	// write(fd[1], ); ecrire dans fd1 la valeur de la deuxieme commande 
	// 	close (fd[1]);
	// }
	// else
	// {
	// 	close (fd[1]);
	// 	// write(1,) ecrire sur la sortie stantard le resultat de premiere commande
	// 	close (fd[0]);
	// }
