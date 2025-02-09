CLIENT = client
SERVER = server

BCLIENT = client_bonus
BSERVER = server_bonus

CFLAG = cc -Wall -Wextra -Werror

RM = rm -f


SRV = mandatory/server.c

CLI = mandatory/client.c

BSRV = bonus/server_bonus.c
BOBJSRV = $(BSRV:.c=.o)

BOBJCLI = $(BCLI:.c=.o)

OBJSRV = $(SRV:.c=.o)

OBJCLI = $(CLI:.c=.o)

BCLI = bonus/client_bonus.c

all: $(CLIENT) $(SERVER)

bonus: $(BCLIENT) $(BSERVER)

$(CLIENT) : $(OBJCLI)
	@make -C ./utils
	@$(CFLAG) -o $(CLIENT) $(CLI) utils/utils.a
	@echo "Client created √"

$(SERVER) : $(BOBJSRV)
	@$(CFLAG) -o $(SERVER) $(SRV) utils/utils.a
	@echo "Server created √"

$(BCLIENT) : $(BOBJCLI)
	@make -C ./utils
	@$(CFLAG) -o $(BCLIENT) $(BCLI) utils/utils.a
	@echo "Client created √"

$(BSERVER) : $(OBJSRV)
	@$(CFLAG) -o $(BSERVER) $(BSRV) utils/utils.a
	@echo "Server created √"

%.o: %.c
	@$(FLAG) -c $< -o $@

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
