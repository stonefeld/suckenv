/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static const char *prompt = NULL;           /* -p  option; prompt to the left of input field */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"Source Code Pro:size=12:antialias=true:autohint=true",
	"Material Design Icons-Regular:size=14:antialias=true:autohint=true",
	"JoyPixels:size=12:antialias=true:autohint=true",
};

#include "../themes/colors.h"
static const char *colors[SchemeLast][2] = {
	/*                        fg             bg            */
	[SchemeNorm]          = { dmenu_norm_fg, dmenu_norm_bg },
	[SchemeSel]           = { dmenu_sel_fg,  dmenu_sel_bg  },
	[SchemeOut]           = { "#000000",     "#00ffff"     },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/* -h option; minimum height of a menu line */
static unsigned int lineheight = 30;
static unsigned int min_lineheight = 8;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " /?\"&[]";
