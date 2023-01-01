CC := 					gcc
CFLAGS += 				-Wall -Werror -Wextra
LDFLAGS += 				-Wall -Werror -Wextra

SRC_DIR := 				./
OBJ_DIR := 				$(SRC_DIR)/objects/

LIB := 					s21_math.a

SRC := 					$(wildcard $(SRC_DIR)*.c)
OBJ := 					$(SRC:%.c=$(OBJ_DIR)%.o)


$(LIB): $(OBJ)
	$(AR) -rcs $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ) $(LIB)
