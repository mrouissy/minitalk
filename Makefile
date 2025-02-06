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
	@$(C) $(CFLAG) -o $(CLIENT) $(CLI) utils/utils.a
	@echo "Client created √"

$(SERVER) : $(OBJSRV)
	@$(C) $(CFLAG) -o $(SERVER) $(SRV) utils/utils.a
	@echo "Server created √"

%.o: %.c
	@$(C) $(FLAG) -c $< -o $@

clean:
	@make clean -C ./utils
	@$(RM) $(OBJCLI) $(OBJSRV)
	@echo "All object files removed √"

fclean : clean
	@make fclean -C ./utils
	@$(RM) $(CLIENT) $(SERVER)
	@echo "All files removed √"

re : clean all
	@make re -C ./utils
	@echo "All files recompiled √"

.PHONY: all, clean, fclean, re
