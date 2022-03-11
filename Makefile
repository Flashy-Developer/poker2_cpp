CPP_NOT_MAIN = $(shell find . -type f -name 'ft_*.cpp')
CPP_MAIN = $(shell find . -type f -name 'main.cpp')
CPP_TEST = $(shell find . -type f -name 'test.cpp')

OUTPUT = a.out

NORM	= norminette -R CheckForbiddenSourceHeader
CXX 	= g++
CXXFLAG	= -Wall -Wextra -Werror

$(OUTPUT): all

all:
	@clear
	@printf '\x1b[38;5;198m------------------------- Source -------------------------\n\n\e[0m'
	@printf 'function file: $(CPP_MAIN) $(CPP_NOT_MAIN)\n\n'
	@printf '\x1b[38;5;220m-------------------- COMPILER  OUTPUT --------------------\n\n\e[0m'
	@$(CXX) --version
	@$(CXX) $(CXXFLAG) $(CPP_MAIN) $(CPP_NOT_MAIN) -o $(OUTPUT)
	@printf 'OUTPUT FILE: $(OUTPUT)\n\n'
	@printf '\x1b[38;5;47m--------------------- PROGRAM OUTPUT ---------------------\n\n\e[0m'
	@./$(OUTPUT)
	@printf '\n\x1b[38;5;45m------------------------- FINISH -------------------------\n\n\e[0m'
	@rm $(OUTPUT)

test:
	@clear
	@printf '\x1b[38;5;198m------------------------- Source -------------------------\n\n\e[0m'
	@printf 'function file: $(CPP_TEST) $(CPP_NOT_MAIN)\n\n'
	@printf '\x1b[38;5;220m-------------------- COMPILER  OUTPUT --------------------\n\n\e[0m'
	@printf 'Version: $(shell $(CXX) --version | grep $(CXX))\n\n'
	@$(CXX) $(CXXFLAG) $(CPP_TEST) $(CPP_NOT_MAIN) -o $(OUTPUT)
	@printf 'OUTPUT FILE: $(OUTPUT)\n\n'
	@printf '\x1b[38;5;47m--------------------- PROGRAM OUTPUT ---------------------\n\n\e[0m'
	@./$(OUTPUT)
	@printf '\n\x1b[38;5;45m------------------------- FINISH -------------------------\n\n\e[0m'
	@rm $(OUTPUT)

clean:
	@rm $(shell find . -type f -name '*.out') $(shell find . -type f -name '*.txt') $(shell find . -type f -name '*.exe')

re: clean all