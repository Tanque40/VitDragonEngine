#pragma once

// From GLFW3.h

/* The unknown key */
#define VDE_KEY_UNKNOWN            -1

/* Printable keys */
#define VDE_KEY_SPACE              32
#define VDE_KEY_APOSTROPHE         39  /* ' */
#define VDE_KEY_COMMA              44  /* , */
#define VDE_KEY_MINUS              45  /* - */
#define VDE_KEY_PERIOD             46  /* . */
#define VDE_KEY_SLASH              47  /* / */
#define VDE_KEY_0                  48
#define VDE_KEY_1                  49
#define VDE_KEY_2                  50
#define VDE_KEY_3                  51
#define VDE_KEY_4                  52
#define VDE_KEY_5                  53
#define VDE_KEY_6                  54
#define VDE_KEY_7                  55
#define VDE_KEY_8                  56
#define VDE_KEY_9                  57
#define VDE_KEY_SEMICOLON          59  /* ; */
#define VDE_KEY_EQUAL              61  /* = */
#define VDE_KEY_A                  65
#define VDE_KEY_B                  66
#define VDE_KEY_C                  67
#define VDE_KEY_D                  68
#define VDE_KEY_E                  69
#define VDE_KEY_F                  70
#define VDE_KEY_G                  71
#define VDE_KEY_H                  72
#define VDE_KEY_I                  73
#define VDE_KEY_J                  74
#define VDE_KEY_K                  75
#define VDE_KEY_L                  76
#define VDE_KEY_M                  77
#define VDE_KEY_N                  78
#define VDE_KEY_O                  79
#define VDE_KEY_P                  80
#define VDE_KEY_Q                  81
#define VDE_KEY_R                  82
#define VDE_KEY_S                  83
#define VDE_KEY_T                  84
#define VDE_KEY_U                  85
#define VDE_KEY_V                  86
#define VDE_KEY_W                  87
#define VDE_KEY_X                  88
#define VDE_KEY_Y                  89
#define VDE_KEY_Z                  90
#define VDE_KEY_LEFT_BRACKET       91  /* [ */
#define VDE_KEY_BACKSLASH          92  /* \ */
#define VDE_KEY_RIGHT_BRACKET      93  /* ] */
#define VDE_KEY_GRAVE_ACCENT       96  /* ` */
#define VDE_KEY_WORLD_1            161 /* non-US #1 */
#define VDE_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define VDE_KEY_ESCAPE             256
#define VDE_KEY_ENTER              257
#define VDE_KEY_TAB                258
#define VDE_KEY_BACKSPACE          259
#define VDE_KEY_INSERT             260
#define VDE_KEY_DELETE             261
#define VDE_KEY_RIGHT              262
#define VDE_KEY_LEFT               263
#define VDE_KEY_DOWN               264
#define VDE_KEY_UP                 265
#define VDE_KEY_PAGE_UP            266
#define VDE_KEY_PAGE_DOWN          267
#define VDE_KEY_HOME               268
#define VDE_KEY_END                269
#define VDE_KEY_CAPS_LOCK          280
#define VDE_KEY_SCROLL_LOCK        281
#define VDE_KEY_NUM_LOCK           282
#define VDE_KEY_PRINT_SCREEN       283
#define VDE_KEY_PAUSE              284
#define VDE_KEY_F1                 290
#define VDE_KEY_F2                 291
#define VDE_KEY_F3                 292
#define VDE_KEY_F4                 293
#define VDE_KEY_F5                 294
#define VDE_KEY_F6                 295
#define VDE_KEY_F7                 296
#define VDE_KEY_F8                 297
#define VDE_KEY_F9                 298
#define VDE_KEY_F10                299
#define VDE_KEY_F11                300
#define VDE_KEY_F12                301
#define VDE_KEY_F13                302
#define VDE_KEY_F14                303
#define VDE_KEY_F15                304
#define VDE_KEY_F16                305
#define VDE_KEY_F17                306
#define VDE_KEY_F18                307
#define VDE_KEY_F19                308
#define VDE_KEY_F20                309
#define VDE_KEY_F21                310
#define VDE_KEY_F22                311
#define VDE_KEY_F23                312
#define VDE_KEY_F24                313
#define VDE_KEY_F25                314
#define VDE_KEY_KP_0               320
#define VDE_KEY_KP_1               321
#define VDE_KEY_KP_2               322
#define VDE_KEY_KP_3               323
#define VDE_KEY_KP_4               324
#define VDE_KEY_KP_5               325
#define VDE_KEY_KP_6               326
#define VDE_KEY_KP_7               327
#define VDE_KEY_KP_8               328
#define VDE_KEY_KP_9               329
#define VDE_KEY_KP_DECIMAL         330
#define VDE_KEY_KP_DIVIDE          331
#define VDE_KEY_KP_MULTIPLY        332
#define VDE_KEY_KP_SUBTRACT        333
#define VDE_KEY_KP_ADD             334
#define VDE_KEY_KP_ENTER           335
#define VDE_KEY_KP_EQUAL           336
#define VDE_KEY_LEFT_SHIFT         340
#define VDE_KEY_LEFT_CONTROL       341
#define VDE_KEY_LEFT_ALT           342
#define VDE_KEY_LEFT_SUPER         343
#define VDE_KEY_RIGHT_SHIFT        344
#define VDE_KEY_RIGHT_CONTROL      345
#define VDE_KEY_RIGHT_ALT          346
#define VDE_KEY_RIGHT_SUPER        347
#define VDE_KEY_MENU               348

#define VDE_KEY_LAST               VDE_KEY_MENU