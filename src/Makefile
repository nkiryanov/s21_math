CC := 					gcc
CFLAGS += 				-Wall -Werror -Wextra
LDFLAGS += 				-Wall -Werror -Wextra

SRC_DIR := 				./lib/
OBJ_DIR := 				./objects/

LIB := 					s21_math.a

SRC := 					$(wildcard $(SRC_DIR)*.c)
OBJ := 					$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

echo:
	@echo LIB=$(LIB)
	@echo CFLAGS=$(CFLAGS)
	@echo CC=$(CC)
	@echo SRC=$(SRC)
	@echo OBJ=$(OBJ)

$(LIB): $(OBJ)
	$(AR) -rcs $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ) $(LIB)
