SUBDIRS=6.1screen 6.2student 6.3mystring 6.4smart_ptr

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
	