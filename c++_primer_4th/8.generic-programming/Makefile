SUBDIRS=8.1intro-template 8.2myqueue

.PHONY: all clean
all: $(SUBDIRS)

#ECHO is used for sub-dir make.
ECHO:
	@echo ""

$(SUBDIRS): ECHO
	$(MAKE) -C $@

clean: $(SUBDIRS)
	for d in $(SUBDIRS); do \
	 	$(MAKE) clean -C $$d; \
	done
	