#include "../push_swap.h"

void	check_flag(int *flag, char ***argv, int *argc)
{
	char	**p_argv;

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = -1;
	flag[4] = 0;
	p_argv = *argv;
	p_argv++;
	(*argc)--;
	while (*argc > 1)
	{
		if (p_argv[0][0] == '-' && p_argv[0][1] == 'v')
			flag[0] = 1;
		else if (p_argv[0][0] == '-' && p_argv[0][1] == 'c')
			flag[1] = 1;
		else if (p_argv[0][0] == '-' && p_argv[0][1] == 'l')
			flag[2] = 1;
		else if (p_argv[0][0] == '-' && p_argv[0][1] == 's')
			flag[3] = 0;
		else if (p_argv[0][0] == '-' && p_argv[0][1] == 'f')
			flag[4] = 1;
		else
			break ;
		(*argc)--;
		p_argv++;
	}
	*argv = p_argv;
}