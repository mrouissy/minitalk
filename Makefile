CLIENT = client
SERVER = server

C = cc

CFLAG = -Wall -Wextra -Werror

RM = rm -f

OBJSRV = $(SRV:.c=.o)

OBJCLI = $(CLI:.c=.o)

SRV = mandatory/server.c

CLI = mandatory/client.c

all: $(CLIENT) $(SERVER)


$(CLIENT) : $(OBJCLI)
	@make -C ./utils
	$(C) $(CFLAG) -o $(CLIENT) $(CLI) utils/utils.a

$(SERVER) : $(OBJSRV)
	$(C) $(CFLAG) -o $(SERVER) $(SRV) utils/utils.a

%.o: %.c
	@$(C) $(FLAG) -c $< -o $@

clean:
	@make clean -C ./utils
	@$(RM) $(OBJCLI) $(OBJSRV)

fclean : clean
	@make fclean -C ./utils
	@$(RM) $(CLIENT) $(SERVER)

re : clean all

.PHONY: all, clean, fclean, re
