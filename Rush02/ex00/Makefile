# ******************************************************************************
# VARIABLES
# ******************************************************************************

NAME	= rush-02

CC		= gcc

FLAGS	= -Werror -Wextra -Wall

SRCDIR	= ./src/

OBJDIR  = ./obj/

HEADER	= ./includes/

SRC		= $(wildcard $(SRCDIR)*.c)

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJS	= $(addprefix $(OBJDIR), $(notdir $(SRC:.c=.o)))

# ******************************************************************************
# TARGETS
# ******************************************************************************

all:			$(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.c
				@mkdir -p $(OBJDIR)
				${CC} ${FLAGS} -c -I ${HEADER} $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
