V = C

$(V) : $(V).c
	cc $(V).c -o $(V)

.PHONY : clean
clean :
	rm $(V)
