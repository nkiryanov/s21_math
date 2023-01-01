CC := 					gcc
CFLAGS += 				-Wall -Werror -Wextra
LDFLAGS += 				-Wall -Werror -Wextra

SRC_DIR := 				./lib/
OBJ_DIR := 				./objects/

SRC := 					$(wildcard $(SRC_DIR)*.c)
OBJ := 					$(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

TEST_DIR := 			./tests/
TEST_SRC := 			$(wildcard $(TEST_DIR)*.c)
TEST_OBJ := 			$(TEST_SRC:.c=.o)
TEST_EXEC := 			$(TEST_DIR)tests_s21_math

LIB := 					s21_math.a

all: $(LIB)

echo:
	@echo LIB=$(LIB)
	@echo CFLAGS=$(CFLAGS)
	@echo CC=$(CC)
	@echo SRC=$(SRC)
	@echo OBJ=$(OBJ)
	@echo LDLIBS=$(LDLIBS)

lint:
	cp ../materials/linters/CPPLINT.cfg .
	python3 ../materials/linters/cpplint.py --extension=c $(SRC_DIR)*
	rm CPPLINT.cfg

test tests: $(TEST_EXEC)
	@$^

$(LIB): $(OBJ)
	$(AR) -rcs $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(TEST_DIR)%.o: CFLAGS += $(shell pkg-config --cflags-only-I check)
$(TEST_DIR)%.o: $(TEST_DIR)%.c
	$(CC) -c $(CFLAGS) $^ -o $@

$(TEST_EXEC): LDLIBS += $(shell pkg-config --libs check)
$(TEST_EXEC): $(TEST_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ $(LDLIBS)

clean:
	rm -rf $(OBJ) $(LIB) $(TEST_OBJ) $(TEST_EXEC)
