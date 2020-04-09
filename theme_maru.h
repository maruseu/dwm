#define BG "#222222"
#define FG "#ffffff"
#define HL "#FFFFFF"
#define DMBG "#2E3440"
//#define FONT "MonteCarlo Fixed 12:size=12"
//#define FONT "MisakiGothic2nd:size=6"
#define FONT "M+ 1p:style=medium:size=8"

static const char *fonts[]      = { FONT };
static const char dmenufont[]   = FONT;
static const char col_bg[]      = BG;
static const char col_fg[]      = FG;
static const char col_hl[]      = HL;
static const char col_dmbg[]    = DMBG;
static const char col_dmfg[]    = FG;
static const char col_dmsb[]    = HL;
static const char col_dmsf[]    = BG;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm]  =  { col_fg,   col_bg, col_bg  },
	[SchemeSel]   =  { col_bg,   col_hl, col_dmbg},
};

