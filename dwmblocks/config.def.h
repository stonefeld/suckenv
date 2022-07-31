// Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/* Icon    Command                              Update Interval   Update Signal */
	// HIDDEN
	{ "",    "dwmrecord",                           0,                7              },

	// MISC.
	{ "",    "dwmupdates",                          0,                6              },

	// INTERNET-STATUS
	{ "",    "dwmwifi",                             15,               5              },

	// SYSTEM-MONITOR
	{ "",    "dwmvolume",                           0,                4              },
	{ "",    "dwmbrightness",                       0,                3              },
	{ "",    "dwmbattery",                          10,               2              },

	// DATE-TIME
	{ "",    "dwmdate",                             10,               1              },
};

// Sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "\0";
static unsigned int delimLen = 5;
