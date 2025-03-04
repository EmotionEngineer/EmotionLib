# Compiler and flags
CC := gcc
CFLAGS := -fPIC -Wall -Wextra -Ofast -Iinclude
LDFLAGS := -shared

# Source files and output binary
BIN := samp.dll # Safeness And MPAA / EmotionLib
SRC := main.c \
      src/mlp_common.c \
      src/mlp_model1.c \
      src/mlp_model2.c \
      src/mlp_model3.c \
	  src/lstm_filter_model.c \
	  src/mlp_mpaa_model.c
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)

# Default target
all: $(BIN)

# Build shared library
$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ -I. -MMD -MF $(@:.o=.d) $<

# Include dependencies
-include $(DEP)

# Cleaning up
.PHONY: clean
clean:
	rm -f $(BIN) $(OBJ) $(DEP) *.args.0 *.bc *.i *.ii *.lto_wrapper_args \
	*.ltrans_args *.ltrans0.o *.ltrans.o *.ltrans.out *.res *.s *.temp.o