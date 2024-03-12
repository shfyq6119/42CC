# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 00:35:02 by mm-isa            #+#    #+#              #
#    Updated: 2024/03/13 00:59:57 by mm-isa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft
LIB_NAME = lib_ft.a

all:  $(LIB_NAME)

$(LIB_NAME):	libft ft_printf
				@echo "Creating library: $(LIB_NAME)"
				@ar rcs $(LIB_NAME) $(LIBFT_DIR)/*.o $(FT_PRINTF_DIR)/*.o
				@echo "Library creation done."

libft:			
				@echo "Compiling libft . . . "
				@$(MAKE) -C $(LIBFT_DIR) --no-print-directory --silent

ft_printf:		
				@echo "Compiling ft_printf . . . "
				@$(MAKE) -C $(FT_PRINTF_DIR) --no-print-directory --silent

clean:			
				@echo "Cleaning libft and ft_printf *.o files . . . "
				@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory --silent
				@$(MAKE) -C $(FT_PRINTF_DIR) clean --no-print-directory --silent
				@echo "Cleaned."

fclean:			clean
				@echo "Cleaning all libs and bins."
				@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory --silent
				@$(MAKE) -C $(FT_PRINTF_DIR) fclean --no-print-directory --silent
				@rm -f $(LIB_NAME)
				@echo "fully cleaned."

re:				fclean all
				@echo "Recompiled."

.PHONY:			all libft ft_printf clean fclean re
