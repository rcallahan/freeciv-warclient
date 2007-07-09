/********************************************************************** 
 Freeciv - Copyright (C) 1996-2004 - The Freeciv Project
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/

enum echo_type {
  ECHO_NONE = 0,
  ECHO_USER,
  ECHO_PLAYERS, /* i.e. all with basic access and above */
  ECHO_ADMINS, /* i.e. all with admin access and above */
  ECHO_ALL,
};

/**************************************************************************
  Commands - can be recognised by unique prefix
**************************************************************************/
struct command {
  const char *name;       /* name - will be matched by unique prefix   */
  enum cmdlevel_id game_level; /* access level to use the command, in-game  */
  enum cmdlevel_id pregame_level; /* access level to use, in pregame */
  const char *synopsis;	  /* one or few-line summary of usage */
  const char *short_help; /* one line (about 70 chars) description */
  const char *extra_help; /* extra help information; will be line-wrapped */
  int echo_mode; /* who to tell when used (enum echo_type) */
};

/* Order here is important: for ambiguous abbreviations the first
   match is used.  Arrange order to:
   - allow old commands 's', 'h', 'l', 'q', 'c' to work.
   - reduce harm for ambiguous cases, where "harm" includes inconvenience,
     eg accidently removing a player in a running game.
*/
enum command_id {
  /* old one-letter commands: */
  CMD_START_GAME = 0,
  CMD_HELP,
  CMD_LIST,
  CMD_QUIT,
  CMD_CUT,
  CMD_BAN,
  CMD_UNBAN,

  /* completely non-harmful: */
  CMD_EXPLAIN,
  CMD_SHOW,
  CMD_SCORE,
  CMD_WALL,
  CMD_VOTE,
  
  /* mostly non-harmful: */
  CMD_DEBUG,
  CMD_SET,
  CMD_TEAM,
  CMD_RULESETDIR,
  CMD_METAMESSAGE,
  CMD_METATOPIC,
  CMD_METAPATCHES,
  CMD_METACONN,
  CMD_METASERVER,
  CMD_AITOGGLE,
  CMD_TAKE,
  CMD_OBSERVE,
  CMD_DETACH,
  CMD_CREATE,
  CMD_AWAY,
  CMD_NOVICE,
  CMD_EASY,
  CMD_NORMAL,
  CMD_HARD,
  CMD_EXPERIMENTAL,
  CMD_CMDLEVEL,
  CMD_FIRSTLEVEL,
  CMD_TIMEOUT,
  CMD_IGNORE,
  CMD_UNIGNORE,
  CMD_AUTOTEAM,

  /* potentially harmful: */
#ifdef HAVE_AUTH
  CMD_AUTHDB,
#endif
  CMD_END_GAME,
  CMD_REMOVE,
  CMD_SAVE,
  CMD_LOAD,
  CMD_LOADMAP,
  CMD_UNLOADMAP,
  CMD_LOADSCERARIO,
  CMD_READ_SCRIPT,
  CMD_WRITE_SCRIPT,
  CMD_RESET,
  CMD_WELCOME_MESSAGE,
  CMD_WELCOME_FILE,
  CMD_DNS_LOOKUP,
  CMD_LOADACTIONLIST,
  CMD_SAVEACTIONLIST,
  CMD_CLEARACTIONLIST,
  CMD_ADDACTION,
  CMD_DELACTION,
  CMD_REQUIRE,

  /* undocumented */
  CMD_RFCSTYLE,
  CMD_SRVID,

  /* pseudo-commands: */
  CMD_NUM,		/* the number of commands - for iterations */
  CMD_UNRECOGNIZED,	/* used as a possible iteration result */
  CMD_AMBIGUOUS		/* used as a possible iteration result */
};

extern const struct command commands[];
