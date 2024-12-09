
NAME = libftprintf.a
C_Compiler = cc
C_FLAGS = -Wall -Wextra -Werror

Funs = 	Funs/ft_putchar.c Funs/ft_putstr.c Funs/ft_putnbr.c Funs/ft_puthexa.c Funs/ft_putunsgned.c Funs/ft_putadrs.c Funs/ft_printf.c
		
Funs_bn = Funs_bn/ft_putchar_bonus.c Funs_bn/ft_putstr_bonus.c Funs_bn/ft_putnbr_bonus.c Funs_bn/ft_puthexa_bonus.c Funs_bn/ft_putunsgned_bonus.c Funs_bn/ft_putadrs_bonus.c Funs_bn/ft_printf_bonus.c

OFuns = $(Funs:.c=.o)
OFuns_bn = $(Funs_bn:.c=.o)

all: $(NAME)

bonus: $(OFuns_bn)
	ar rc ${NAME} $(OFuns_bn)

$(NAME): $(OFuns)
	ar rc ${NAME} $(OFuns)
	
Funs/%.o: Funs/%.c ft_printf.h
	$(C_Compiler) $(C_FLAGS) -c $< -o $@

Funs/%.o: Funs/_bn%.c ft_printf.h
	$(C_Compiler) $(C_FLAGS) -c $< -o $@

clean:
	$(RM) $(OFuns) $(OFuns_bn)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean