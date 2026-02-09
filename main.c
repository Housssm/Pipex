/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/09 19:16:13 by hoel-har         ###   ########.fr       */
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

void	free_struct(t_data *data)
{
	free_split(data->env);
	free_split(data->args);
	free_split(data->env);
	free(data->path);
}
int	check_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if(ft_strncmp(data->env[i], "PATH=", 5) == 0)
		{
			data->path = ft_strdup(data->env[i]); // Ajouter la verification de la validite du path
			return (0);
		}
		i++;
	}
	return (1);	
}

int	struct_attribution(char **av, char**env, t_data *data)
{
	(void)av;
	data->env = env;
	if (!data->env)
		return (ft_putstr_fd("Error copy env\n", 1),free_split(data->env), 1);
	data->args = av;
	if (!data->args)
		return (ft_putstr_fd("Error copy args\n", 1),free_split(data->args), 1);
	data->cmd = NULL;
	if (check_path(data))
		return (free_struct(data),1);
	data->in_fd = open(av[1], O_RDONLY);
	if (data->in_fd < 0)
		return (1);
	return (0);
}


int	first_cmd(t_data *data)
{
	
	// dup2(data->in_fd, data->pip[1]);
	// {		
	// 	printf("TETET\n");

	// 	if(check_path(data))
	// 		return(1);
	// }
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	(void)av;
	if (ac < 5 || !env)
		return (1);
	if (struct_attribution(av, env, &data))
		return 1;
	first_cmd(&data);


	
}




/* 
utiliser excecve pour appliquer la commande 
trouver le path en utilisant env,
securiser le chemin avec equivalent de whereis "X"
"envie -i" enelve lenvie il faut proteger 
dup2 pour dupliquer sortie et entree
test avec sleep5
gerer la creation du fichier de sortie
 */
