POSTS=aaron.html index.html
index.html: $(POSTS)
%.bin: %.c
	cc -static -o $@ $<
%.html: %.bin
	./$< > $@
clean:
	rm -f *.bin *.html
