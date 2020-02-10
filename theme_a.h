#define BG "#000000"
#define FG "#ffffff"
#define HL "#f1c0b0"
#define DMBG "#294f54"
#define DMHL "#ffe6e1"
#define FONT "monospace:size=10"

static const char *fonts[]      = { FONT };
static const char dmenufont[]   = FONT;
static const char col_bg[]      = BG;
static const char col_fg[]      = FG;
static const char col_hl[]      = HL;
static const char col_dmbg[]    = DMBG;
static const char col_dmfg[]    = FG;
static const char col_dmsb[]    = DMHL;
static const char col_dmsf[]    = BG;
static const char col_red[]     = "#613243";
static const char col_blu[]     = "#3c4b74";
static const unsigned int alpha = 0x70;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm] = {   col_fg,   col_bg, col_bg  },
	[SchemeSel]  = {   col_bg,   col_hl, col_dmsb},
	[SchemeWarn]  =  { col_bg,   col_blu,col_red },
	[SchemeUrgent]=	 { col_fg,   col_red,col_red },
};

static const unsigned int alphas[][3]      = {
	[SchemeNorm]  = { OPAQUE, alpha, alpha  },
	[SchemeSel]   = { OPAQUE, alpha, alpha  },
	[SchemeWarn]  = { OPAQUE, alpha, alpha  },
	[SchemeUrgent]= { OPAQUE, alpha, alpha  },
};