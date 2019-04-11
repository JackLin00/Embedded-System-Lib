include ../make.rule
OBJS = FileClass.o


all:$(OBJS)
$(OBJS):%.o:%.c
	$(CC) -o $(OBJDIR)/$@ -c $^ $(CFLAGS)


	