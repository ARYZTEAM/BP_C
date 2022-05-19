CC = gcc
CFLAGS = 
SUFFIX = 
OBJS = $(patsubst %.c, %.o, $(wildcard *.c))
DEPS = $(wildcard *.h)
ifneq ($(findstring indows, $(OS)),)
	SUFFIX := .exe
else
	SUFFIX := 
endif
BP: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $@$(SUFFIX)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $< $(DEPS)
.PHONY :clean
clean:
	@rm -f *.o *.gch