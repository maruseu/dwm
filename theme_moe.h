#define BG "#914061"
#define FG "#000000"
#define HL "#ffffff"
#define DMBG "#ffdcff"
#define FONT "M+ 1p heavy:italic:style=heavy:size=11"

static const char *fonts[]          = { FONT };
static const char dmenufont[]       = FONT;
static const char col_bg[]      = BG;
static const char col_fg[]      = FG;
static const char col_hl[]      = HL;
static const char col_dmbg[]    = DMBG;
static const char col_dmfg[]    = FG;
static const char col_dmsb[]    = HL;
static const char col_dmsf[]    = FG;
static const char col_red[]     = "#613243";
static const char col_blu[]     = "#3c4b74";
static const unsigned int alpha = 0x22;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm]  =  { col_fg,   col_bg, col_bg  },
	[SchemeSel]   =  { col_fg,   col_hl, col_dmbg},
	[SchemeWarn]  =  { col_fg,   col_blu,col_red },
	[SchemeUrgent]=	 { col_fg,   col_red,col_red },
};

static const unsigned int alphas[][3]      = {
	[SchemeNorm]  = { OPAQUE, alpha, alpha  },
	[SchemeSel]   = { OPAQUE, alpha, alpha  },
	[SchemeWarn]  = { OPAQUE, alpha, alpha  },
	[SchemeUrgent]= { OPAQUE, alpha, alpha  },
};
