/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 5;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "MotoyaLMaru:size=11" };
static const char dmenufont[]       = "MotoyaLMaru:size=11";
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#4E4B58";
static const char col_gray3[]       = "#c3c9b0";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#c3c9b0";
//static const char col_cyan[]        = "#f1b0c1";
static const unsigned int baralpha = 0x70;
static const unsigned int borderalpha = 0x70;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray1, col_cyan,  col_cyan  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
/* symbol     arrange function */
{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* functions */
void shiftview(const Arg *arg) {
	Arg shifted;
	if(arg->i > 0) // left circular shift
		shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
		   | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));
	else // right circular shift
		shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
		   | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);
	view(&shifted);
}

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon , "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray1, "-x", "10", "-y", "2", "-w", "1346", NULL };
static const char *animecmd[] = { "anime.sh", "-i", "-l", "20", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray1, "-x", "10", "-y", "2", "-w", "1346", NULL };
static const char *termcmd[]  = { "urxvtc", NULL };

static Key keys[] = {
	/* modifier           key               function        argument */
	{ MODKEY,             XK_d,             spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,   XK_a,             spawn,          {.v = animecmd } },
	{ MODKEY,             XK_Return,        spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,   XK_b,             togglebar,      {0} },
	{ MODKEY,             XK_j,             focusstack,     {.i = +1 } },
	{ MODKEY,             XK_k,             focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_o,             incnmaster,     {.i = +1 } },
	{ MODKEY,             XK_o,             incnmaster,     {.i = -1 } },
	{ MODKEY,             XK_h,             setmfact,       {.f = -0.05} },
	{ MODKEY,             XK_l,             setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,   XK_minus,         incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_equal,         incrgaps,       {.i = +1 } },
	{ MODKEY,             XK_g,             togglegaps,     {0} },
	{ MODKEY|Mod1Mask,              XK_h,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|Mod1Mask,              XK_j,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|Mod1Mask,              XK_k,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|Mod1Mask,              XK_l,      setlayout,      {0} },
	{ MODKEY,             XK_space,         zoom,           {0} },
	{ MODKEY,             XK_Tab,           view,           {0} },
	{ MODKEY|ShiftMask,   XK_q,             killclient,     {0} },
	{ MODKEY|ShiftMask,   XK_space,         togglefloating, {0} },
	{ MODKEY,             XK_bracketleft,   focusmon,       {.i = -1 } },
	{ MODKEY,             XK_bracketright,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_bracketleft,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_bracketright,  tagmon,         {.i = +1 } },
	{ MODKEY,             XK_i,             spawn,          SHCMD("urxvtc -e watch -c -n1 ~/.scripts/animeChart2.lua ansib") },
	{ MODKEY|ControlMask, XK_l,             spawn,          SHCMD("maim /tmp/lock.png ; convert /tmp/lock.png  channel RGB -filter Gaussian -resize 2% -define filter:sigma=1 -resize 5100% /tmp/lock.png ; i3lock -i /tmp/lock.png") },
	{ MODKEY|ShiftMask,   XK_s,             spawn,          SHCMD("rm -f /tmp/clip.png ; maim -s /tmp/clip.png -u ; xclip -selection clipboard -t image/png -i /tmp/clip.png") },
	{ MODKEY|ShiftMask,   XK_e,             spawn,          SHCMD("~/.scripts/logout.sh") },
	{ MODKEY,             XK_p,             spawn,          SHCMD("mpc toggle") },
	{ MODKEY|ShiftMask,   XK_comma,         spawn,          SHCMD("mpc volume -5") },
	{ MODKEY|ShiftMask,   XK_period,        spawn,          SHCMD("mpc volume +5") },
	{ MODKEY,             XK_comma,         spawn,          SHCMD("mpc prev") },
	{ MODKEY,             XK_period,        spawn,          SHCMD("mpc next") },
	{ MODKEY,             XK_m,             spawn,          SHCMD("urxvtc -e ncmpcpp") },
	{ MODKEY,             XK_t,             spawn,          SHCMD("urxvtc -e tremc") },
	{ MODKEY,             XK_f,             spawn,          SHCMD("urxvtc -e ranger") },
	{ MODKEY,             XK_minus,         spawn,          SHCMD("dvol") },
	{ MODKEY,             XK_equal,         spawn,          SHCMD("dvol inc") },
	{ MODKEY,             XK_0,             view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,   XK_0,             tag,            {.ui = ~0 } },
	TAGKEYS(              XK_1,                             0)
	TAGKEYS(              XK_2,                             1)
	TAGKEYS(              XK_3,                             2)
	TAGKEYS(              XK_4,                             3)
	TAGKEYS(              XK_5,                             4)
	TAGKEYS(              XK_6,                             5)
	TAGKEYS(              XK_7,                             6)
	TAGKEYS(              XK_8,                             7)
	TAGKEYS(              XK_9,                             8)
	{ MODKEY|ShiftMask,   XK_r,             quit,           {0} },
//	{ MODKEY,             XK_t,             setlayout,      {.v = &layouts[0]} },
//	{ MODKEY,             XK_f,             setlayout,      {.v = &layouts[1]} },
//	{ MODKEY,             XK_m,             setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,             XK_space,         setlayout,      {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("mpc toggle") },
	{ ClkStatusText,        0,              Button4,        spawn,          SHCMD("vol inc") },
	{ ClkStatusText,        0,              Button5,        spawn,          SHCMD("vol") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkWinTitle,          0,              Button4,        shiftview,      {.i = -1} },
	{ ClkWinTitle,          0,              Button5,        shiftview,      {.i = +1} },
	{ ClkLtSymbol,          0,              Button4,        shiftview,      {.i = -1} },
	{ ClkLtSymbol,          0,              Button5,        shiftview,      {.i = +1} },
	{ ClkTagBar,            0,              Button4,        shiftview,      {.i = -1} },
	{ ClkTagBar,            0,              Button5,        shiftview,      {.i = +1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

