/**
 * @file
 * GUI display the mailboxes in a side panel
 *
 * @authors
 * Copyright (C) 2004 Justin Hibbits <jrh29@po.cwru.edu>
 * Copyright (C) 2004 Thomer M. Gil <mutt@thomer.com>
 * Copyright (C) 2015-2020 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MUTT_SIDEBAR_LIB_H
#define MUTT_SIDEBAR_LIB_H

#include <stdbool.h>
#include <stdint.h>
#include "mutt/lib.h"
#include "mutt_commands.h"

struct Mailbox;
struct MuttWindow;

/* These Config Variables are only used in sidebar.c */
extern short C_SidebarComponentDepth;
extern char *C_SidebarDelimChars;
extern char *C_SidebarDividerChar;
extern bool  C_SidebarFolderIndent;
extern char *C_SidebarFormat;
extern char *C_SidebarIndentString;
extern bool  C_SidebarNewMailOnly;
extern bool  C_SidebarNonEmptyMailboxOnly;
extern bool  C_SidebarNextNewWrap;
extern bool  C_SidebarOnRight;
extern bool  C_SidebarShortPath;
extern short C_SidebarSortMethod;
extern bool  C_SidebarVisible;
extern short C_SidebarWidth;

extern struct ListHead SidebarWhitelist;

void            sb_change_mailbox  (int op);
bool            select_next        (void);
void            sb_draw            (struct MuttWindow *win);
struct Mailbox *sb_get_highlight   (void);
void            sb_set_open_mailbox(struct Mailbox *m);
int             sb_observer        (struct NotifyCallback *nc);

enum CommandResult sb_parse_unwhitelist(struct Buffer *buf, struct Buffer *s, intptr_t data, struct Buffer *err);
enum CommandResult sb_parse_whitelist  (struct Buffer *buf, struct Buffer *s, intptr_t data, struct Buffer *err);

void sb_notify_mailbox(struct Mailbox *m, bool created);

#endif /* MUTT_SIDEBAR_LIB_H */
