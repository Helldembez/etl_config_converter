//
// Created by Helldembez on 19-10-2021.
//
#include <stdio.h>

typedef struct {
    char *key;
    char *value;
} Map;

typedef struct {
    char *key;
    char *value;
    Map *valueMapping;
    int vmSize;
    char *descText;
} CVARMapping;

static Map booleanInverse[] = {{"0", "1"},
                               {"1", "0"}};
static Map depthBitsValueMapping[] = {{"*", "24"}};
static Map tracerValueMapping[] = {{"2", "3"}};
static Map crosshairValueMapping[] = {{"1", "2"}};
static Map fontscaleValueMapping[] = {{"*", "0.22"}};

// Key must be lowercase because I dont want to perform tolower on it.
static CVARMapping cvarMapping[] =
        {
                {"bot_debug",                   NULL},
                {"bot_developer",               NULL},
                {"bot_enable",                  NULL},
                {"bot_fastchat",                NULL},
                {"bot_grapple",                 NULL},
                {"bot_groundonly",              NULL},
                {"bot_minplayers",              NULL},
                {"bot_nochat",                  NULL},
                {"bot_norcd",                   NULL},
                {"bot_reachability",            NULL},
                {"bot_reloadcharacters",        NULL},
                {"bot_rocketjump",              NULL},
                {"bot_testichat",               NULL},
                {"bot_testrchat",               NULL},
                {"bot_thinktime",               NULL},

                {"cg_bobpitch",                 NULL},
                {"cg_bobroll",                  NULL},
                {"cg_bobup",                    NULL},
                {"cg_bobyaw",                   NULL},
                {"cg_botmenutype",              NULL},
                {"cg_cameraorbit",              NULL},
                {"cg_clipboardname",            NULL},
                {"cg_enablebreath",             NULL},
                {"cg_fastsolids",               NULL},
                {"cg_footsteps",                NULL},
                {"cg_ignore",                   NULL},
                {"cg_messageplayer",            NULL},
                {"cg_norender",                 NULL},
                {"cg_notaunt",                  NULL},
                {"cg_novoicechats",        "cg_voiceChats", .valueMapping = booleanInverse, .vmSize = 2},
                {"cg_novoicetext",         "cg_voiceText", .valueMapping =  booleanInverse, .vmSize = 2},
                {"cg_recording_statusline",     NULL},
                {"cg_runpitch",                 NULL},
                {"cg_runroll",                  NULL},
                {"cg_session",                  NULL},
                {"cg_stereoseparation",         NULL},
                {"cg_usescreenshotjpeg",        NULL},
                {"cg_viewsize",                 NULL},
                {"cg_wolfparticles",            NULL},

                {"cl_anonymous",                NULL},
                {"cl_autoupdate",               NULL},
                {"cl_debugtranslation",         NULL},
                {"cl_language",                 NULL},
                {"cl_motd",                     NULL},
                {"cl_motdstring",               NULL},
                {"cl_punkbuster",               NULL},
                {"cl_updateavailable",          NULL},
                {"cl_updatefiles",              NULL},
                {"cl_visibleclients",           NULL},
                {"cl_waitforfire",              NULL},

                {"com_cameramode",              NULL},
                {"com_dropsim",                 NULL},
                {"com_logosplaying",            NULL},
                {"com_watchdog",                NULL},

                {"con_debug",                   NULL},
                {"con_restricted",              NULL},

                {"debug_protocol",              NULL},
                {"debuggraph",                  NULL},
                {"devdll",                      NULL},
                {"dmflags",                     NULL},
                {"fraglimit",                   NULL},

                {"fs_buildgame",                NULL},
                {"fs_buildpath",                NULL},
                {"fs_cdpath",                   NULL},
                {"fs_copyfiles",                NULL},
                {"fs_restrict",                 NULL},

                {"g_alliedmaxlives",            NULL},
                {"g_arenasfile",                NULL},
                {"g_axismaxlives",              NULL},
                {"g_botsfile",                  NULL},
                {"g_movespeed",                 NULL},
                {"g_oldcampaign",               NULL},
                {"g_reloading",                 NULL},
                {"g_spawards",                  NULL},
                {"g_spscores1",                 NULL},
                {"g_spscores2",                 NULL},
                {"g_spscores3",                 NULL},
                {"g_spscores4",                 NULL},
                {"g_spscores5",                 NULL},
                {"g_spskill",                   NULL},
                {"g_spvideos",                  NULL},

                {"headmodel",                   NULL},

                {"in_debugjoystick",            NULL},
                {"in_joyballscale",             NULL},
                {"in_midi",                     NULL},
                {"in_midichannel",              NULL},
                {"in_mididevice",               NULL},
                {"in_midiport",                 NULL},

                {"joy_threshold",               NULL},

                {"mp_currentplayertype",        NULL},
                {"mp_currentteam",              NULL},
                {"mp_playertype",               NULL},
                {"mp_team",                     NULL},
                {"mp_weapon",                   NULL},

                {"net_noipx",                   NULL},
                {"net_noudp",                   NULL},

                {"r_ati_fsaa_samples",          NULL},
                {"r_ati_truform_normalmode",    NULL},
                {"r_ati_truform_pointmode",     NULL},
                {"r_ati_truform_tess",          NULL},
                {"r_clamptoedge",               NULL},
                {"r_dlightbacks",               NULL},
                {"r_ext_ati_pntriangles",       NULL},
                {"r_ext_compiled_vertex_array", NULL},
                {"r_ext_gamma_control",         NULL},
                {"r_ext_nv_fog_dist",           NULL},
                {"r_gldriver",                  NULL},
                {"r_glignorewicked3d",          NULL},
                {"r_highqualityvideo",          NULL},
                {"r_ingamevideo",               NULL},
                {"r_lastvalidrenderer",         NULL},
                {"r_maskminidriver",            NULL},
                {"r_nv_fogdist_mode",           NULL},
                {"r_primitives",                NULL},
                {"r_railcorewidth",             NULL},
                {"r_rmse",                      NULL},
                {"r_savefontdata",              NULL},
                {"r_showmodelbounds",           NULL},
                {"r_showsmp",                   NULL},
                {"r_smp",                       NULL},
                {"r_stereo",                    NULL},
                {"r_textureanisotropy",         NULL},
                {"r_verbose",                   NULL},
                {"r_depthbits",            "r_depthbits", .valueMapping = depthBitsValueMapping, .vmSize = 1},

                {"s_debugmusic",                NULL},
                {"s_defaultsound",              NULL},
                {"s_mute",                      NULL},
                {"s_nocompressed",              NULL},
                {"s_separation",                NULL},
                {"s_wavonly",                   NULL},

                {"savegame_loading",            NULL},
                {"scr_conspeed",                NULL},
                {"server_autoconfig",           NULL},

                {"sv_allowanonymous",           NULL},
                {"sv_dl_maxrate",               NULL},
                {"sv_minguidage",               NULL},
                {"sv_punkbuster",               NULL},
                {"sv_showloss",                 NULL},

                {"sys_cpuid",                   NULL},
                {"sys_cpustring",               NULL},

                {"team_maxpanzers",             NULL},

                {"vid_xpos",                    NULL},
                {"vid_ypos",                    NULL},

                {"vm_cgame",                    NULL},
                {"vm_game",                     NULL},
                {"vm_ui",                       NULL},

                {"vote_allow_comp",             NULL},
                {"vote_allow_pub",              NULL},
                {"vote_allow_shuffleteamsxp",   NULL},

                {"win_hinstance",               NULL},
                {"win_wndproc",                 NULL},

                // etpro values mapping
                {"b_althud",               "cg_althud"},
                {"b_althudflags",          "cg_althudflags"},
                {"b_antilag",              "cg_antilag"},
                {"b_chatalpha",            "cg_chatalpha"},
                {"b_chatflags",            "cg_chatflags"},
                {"b_drawclock",            "cg_drawTime"},
                {"b_drawfps",              "cg_drawfps"},
                {"b_drawranks",            "cg_drawCrosshairInfo", .valueMapping = crosshairValueMapping, .vmSize = 1},
                {"b_drawspeed",            "cg_drawspeed"},
                {"b_fireteamlatchedclass", "cg_fireteamlatchedclass"},
                {"b_hitsounds",            "cg_hitsounds"},
                {"b_locationjustify",      "cg_fireteamLocationAlign"},
                {"b_locationmaxchars",     "cg_locationmaxchars"},
                {"b_mapzoom",              "cg_automapzoom"},
                {"b_muzzleflash",          "cg_muzzleflash"},
                {"b_numpopups",            "cg_numpopups"},
                {"b_noactivatelean",       "cl_activatelean", .valueMapping = booleanInverse, .vmSize = 2},
                {"b_optimizeprediction",   "cg_optimizeprediction"},
                {"b_popupfadetime",        "cg_popupfadetime"},
                {"b_popupstaytime",        "cg_popupstaytime"},
                {"b_popuptime",            "cg_popuptime"},
                {"b_predefineddemokeys",   "cg_predefineddemokeys"},
                {"b_simpleitems",          "cg_simpleitems"},
                {"b_smallpopups",          "cg_drawsmallpopupicons"},
                {"b_tracers",              "cg_tracers", .valueMapping = tracerValueMapping, .vmSize = 1},
                {"b_votetextscale",        "cg_fontscalesp", .valueMapping = fontscaleValueMapping, .vmSize = 1, .descText = "This CVAR does not map 1 to 1. In legacy there are multiple font scaling cvars. Default is 0.22. See https://etlegacy.readthedocs.io/en/latest/cvars.html?highlight=fireteam#cg-fontscalesp-cvar-added"},
                {"b_weapaltreloads",       "cg_weapaltreloads"},

                // deleted etpro values
                {"b_backupcvars",               NULL},
                {"b_centeredweapons",           NULL},
                {"b_chatsounds",                NULL},
                {"b_cmdwarnings",               NULL},
                {"b_debugfakebmodel",           NULL},
                {"b_debuglocations",            NULL},
                {"b_debugsnapents",             NULL},
                {"b_demo_autotimescale",        NULL},
                {"b_demo_autotimescaleweapons", NULL},
                {"b_demo_dynamitecam",          NULL},
                {"b_demo_dynamitecounter",      NULL},
                {"b_demo_followxdistance",      NULL},
                {"b_demo_followydistance",      NULL},
                {"b_demo_followzdistance",      NULL},
                {"b_demo_freecamspeed",         NULL},
                {"b_demo_grenadecam",           NULL},
                {"b_demo_lookat",               NULL},
                {"b_demo_mortarcam",            NULL},
                {"b_demo_nametags",             NULL},
                {"b_demo_nopitch",              NULL},
                {"b_demo_panzercam",            NULL},
                {"b_demo_pitchturnspeed",       NULL},
                {"b_demo_playersprites",        NULL},
                {"b_demo_pvshint",              NULL},
                {"b_demo_rollspeed",            NULL},
                {"b_demo_teamonlymissilecam",   NULL},
                {"b_demo_yawturnspeed",         NULL},
                {"b_demorecord_statusline",     NULL},
                {"b_descriptivetextscale",      NULL},
                {"b_drawpromotions",            NULL},
                {"b_drawrewards",               NULL},
                {"b_drawspectatoralpha",        NULL},
                {"b_drawspectatorteamflags",    NULL},
                {"b_fireteamalpha",             NULL},
                {"b_fixedphysics",              NULL},
                {"b_goatsound",                 NULL},
                {"b_hudyoffset",                NULL},
                {"b_killshot_delay",            NULL},
                {"b_lagometeralpha",            NULL},
                {"b_locationmode",              NULL},
                {"b_logbanners",                NULL},
                {"b_panzerhack",                NULL},
                {"b_shovesounds",               NULL},
                {"b_speedinterval",             NULL},
                {"b_speedunit",                 NULL},
                {"b_textcolorfilter",           NULL},
                {"b_tjg_ghostfx",               NULL},
                {"b_tjl_color",                 NULL},
                {"b_tjl_draw",                  NULL},
                {"b_tjl_quickslot",             NULL},
                {"b_tjl_showmaxspeed",          NULL},
                {"b_tjl_stepsize",              NULL},
                {"b_tjl_stoponnomove",          NULL},
                {"b_watermarkalpha",            NULL},

                {"ui_*",                        NULL},
                {"b_*",                         NULL},
        };

// \w{3,}(?=(?:[^"]*"[^"]*")*[^"]*\Z)
//
// Show lines that only exist in file a: (i.e. what was deleted from a)
//      comm -23 a b
// Show lines that only exist in file b: (i.e. what was added to b)
//      comm -13 a b
// Show lines that only exist in one file or the other: (but not both)
//      comm -3 a b | sed 's/^\t//'
// tr [:upper:] [:lower:]


static const unsigned int cvarMappingSize = sizeof(cvarMapping) / sizeof(cvarMapping[0]);