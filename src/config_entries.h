/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#include "common.h"

#include "git2/sys/config.h"
#include "config.h"

typedef struct config_entry_list {
	struct config_entry_list *next;
	struct config_entry_list *last;
	git_config_entry *entry;
} config_entry_list;

typedef struct {
	git_refcount rc;
	git_strmap *map;
	config_entry_list *list;
} git_config_entries;

int git_config_entries_new(git_config_entries **out);
void git_config_entries_incref(git_config_entries *entries);
void git_config_entries_free(git_config_entries *entries);
/* Add or append the new config option */
int git_config_entries_append(git_config_entries *entries, git_config_entry *entry);
int git_config_entries_get(git_config_entry **out, git_config_entries *entries, const char *key);
int git_config_entries_get_unique(git_config_entry **out, git_config_entries *entries, const char *key);
int git_config_entries_iterator_new(git_config_iterator **out, git_config_backend *backend, git_config_entries *entries);
