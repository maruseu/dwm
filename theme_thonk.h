#define BG "#222222"
#define FG "#eeeeee"
#define HL "#005577"
//#define FONT "MonteCarlo Fixed 12:size=12"
#define FONT "M+ 1p:style=medium:size=8"

static const char *fonts[]      = { FONT };
static const char dmenufont[]   = FONT;
static const char col_bg[]      = BG;
static const char col_fg[]      = FG;
static const char col_hl[]      = HL;
static const char col_dmbg[]    = BG;
static const char col_dmfg[]    = FG;
static const char col_dmsb[]    = HL;
static const char col_dmsf[]    = FG;
static const char col_erro[]     = "#df4c49";
static const char col_warn[]     = "#b58900";
static const char col_info[]     = "#4adfad";
static const unsigned int alpha = 0xff;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm]  =  { col_fg,   col_bg, col_bg  },
	[SchemeSel]   =  { col_fg,   col_hl, col_hl  },
	[SchemeWarn]  =  { col_warn, col_bg, col_dmbg },
	[SchemeUrgent]=	 { col_erro, col_bg, col_dmbg },
	[SchemeInfo]=	 { col_info, col_bg, col_dmbg },
};

static const unsigned int alphas[][3]      = {
	[SchemeNorm]  = { OPAQUE, alpha, alpha  },
	[SchemeSel]   = { OPAQUE, alpha, alpha  },
	[SchemeWarn]  = { OPAQUE, alpha, alpha  },
	[SchemeUrgent]= { OPAQUE, alpha, alpha  },
	[SchemeInfo]  = { OPAQUE, alpha, alpha  },
};
