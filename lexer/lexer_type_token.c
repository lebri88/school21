#include "shell.h"

void	ft_add_io_number_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = IO_NUMBER;
	token->content = ft_strsub(str, 0, i);
	data->content = token;
}

void	ft_add_newline_token(t_list *data)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = A_NEWLINE;
	token->content = ft_strdup("newline");
	data->content = token;
}

void	ft_add_control_operator_token(t_list *data, char *str, int i)
{
	t_token	*token;

	token = ft_memalloc(sizeof(t_token));
	token->content = ft_strsub(str, 0, i);
	if (!ft_strcmp(token->content, "|"))
		token->type = CTRL_OP_PIPELINE;
	else if (!ft_strcmp(token->content, ";"))
		token->type = CTRL_OP_SEMICOLON;
	else if (!ft_strcmp(token->content, "&"))
		token->type = CTRL_OP_AMPERSAND;
	else if (!ft_strcmp(token->content, "&&"))
		token->type = CTRL_OP_AND_IF;
	else if (!ft_strcmp(token->content, "||"))
		token->type = CTRL_OP_OR_IF;
	else if (!ft_strcmp(token->content, ";;"))
		token->type = CTRL_OP_DSEMI;
	else if (!ft_strcmp(token->content, "("))
		token->type = CTRL_OP_OP_R_BRACKETS;
	else if (!ft_strcmp(token->content, ")"))
		token->type = CTRL_OP_CL_R_BRACKETS;
	data->content = token;
}

void	ft_add_redirect_operator_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->content = ft_strsub(str, 0, i);
	if (!ft_strcmp(token->content, "<<-"))
		token->type = RED_OP_DLESSDASH;
	else if (!ft_strcmp(token->content, "<<"))
		token->type = RED_OP_DLESS;
	else if (!ft_strcmp(token->content, ">>"))
		token->type = RED_OP_DGREAT;
	else if (!ft_strcmp(token->content, ">&"))
		token->type = RED_OP_GREATAND;
	else if (!ft_strcmp(token->content, "<&"))
		token->type = RED_OP_LESSAND;
	else if (!ft_strcmp(token->content, "<>"))
		token->type = RED_OP_LESSGREAT;
	else if (!ft_strcmp(token->content, ">|"))
		token->type = RED_OP_CLOBBER;
	else if (!ft_strcmp(token->content, "<"))
		token->type = RED_OP_GREAT;
	else if (!ft_strcmp(token->content, ">"))
		token->type = RED_OP_LESS;
	data->content = token;
}

void	ft_add_word_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = WORD;
	token->content = ft_strsub(str, 0, i);
	data->content = token;
}

void	ft_check_type_and_add_token(t_list *data, char *str,
			int i, int io_nbr_flag)
{
	if (io_nbr_flag != 0)
		ft_add_io_number_token(data, str, i);
	else if (*str == '\n')
		ft_add_newline_token(data);
	else if (ft_is_operator(str) > 0)
	{
		if (ft_is_redirect_operator(str) > 0)
			ft_add_redirect_operator_token(data, str, i);
		else
			ft_add_control_operator_token(data, str, i);
	}
	else
		ft_add_word_token(data, str, i);
}
