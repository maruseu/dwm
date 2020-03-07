/* key definitions */
#define MODKEY Mod4Mask
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, 
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

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

/* commands */
static const char *termcmd[]  = { "urxvtc", NULL };
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon ,
	"-fn", dmenufont, "-nb", col_dmbg, "-nf", col_dmfg, "-sb", col_dmsb, "-sf", col_dmsf,
	"-x", "15","-y", "5","-w", "1336", NULL  };
//	NULL  };

static const char *animecmd[] = { "/home/maruseu/.scripts/anime.sh", "-i", "-l", "20",
	"-fn", dmenufont, "-nb", col_dmbg, "-nf", col_dmfg, "-sb", col_dmsb, "-sf", col_dmsf,
	"-x", "15","-y", "5","-w", "1336", NULL  };
//	NULL  };

static const char *logoutcmd[]= { "/home/maruseu/.scripts/logout.sh", "-i",
	"-fn", dmenufont, "-nb", col_dmbg, "-nf", col_dmfg, "-sb", col_dmsb, "-sf", col_dmsf,
	"-x", "15","-y", "5","-w", "1336", NULL  };
//	NULL  };

static const char *displaycmd[]= { "/home/maruseu/.scripts/menudisplay.sh", "-i",
	"-fn", dmenufont, "-nb", col_dmbg, "-nf", col_dmfg, "-sb", col_dmsb, "-sf", col_dmsf,
	"-x", "15","-y", "5","-w", "1336", NULL  };
//	NULL  };

static Key keys[] = {
	/* modifier           key               function        argument */
	{ MODKEY|ShiftMask,   XK_s,             spawn,          SHCMD("rm -f /tmp/ram/clip.png ; maim -s /tmp/ram/clip.png -u ; xclip -selection clipboard -t image/png -i /tmp/ram/clip.png") },
	{ MODKEY|ShiftMask,   XK_e,             spawn,          {.v = logoutcmd } },
	{ MODKEY|ShiftMask,   XK_i,             spawn,          SHCMD("~/.scripts/ibus-ch.sh") },
	{ MODKEY,             XK_m,             spawn,          SHCMD("urxvtc --title Music -e ncmpcpp") },
	{ MODKEY,             XK_t,             spawn,          SHCMD("urxvtc -e tremc") },
	{ MODKEY,             XK_f,             spawn,          SHCMD("urxvtc -e ranger") },
	{ MODKEY,             XK_i,             spawn,          SHCMD("urxvtc -e watch -c -n1 ~/.scripts/animeChart2.lua ansib") },
	{ MODKEY,             XK_d,             spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,   XK_a,             spawn,          {.v = animecmd } },
	{ MODKEY,             XK_Return,        spawn,          {.v = termcmd } },
	/* navigation bindings */
	{ MODKEY|ShiftMask,   XK_minus,         incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_equal,         incrgaps,       {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_g,             defaultgaps,    {0} },
	{ MODKEY,             XK_g,             togglegaps,     {0} },
	{ MODKEY,             XK_b,             togglebar,      {0} },
	{ MODKEY,             XK_o,             incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_o,             incnmaster,     {.i = -1 } },
	{ MODKEY,             XK_h,             setmfact,       {.f = -0.05} },
	{ MODKEY,             XK_l,             setmfact,       {.f = +0.05} },
	{ MODKEY,             XK_space,         zoom,           {0} },
	{ MODKEY,             XK_Tab,           view,           {0} },
	{ MODKEY|ShiftMask,   XK_q,             killclient,     {0} },
	{ MODKEY|ShiftMask,   XK_space,         togglefloating, {0} },
	STACKKEYS(            MODKEY,                           focus)
	STACKKEYS(            MODKEY|ShiftMask,                 push)
	/* tags bindings */
	{ MODKEY,             XK_bracketleft,   focusmon,       {.i = -1 } },
	{ MODKEY,             XK_bracketright,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_bracketleft,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,   XK_bracketright,  tagmon,         {.i = +1 } },
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
	// T420 _\|/_ fn and media keys
	{ 0,             XF86XK_Display,               spawn,          {.v = displaycmd } },
	{ 0,             XF86XK_TouchpadToggle,        spawn,          SHCMD("~/.scripts/toggle-touchpad.sh") },
	{ 0,             XF86XK_ScreenSaver,           spawn,          SHCMD("maim /tmp/ram/lock.png ; convert /tmp/ram/lock.png  channel RGB -filter Gaussian -resize 2% -define filter:sigma=1 -resize 5200% /tmp/ram/lock.png ; i3lock -i /tmp/ram/lock.png") },
	{ 0,             XF86XK_Launch1,               spawn,          SHCMD("urxvtc --title Settings -e ~/Documents/m.a.r.u/maruSettings.sh") },
	{ 0,             XF86XK_AudioStop,             spawn,          SHCMD("mpc stop") },
	{ 0,             XF86XK_AudioPlay,             spawn,          SHCMD("mpc toggle") },
	{ MODKEY,        XF86XK_AudioLowerVolume,      spawn,          SHCMD("mpc volume -5") },
	{ MODKEY,        XF86XK_AudioRaiseVolume,      spawn,          SHCMD("mpc volume +5") },
	{ 0,             XF86XK_AudioPrev,             spawn,          SHCMD("mpc prev") },
	{ 0,             XF86XK_AudioNext,             spawn,          SHCMD("mpc next") },
	{ 0,             XF86XK_AudioLowerVolume,      spawn,          SHCMD("dvol") },
	{ 0,             XF86XK_AudioRaiseVolume,      spawn,          SHCMD("dvol inc") },
	{ 0,             XF86XK_AudioMute,             spawn,          SHCMD("dvol toggle") },
	{ 0,             XF86XK_AudioMicMute,          spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },

	{ MODKEY,        XK_p,                         spawn,          {.v = displaycmd } },
	//{ 0,             XF86XK_ScreenSaver,           spawn,          SHCMD("maim /tmp/ram/lock.png ; convert /tmp/ram/lock.png  channel RGB -filter Gaussian -resize 2% -define filter:sigma=1 -resize 5200% /tmp/ram/lock.png ; i3lock -i /tmp/ram/lock.png") },
	{ 0,             XF86XK_Explorer,              spawn,          SHCMD("urxvtc --title Settings -e ~/Documents/m.a.r.u/maruSettings.sh") },
	{ 0,             XF86XK_Tools,                 spawn,          SHCMD("mpc stop") },
	{ MODKEY|Mod1Mask,XK_minus,                    spawn,          SHCMD("mpc volume -5") },
	{ MODKEY|Mod1Mask,XK_equal,                    spawn,          SHCMD("mpc volume +5") },
	{ MODKEY,        XK_minus,                     spawn,          SHCMD("dvol") },
	{ MODKEY,        XK_equal,                     spawn,          SHCMD("dvol inc") },
	{ MODKEY|ShiftMask,XK_m,                       spawn,          SHCMD("dvol toggle") },
	{ MODKEY|Mod1Mask,XK_m,                        spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },

	{ MODKEY|ShiftMask,   XK_r,             quit,           {0} },
		/* commands that i will never use but i dont want to see unused warnings
		during compiling so i defined them with convoluted bindings */
		{ MODKEY|Mod1Mask,    XK_h,             setlayout,      {.v = &layouts[0]} },
		{ MODKEY|Mod1Mask,    XK_j,             setlayout,      {.v = &layouts[1]} },
		{ MODKEY|Mod1Mask,    XK_k,             setlayout,      {.v = &layouts[2]} },
		{ MODKEY|Mod1Mask,    XK_l,             setlayout,      {0} },
		{ MODKEY|Mod1Mask|ShiftMask,    XK_q,      incrigaps,      {.i = +1 } },
		{ MODKEY|Mod1Mask|ShiftMask,    XK_w,      incrogaps,      {.i = +1 } },
		{ MODKEY|Mod1Mask|ShiftMask,    XK_e,      incrihgaps,     {.i = +1 } },
		{ MODKEY|Mod1Mask|ShiftMask,    XK_r,      incrivgaps,     {.i = +1 } },
		{ MODKEY|Mod1Mask|ShiftMask,    XK_t,      incrohgaps,     {.i = +1 } },
		{ MODKEY|Mod1Mask|ShiftMask,    XK_y,      incrovgaps,     {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          SHCMD("pavucontrol") },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("mpc toggle") },
	{ ClkStatusText,        0,              Button4,        spawn,          SHCMD("dvol inc") },
	{ ClkStatusText,        0,              Button5,        spawn,          SHCMD("dvol") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        shiftview,      {.i = -1} },
	{ ClkTagBar,            0,              Button5,        shiftview,      {.i = +1} },
	{ ClkWinTitle,          0,              Button4,        shiftview,      {.i = -1} },
	{ ClkWinTitle,          0,              Button5,        shiftview,      {.i = +1} },
	{ ClkLtSymbol,          0,              Button4,        shiftview,      {.i = -1} },
	{ ClkLtSymbol,          0,              Button5,        shiftview,      {.i = +1} },
	{ ClkTagBar,            MODKEY,         Button4,        shiftview,      {.i = -1} },
	{ ClkTagBar,            MODKEY,         Button5,        shiftview,      {.i = +1} },
	{ ClkLtSymbol,          MODKEY,         Button4,        shiftview,      {.i = -1} },
	{ ClkLtSymbol,          MODKEY,         Button5,        shiftview,      {.i = +1} },
	{ ClkStatusText,        MODKEY,         Button4,        shiftview,      {.i = -1} },
	{ ClkStatusText,        MODKEY,         Button5,        shiftview,      {.i = +1} },
	{ ClkWinTitle,          MODKEY,         Button4,        shiftview,      {.i = -1} },
	{ ClkWinTitle,          MODKEY,         Button5,        shiftview,      {.i = +1} },
	{ ClkClientWin,         MODKEY,         Button4,        shiftview,      {.i = -1} },
	{ ClkClientWin,         MODKEY,         Button5,        shiftview,      {.i = +1} },
	{ ClkRootWin,           MODKEY,         Button4,        shiftview,      {.i = -1} },
	{ ClkRootWin,           MODKEY,         Button5,        shiftview,      {.i = +1} },
}; 


