NAME = ClapTrap
SRC = ClapTrap.cpp main.cpp
OBJS = $(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98
INC = ClapTrap.hpp
R        := $(shell tput -Txterm setaf 1)
G        := $(shell tput -Txterm setaf 2)
Y       := $(shell tput -Txterm setaf 3)

all: $(NAME)
	@echo $(G) "ALL functions are done!"

$(NAME): $(OBJS)
	@echo $(Y) Compiling: $< ... Done!
	@c++ $(CFLAGS) $(OBJS) -o $@

%.o: %.cpp $(INC)
	@echo $(Y) Compiling: $< ... Done!
	@c++ $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean:
	@echo $(R) Cleaned
	@rm -f $(OBJS)

fclean: clean
	@echo $(R) Fully cleaned
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all