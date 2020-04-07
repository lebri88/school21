#ifndef LEXER_H
# define LEXER_H

enum					e_token
{
	WORD,
	ASSIGMENT_WORD,
	NAME,
	A_NEWLINE,
	IO_NUMBER,
	CTRL_OP_PIPELINE,
	CTRL_OP_SEMICOLON,
	CTRL_OP_AMPERSAND,
	CTRL_OP_AND_IF,
	CTRL_OP_OR_IF,
	CTRL_OP_DSEMI,
	CTRL_OP_OP_R_BRACKETS,
	CTRL_OP_CL_R_BRACKETS,
	RED_OP_LESS,
	RED_OP_GREAT,
	RED_OP_DLESS,
	RED_OP_DGREAT,
	RED_OP_LESSAND,
	RED_OP_GREATAND,
	RED_OP_LESSGREAT,
	RED_OP_DLESSDASH,
	RED_OP_CLOBBER,
};

typedef struct			s_token
{
	enum e_token		type;
	char				*content;
}						t_token;


	
t_list					*lexer(char *line);
int		ft_is_redirect_operator(char *str);
int		ft_is_operator(char *str);
int		ft_find_closing_double_quotes(int i, char *str, int *cont_read);
int		ft_find_closing_single_quotes(int i, char *str, int *cont_read);
void	ft_check_type_and_add_token(t_list *data, char *str, int i, int io_nbr_flag);





#endif
