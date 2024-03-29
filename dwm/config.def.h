/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx        = 2;        /* border pixel of windows */
static const unsigned int snap            = 8;        /* snap pixel */
static const int showbar                  = 1;        /* 0 means no bar */
static const int topbar                   = 1;        /* 0 means bottom bar */
static const char *fonts[]                = {
	"Fantasque Sans Mono:style=Bold:size=10:antialias=true:autohint=true",
	"Material Design Icons:size=12:antialias=true:autohint=true",
};

/* systray */
static const unsigned int systraypinning  = 0;        /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft   = 0;        /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing  = 5;        /* systray spacing */
static const unsigned int systraypadding  = 5;
static const int systraypinningfailfirst  = 1;        /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray              = 1;        /* 0 means no systray */

/* statuspadding */
static const int horizpadbar              = 12;       /* horizontal padding for statusbar */
static const int vertpadbar               = 12;       /* vertical padding for statusbar */

/* uselessgaps */
static const unsigned int gappx           = 10;       /* gaps between windows */

/* underline */
static const unsigned int ulinepad        = 5;        /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke     = 3;        /* thickness / height of the underline */
static const unsigned int ulinevoffset    = 0;        /* how far above the bottom of the bar the line should appear */
static const int ulineall                 = 0;        /* 1 to show underline on all tags, 0 for just the active ones */

/* colors */
#include "../themes/colors.h"
static const char *colors[][4]      = {
	/*                    fg            bg            border           float           */
	[SchemeNorm]      = { dwm_norm_fg,  dwm_norm_bg,  dwm_norm_border, dwm_norm_border },
	[SchemeSel]       = { dwm_sel_fg,   dwm_sel_bg,   dwm_sel_border,  suck_violet     },
	[SchemeBgBlack]   = { dwm_norm_bg,  suck_black,   NULL,            NULL,           },
	[SchemeFgBlack]   = { suck_black,   dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgRed]     = { dwm_norm_bg,  suck_red,     NULL,            NULL,           },
	[SchemeFgRed]     = { suck_red,     dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgGreen]   = { dwm_norm_bg,  suck_green,   NULL,            NULL,           },
	[SchemeFgGreen]   = { suck_green,   dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgYellow]  = { dwm_norm_bg,  suck_yellow,  NULL,            NULL,           },
	[SchemeFgYellow]  = { suck_yellow,  dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgBlue]    = { dwm_norm_bg,  suck_blue,    NULL,            NULL,           },
	[SchemeFgBlue]    = { suck_blue,    dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgMagenta] = { dwm_norm_bg,  suck_magenta, NULL,            NULL,           },
	[SchemeFgMagenta] = { suck_magenta, dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgCyan]    = { dwm_norm_bg,  suck_cyan,    NULL,            NULL,           },
	[SchemeFgCyan]    = { suck_cyan,    dwm_norm_bg,  NULL,            NULL,           },
	[SchemeBgWhite]   = { dwm_norm_bg,  suck_white,   NULL,            NULL,           },
	[SchemeFgWhite]   = { suck_white,   dwm_norm_bg,  NULL,            NULL,           },
};

/* tagging */
static const char *tags[] = { "󰆋", "󰆍", "󰆍", "󰆍", "󰉋", "󰇮", "󰆦", "󰊠", "󰖷" };

/* tag colors */
static const char *tagsel[][2] = {
	/* fg           bg */
	{ suck_blue,    dwm_norm_bg },
	{ suck_red,     dwm_norm_bg },
	{ suck_yellow,  dwm_norm_bg },
	{ suck_purple,  dwm_norm_bg },
	{ suck_magenta, dwm_norm_bg },
	{ suck_green,   dwm_norm_bg },
	{ suck_cyan,    dwm_norm_bg },
	{ suck_orange,  dwm_norm_bg },
	{ suck_violet,  dwm_norm_bg },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                  instance      title       tags mask     isfloating   monitor */
	{ "Floating",             NULL,         NULL,       0,            1,           -1 },
	{ "MPlayer",              NULL,         NULL,       0,            1,           -1 },
	{ "Nm-connection-editor", NULL,         NULL,       0,            1,           -1 },
	{ "Pavucontrol",          NULL,         NULL,       0,            1,           -1 },
	{ "Pcmanfm",              NULL,         NULL,       0,            1,           -1 },
	{ "Pinentry-gtk-2",       NULL,         NULL,       0,            1,           -1 },
	{ NULL,                   "Msgcompose", NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },

	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_m,      togglefullscr,  {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },

	{ MODKEY|ShiftMask,             XK_w,      killclient,     {0} },
	{ MODKEY,                       XK_q,      focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q,      tagmon,         {.i = +1 } },

	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },

	{ MODKEY|ControlMask,           XK_j,      moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_k,      moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_l,      moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY|ControlMask,           XK_h,      moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ControlMask|ShiftMask, XK_j,      moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ControlMask|ShiftMask, XK_k,      moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ControlMask|ShiftMask, XK_l,      moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ControlMask|ShiftMask, XK_h,      moveresize,     {.v = "0x 0y -25w 0h" } },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          SHCMD("dmlogout") },
	{ MODKEY|ControlMask,           XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },

	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
};

