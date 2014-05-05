obj-m := seq.o
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	    $(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	    $(RM) *.o *.mod.c *.ko *.symvers *.markers *.order
