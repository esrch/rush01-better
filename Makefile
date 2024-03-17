CC = clang
override CFLAGS += -g -Wall -Wextra -Werror -pthread -lm -I./inc

COMMON_SRCS = $(shell find src/common -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
GENERATOR_SRCS = $(shell find src/generator -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
SOLVER_SRCS = $(shell find src/solver -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
CHECKER_SRCS = $(shell find src/checker -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

all: generator solver checker

generator: $(GENERATOR_SRCS) $(COMMON_SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(GENERATOR_SRCS) $(COMMON_SRCS) -o "$@"

solver: $(SOLVER_SRCS) $(COMMON_SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SOLVER_SRCS) $(COMMON_SRCS) -o "$@"

checker: $(CHECKER_SRCS) $(COMMON_SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(CHECKER_SRCS) $(COMMON_SRCS) -o "$@"

clean:
	rm -f generator solver checker