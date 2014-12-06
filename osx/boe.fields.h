
#ifndef BOE_GAME_FIELDS_H
#define BOE_GAME_FIELDS_H
// TODO: I think these should be integrated into the cTown class.

bool is_explored(short i,short j);
void make_explored(short i,short j);
void take_explored(short i,short j);
bool is_out();
bool is_town();
bool is_combat();
//bool special(short i,short j);
//void flip_special(short i,short j);
//void make_special(short i,short j);
//void take_special(short i,short j);
//bool is_web(short i,short j);
void make_web(short i,short j);
//void take_web(short i,short j);
//bool is_crate(short i,short j);
//void make_crate(short i,short j);
//void take_crate(short i,short j);
//bool is_barrel(short i,short j);
//void make_barrel(short i,short j);
//void take_barrel(short i,short j);
//bool is_fire_barrier(short i,short j);
//void make_fire_barrier(short i,short j);
//void take_fire_barrier(short i,short j);
//bool is_force_barrier(short i,short j);
//void make_force_barrier(short i,short j);
//void take_force_barrier(short i,short j);
//bool is_quickfire(short i,short j);
void make_quickfire(short i,short j);
//void take_quickfire(short i,short j);
//bool is_force_wall(short i,short j);
void make_force_wall(short i,short j);
//void take_force_wall(short i,short j);
//bool is_fire_wall(short i,short j);
void make_fire_wall(short i,short j);
//void take_fire_wall(short i,short j);
//bool is_antimagic(short i,short j);
void make_antimagic(short i,short j);
//void take_antimagic(short i,short j);
//bool is_scloud(short i,short j);
void make_scloud(short i,short j);
//void take_scloud(short i,short j);
//bool is_ice_wall(short i,short j);
void make_ice_wall(short i,short j);
//void take_ice_wall(short i,short j);
//bool is_blade_wall(short i,short j);
void make_blade_wall(short i,short j);
//void take_blade_wall(short i,short j);
//bool is_sleep_cloud(short i,short j);
void make_sleep_cloud(short i,short j);
//void take_sleep_cloud(short i,short j);


//bool is_small_blood(short i,short j);
//bool is_medium_blood(short i,short j);
//bool is_large_blood(short i,short j);
//bool is_small_slime(short i,short j);
//bool is_big_slime(short i,short j);
//bool is_ash(short i,short j);
//bool is_bones(short i,short j);
//bool is_rubble(short i,short j);
void make_sfx(short i,short j, short type);
void spread_sfx(short type,short prob);

#endif
