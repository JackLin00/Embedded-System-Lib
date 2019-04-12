include ../make.rule
OBJS = Sem.o

all:$(OBJS)
$(OBJS):%.o:%.c
	$(CC) -o $(OBJDIR)/$@ -c $< $(CFLAGS)



