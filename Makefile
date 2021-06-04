SUBDIRS=helloworld using_namespace string_vector  

.PHONY: all clean
all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean: $(SUBDIRS)
	$(MAKE) -C $^ clean