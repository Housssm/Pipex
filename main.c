/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoel-har <hoel-har@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:36:10 by marvin            #+#    #+#             */
/*   Updated: 2026/02/11 12:55:09 by hoel-har         ###   ########.fr       */
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
#include <sys/wait.h>

void	free_struct(t_data *data)
{
	// free_split(data->env);
	// free_split(data->args);
	free(data->path);
	free_split(data->cmd1);
	free_split(data->cmd2);
}
char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*result;
	int		i;
	int		j;
	int		size;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + ft_strlen((char *)s3);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0 ;
	j = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	j = 0;
	while (s3[j])
		result[i++] = s3[j++];
	result[i] = '\0';
	return (result);
}

int	extract_path(t_data *data, char **full_path)
{
	int		i;
	int		verif;
	char	*str;
	
	i = 0;
	verif = 1;
	while(full_path[i])
	{
		str = ft_strjoin_three(full_path[i], "/", data->cmd1[0]);
		if (access(str, F_OK | R_OK ) == 0)
		{
			data->path = ft_strdup(full_path[i]);
			free(str);
			verif = 0;
			break;
		}
		i++;
		free(str);
	}
	if (verif == 1)
		return (1);
	return (0);
}
int	check_path(t_data *data)
{
	int		i;
	char	**full_path;
	

	i = 0;
	full_path = NULL;
	while (data->env[i])
	{
		if(ft_strncmp(data->env[i], "PATH=", 5) == 0)
		{
			full_path = ft_split(data->env[i] + 5, ':');
			break;
		}
		i++;
	}
	if (!full_path)
		return (free_split(full_path), 1);
	if (extract_path(data, full_path))
		return (free_split(full_path), 1);
	free_split(full_path);
	return (0);	
}

int	struct_attribution(char **av, char**env, t_data *data)
{
	(void)av;
	data->env = env;
	if (!data->env)
		return (ft_putstr_fd("Error copy env\n", 1),free_split(data->env), 1);
	// data->args = av;
	// if (!data->args)
	// 	return (ft_putstr_fd("Error copy args\n", 1),free_split(data->args), 1);
	data->cmd1 = ft_split(av[2], ' ');
	data->cmd2 = ft_split(av[3], ' ');
	if (check_path(data))
		return (free_struct(data),1);
	data->in_fd = open(av[1], O_RDONLY);
	data->out_fd = 1;
	if (data->in_fd < 0)
		return (1);
	return (0);
}


// int	first_cmd(t_data *data)
// {
// 	int	pid1;
// 	int	pid2;
	
// 	if (pipe(data->pip) == 1)
// 		return (free_struct(data), 1);
// 	pid1 = fork();
// 	if  (pid1 < 0)
// 		return (free_struct(data), 2);
// 	if (pid1 == 0)
// 	{
// 		dup2(data->pip[1], STDOUT_FILENO);
// 		close (data->pip[1]);
// 		close (data->pip[0]);
// 		execve(data->path, data->args, data->env);		
// 	}
// 	pid2 = fork();
// 	if (pid2 < 0)
// 		return (free_struct(data), 3);
// 	if (pid2 == 0)
// 	{
// 		dup2(data->pip[0], STDIN_FILENO);
// 		close(data->pip[0]);
// 		close(data->pip[1]);
// 		execve(data->path, data->args, data->env);
// 	}
// 	close(data->pip[0]);
// 	close(data->pip[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }



int	main(int ac, char **av, char **env)
{
	t_data	data;
	(void)av;
	if (ac < 5 || !env)
		return (1);
	if (struct_attribution(av, env, &data))
		return 1;
	printf("%s\n", data.path);

	free_struct(&data);
	return (0);
}
/* 
creer un pip[2]
creer un pid 
dire pid= fork()
pid < 0 erreur pid == 0 child process, pid == 1 parent process
path 
usr/ls
Lusr/:

// tester chemin dacces
si dans mon av il y a des / verfier si le chemin na pas ete mit directement
sinon splitr path avec ":" et tester char string en rajoutant la commande demandee : usr/bin  -> usr/bin/ls
 dans excec chemin = bin/usr/ls , arg = -ls, env = env
*/
/* 
utiliser excecve pour appliquer la commande et verfier si la c=fonction existe 
trouver le path en utilisant env,
securiser le chemin avec equivalent de whereis "X"
"envie -i" enelve lenvie il faut proteger 
dup2 pour dupliquer sortie et entree
test avec sleep5
gerer la creation du fichier de sortie
 */
