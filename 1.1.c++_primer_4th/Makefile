# manually appinted subdirs
SUBDIRS=1.helloworld 2.using_namespace 3.squential_container \
		4.associative_containers 5.generic_algorithms 6.class \
		7.object-oriented 8.generic-programming

# get all the subdir of current working directory                                                                                                                        
#SUBDIRS=$(shell ls -l ${PWD} |awk '/^d/ {print $NF}')

.PHONY: all clean
all: $(SUBDIRS)

#ECHO is used for calling sub-dir makefile one by one.
ECHO:
	@echo ""

$(SUBDIRS): ECHO
	$(MAKE) -C $@

#remove by calling each sub-dir's makefile 
clean: $(SUBDIRS)
	for d in $(SUBDIRS); do \
	 	$(MAKE) clean -C $$d; \
	done

	