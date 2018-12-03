/**
 * \file mon-group.h
 * \brief Monster group behaviours
 *
 * Copyright (c) 2018 Nick McConnell
 *
 * This work is free software; you can redistribute it and/or modify it
 * under the terms of either:
 *
 * a) the GNU General Public License as published by the Free Software
 *    Foundation, version 2, or
 *
 * b) the "Angband licence":
 *    This software may be copied and distributed for educational, research,
 *    and not for profit purposes provided that this copyright and statement
 *    are included in all such copies.  Other copyrights may also apply.
 */
#ifndef MON_GROUP_H
#define MON_GROUP_H

struct mon_group_list_entry {
	int midx;
	struct mon_group_list_entry *next;
};

struct monster_group {
	int index;
	int leader;
	struct mon_group_list_entry *member_list;
	struct loc home;
	struct heatmap heatmap;
};

struct monster_group *monster_group_new(void);
void monster_group_free(struct chunk *c, struct monster_group *group);
int monster_group_index_new(struct chunk *c);
int monster_group_index(struct monster_group *group);
struct monster_group *monster_group_by_index(struct chunk *c, int index);
bool monster_group_change_index(struct chunk *c, int new, int old);
int monster_group_leader_idx(struct monster_group *group);
struct monster *monster_group_leader(struct chunk *c,
									 struct monster_group *group);

#endif /* !MON_GROUP_H */
