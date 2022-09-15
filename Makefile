SCRIPTS_PATH=/usr/local/bin

install:
	cd dwm && make clean install
	cd dwmblocks && make clean install
	cd dmenu && make clean install
	cd st && make clean install
	cp scripts/* $(SCRIPTS_PATH)

clean:
	cd dwm && make clean
	cd dwmblocks && make clean
	cd dmenu && make clean
	cd st && make clean

uninstall:
	cd dwm && make uninstall
	cd dwmblocks && make uninstall
	cd dmenu && make uninstall
	cd st && make uninstall
	rm -f $(SCRIPTS_PATH)/dwm*
	rm -f $(SCRIPTS_PATH)/suckcolors
