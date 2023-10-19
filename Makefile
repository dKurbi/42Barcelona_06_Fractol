# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkurcbar <dkurcbar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 17:48:56 by dkurcbar          #+#    #+#              #
#    Updated: 2023/10/19 11:32:44 by dkurcbar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

	#Libraries 
MINILIBX		=	./mlx/libmlx.a
LIBFT 			=	./libft/libft.a

	#Paths
SRCS_PATH	=	src#		
SRCS_PATH_M	=	src_m#		
SRCS_PATH_B	=	src_b#										# the path to your sources without ending /
INCS_PATH	=	include#	
BIN_PATH  	=	bin#		
LIBMLX_PATH	=	mlx
LIBFT_PATH	=	libft#

	# Mandatory Variables #
SRC     	= $(wildcard $(SRCS_PATH)/*.c)#		
SRC_M		= $(wildcard $(SRCS_PATH_M)/*.c)#	
SRC_B		= $(wildcard $(SRCS_PATH_B)/*.c)#	
BIN_OBJ		= $(SRC:$(SRCS_PATH)%.c=$(BIN_PATH)%.o)#
BIN_OBJ_M	= $(SRC_M:$(SRCS_PATH_M)%.c=$(BIN_PATH)%.o)#

	# Bonus Variables #
SRC_B		= $(wildcard $(SRCS_PATH_B)/*.c)#
BIN_OBJ_B	= $(SRC_B:$(SRCS_PATH_B)%.c=$(BIN_PATH)%.o)#

BIN_OBJ_M	= $(SRC_M:$(SRCS_PATH_M)%.c=$(BIN_PATH)%.o)#
CC		:=	gcc
CFLAG	:=	-Wall -Werror -Wextra -O2 -g #-fsanitize=address
AR		:=	ar rcs
RM		:=	rm -f
INC_LIB	:=	-I$(LIBMLX_PATH) -I$(INCS_PATH) -I$(LIBFT_PATH)
INCLUDE :=  -L$(LIBMLX_PATH) -l$(LIBMLX_PATH) -L$(LIBFT_PATH) -lft
FRAME	:= -framework OpenGL -framework AppKit

all: 
	 @mkdir -p bin
	 @$(MAKE) --no-print-directory  -C $(LIBMLX_PATH)
	 @$(MAKE) --no-print-directory  -C $(LIBFT_PATH)
	 @$(MAKE) --no-print-directory $(NAME)

bonus :.bonus

.bonus: $(BIN_OBJ) $(BIN_OBJ_B) $(MINILIBX) $(LIBFT) Makefile
	@$(MAKE) --no-print-directory  -C $(LIBMLX_PATH)
	@$(MAKE) --no-print-directory  -C $(LIBFT_PATH)
	@$(CC) $(CFLAG) $(BIN_OBJ) $(BIN_OBJ_B) $(INCLUDE) $(FRAME) -g -o $(NAME) 
	@printf "$(_SUCCESS) Fractol Bonus compiled.\n"
	@$(RM) .mandatory
	@touch $@ 

$(NAME): .mandatory

.mandatory: $(BIN_OBJ) $(BIN_OBJ_M) $(MINILIBX) $(LIBFT) Makefile
	@$(CC) $(CFLAG) $(BIN_OBJ) $(BIN_OBJ_M) $(INCLUDE) $(FRAME) -g -o $(NAME) 
	@printf "$(_SUCCESS) Fractol compiled.\n"
	@$(RM) .bonus
	@touch $@
	
$(LIBFT):
	 @$(MAKE) -C $(LIBFT_PATH)

$(MINILIBX): 
	 @$(MAKE) -C  $(LIBMLX_PATH)
	
$(BIN_PATH)/%.o: $(SRCS_PATH)/%.c include/fractol.h
	@$(CC) $(CFLAG) $(INC_LIB)  -c $< -o $@  && echo "Compiled: $< -> $@"

$(BIN_PATH)/%.o: $(SRCS_PATH_M)/%.c include/fractol.h
	@$(CC) $(CFLAG) $(INC_LIB)  -c $< -o $@  && echo "Compiled: $< -> $@"

$(BIN_PATH)/%.o: $(SRCS_PATH_B)/%.c include/fractol.h
	@$(CC) $(CFLAG) $(INC_LIB)  -c $< -o $@  && echo "Compiled: $< -> $@"

clean:
	@ $(MAKE) --no-print-directory clean -C $(LIBFT_PATH)
	@ ${RM} ${BIN_OBJ}
	@$(foreach obj,${OBJ},echo "File deleted: ${obj}";)
	@printf "$(_INFO) Binary Files Fractol removed.\n"

fclean: 
	@ $(MAKE) --no-print-directory clean -C $(LIBMLX_PATH)
	@ $(MAKE) --no-print-directory fclean -C $(LIBFT_PATH)
	@ $(MAKE) clean
	@ $(RM) $(NAME) 
	@ $(RM) .bonus .mandatory
	@printf "$(_INFO) Fractol removed.\n"

re:	fclean all

.PHONY: all clean fclean re bonus

