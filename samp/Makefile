# Compiler and flags
CC := gcc
CFLAGS := -fPIC -Wall -Wextra -Ofast -Iinclude
LDFLAGS := -shared

# Select extension
ifeq ($(OS),Windows_NT) # Windows
  SHLIB_EXT := dll
else
  # for everything else use uname
  UNAME_S  := $(shell uname -s)
  ifeq ($(UNAME_S),Darwin)          # macOS
    SHLIB_EXT := dylib
  else                              # Linux, *BSD, ...
    SHLIB_EXT := so
  endif
endif

# Source files and output binary
override BIN := samp.$(SHLIB_EXT) # Safeness And MPAA / EmotionLib
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
