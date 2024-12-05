
NAME = libftprintf.a
C_Compiler = cc
C_FLAGS = -Wall -Wextra -Werror

Funs = 	ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthexa.c ft_putunsgned.c ft_putadrs.c ft_printf.c
		
# Funs_bn = 

OFuns = $(Funs:.c=.o)
# OFuns_bn = $(Funs_bn:.c=.o)

all: $(NAME)

# bonus: $(OFuns_bn)
# 	ar rc ${NAME} $(OFuns_bn)

$(NAME): $(OFuns)
	ar rc ${NAME} $(OFuns)
	
%.o: %.c ft_printf.h
	$(C_Compiler) $(C_FLAGS) -c $< -o $@

clean:
	$(RM) $(OFuns) 

# $(OFuns_bn)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean