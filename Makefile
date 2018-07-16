NAME	= Game

SRC	= ./src/main.cpp \
	./src/Window.cpp

OBJ	 = $(SRC:.cpp=.o)

CC	 = g++

CXXFLAGS = -std=c++17 -I./include


all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CXXFLAGS) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -rf src/*.o

fclean:	clean
	rm -rf $(NAME)
	rm -rf ./*~

re:	fclean all
