static const char *fonts[]          = { "MotoyaLMaru:size=11" };
static const char dmenufont[]       = "MotoyaLMaru:size=11";
static const char col_bg[]      = "#2E3440";
static const char col_dmbg[]    = "#2E3440";
static const char col_fg[]      = "#D8DEE9";
static const char col_dmhl[]    = "#5E81AC";
static const char col_hl[]      = "#5E81AC";
static const unsigned int alpha = 0x70;
static const char *colors[][3]      = {
	/*               fg      bg      border   */
	[SchemeNorm] = {   col_fg,   col_bg, col_bg    },
	[SchemeSel]  = {   col_bg,   col_hl, col_dmhl  },
};
//*
static const unsigned int alphas[][3]      = {
	[SchemeNorm] = { OPAQUE, alpha,  OPAQUE },
	[SchemeSel]  = { OPAQUE, alpha,  OPAQUE },
};//*/
/*
static const unsigned int alphas[][3]      = {
	[SchemeNorm] = { OPAQUE,    alpha,   alpha },
	[SchemeSel]  = { OPAQUE,    alpha,   alpha },
};//*/

