/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:07:42 by amelikia          #+#    #+#             */
/*   Updated: 2018/11/26 13:11:32 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	begin(void)
{
	char	*line;
	int		e_status;

	e_status = 0;
	while (1 || e_status == 1)
	{
		ft_printf("$ >");
		while (get_next_line(line) > 0)
		{
			ft_printf("LOL %s\n", line);
		}
	}
}

int		main(void)
{
	begin();
	return (0);
}
