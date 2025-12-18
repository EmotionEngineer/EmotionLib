# ------------------------------------------
# Compiler and base flags
# ------------------------------------------
CC      ?= gcc
CFLAGS  ?= -fPIC -Wall -Wextra -Ofast -Iinclude
LDFLAGS ?= -shared
LDLIBS  ?= -lm

# ------------------------------------------
# Select shared library extension
# ------------------------------------------
ifeq ($(OS),Windows_NT)
  SHLIB_EXT := dll
else
  UNAME_S := $(shell uname -s)
  ifeq ($(UNAME_S),Darwin)
    SHLIB_EXT := dylib
  else
    SHLIB_EXT := so
  endif
endif

# ------------------------------------------
# Optional: link libmvec on Linux when present
# ------------------------------------------
USE_LMVEC ?= 1

ifeq ($(UNAME_S),Linux)
  ifeq ($(USE_LMVEC),1)
    LMVEC_SO := $(shell $(CC) -print-file-name=libmvec.so)
    ifneq ($(LMVEC_SO),libmvec.so)
      ifneq ($(wildcard $(LMVEC_SO)),)
        # Force DT_NEEDED for libmvec even with --as-needed defaults
        LDLIBS += -Wl,--no-as-needed -lmvec -Wl,--as-needed
      endif
    endif
  endif
endif

# ------------------------------------------
# Target / sources
# ------------------------------------------
override BIN := samp.$(SHLIB_EXT) # Safeness And MPAA / EmotionLib

SRC := main.c \
      src/mlp_common.c \
      src/mlp_model1.c \
      src/mlp_model2.c \
      src/mlp_model3.c \
      src/mlp_model4.c \
      src/lstm_filter_model.c \
      src/mlp_mpaa_model.c

OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)

# ------------------------------------------
# Build rules
# ------------------------------------------
.PHONY: all clean
all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ -I. -MMD -MF $(@:.o=.d) $<

-include $(DEP)

# ------------------------------------------
# Clean
# ------------------------------------------
clean:
	rm -f $(BIN) $(OBJ) $(DEP) *.args.0 *.bc *.i *.ii *.lto_wrapper_args \
	*.ltrans_args *.ltrans0.o *.ltrans.o *.ltrans.out *.res *.s *.temp.o
