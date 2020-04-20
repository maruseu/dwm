/* appearance */
#include <X11/XF86keysym.h>
#include "theme_sol.h"
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 5;       /* snap pixel */
//static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
//static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
//static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
//static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 40;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

/* tagging */
//static const char *tags[] = {"一","二","三","四","五","六","七","八","九" };
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
//	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "URxvt",    NULL,       "Music",    0,            1,           -1 },
	{ "URxvt",    NULL,       "tremc",    0,            1,           -1 },
	{ "URxvt",    NULL,       "Settings",    0,            1,           -1 },
	{ "Pavucontrol",NULL,     NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "×",       tile },    /* first entry is default */
	{ "〇",      NULL },    /* no layout function means floating behavior */
	{ "[M]",     monocle },
};
#include "bindings.h"
