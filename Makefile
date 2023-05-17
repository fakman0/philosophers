all:
	@gcc *.c -Wall -Wextra -Werror -o philo
	@echo ✅

datarace:
	@gcc *.c -pthread -fsanitize=thread

fclean:
	@rm -rf philo
	@echo 🗑️

re:
	@make fclean
	@make all

norm:
	@norminette
