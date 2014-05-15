filelist = $(wildcard *.c)
substr_test=$(subst .c, .h, $(filelist))
#aa_test=$(filelist:%.c=nihaoma/%.h)
full_path=/aa/bb/cc/dd/file.c
notdir_test=$(notdir $(full_path))
dir_test=$(dir $(full_path))
aa_test=$(full_path:%.c=nihaoma/%.h)


.PHONY:test


test:
	@ echo $(filelist)
	@ echo $(substr_test)
	@ echo $(aa_test)
	@ echo $(notdir_test)
	@ echo $(dir_test)


