#/bin/sh
VIM_PATH=/usr/share/vim/vim73

if [ -d doc ]; then
	sudo mv doc/* $VIM_PATH/doc/
#	sudo rm -rf doc
fi

if [ -d plugin ]; then
	sudo mv plugin/* $VIM_PATH/plugin/
#	sudo rm -rf plugin
fi

