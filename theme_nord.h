#define BG "#2E3440"
#define FG "#D8DEE9"
#define HL "#5E81AC"


#define FONT "M+ 1p heavy:style=heavy:size=8"

static const char *fonts[]          = { FONT };
static const char dmenufont[]       = FONT;
static const char col_bg[]      = BG;
static const char col_fg[]      = FG;
static const char col_hl[]      = HL;
static const char col_dmbg[]    = BG;
static const char col_dmfg[]    = FG;
static const char col_dmsb[]    = HL;
static const char col_dmsf[]    = FG;
static const char col_erro[]     = "#613243";
static const char col_warn[]     = "#b58900";
static const char col_info[]     = "#3c4b74";
static const unsigned int alpha = 0x44;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm]  =  { col_fg,   col_bg, col_bg  },
	[SchemeSel]   =  { col_bg,   col_hl, col_dmsb},
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
