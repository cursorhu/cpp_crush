SUBDIRS=1.helloworld 2.using_namespace 3.squential_container 4.associative_containers 5.Generic Algorithms

.PHONY: all clean
all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

clean: $(SUBDIRS)
	$(MAKE) -C $^ clean