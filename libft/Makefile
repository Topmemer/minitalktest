NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

HEADER = libft.h

OFILES = *.o

#BONUSHEADER = include/libft_bonus.h

FILES = ft_[!l]*.c

BONUSOFILES = ft_[l]*.o

BONUSFILES = ft_[l]*.c

all: $(NAME)

$(NAME): 
	gcc -c $(CFLAGS) $(FILES)
	ar rc $(NAME) $(OFILES)
	@echo "Build done"

clean:
	rm -f $(NAME)
	rm -f *.o
	@echo "cleaning"

fclean: clean

re: fclean all

bonus: 
	gcc -c $(CFLAGS) $(BONUSFILES)
	ar rc $(NAME) $(BONUSOFILES)
	@echo "Bonus build done"

rebonus: fclean bonus

testenv:
	cmake -S . -B build

testrun:
	cmake --build build && \
	cd build && \
	ctest --output-on-failure

norm:
	norminette ./*.*

gcc:
	gcc -c $(CFLAGS) $(FILES); rm ./*.o