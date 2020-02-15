#define BASE03    "#002b36"
#define BASE02    "#073642"
#define BASE01    "#586e75"
#define BASE00    "#657b83"
#define BASE0     "#839496"
#define BASE1     "#93a1a1"
#define BASE2     "#eee8d5"
#define BASE3     "#fdf6e3"
#define YELLOW    "#b58900"
#define ORANGE    "#cb4b16"
#define RED       "#dc322f"
#define MAGENTA   "#d33682"
#define VIOLET    "#6c71c4"
#define BLUE      "#268bd2"
#define CYAN      "#2aa198"
#define GREEN     "#859900"
#define FONT "M+ 1p:style=bold:italic:size=9"

static const char *fonts[]      = { FONT };
static const char dmenufont[]   = FONT;
static const char col_dmsb[]    = CYAN;
static const char col_hl[]      = BLUE;
static const char col_warn[]     = YELLOW;
static const char col_erro[]     = MAGENTA;
static const char col_info[]     = VIOLET;

//* Dark
static const char col_bg[]      = BASE03;
static const char col_fg[]      = BASE0;
static const char col_dmbg[]    = BASE02;
static const char col_dmfg[]    = BASE1;
static const char col_dmsf[]    = BASE03;
static const unsigned int alpha = 0x0f2;
// */

/* Light
static const char col_bg[]      = BASE3;
static const char col_fg[]      = BASE00;
static const char col_dmbg[]    = BASE2;
static const char col_dmfg[]    = BASE01;
static const char col_dmsf[]    = BASE3;
static const unsigned int alpha = 0x0e5;
// */

static const char *colors[][4]      = {
	/*               fg      bg      border   */
	[SchemeNorm]  =  { col_fg,   col_bg, col_bg  },
	[SchemeSel]   =  { col_bg,   col_hl, col_dmbg},
	[SchemeWarn]  =  { col_bg,   col_warn,col_dmbg },
	[SchemeUrgent]=	 { col_bg,   col_erro,col_dmbg },
	[SchemeInfo]=	 { col_bg,   col_info,col_dmbg },
};

static const unsigned int alphas[][4]      = {
	[SchemeNorm]  = { alpha, alpha, alpha  },
	[SchemeSel]   = { alpha, alpha, alpha  },
	[SchemeWarn]  = { alpha, alpha, alpha  },
	[SchemeUrgent]= { alpha, alpha, alpha  },
	[SchemeInfo]= { alpha, alpha, alpha  },
};
