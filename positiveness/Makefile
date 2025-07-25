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

override BIN := positiveness.$(SHLIB_EXT)
override SRC := positiveness.c positiveness_activation.c positiveness_model.c positiveness_tensor.c positiveness_weights.c
override OBJ := $(SRC:%=%.o)
override DEP := $(SRC:%=%.d)
override CC  := $(or $(if $(filter default,$(origin CC)),,$(CC)),gcc)

override undefine WITH_CLANG_CC
USE_CLANG = $(eval USE_CLANG := $$(shell \
  printf '#ifdef __clang__\n1\n#endif\n' | $$(CC) -E -P -xc -))$(USE_CLANG)

override BASE_CFLAGS := $(strip -fPIC $(SANITIZE:%=-fsanitize=%)          \
  -O$(if $(DEBUG),$(if $(USE_CLANG),0,g) -g3,fast -DNDEBUG) -Wall -Wextra \
  $(if $(USE_CLANG),                                                      \
    -Weverything                                                          \
    -Wno-c++-compat                                                       \
    -Wno-c++98-compat                                                     \
    -Wno-disabled-macro-expansion                                         \
    -Wno-fixed-enum-extension                                             \
    -Wno-gnu-empty-struct                                                 \
    -Wno-gnu-statement-expression                                         \
    -Wno-gnu-statement-expression-from-macro-expansion                    \
    -Wno-gnu-zero-variadic-macro-arguments                                \
    -Wno-switch-enum                                                      \
    -Wno-unknown-warning-option                                           \
    -Wno-unsafe-buffer-usage                                              \
    -Wno-used-but-marked-unused)                                          \
  -Wformat=2 -Wno-declaration-after-statement -Wno-unknown-pragmas)

ifeq (command line,$(origin CFLAGS))
override USER_CFLAGS := $(CFLAGS)
override EXTRA_CFLAGS := $(strip                \
  $(if $(filter -save-temps,$(USER_CFLAGS)),    \
    $(if $(USE_CLANG),                          \
      -Wno-constant-logical-operand             \
      -Wno-gnu-line-marker -pipe),              \
    -pipe)                                      \
  $(filter-out -flto -pipe,$(USER_CFLAGS)))
else
override undefine USER_CFLAGS
override EXTRA_CFLAGS := -pipe
endif

ifeq (,$(filter -fno-lto,$(USER_CFLAGS)))
override BASE_CFLAGS := -flto $(BASE_CFLAGS)
endif

override CFLAGS := $(BASE_CFLAGS) $(EXTRA_CFLAGS)
override LIBS   := -lm

$(BIN): $(OBJ)
	$(CC) -shared $(CFLAGS) -o $@ $^ $(LIBS)

%.c.o: %.c
	$(CC) $(CFLAGS) -o $@ -c -I. -MMD -MQ $@ -MF $<.d $<

-include $(DEP)

.PHONY: clean
clean: override WHAT = $(wildcard \
	$(BIN) $(OBJ) $(DEP) *.args.0 *.bc *.i *.ii *.lto_wrapper_args \
	*.ltrans_args *.ltrans0.o *.ltrans.o *.ltrans.out *.res *.s *.temp.o)
clean:; $(if $(WHAT),$(RM) $(WHAT),@:)
