/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:10:07 by jihyeole          #+#    #+#             */
/*   Updated: 2023/04/14 08:39:57 by jihyeole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_process	*process;
	t_arg_info	arg_info;
	int			i;

	if (argc < 5)
		print_error("need at least 4 arguments", 1);
	process = (t_process *)malloc(sizeof(process) * argc - 4);
	arg_info.argv = argv;
	arg_info.env = env;
	create_pipe(process, argc - 4);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		heredoc_first_process(process, argc - 4, argv[2]);
	else
		first_process(process, argc - 4, argv, env);
	i = 1;
	while (i < argc - 4)
		nth_process(i++, process, argc - 4, &arg_info);
	wait_all_child(argc - 4, process);
	parent_process(process, argc, argv, env);
}
