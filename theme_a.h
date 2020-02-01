static const char *fonts[]          = { "07LightNovelPOP:size=10" };
static const char dmenufont[]       = "07LightNovelPOP:size=10";
static const char col_bg[]      = "#000000";
static const char col_dmbg[]    = "#294f54";
static const char col_fg[]      = "#ffffff";
static const char col_dmhl[]    = "#ffe6e1";
static const char col_hl[]      = "#f1c0b0";
static const unsigned int alpha = 0x70;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm] = {   col_fg,   col_bg, col_bg    },
	[SchemeSel]  = {   col_bg,   col_hl, col_dmhl  },
};

static const unsigned int alphas[][3]      = {
	[SchemeNorm] = { OPAQUE, alpha,  OPAQUE },
	[SchemeSel]  = { OPAQUE, alpha,  OPAQUE },
};
