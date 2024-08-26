#include "pipex.h"

int main(int argc, char **argv, char **env)
{	
	argv = NULL;
	argc =  0;
	char *exec_path;
	int ret = -1;
	char **cmd;

	init_data();
	getinstance()->path = get_path(env); //error나면 null임
	
	int i = 0;
	while (ret == -1 && getinstance()->path[i])
	{
		cmd = ft_split("ls -al", ' ');
		exec_path = ft_triple_strjoin(getinstance()->path[i], "/", cmd[0]);
		ret = execve(exec_path, cmd, env);
		i++;
		
	}
}