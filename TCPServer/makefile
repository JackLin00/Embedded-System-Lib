OBJS = TCPServer.o

all:$(OBJS)
$(OBJS):%.o:%.c
	gcc -c $< -o $(OBJDIR)/$@ $(CFLAGS) -g

clean:
	$(RM) $(OBJDIR)/$(OBJS)