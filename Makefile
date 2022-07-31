SCRIPTS_PATH=/usr/local/bin

include config.mk

install:
	cd dwm && make clean install
	cd dwmblocks && make clean install
	cd dmenu && make clean install
	cp scripts/* $(SCRIPTS_PATH)

clean:
	cd dwm && make clean
	cd dwmblocks && make clean
	cd dmenu && make clean

uninstall:
	rm -f /usr/local/bin/dwm
	rm -f /usr/local/bin/dwmblocks
	rm -f /usr/local/bin/dmenu
	rm -f /usr/local/bin/dmenu_run
	rm -f /usr/local/bin/dmenu_path
	rm -f $(SCRIPTS_PATH)/dwm*
