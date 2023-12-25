SCRIPTS_PATH=/usr/local/bin

.PHONY: dwm dwmblocks dmenu dmenu-minimal st scripts

install: dwm dwmblocks dmenu st scripts

dwm:
	cd dwm && make clean install

dwmblocks:
	cd dwmblocks && make clean install

dmenu:
	cd dmenu && make clean install

dmenu-minimal:
	cd dmenu-minimal && make clean install

st:
	cd st && make clean install

scripts:
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
