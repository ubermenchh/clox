OBJDIR := ./build

clox: $(OBJDIR)/main.o $(OBJDIR)/memory.o $(OBJDIR)/chunk.o $(OBJDIR)/debug.o
	gcc -o clox $^

# build/main.o: main.c common.h chunk.h debug.h
# 	gcc -c main.c

# build/memory.o: memory.c memory.h common.h
# 	gcc -c memory.c 

# build/chunk.o: chunk.c chunk.h memory.h common.h
# 	gcc -c chunk.c 

# build/debug.o: debug.c debug.h chunk.h common.h
# 	gcc -c debug.c 

$(OBJDIR)/%.o: %.c %.h common.h
	mkdir -p $(@D)
	gcc -c $< -o $@