OUT1	=	server
OUT2	=	client
CFLAGS	=	-Wall -Wextra -Werror
OBJS_1	=	server.o 
OBJS_2	=	client.o 

all		:	$(OUT1) $(OUT2)

$(OUT1)	:	$(OBJS_1)
	gcc $(CFLAGS) $^ -o $@

$(OUT2)	:	$(OBJS_2)
	gcc $(CFLAGS) $^ -o $@

%.o		:	%.c
	gcc -c $(CFLAGS) $^ 

clean	:
	rm -rf $(OBJS_1) $(OBJS_2)

fclean	:	clean
	rm -rf $(OUT1) $(OUT2)

re		:	fclean all

PHONY	:	all clean fclean re
