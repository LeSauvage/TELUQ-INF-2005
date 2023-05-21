# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(TARGET)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif

# Project tests
TEST1 = 0
TEST2 = 5
TEST3 = 11
PROJECT_TESTS = $(TEST1) $(TEST2) $(TEST3)

TARGET = multiply
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++11 -I.
LDFLAGS =
SRCS = $(wildcard *.cpp)
PROJECT_DEPS = $(wildcard *.hpp)
OBJS = $(SRCS:.cpp=.o)
RM	=	rm -rf

# Define rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(HIDE)$(CC) $(LDFLAGS) $^ -o $@
	$(HIDE)printf "\033[32;1m\nCompiling with: \033[38;5;208m$(CPPFLAGS)\033[0m\\n\\n"
	$(HIDE)printf "\033[32;1m\nCompiling: \033[38;5;208m$(PROJECT_TARGET)\033[0m\\n"

%.o: %.cpp $(PROJECT_DEPS) $(PROJECT_SRCS)
	$(HIDE)$(CC) $(CPPFLAGS) -c $< -o $@

run: $(TARGET)
	@for test in $(PROJECT_TESTS); do \
		echo "Running Test: $$test"; \
		./$(TARGET) $$test; \
	done

clean:
	$(HIDE)$(RM) $(OBJS)

fclean: clean
	$(HIDE)$(RM) $(TARGET)

re: fclean all
