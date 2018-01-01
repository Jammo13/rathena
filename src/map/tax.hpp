// Copyright (c) rAthena Dev Teams - Licensed under GNU GPL
// For more information, see LICENCE in the main folder

#ifndef _TAX_HPP_
#define _TAX_HPP_

#include <string>
#include <vector>

#include "../common/cbasetypes.h"

#pragma once

enum e_tax_type : unsigned char {
	TAX_SELLING = 0,
	TAX_BUYING,
	TAX_MAX,
};

struct s_tax_entry {
	size_t minimal;
	unsigned short tax;
};

struct s_tax {
	std::vector <struct s_tax_entry> each;
	std::vector <struct s_tax_entry> total;

	unsigned short get_tax(const std::vector <struct s_tax_entry>, double);
};

struct s_tax *tax_get(enum e_tax_type type);
void tax_reloadall(void);

void tax_readdb(void);
void tax_reload_vendors(void);
void tax_set_conf(const std::string filename);

void do_init_tax(void);
void do_final_tax(void);

#endif /* _TAX_HPP_ */
