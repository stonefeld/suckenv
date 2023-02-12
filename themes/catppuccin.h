/*********************/
/* CATPPUCCIN COLORS */
/*********************/
#define ROSEWATER "#f5e0dc"
#define FLAMINGO  "#f2cdcd"
#define PINK      "#f5c2e7"
#define MAUVE     "#cba6f7"
#define RED       "#f38ba8"
#define MAROON    "#eba0ac"
#define PEACH     "#fab387"
#define YELLOW    "#f9e2af"
#define GREEN     "#a6e3a1"
#define TEAL      "#94e2d5"
#define SKY       "#89dceb"
#define SAPPHIRE  "#74c7ec"
#define BLUE      "#89b4fa"
#define LAVENDER  "#b4befe"
#define TEXT      "#cdd6f4"
#define SUBTEXT1  "#bac2de"
#define SUBTEXT0  "#a6adc8"
#define OVERLAY2  "#9399b2"
#define OVERLAY1  "#7f849c"
#define OVERLAY0  "#6c7086"
#define SURFACE2  "#585b70"
#define SURFACE1  "#45475a"
#define SURFACE0  "#313244"
#define BASE      "#1e1e2e"
#define MANTLE    "#181825"
#define CRUST     "#11111b"

/******************/
/* GENERAL COLORS */
/******************/
static const char suck_black[]       = SURFACE1;
static const char suck_red[]         = RED;
static const char suck_orange[]      = PEACH;
static const char suck_green[]       = GREEN;
static const char suck_yellow[]      = YELLOW;
static const char suck_blue[]        = BLUE;
static const char suck_magenta[]     = PINK;
static const char suck_purple[]      = LAVENDER;
static const char suck_violet[]      = MAUVE;
static const char suck_cyan[]        = TEAL;
static const char suck_white[]       = SUBTEXT1;

/****************/
/* DMENU COLORS */
/****************/
static const char dmenu_norm_fg[]   = TEXT;
static const char dmenu_norm_bg[]   = BASE;
static const char dmenu_sel_fg[]    = BASE;
static const char dmenu_sel_bg[]    = BLUE;

/**************/
/* DWM COLORS */
/**************/
static const char dwm_norm_fg[]     = OVERLAY0;
static const char dwm_norm_bg[]     = BASE;
static const char dwm_norm_border[] = BASE;
static const char dwm_sel_fg[]      = SKY;
static const char dwm_sel_bg[]      = SURFACE0;
static const char dwm_sel_border[]  = BLUE;

/*************/
/* ST COLORS */
/*************/
static const char *colorname[] = {
	SURFACE1, RED, GREEN, YELLOW,
	BLUE, PINK, TEAL, SUBTEXT1,

	SURFACE2, RED, GREEN, YELLOW,
	BLUE, PINK, TEAL, SUBTEXT0,

	[255] = 0,
	TEXT, BASE,
};
