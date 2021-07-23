SUBDIRS=7.1book_item 7.2oop_attentions 7.3handle_class

.PHONY: all clean
all: $(SUBDIRS)

#ECHO is used for sub-dir make.
ECHO:
	@echo $(SUBDIRS)

$(SUBDIRS): ECHO
	$(MAKE) -C $@

clean: $(SUBDIRS)
	for d in $(SUBDIRS); do \
	 	$(MAKE) clean -C $$d; \
	done
	