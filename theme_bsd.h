#define BG "#000000"
#define FG "#ffffff"
#define HL "#ff72a3"
#define DMBG "#2E3440"
//#define FONT "MonteCarlo Fixed 12:size=12"
#define FONT "M+ 1p:style=heavy:size=8"

static const char *fonts[]      = { FONT };
static const char dmenufont[]   = FONT;
static const char col_bg[]      = BG;
static const char col_fg[]      = FG;
static const char col_hl[]      = HL;
static const char col_dmbg[]    = DMBG;
static const char col_dmfg[]    = FG;
static const char col_dmsb[]    = HL;
static const char col_dmsf[]    = BG;
static const char col_erro[]     = "#f88377";
static const char col_warn[]     = "#f0fb79";
static const char col_info[]     = "#98d4ff";
static const unsigned int alpha = 0xcc;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm]  =  { col_fg,   col_bg, col_bg  },
	[SchemeSel]   =  { col_bg,   col_hl, col_hl},
	[SchemeWarn]  =  { col_bg,   col_warn,col_dmbg },
	[SchemeUrgent]=	 { col_bg,   col_erro,col_dmbg },
	[SchemeInfo]=	 { col_fg,   col_info,col_dmbg },
};

static const unsigned int alphas[][3]      = {
	[SchemeNorm]  = { OPAQUE, alpha, alpha  },
	[SchemeSel]   = { OPAQUE, alpha, alpha  },
	[SchemeWarn]  = { OPAQUE, alpha, alpha  },
	[SchemeUrgent]= { OPAQUE, alpha, alpha  },
	[SchemeInfo]  = { OPAQUE, alpha, alpha  },
};
