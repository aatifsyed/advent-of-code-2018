BIN_DIR=./bin
SRC_DIR=./src
LIB_DIR=./lib
INC_DIR=./include
OBJ_DIR=./obj

LIBS=pthread rt
LFLAGS=$(addprefix -l, $(LIBS))

CC=clang
CFLAGS=-I$(INC_DIR) -L$(LIB_DIR) $(LFLAGS)

%:$(SRC_DIR)/%.c
	$(CC) -o $(BIN_DIR)/$@ $^ $(CFLAGS)
	$(BIN_DIR)/$@

.PHONY: clean dirs
dirs:
	mkdir -p $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR)
clean:
	rm -r $(BIN_DIR) $(LIB_DIR) $(OBJ_DIR)
