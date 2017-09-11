ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m   := hello1.o
obj-m   := hello2.o

ccflags-y := -Iinc
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif
