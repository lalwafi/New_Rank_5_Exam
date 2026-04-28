CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
NAME = polyset

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJS)

re: clean all