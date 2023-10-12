# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:48:56 by dkurcbar          #+#    #+#              #
#    Updated: 2023/10/10 14:41:43 by dkurcbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

	#Libraries 
MINILIBX		=	./mlx/mlx.a

	#Paths
SRCS_PATH	=	src#												# the path to your sources without ending /
INCS_PATH	=	include#	
BIN_PATH  	=	bin#		
LIBMLX_PATH	=	mlx

	# Mandatory Variables #
SRC     = $(wildcard $(SRCS_PATH)/*.c)#		
OBJ     = $(SRC:$(SRCS_PATH)%.c=$(SRCS_PATH)%.o)#
BIN_OBJ	= $(SRC:$(SRCS_PATH)%.c=$(BIN_PATH)%.o)#

CC		:=	gcc
CFLAG	:=	-Wall -Werror -Wextra -O2 -g -fsanitize=address
AR		:=	ar rcs
RM		:=	rm -f
INC_LIB	:=	-I$(LIBMLX_PATH) -I$(INCS_PATH)
INCLUDE :=  -L$(LIBMLX_PATH) -l$(LIBMLX_PATH) 
FRAME	:= -framework OpenGL -framework AppKit

all: 
	@ $(MAKE) --no-print-directory  -C $(LIBMLX_PATH)
	@ $(MAKE) --no-print-directory $(NAME)

	
$(NAME): $(OBJ) $(MINILIBX) Makefile 
	@mv $(OBJ) $(BIN_PATH)
	$(CC) $(CFLAG) $(BIN_OBJ) $(INCLUDE) $(FRAME) -o $(NAME) 
	@printf "$(_SUCCESS) Fractol compiled.\n"

$(MINILIBX): 
	@ $(MAKE) -C  $(LIBMLX_PATH)
	
%.o: %.c ${INCLUDE}
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
	# @${CC} $(CFLAG) $(INC_LIB) -c $< -o $@  && echo "Compiled: $< -> $@"

clean:
	@ ${RM} ${BIN_OBJ}
	@$(foreach obj,${OBJ},echo "File deleted: ${obj}";)
	@printf "$(_INFO) Binary Files Fractol removed.\n"

fclean: 
	@ $(MAKE) --no-print-directory clean -C $(LIBMLX_PATH)
	@ $(MAKE) clean
	@ $(RM) $(NAME) 
	@printf "$(_INFO) Fractol removed.\n"

re:	fclean all

.PHONY: all clean fclean re 

