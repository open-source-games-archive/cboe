
#include "dialog.h"
#include "pict.h"

void sort_pc_items(short pc_num);
bool give_to_pc(short pc_num,cItemRec  item,short  print_result);
bool forced_give(short item_num,eItemAbil abil);
bool GTP(short item_num);
bool silent_GTP(short item_num);
void give_gold(short amount,bool print_result);
bool take_gold(short amount,bool print_result);
short pc_has_abil_equip(short pc_num,short abil);
short pc_has_abil(short pc_num,short abil);
bool party_has_abil(short abil);
bool party_take_abil(short abil);
bool party_check_class(short item_class,short mode);
short pc_carry_weight(short pc_num);
short amount_pc_can_carry(short pc_num);
void give_food(short amount,bool print_result);
short take_food(short amount,bool print_result);
short pc_has_space(short pc_num);
short pc_ok_to_buy(short pc_num,short cost,cItemRec item);
void take_item(short pc_num,short which_item);
void remove_charge(short pc_num,short which_item);
void enchant_weapon(short pc_num,short item_hit,short enchant_type,short new_val);
void equip_item(short pc_num,short item_num);
void drop_item(short pc_num,short item_num,location where_drop);
bool place_item(cItemRec item,location where,bool forced);
void destroy_an_item();
void give_thing(short pc_num, short item_num);
void combine_things(short pc_num);
short dist_from_party(location where);
void set_item_flag(cItemRec *item);
short get_item(location place,short pc_num,bool check_container);
short get_prot_level(short pc_num,short abil);

void make_town_hostile();
bool display_item(location from_loc,short pc_num,short mode, bool check_container);
short custom_choice_dialog(std::array<std::string, 6>& strs,short pic_num,ePicType pic_type,std::array<short, 3>& buttons) ;
//short fancy_choice_dialog(short which_dlog,short parent);
short char_select_pc(short active_only,short free_inv_only,const char *title);
short select_pc(short active_only,short free_inv_only);
short get_num_of_items(short max_num);
void init_mini_map();
void put_pc_effects_on_dialog(cDialog& dialog,short item);
void draw_help_dialog_item_buttons(cDialog& dialog,short item);
void draw_help_dialog_forcefields(cDialog& dialog,short item);
void make_cursor_watch() ;
void place_glands(location where,m_num_t m_type);
short party_total_level() ;
void reset_item_max();
short item_val(cItemRec item);
bool give_to_party(cItemRec item, short print_result);
void place_treasure(location where,short level,short loot,short mode);
short luck_total();
cItemRec return_treasure(short loot,short level,short mode);
void refresh_store_items();
std::string get_text_response(short dlg,short parent_num);