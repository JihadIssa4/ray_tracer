app:
	cd minilibx-linux ; make; cd ..
	cd libft ; make ; cd .. 
	cc -Wall -Wextra -Werror test.c -Iminilibx-linux -Lminilibx-linux -lmlx -lX11 -lXext
