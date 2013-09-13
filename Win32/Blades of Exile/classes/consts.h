/*
 *  simpletypes.h
 *  BoE
 *
 *  Created by Celtic Minstrel on 01/06/09.
 *
 */

#ifndef _CONSTS_H
	#define _CONSTS_H

#define NUM_OF_PCS		6
#define INVALID_PC		6

#define	NUM_SOUNDS	100

#define NUM_OF_BOATS	30
#define NUM_OF_HORSES	30

/* stuff done flags */
#define SDF_IS_PARTY_SPLIT 304][0
#define SDF_PARTY_SPLIT_WHERE_PARTY_X 304][1
#define SDF_PARTY_SPLIT_WHERE_PARTY_Y 304][2
#define SDF_PARTY_SPLIT_PC      304][3
#define SDF_PARTY_SPLIT_TOWN    304][4 //for future use, hopefully
#define SDF_STEALTH             305][0
#define SDF_FLYING              305][1
#define SDF_DETECT_MONSTER      305][2
#define SDF_LAVAWALK            305][3
//#define SDF_SKIP_STARTUP        305][4 //is now a boolean : play_startup
#define SDF_LESS_SOUND          305][5
#define SDF_NO_TARGET_LINE      305][6
#define SDF_FASTER_BOOM_SPACES  305][7 //new (Classic Blades of Exile) option
#define SDF_MONSTERS_ALERTNESS  305][9 //is 0 if monsters are placid (not detected), 30 if an active monster is seeking the party (detected), reduced by one (until 0) each turn when no such monster exists
#define SFD_NO_MAPS             306][0
#define SDF_NO_SOUNDS           306][1
#define SDF_NO_FRILLS           306][2
#define SDF_ROOM_DESCS_AGAIN    306][3 //not used in the code
#define SDF_NO_INSTANT_HELP     306][4 //boolean
#define SDF_NO_SHORE_FRILLS     306][5
#define SDF_GAME_SPEED          306][6
#define SDF_EASY_MODE           306][7
#define SDF_LESS_WANDER_ENC     306][8
#define SDF_NO_TER_ANIM         306][9
#define SDF_USE_DARKER_GRAPHICS 307][0 //new (Classic Blades of Exile) option (use Mac graphics)
#define SDF_ASK_ABOUT_TEXT_BOX  307][1 //new (Classic Blades of Exile) option (display an "Ask About" text box in talk mode)
#define SDF_HIDDEN_MAP          308][0
#define SDF_LEGACY_SCENARIO     305][8 //0 is new scenario, 1 is legacy

#define SDF_COMPATIBILITY_LEGACY_DAY_REACHED 309][0
#define SDF_COMPATIBILITY_LEGACY_KILL_NODE 309][1
#define SDF_COMPATIBILITY_WORKING_TOWN_WATERFALL 309][2
#define SDF_COMPATIBILITY_FULL_TRIMS 309][3
#define SDF_COMPATIBILITY_SPECIALS_INTERRUPT_REST 309][4
#define SDF_COMPATIBILITY_ANYTIME_STAIRWAY_NODES 309][5
#define SDF_COMPATIBILITY_CHECK_TIMERS_WHILE_RESTING 309][6
#define SDF_COMPATIBILITY_TRIGGER_SPECIALS_ON_BOAT 309][7

#define INVALID_TOWN	200

typedef unsigned short m_num_t;
typedef unsigned short ter_num_t;
typedef signed short spec_num_t;
typedef signed short item_num_t;
typedef unsigned short str_num_t;

/* Monsters Attitudes :
    0 - Friendly, Docile
    1 - Hostile, Type A
    2 - Friendly, Will fight
    3 - Hostile, Type B
*/

/* overall mode; some seem to be missing */ //<=seems complete now
enum eMode {
    MODE_OUTDOORS = 0,
    MODE_TOWN = 1,
    MODE_TALK_TOWN = 2, // looking for someone to talk
    MODE_TOWN_TARGET = 3, // spell target, that is
    MODE_USE = 4,
    MODE_TOWN_DROPPING = 5,//dropping while in town mode
    MODE_COMBAT = 10,
    MODE_SPELL_TARGET = 11,
    MODE_FIRING = 12, // firing from bow or crossbow
    MODE_THROWING = 13, // throwing missile
    MODE_FANCY_TARGET = 14, // spell target, that is
    MODE_DROPPING = 15,//dropping while in combat mode
    MODE_TALKING = 20,
    MODE_SHOPPING = 21,
    MODE_LOOK_OUTDOORS = 35, // looking at something
    MODE_LOOK_TOWN = 36,
    MODE_LOOK_COMBAT = 37,
    MODE_STARTUP = 45,
    MODE_REDRAW = 50,
    MODE_CUTSCENE = 51,
};

enum eTrapType {
    TRAP_RANDOM = 0,
    TRAP_BLADE = 1,
    TRAP_DART = 2,
    TRAP_GAS = 3,			// poisons all
    TRAP_EXPLOSION = 4,	// damages all => uses c_town.difficulty rather than trap_level to calculates damages (and even c_town.difficulty /13).
    TRAP_SLEEP_RAY = 5,
    TRAP_FALSE_ALARM = 6,
    TRAP_DRAIN_XP = 7,
    TRAP_ALERT = 8,		// makes town hostile
    TRAP_FLAMES = 9,		// damages all => uses trap_level (*5) to calculates damages.
    TRAP_DUMBFOUND = 10,   //dumbfound all
    TRAP_DISEASE = 11,
    TRAP_DISEASE_ALL = 12,
};

enum eMainStatus {
	MAIN_STATUS_ABSENT = 0, // absent, empty slot
	MAIN_STATUS_ALIVE = 1,
	MAIN_STATUS_DEAD = 2,
	MAIN_STATUS_DUST = 3,
	MAIN_STATUS_STONE = 4,
	MAIN_STATUS_FLED = 5,
	MAIN_STATUS_SURFACE = 6, // fled to surface?
	MAIN_STATUS_WON = 7,
	MAIN_STATUS_SPLIT = 10,
	// The rest are not really necessary, but are here for completeness so that all valid values have a name.
	MAIN_STATUS_SPLIT_ABSENT = MAIN_STATUS_SPLIT + MAIN_STATUS_ABSENT,
	MAIN_STATUS_SPLIT_ALIVE = MAIN_STATUS_SPLIT + MAIN_STATUS_ALIVE,
	MAIN_STATUS_SPLIT_DEAD = MAIN_STATUS_SPLIT + MAIN_STATUS_DEAD,
	MAIN_STATUS_SPLIT_DUST = MAIN_STATUS_SPLIT + MAIN_STATUS_DUST,
	MAIN_STATUS_SPLIT_STONE = MAIN_STATUS_SPLIT + MAIN_STATUS_STONE,
	MAIN_STATUS_SPLIT_FLED = MAIN_STATUS_SPLIT + MAIN_STATUS_FLED,
	MAIN_STATUS_SPLIT_SURFACE = MAIN_STATUS_SPLIT + MAIN_STATUS_SURFACE,
	MAIN_STATUS_SPLIT_WON = MAIN_STATUS_SPLIT + MAIN_STATUS_WON,
};

/* adven[i].race */ //future races !!! only first 3 (zero, one and two) are legacy !
enum eRace {
	RACE_UNKNOWN = -1, // for parameters to some functions; not valid in the class
	RACE_HUMAN = 0,
	RACE_NEPHIL = 1,
	RACE_SLITH = 2,
	RACE_VAHNATAI = 3,
	RACE_REPTILE = 4,
	RACE_BEAST = 5,
	RACE_IMPORTANT = 6,
	RACE_MAGE = 7,
	RACE_PRIEST = 8,
	RACE_HUMANOID = 9,
	RACE_DEMON = 10,
	RACE_UNDEAD = 11,
	RACE_GIANT = 12,
	RACE_SLIME = 13,
	RACE_STONE = 14,
	RACE_BUG = 15,
	RACE_DRAGON = 16,
	RACE_MAGICAL = 17,
	RACE_PLANT = 18,
	RACE_BIRD = 19,
}; // TODO: Expand and merge with eMonsterType

/* adven[i].status*/ //complete - assign a positive value for a help pc effect, a negative for harm pc
enum eStatus {
	STATUS_POISONED_WEAPON = 0,
	STATUS_BLESS_CURSE = 1,
	STATUS_POISON = 2,
	STATUS_HASTE_SLOW = 3,
	STATUS_INVULNERABLE = 4,
	STATUS_MAGIC_RESISTANCE = 5,
	STATUS_WEBS = 6,
	STATUS_DISEASE = 7,
	STATUS_INVISIBLE = 8, //sanctuary
	STATUS_DUMB = 9,
	STATUS_MARTYRS_SHIELD = 10,
	STATUS_ASLEEP = 11,
	STATUS_PARALYZED = 12,
	STATUS_ACID = 13,
};

/* adven[i].skills */ //complete
enum eSkill {
	SKILL_STRENGTH = 0,
	SKILL_DEXTERITY = 1,
	SKILL_INTELLIGENCE = 2,
	SKILL_EDGED_WEAPONS = 3,
	SKILL_BASHING_WEAPONS = 4,
	SKILL_POLE_WEAPONS = 5,
	SKILL_THROWN_MISSILES = 6,
	SKILL_ARCHERY = 7,
	SKILL_DEFENSE = 8,
	SKILL_MAGE_SPELLS = 9,
	SKILL_PRIEST_SPELLS = 10,
	SKILL_MAGE_LORE = 11,
	SKILL_ALCHEMY = 12,
	SKILL_ITEM_LORE = 13,
	SKILL_DISARM_TRAPS = 14,
	SKILL_LOCKPICKING = 15,
	SKILL_ASSASSINATION = 16,
	SKILL_POISON = 17,
	SKILL_LUCK = 18,
};

/* adven[i].traits */ //complete
enum eTrait {
	TRAIT_TOUGHNESS = 0,
	TRAIT_MAGICALLY_APT = 1,
	TRAIT_AMBIDEXTROUS = 2,
	TRAIT_NIMBLE = 3,
	TRAIT_CAVE_LORE = 4,
	TRAIT_WOODSMAN = 5,
	TRAIT_GOOD_CONST = 6,
	TRAIT_HIGHLY_ALERT = 7,
	TRAIT_STRENGTH = 8,
	TRAIT_RECUPERATION = 9,
	TRAIT_SLUGGISH = 10,
	TRAIT_MAGICALLY_INEPT = 11,
	TRAIT_FRAIL = 12,
	TRAIT_CHRONIC_DISEASE = 13,
	TRAIT_BAD_BACK = 14,
	TRAIT_PACIFIST = 15,
};

/* Monster Type a.k.a m_type */
enum eMonsterType {
	MONSTER_TYPE_UNKNOWN = -1, // for parameters to some functions; not valid in the class
	MONSTER_TYPE_HUMAN = 0,
	MONSTER_TYPE_REPTILE = 1,
	MONSTER_TYPE_BEAST = 2,
	MONSTER_TYPE_IMPORTANT = 3,
	MONSTER_TYPE_MAGE = 4,
	MONSTER_TYPE_PRIEST = 5,
	MONSTER_TYPE_HUMANOID = 6,
	MONSTER_TYPE_DEMON = 7,
	MONSTER_TYPE_UNDEAD = 8,
	MONSTER_TYPE_GIANT = 9,
	MONSTER_TYPE_SLIME = 10,
	MONSTER_TYPE_STONE = 11,
	MONSTER_TYPE_BUG = 12,
	MONSTER_TYPE_DRAGON = 13,
	MONSTER_TYPE_MAGICAL = 14,
};


//future spec_skill !!!
/* Special Ability a.k.a spec_skill */

/*enum eMonstAbil {
	MONST_NO_ABIL = 0,
	// Missile abilities (extra1 = number of sided dice; extra2 = number of sides)
	MONST_THROWS_DARTS = 10,
	MONST_SHOOTS_ARROWS,
	MONST_THROWS_SPEARS,
	MONST_THROWS_ROCKS,
	MONST_THROWS_RAZORDISKS,
	MONST_GOOD_ARCHER,
	MONST_SHOOTS_SPINES,
	MONST_THROWS_KNIVES,
	// Ray abilities (extra1 = type of damage / status where applicable)
	MONST_DAMAGE_RAY = 20,
	MONST_STATUS_RAY,
	MONST_PETRIFY_RAY,
	MONST_DRAIN_SP_RAY,
	MONST_DRAIN_XP_RAY,
	MONST_DRAIN_XP_DAMAGE_RAY,
	MONST_KILL_RAY,
	MONST_STEAL_FOOD_RAY,
	MONST_STEAL_GOLD_RAY,
	// Touch abilities (extra1 = type of damage / status where applicable)
	MONST_DAMAGE_TOUCH = 30,
	MONST_STATUS_TOUCH,
	MONST_PETRIFY_TOUCH,
	MONST_DRAIN_SP_TOUCH,
	MONST_DRAIN_XP_TOUCH,
	MONST_DRAIN_XP_DAMAGE_TOUCH,
	MONST_KILL_TOUCH,
	MONST_STEAL_FOOD_TOUCH,
	MONST_STEAL_GOLD_TOUCH,
	// Summon abilities (extra1 = which monster / type / species; extra2 = % chance)
	MONST_SUMMON_ONE = 40,
	MONST_SUMMON_TYPE,
	MONST_SUMMON_SPECIES,
	MONST_SUMMON_RANDOM,
	MONST_MASS_SUMMON,
	// Misc abilities (extra1 = field / special #; extra2 = % chance for radiate only)
	MONST_SPLITS = 50,
	MONST_FIELD_MISSILE,
	MONST_MARTYRS_SHIELD,
	MONST_ABSORB_SPELLS,
	MONST_INVULNERABLE,
	MONST_RADIATE,
	MONST_CALL_LOCAL_SPECIAL,
	MONST_CALL_GLOBAL_SPECIAL,
};*/

//at least for proper code comprehension
//legacy spec_skill
/* Special Ability a.k.a spec_skill */

 #define MONSTER_NO_SPECIAL_ABILITY 0
 #define MONSTER_THROWS_DARTS 1
 #define MONSTER_SHOOTS_ARROWS 2
 #define MONSTER_THROWS_SPEARS 3
 #define MONSTER_THROWS_ROCKS1 4    //4-24 damages
 #define MONSTER_THROWS_ROCKS2 5    //5-30 damages
 #define MONSTER_THROWS_ROCKS3 6    //6-36 damages
 #define MONSTER_THROWS_RAZORDISKS 7
 #define MONSTER_PETRIFICATION_RAY 8
 #define MONSTER_SP_DRAIN_RAY 9    //spell points drain ray
 #define MONSTER_HEAT_RAY 10
 #define MONSTER_INVISIBLE 11
 #define MONSTER_SPLITS 12
 #define MONSTER_MINDLESS 13
 #define MONSTER_BREATHES_STINKING_CLOUDS 14
 #define MONSTER_ICY_TOUCH 15
 #define MONSTER_XP_DRAINING_TOUCH 16
 #define MONSTER_ICY_AND_DRAINING_TOUCH 17
 #define MONSTER_SLOWING_TOUCH 18
 #define MONSTER_SHOOTS_WEB 19
 #define MONSTER_GOOD_ARCHER 20
 #define MONSTER_STEALS_FOOD 21
 #define MONSTER_PERMANENT_MARTYRS_SHIELD 22
 #define MONSTER_PARALYSIS_RAY 23
 #define MONSTER_DUMBFOUNDING_TOUCH 24
 #define MONSTER_DISEASE_TOUCH 25
 #define MONSTER_ABSORB_SPELLS 26
 #define MONSTER_WEB_TOUCH 27
 #define MONSTER_SLEEP_TOUCH 28
 #define MONSTER_PARALYSIS_TOUCH 29
 #define MONSTER_PETRIFYING_TOUCH 30
 #define MONSTER_ACID_TOUCH 31
 #define MONSTER_BREATHES_SLEEP_CLOUDS 32
 #define MONSTER_ACID_SPIT 33
 #define MONSTER_SHOOTS_SPINES 34
 #define MONSTER_DEATH_TOUCH 35
 #define MONSTER_INVULNERABILITY 36
 #define MONSTER_GUARD 37

 /* Create Monsters/Fields */
 //a.k.a radiate_1
 //radiate_2 is the second field (monster to summon, probability to happens, etc)

 #define MONSTER_NO_RADIATE 0
 #define MONSTER_RADIATE_FIRE_FIELDS 1
 #define MONSTER_RADIATE_ICE_FIELDS 2
 #define MONSTER_RADIATE_SHOCK_FIELDS 3
 #define MONSTER_RADIATE_ANTIMAGIC_FIELDS 4
 #define MONSTER_RADIATE_SLEEP_FIELDS 5
 #define MONSTER_RADIATE_STINKING_CLOUDS 6
 // 7,8 and 9 are unused
 #define MONSTER_SUMMON1 10    //5 percent chance
 #define MONSTER_SUMMON2 11    //20 percent chance
 #define MONSTER_SUMMON3 12    //50 percent chance
 // 13 and 14 are unused
 #define MONSTER_DEATH_TRIGGERS 15        //death triggers global special

/* Attack Types */

enum eMonsterAttackTypes{
    MONSTER_ATTACK_SWINGS = 0,
    MONSTER_ATTACK_CLAWS = 1,
    MONSTER_ATTACK_BITES = 2,
    MONSTER_ATTACK_SLIMES = 3,
    MONSTER_ATTACK_PUNCHES = 4,
    MONSTER_ATTACK_STINGS = 5,
    MONSTER_ATTACK_CLUBS = 6,
    MONSTER_ATTACK_BURNS = 7,
    MONSTER_ATTACK_HARMS = 8,
    MONSTER_ATTACK_STABS = 9,
};

/* Terrains Special Properties : scenario.ter_types[i].special */      //complete

enum eTerSpec {
		TER_SPEC_NONE = 0,
		TER_SPEC_CHANGE_WHEN_STEP_ON = 1,
		TER_SPEC_DOES_FIRE_DAMAGE = 2,
		TER_SPEC_DOES_COLD_DAMAGE = 3,
		TER_SPEC_DOES_MAGIC_DAMAGE = 4,
		TER_SPEC_POISON_LAND = 5,
		TER_SPEC_DISEASED_LAND = 6,
		TER_SPEC_CRUMBLING_TERRAIN = 7,
		TER_SPEC_LOCKABLE_TERRAIN = 8,
		TER_SPEC_UNLOCKABLE_TERRAIN = 9,
		TER_SPEC_UNLOCKABLE_BASHABLE = 10,
		TER_SPEC_IS_A_SIGN = 11,
		TER_SPEC_CALL_LOCAL_SPECIAL = 12,
		TER_SPEC_CALL_SCENARIO_SPECIAL = 13,
		TER_SPEC_IS_A_CONTAINER = 14,
		TER_SPEC_WATERFALL = 15,
		TER_SPEC_CONVEYOR_NORTH = 16,
		TER_SPEC_CONVEYOR_EAST = 17,
		TER_SPEC_CONVEYOR_SOUTH = 18,
		TER_SPEC_CONVEYOR_WEST = 19,
		TER_SPEC_BLOCKED_TO_MONSTERS = 20,
		TER_SPEC_TOWN_ENTRANCE = 21,
		TER_SPEC_CHANGE_WHEN_USED = 22,
		TER_SPEC_CALL_SPECIAL_WHEN_USED = 23,

	//future specs
	/*TER_SPEC_NONE = 0,
	TER_SPEC_CHANGE_WHEN_STEP_ON = 1,
	TER_SPEC_DAMAGING = 2,
	TER_SPEC_BRIDGE = 3, // new
	TER_SPEC_BED = 4, // new
	TER_SPEC_DANGEROUS = 5,
	TER_SPEC_UNUSED1 = 6,
	TER_SPEC_CRUMBLING = 7,
	TER_SPEC_LOCKABLE = 8,
	TER_SPEC_UNLOCKABLE = 9,
	TER_SPEC_UNUSED2 = 10,
	TER_SPEC_IS_A_SIGN = 11,
	TER_SPEC_CALL_SPECIAL = 12,
	TER_SPEC_UNUSED3 = 13,
	TER_SPEC_IS_A_CONTAINER = 14,
	TER_SPEC_WATERFALL = 15,
	TER_SPEC_CONVEYOR = 16,
	TER_SPEC_UNUSED4 = 17,
	TER_SPEC_UNUSED5 = 18,
	TER_SPEC_UNUSED6 = 19,
	TER_SPEC_BLOCKED_TO_MONSTERS = 20,
	TER_SPEC_TOWN_ENTRANCE = 21,
	TER_SPEC_CHANGE_WHEN_USED = 22,
	TER_SPEC_CALL_SPECIAL_WHEN_USED = 23,
	//	1. Change when step on (What to change to, number of sound, Unused)
	//	2. Damaging terrain; can't rest here (Amount of damage done, multiplier, damage type)
	//	3. Reserved
	//	4. Reserved
	//	5. Dangerous land; can't rest here; percentage chance may be 0 (Strength, Percentage chance, status type)
	//	6. Reserved
	//	7. Crumbling terrain (Terrain to change to, strength?, destroyed by what - quickfire, shatter/move mountains, or both)
	//	8. Lockable terrain (Terrain to change to when locked, Unused, Unused)
	//	9. Unlockable terrain (Terrain to change to when locked, Difficulty, can be bashed)
	//	10. Reserved
	//	11. Sign (Unused, Unused, Unused)
	//	12. Call special (Special to call, local or scenario?, Unused)
	//	13. Reserved
	//	14. Container (Unused, Unused, Unused)
	//	15. Waterfall (Direction, Unused, Unused)
	//	16. Conveyor Belt (Direction, Unused, Unused)
	//	17. Reserved
	//	18. Reserved
	//	19. Reserved
	//	20. Blocked to Monsters (Unused, Unused, Unused)
	//	21. Town entrance (Terrain type if hidden, Unused, Unused)
	//	22. Change when Used (Terrain to change to when used, Number of sound, Unused)
	//	23. Call special when used (Special to call, local or scenario?, Unused)
	//	24. Bridge - if the party boats over it, they get the option to land. (Unused, Unused, Unused)*/
};

enum eTrimType {//hopefully used in the future
	TRIM_NONE = 0,
	TRIM_WALL = 1, // not a trim, but trims will conform to it as if it's the same ground type (eg stone wall)
	TRIM_S, TRIM_SE, TRIM_E, TRIM_NE, TRIM_N, TRIM_NW, TRIM_W, TRIM_SW,
	TRIM_NE_INNER, TRIM_SE_INNER, TRIM_SW_INNER, TRIM_NW_INNER,
	TRIM_FRILLS = 14, // like on lava and underground water; no trim_ter required
	TRIM_ROAD = 15, // the game will treat it like a road space and draw roads; no trim_ter required
	TRIM_WALKWAY = 16, // the game will draw walkway corners; trim_ter is base terrain to draw on
	TRIM_WATERFALL = 17, // special case for waterfalls
	TRIM_CITY = 18, // the game will join roads up to this space but not draw roads on the space
};


/*      items[i].type    a.k.a type of weapon         */
enum eWeapType {
	ITEM_NOT_MELEE = 0,
	ITEM_EDGED = 1,
	ITEM_BASHING = 2,
	ITEM_POLE = 3,
};

/*      items[i].variety    a.k.a item type (in editor)      */
enum eItemType {
	ITEM_TYPE_NO_ITEM = 0,
	ITEM_TYPE_ONE_HANDED = 1,
	ITEM_TYPE_TWO_HANDED = 2,
	ITEM_TYPE_GOLD = 3,
	ITEM_TYPE_BOW = 4,
	ITEM_TYPE_ARROW = 5,
	ITEM_TYPE_THROWN_MISSILE = 6,
	ITEM_TYPE_POTION = 7, // potion/magic item
	ITEM_TYPE_SCROLL = 8, // scroll/magic item
	ITEM_TYPE_WAND = 9,
	ITEM_TYPE_TOOL = 10,
	ITEM_TYPE_FOOD = 11,
	ITEM_TYPE_SHIELD = 12,
	ITEM_TYPE_ARMOR = 13,
	ITEM_TYPE_HELM = 14,
	ITEM_TYPE_GLOVES = 15,
	ITEM_TYPE_SHIELD_2 = 16,
	// don't know why a second type of shield is used ; it is actually checked
	// in the armor code (item >= 12 and <= 17)
	// and you can't equip another (12) shield while wearing it ... I didn't
	// find a single item with this property in the bladbase.exs ...
	ITEM_TYPE_BOOTS = 17,
	ITEM_TYPE_RING = 18,
	ITEM_TYPE_NECKLACE = 19,
	ITEM_TYPE_WEAPON_POISON = 20,
	ITEM_TYPE_NON_USE_OBJECT = 21,
	ITEM_TYPE_PANTS = 22,
	ITEM_TYPE_CROSSBOW = 23,
	ITEM_TYPE_BOLTS = 24,
	ITEM_TYPE_MISSILE_NO_AMMO = 25, //e.g slings
	ITEM_TYPE_UNUSED1 = 26, // these are here solely because they are options in the editor
	ITEM_TYPE_UNUSED2 = 27,
};

/*      items[i].ability      */
enum eItemAbil {
	// Weapon abilities
	ITEM_NO_ABILITY = 0,
	ITEM_FLAMING_WEAPON = 1,
	ITEM_DEMON_SLAYER = 2,
	ITEM_UNDEAD_SLAYER = 3,
	ITEM_LIZARD_SLAYER = 4,
	ITEM_GIANT_SLAYER = 5,
	ITEM_MAGE_SLAYER = 6,
	ITEM_PRIEST_SLAYER = 7,
	ITEM_BUG_SLAYER = 8,
	ITEM_ACIDIC_WEAPON = 9,
	ITEM_SOULSUCKER = 10,
	ITEM_DRAIN_MISSILES = 11,
	ITEM_WEAK_WEAPON = 12,
	ITEM_CAUSES_FEAR = 13,
	ITEM_POISONED_WEAPON = 14,
	// General abilities
	ITEM_PROTECTION = 30,
	ITEM_FULL_PROTECTION = 31,
	ITEM_FIRE_PROTECTION = 32,
	ITEM_COLD_PROTECTION = 33,
	ITEM_POISON_PROTECTION = 34,
	ITEM_MAGIC_PROTECTION = 35,
	ITEM_ACID_PROTECTION = 36,
	ITEM_SKILL = 37,
	ITEM_STRENGTH = 38,
	ITEM_DEXTERITY = 39,
	ITEM_INTELLIGENCE = 40,
	ITEM_ACCURACY = 41,
	ITEM_THIEVING = 42,
	ITEM_GIANT_STRENGTH = 43,
	ITEM_LIGHTER_OBJECT = 44,
	ITEM_HEAVIER_OBJECT = 45,
	ITEM_OCCASIONAL_BLESS = 46,
	ITEM_OCCASIONAL_HASTE = 47,
	ITEM_LIFE_SAVING = 48,
	ITEM_PROTECT_FROM_PETRIFY = 49,
	ITEM_REGENERATE = 50,
	ITEM_POISON_AUGMENT = 51,
	ITEM_DISEASE_PARTY = 52,
	ITEM_WILL = 53,
	ITEM_FREE_ACTION = 54,
	ITEM_SPEED = 55,
	ITEM_SLOW_WEARER = 56,
	ITEM_PROTECT_FROM_UNDEAD = 57,
	ITEM_PROTECT_FROM_DEMONS = 58,
	ITEM_PROTECT_FROM_HUMANOIDS = 59,
	ITEM_PROTECT_FROM_REPTILES = 60,
	ITEM_PROTECT_FROM_GIANTS = 61,
	ITEM_PROTECT_FROM_DISEASE = 62,
	// Nonspell Usable
	ITEM_POISON_WEAPON = 70, //put poison on weapon
	ITEM_BLESS_CURSE = 71,
	ITEM_AFFECT_POISON = 72,
	ITEM_HASTE_SLOW = 73,
	ITEM_AFFECT_INVULN = 74,
	ITEM_AFFECT_MAGIC_RES = 75,
	ITEM_AFFECT_WEB = 76,
	ITEM_AFFECT_DISEASE = 77,
	ITEM_AFFECT_SANCTUARY = 78,
	ITEM_AFFECT_DUMBFOUND = 79,
	ITEM_AFFECT_MARTYRS_SHIELD = 80,
	ITEM_AFFECT_SLEEP = 81,
	ITEM_AFFECT_PARALYSIS = 82,
	ITEM_AFFECT_ACID = 83,
	ITEM_BLISS = 84,
	ITEM_AFFECT_EXPERIENCE = 85,
	ITEM_AFFECT_SKILL_POINTS = 86,
	ITEM_AFFECT_HEALTH = 87,
	ITEM_AFFECT_SPELL_POINTS = 88,
	ITEM_DOOM = 89,
	ITEM_LIGHT = 90,
	ITEM_STEALTH = 91,
	ITEM_FIREWALK = 92,
	ITEM_FLYING = 93,
	ITEM_MAJOR_HEALING = 94,
	ITEM_CALL_SPECIAL = 95, //new (Classic Blades of Exile) item property
	// Spell Usable
	ITEM_SPELL_FLAME = 110,
	ITEM_SPELL_FIREBALL = 111,
	ITEM_SPELL_FIRESTORM = 112,
	ITEM_SPELL_KILL = 113,
	ITEM_SPELL_ICE_BOLT = 114,
	ITEM_SPELL_SLOW = 115,
	ITEM_SPELL_SHOCKWAVE = 116,
	ITEM_SPELL_DISPEL_UNDEAD = 117,
	ITEM_SPELL_RAVAGE_SPIRIT = 118,
	ITEM_SPELL_SUMMONING = 119,
	ITEM_SPELL_MASS_SUMMONING = 120,
	ITEM_SPELL_ACID_SPRAY = 121,
	ITEM_SPELL_STINKING_CLOUD = 122,
	ITEM_SPELL_SLEEP_FIELD = 123,
	ITEM_SPELL_VENOM = 124,
	ITEM_SPELL_SHOCKSTORM = 125,
	ITEM_SPELL_PARALYSIS = 126,
	ITEM_SPELL_WEB_SPELL = 127,
	ITEM_SPELL_STRENGTHEN_TARGET = 128, //wand of carrunos effect
	ITEM_SPELL_QUICKFIRE = 129,
	ITEM_SPELL_MASS_CHARM = 130,
	ITEM_SPELL_MAGIC_MAP = 131,
	ITEM_SPELL_DISPEL_BARRIER = 132,
	ITEM_SPELL_MAKE_ICE_WALL = 133,
	ITEM_SPELL_CHARM_SPELL = 134,
	ITEM_SPELL_ANTIMAGIC_CLOUD = 135,
	// Reagents
	ITEM_HOLLY = 150, // Holly/Toadstool
	ITEM_COMFREY_ROOT = 151,
	ITEM_GLOWING_NETTLE = 152,
	ITEM_WORMGRASS = 153, // Crypt Shroom/Wormgr.
	ITEM_ASPTONGUE_MOLD = 154,
	ITEM_EMBER_FLOWERS = 155,
	ITEM_GRAYMOLD = 156,
	ITEM_MANDRAKE = 157,
	ITEM_SAPPHIRE = 158,
	ITEM_SMOKY_CRYSTAL = 159,
	ITEM_RESSURECTION_BALM = 160,
	ITEM_LOCKPICKS = 161,
	// Missile Abilities
	ITEM_MISSILE_RETURNING = 170,
	ITEM_MISSILE_LIGHTNING = 171,
	ITEM_MISSILE_EXPLODING = 172,
	ITEM_MISSILE_ACID = 173,
	ITEM_MISSILE_SLAY_UNDEAD = 174,
	ITEM_MISSILE_SLAY_DEMON = 175,
	ITEM_MISSILE_HEAL_TARGET = 176,
};

/* damage type*/
/* used as parameter to some functions */
enum eDamageType {
	DAMAGE_WEAPON = 0,
	DAMAGE_FIRE = 1,
	DAMAGE_POISON = 2,
	DAMAGE_MAGIC = 3,
	DAMAGE_UNBLOCKABLE = 4, //from the source files - the display is the same as the magic one (damage_monst in SPECIALS.cpp)
	DAMAGE_COLD = 5,
	DAMAGE_UNDEAD = 6, //from the source files - the display is the same as the weapon one
	DAMAGE_DEMON = 7, //from the source files - the display is the same as the weapon one
	// 8 and 9 aren't defined : doesn't print any damage. According to the source files the 9 is DAMAGE_MARKED though. Wrong ?
	DAMAGE_MARKED = 10, // usage: DAMAGE_MARKED + damage_type
	DAMAGE_WEAPON_MARKED = 10,
	DAMAGE_FIRE_MARKED = 11,
	DAMAGE_POISON_MARKED = 12,
	DAMAGE_MAGIC_MARKED = 13,
	DAMAGE_UNBLOCKABLE_MARKED = 14,
	DAMAGE_COLD_MARKED = 15,
	DAMAGE_UNDEAD_MARKED = 16,
	DAMAGE_DEMON_MARKED = 17,
	DAMAGE_NO_PRINT = 30, // usage: DAMAGE_NO_PRINT + damage_type
	DAMAGE_WEAPON_NO_PRINT = 30,
	DAMAGE_FIRE_NO_PRINT = 31,
	DAMAGE_POISON_NO_PRINT = 32,
	DAMAGE_MAGIC_NO_PRINT = 33,
	DAMAGE_UNBLOCKABLE_NO_PRINT = 34,
	DAMAGE_COLD_NO_PRINT = 35,
	DAMAGE_UNDEAD_NO_PRINT = 36,
	DAMAGE_DEMON_NO_PRINT = 37,
	// What about both NO_PRINT and MARKED?
};

inline void operator -= (eDamageType& cur, eDamageType othr){
	if((othr == DAMAGE_MARKED && cur >= DAMAGE_MARKED && cur < DAMAGE_NO_PRINT) ||
	   (othr == DAMAGE_NO_PRINT && cur >= DAMAGE_NO_PRINT))
		cur = (eDamageType) ((int)cur - (int)othr);
}

inline void operator += (eDamageType& cur, eDamageType othr){
	if((othr == DAMAGE_MARKED || othr == DAMAGE_NO_PRINT) && cur < DAMAGE_MARKED)
		cur = (eDamageType) ((int)cur + (int)othr);
}

//class sbyte {
//	signed char c;
//public:
//	operator int() {return c;}
//	sbyte(signed char k) : c(k) {}
//}

enum eSpecContext {
	SPEC_OUT_MOVE = 0,
	SPEC_TOWN_MOVE = 1,
	SPEC_COMBAT_MOVE = 2,
	SPEC_OUT_LOOK = 3,
	SPEC_TOWN_LOOK = 4,
	SPEC_ENTER_TOWN = 5,
	SPEC_LEAVE_TOWN = 6,
	SPEC_TALK = 7,
	SPEC_USE_SPEC_ITEM = 8,
	SPEC_TOWN_TIMER = 9,
	SPEC_SCEN_TIMER = 10,
	SPEC_PARTY_TIMER = 11,
	SPEC_KILL_MONST = 12,
	SPEC_OUTDOOR_ENC = 13,
	SPEC_WIN_ENCOUNTER = 14,
	SPEC_FLEE_ENCOUNTER = 15,
	SPEC_TARGET = 16,
	SPEC_USE_SPACE = 17,
	SPEC_SEE_MONST = 18,
};

enum eSpecNodeType {
	SPEC_ERROR = -1,
	SPEC_NULL = 0,
	SPEC_SET_SDF = 1,
	SPEC_INC_SDF = 2,
	SPEC_DISPLAY_MSG = 3,
	SPEC_SECRET_PASSAGE = 4,
	SPEC_DISPLAY_SM_MSG = 5,
	SPEC_FLIP_SDF = 6,
	SPEC_OUT_BLOCK = 7,
	SPEC_TOWN_BLOCK = 8,
	SPEC_FIGHT_BLOCK = 9,
	SPEC_LOOK_BLOCK = 10,
	SPEC_CANT_ENTER = 11,
	SPEC_CHANGE_TIME = 12,
	SPEC_SCEN_TIMER_START = 13,
	SPEC_PLAY_SOUND = 14,
	SPEC_CHANGE_HORSE_OWNER = 15,
	SPEC_CHANGE_BOAT_OWNER = 16,
	SPEC_SET_TOWN_VISIBILITY = 17,
	SPEC_MAJOR_EVENT_OCCURRED = 18,
	SPEC_FORCED_GIVE = 19,
	SPEC_BUY_ITEMS_OF_TYPE = 20,
	SPEC_CALL_GLOBAL = 21,
	SPEC_SET_SDF_ROW = 22,
	SPEC_COPY_SDF = 23,
	SPEC_SANCTIFY = 24,
	SPEC_REST = 25,
	SPEC_WANDERING_WILL_FIGHT = 26,
	SPEC_END_SCENARIO = 27,
	SPEC_DISPLAY_PICTURE = 28,//new (Classic Blades of Exile) special
	SPEC_RAND_SDF = 29,
	SPEC_ONCE_GIVE_ITEM = 50,
	SPEC_ONCE_GIVE_SPEC_ITEM = 51,
	SPEC_ONCE_NULL = 52,
	SPEC_ONCE_SET_SDF = 53,
	SPEC_ONCE_DISPLAY_MSG = 54,
	SPEC_ONCE_DIALOG = 55,
	SPEC_ONCE_DIALOG_TERRAIN = 56,
	SPEC_ONCE_DIALOG_MONSTER = 57,
	SPEC_ONCE_GIVE_ITEM_DIALOG = 58,
	SPEC_ONCE_GIVE_ITEM_TERRAIN = 59,
	SPEC_ONCE_GIVE_ITEM_MONSTER = 60,
	SPEC_ONCE_OUT_ENCOUNTER = 61,
	SPEC_ONCE_TOWN_ENCOUNTER = 62,
	SPEC_ONCE_TRAP = 63,
	SPEC_SELECT_PC = 80,
	SPEC_DAMAGE = 81,
	SPEC_AFFECT_HP = 82,
	SPEC_AFFECT_SP = 83,
	SPEC_AFFECT_XP = 84,
	SPEC_AFFECT_SKILL_PTS = 85,
	SPEC_AFFECT_DEADNESS = 86,
	SPEC_AFFECT_POISON = 87,
	SPEC_AFFECT_SPEED = 88,
	SPEC_AFFECT_INVULN = 89,
	SPEC_AFFECT_MAGIC_RES = 90,
	SPEC_AFFECT_WEBS = 91,
	SPEC_AFFECT_DISEASE = 92,
	SPEC_AFFECT_SANCTUARY = 93,
	SPEC_AFFECT_CURSE_BLESS = 94,
	SPEC_AFFECT_DUMBFOUND = 95,
	SPEC_AFFECT_SLEEP = 96,
	SPEC_AFFECT_PARALYSIS = 97,
	SPEC_AFFECT_STAT = 98,
	SPEC_AFFECT_MAGE_SPELL = 99,
	SPEC_AFFECT_PRIEST_SPELL = 100,
	SPEC_AFFECT_GOLD = 101,
	SPEC_AFFECT_FOOD = 102,
	SPEC_AFFECT_ALCHEMY = 103,
	SPEC_AFFECT_STEALTH = 104,
	SPEC_AFFECT_FIREWALK = 105,
	SPEC_AFFECT_FLIGHT = 106,
	SPEC_IF_SDF = 130,
	SPEC_IF_TOWN_NUM = 131,
	SPEC_IF_RANDOM = 132,
	SPEC_IF_HAVE_SPECIAL_ITEM = 133,
	SPEC_IF_SDF_COMPARE = 134,
	SPEC_IF_TOWN_TER_TYPE = 135,
	SPEC_IF_OUT_TER_TYPE = 136,
	SPEC_IF_HAS_GOLD = 137,
	SPEC_IF_HAS_FOOD = 138,
	SPEC_IF_ITEM_CLASS_ON_SPACE = 139,
	SPEC_IF_HAVE_ITEM_CLASS = 140,
	SPEC_IF_EQUIP_ITEM_CLASS = 141,
	SPEC_IF_HAS_GOLD_AND_TAKE = 142,
	SPEC_IF_HAS_FOOD_AND_TAKE = 143,
	SPEC_IF_ITEM_CLASS_ON_SPACE_AND_TAKE = 144,
	SPEC_IF_HAVE_ITEM_CLASS_AND_TAKE = 145,
	SPEC_IF_EQUIP_ITEM_CLASS_AND_TAKE = 146,
	SPEC_IF_DAY_REACHED = 147,
	SPEC_IF_BARRELS = 148,
	SPEC_IF_CRATES = 149,
	SPEC_IF_EVENT_OCCURRED = 150,
	SPEC_IF_HAS_CAVE_LORE = 151,
	SPEC_IF_HAS_WOODSMAN = 152,
	SPEC_IF_ENOUGH_STATISTIC = 153,//modified (Classic Blades of Exile) special node
	SPEC_IF_TEXT_RESPONSE = 154,
	SPEC_IF_SDF_EQ = 155,
	SPEC_IF_ENOUGH_SPECIES = 156,
	SPEC_SET_TOWN_STATUS = 170,
	SPEC_TOWN_CHANGE_TER = 171,
	SPEC_TOWN_SWAP_TER = 172,
	SPEC_TOWN_TRANS_TER = 173,
	SPEC_TOWN_MOVE_PARTY = 174,
	SPEC_TOWN_HIT_SPACE = 175,
	SPEC_TOWN_EXPLODE_SPACE = 176,
	SPEC_TOWN_LOCK_SPACE = 177,
	SPEC_TOWN_UNLOCK_SPACE = 178,
	SPEC_TOWN_SFX_BURST = 179,
	SPEC_TOWN_CREATE_WANDERING = 180,
	SPEC_TOWN_PLACE_MONST = 181,
	SPEC_TOWN_DESTROY_MONST = 182,
	SPEC_TOWN_NUKE_MONSTS = 183,
	SPEC_TOWN_GENERIC_LEVER = 184,
	SPEC_TOWN_GENERIC_PORTAL = 185,
	SPEC_TOWN_GENERIC_BUTTON = 186,
	SPEC_TOWN_GENERIC_STAIR = 187,
	SPEC_TOWN_LEVER = 188,
	SPEC_TOWN_PORTAL = 189,
	SPEC_TOWN_STAIR = 190,
	SPEC_TOWN_RELOCATE = 191, // Relocate outdoors
	SPEC_TOWN_PLACE_ITEM = 192,
	SPEC_TOWN_SPLIT_PARTY = 193,
	SPEC_TOWN_REUNITE_PARTY = 194,
	SPEC_TOWN_TIMER_START = 195,
	SPEC_TOWN_CHANGE_LIGHTING = 196,//new (Classic Blades of Exile) special node
	SPEC_TOWN_CHANGE_ATTITUDE = 197,//new (Classic Blades of Exile) special node
	SPEC_RECT_PLACE_FIRE = 200,
	SPEC_RECT_PLACE_FORCE = 201,
	SPEC_RECT_PLACE_ICE = 202,
	SPEC_RECT_PLACE_BLADE = 203,
	SPEC_RECT_PLACE_SCLOUD = 204,
	SPEC_RECT_PLACE_SLEEP = 205,
	SPEC_RECT_PLACE_QUICKFIRE = 206,
	SPEC_RECT_PLACE_FIRE_BARR = 207,
	SPEC_RECT_PLACE_FORCE_BARR = 208,
	SPEC_RECT_CLEANSE = 209,
	SPEC_RECT_PLACE_SFX = 210,
	SPEC_RECT_PLACE_OBJECT = 211, // place barrels, etc
	SPEC_RECT_MOVE_ITEMS = 212,
	SPEC_RECT_DESTROY_ITEMS = 213,
	SPEC_RECT_CHANGE_TER = 214,
	SPEC_RECT_SWAP_TER = 215,
	SPEC_RECT_TRANS_TER = 216,
	SPEC_RECT_LOCK = 217,
	SPEC_RECT_UNLOCK = 218,
	SPEC_OUT_MAKE_WANDER = 225,
	SPEC_OUT_CHANGE_TER = 226,
	SPEC_OUT_PLACE_ENCOUNTER = 227,
	SPEC_OUT_MOVE_PARTY = 228,
	SPEC_OUT_STORE = 229,
};

enum eTalkNodeType {
	TALK_REGULAR = 0,
	TALK_DEP_ON_SDF = 1,
	TALK_SET_SDF = 2,
	TALK_INN = 3,
	TALK_DEP_ON_TIME = 4,
	TALK_DEP_ON_TIME_AND_EVENT = 5,
	TALK_DEP_ON_TOWN = 6,
	TALK_BUY_ITEMS = 7,
	TALK_TRAINING = 8,
	TALK_BUY_MAGE = 9,
	TALK_BUY_PRIEST = 10,
	TALK_BUY_ALCHEMY = 11,
	TALK_BUY_HEALING = 12,
	TALK_SELL_WEAPONS = 13,
	TALK_SELL_ARMOR = 14,
	TALK_SELL_ITEMS = 15,
	TALK_IDENTIFY = 16,
	TALK_ENCHANT = 17,
	TALK_BUY_INFO = 18,
	TALK_BUY_SDF = 19,
	TALK_BUY_SHIP = 20,
	TALK_BUY_HORSE = 21,
	TALK_BUY_SPEC_ITEM = 22,
	TALK_BUY_JUNK = 23,
	TALK_BUY_TOWN_LOC = 24,
	TALK_END_FORCE = 25,
	TALK_END_FIGHT = 26,
	TALK_END_ALARM = 27, // Town hostile
	TALK_END_DIE = 28,
	TALK_CALL_TOWN_SPEC = 29,
	TALK_CALL_SCEN_SPEC = 30,
};

enum eMageSpells {
	SPELL_MAGE_LIGHT = 0,
	SPELL_MAGE_SPARK = 1,
	SPELL_MAGE_MINOR_HASTE = 2,
	SPELL_MAGE_STRENGTH = 3,
	SPELL_MAGE_SCARE = 4,
	SPELL_MAGE_FLAME_CLOUD = 5,
	SPELL_MAGE_IDENTIFY = 6,
	SPELL_MAGE_SCRY_MONSTER = 7,
	SPELL_MAGE_GOO = 8,
	SPELL_MAGE_TRUE_SIGHT = 9,
	SPELL_MAGE_MINOR_POISON = 10,
	SPELL_MAGE_FLAME = 11,
	SPELL_MAGE_SLOW = 12,
	SPELL_MAGE_DUMBFOUND = 13,
	SPELL_MAGE_ENVENOM = 14,
	SPELL_MAGE_STINKING_CLOUD = 15,
	SPELL_MAGE_SUMMON_BEAST = 16,
	SPELL_MAGE_CONFLAGRATION = 17,
	SPELL_MAGE_DISPEL_FIELDS = 18,
	SPELL_MAGE_SLEEP_CLOUD = 19,
	SPELL_MAGE_UNLOCK = 20,
	SPELL_MAGE_HASTE = 21,
	SPELL_MAGE_FIREBALL = 22,
	SPELL_MAGE_LONG_LIGHT = 23,
	SPELL_MAGE_FEAR = 24,
	SPELL_MAGE_WALL_OF_FORCE = 25,
	SPELL_MAGE_WEAK_SUMMONING = 26,
	SPELL_MAGE_FLAME_ARROWS = 27,
	SPELL_MAGE_WEB = 28,
	SPELL_MAGE_RESIST_MAGIC = 29,
	SPELL_MAGE_POISON = 30,
	SPELL_MAGE_ICE_BOLT = 31,
	SPELL_MAGE_SLOW_GROUP = 32,
	SPELL_MAGE_MAGIC_MAP = 33,
	SPELL_MAGE_CAPTURE_SOUL = 34,
	SPELL_MAGE_SIMULACRUM = 35,
	SPELL_MAGE_VENOM_ARROWS = 36,
	SPELL_MAGE_WALL_OF_ICE = 37,
	SPELL_MAGE_STEALTH = 38,
	SPELL_MAGE_MAJOR_HASTE = 39,
	SPELL_MAGE_FIRE_STORM = 40,
	SPELL_MAGE_DISPEL_BARRIER = 41,
	SPELL_MAGE_FIRE_BARRIER = 42,
	SPELL_MAGE_SUMMONING = 43,
	SPELL_MAGE_SHOCKSTORM = 44,
	SPELL_MAGE_SPRAY_FIELDS = 45,
	SPELL_MAGE_MAJOR_POISON = 46,
	SPELL_MAGE_GROUP_FEAR = 47,
	SPELL_MAGE_KILL = 48,
	SPELL_MAGE_PARALYSIS = 49,
	SPELL_MAGE_DAEMON = 50,
	SPELL_MAGE_ANTIMAGIC_CLOUD = 51,
	SPELL_MAGE_MINDDUEL = 52,
	SPELL_MAGE_FLIGHT = 53,
	SPELL_MAGE_SHOCKWAVE = 54,
	SPELL_MAGE_MAJOR_BLESSING = 55,
	SPELL_MAGE_MASS_PARALYSIS = 56,
	SPELL_MAGE_PROTECTION = 57,
	SPELL_MAGE_MAJOR_SUMMON = 58,
	SPELL_MAGE_FORCE_BARRIER = 59,
	SPELL_MAGE_QUICKFIRE = 60,
	SPELL_MAGE_DEATH_ARROWS = 61,
};

enum ePriestSpells {
	SPELL_PRIEST_MINOR_BLESS = 0,
	SPELL_PRIEST_MINOR_HEAL = 1,
	SPELL_PRIEST_WEAKEN_POISON = 2,
	SPELL_PRIEST_TURN_UNDEAD = 3,
	SPELL_PRIEST_LOCATION = 4,
	SPELL_PRIEST_SANCTUARY = 5,
	SPELL_PRIEST_SYMBIOSIS = 6,
	SPELL_PRIEST_MINOR_MANNA = 7,
	SPELL_PRIEST_RITUAL_SANCTIFY = 8,
	SPELL_PRIEST_STUMBLE = 9,
	SPELL_PRIEST_BLESS = 10,
	SPELL_PRIEST_CURE_POISON = 11,
	SPELL_PRIEST_CURSE = 12,
	SPELL_PRIEST_LIGHT = 13,
	SPELL_PRIEST_WOUND = 14,
	SPELL_PRIEST_SUMMON_SPIRIT = 15,
	SPELL_PRIEST_MOVE_MOUNTAINS = 16,
	SPELL_PRIEST_CHARM_FOE = 17,
	SPELL_PRIEST_DISEASE = 18,
	SPELL_PRIEST_AWAKEN = 19,
	SPELL_PRIEST_HEAL = 20,
	SPELL_PRIEST_LIGHT_HEAL_ALL = 21,
	SPELL_PRIEST_HOLY_SCOURGE = 22,
	SPELL_PRIEST_DETECT_LIFE = 23,
	SPELL_PRIEST_CURE_PARALYSIS = 24,
	SPELL_PRIEST_MANNA = 25,
	SPELL_PRIEST_FORCEFIELD = 26,
	SPELL_PRIEST_CURE_DISEASE = 27,
	SPELL_PRIEST_RESTORE_MIND = 28,
	SPELL_PRIEST_SMITE = 29,
	SPELL_PRIEST_CURE_PARTY = 30,
	SPELL_PRIEST_CURSE_ALL = 31,
	SPELL_PRIEST_DISPEL_UNDEAD = 32,
	SPELL_PRIEST_REMOVE_CURSE = 33,
	SPELL_PRIEST_STICKS_TO_SNAKES = 34,
	SPELL_PRIEST_MARTYRS_SHIELD = 35,
	SPELL_PRIEST_CLEANSE = 36,
	SPELL_PRIEST_FIREWALK = 37,
	SPELL_PRIEST_BLESS_PARTY = 38,
	SPELL_PRIEST_MAJOR_HEAL = 39,
	SPELL_PRIEST_RAISE_DEAD = 40,
	SPELL_PRIEST_FLAMESTRIKE = 41,
	SPELL_PRIEST_MASS_SANCTUARY = 42,
	SPELL_PRIEST_SUMMON_HOST = 43,
	SPELL_PRIEST_SHATTER = 44,
	SPELL_PRIEST_DISPEL_FIELDS = 45,
	SPELL_PRIEST_HEAL_ALL = 46,
	SPELL_PRIEST_REVIVE = 47,
	SPELL_PRIEST_HYPERACTIVITY = 48,
	SPELL_PRIEST_DESTONE = 49,
	SPELL_PRIEST_GUARDIAN = 50,
	SPELL_PRIEST_MASS_CHARM = 51,
	SPELL_PRIEST_PROTECTIVE_CIRCLE = 52,
	SPELL_PRIEST_PESTILENCE = 53,
	SPELL_PRIEST_REVIVE_ALL = 54,
	SPELL_PRIEST_RAVAGE_SPIRIT = 55,
	SPELL_PRIEST_RESURRECT = 56,
	SPELL_PRIEST_DIVINE_THUD = 57,
	SPELL_PRIEST_AVATAR = 58,
	SPELL_PRIEST_WALL_OF_BLADES = 59,
	SPELL_PRIEST_WORD_OF_RECALL = 60,
	SPELL_PRIEST_MAJOR_CLEANSING = 61,
};

//Specific spells called when using items
enum eItemsSpells {
    SPELL_ITEMS_STRENGHTEN_TARGET = 62, //wand of carrunos effect
    SPELL_ITEMS_ICE_WALL_BALLS = 64, //circular radius rather than straight wall
    SPELL_ITEMS_GOO_BOMB = 65, //greater radius than webs
    SPELL_ITEMS_FOUL_VAPORS = 66, //greater radius than stinking cloud
    SPELL_ITEMS_SPRAY_ACID = 68,
    SPELL_ITEMS_PARALYZE = 69, //powerful paralysis (won't break out of it soon)
};

enum eMonstersMageSpells {
    SPELL_MONST_MAGE_NO_SPELL = 0,
    SPELL_MONST_MAGE_SPARK = 1,
    SPELL_MONST_MAGE_MINOR_HASTE = 2,
    SPELL_MONST_MAGE_STRENGH = 3,
    SPELL_MONST_MAGE_FLAME_CLOUD = 4,
    SPELL_MONST_MAGE_FLAME = 5,
    SPELL_MONST_MAGE_MINOR_POISON = 6,
    SPELL_MONST_MAGE_SLOW = 7,
    SPELL_MONST_MAGE_DUMBFOUND = 8,
    SPELL_MONST_MAGE_STINKING_CLOUD = 9,
    SPELL_MONST_MAGE_SUMMON_BEAST = 10,
    SPELL_MONST_MAGE_CONFLAGRATION = 11,
    SPELL_MONST_MAGE_FIREBALL = 12,
    SPELL_MONST_MAGE_WEAK_SUMMONING = 13,
    SPELL_MONST_MAGE_WEB = 14,
    SPELL_MONST_MAGE_POISON = 15,
    SPELL_MONST_MAGE_ICE_BOLT = 16,
    SPELL_MONST_MAGE_SLOW_GROUP = 17,
    SPELL_MONST_MAGE_MAJOR_HASTE = 18,
    SPELL_MONST_MAGE_FIRESTORM = 19,
    SPELL_MONST_MAGE_SUMMONING = 20,
    SPELL_MONST_MAGE_SHOCKSTORM = 21,
    SPELL_MONST_MAGE_MAJOR_POISON = 22,
    SPELL_MONST_MAGE_KILL = 23,
    SPELL_MONST_MAGE_DAEMON = 24,
    SPELL_MONST_MAGE_MAJOR_BLESSING = 25,
    SPELL_MONST_MAGE_MAJOR_SUMMONING = 26,
    SPELL_MONST_MAGE_SHOCKWAVE = 27,
};

enum eMonstersPriestSpells {
    SPELL_MONST_PRIEST_NO_SPELL = 0,
    SPELL_MONST_PRIEST_MINOR_BLESS = 1,
    SPELL_MONST_PRIEST_LIGHT_HEAL = 2,
    SPELL_MONST_PRIEST_WRACK = 3,
    SPELL_MONST_PRIEST_STUMBLE = 4,
    SPELL_MONST_PRIEST_BLESS = 5,
    SPELL_MONST_PRIEST_CURSE = 6,
    SPELL_MONST_PRIEST_WOUND = 7,
    SPELL_MONST_PRIEST_SUMMON_SPIRIT = 8,
    SPELL_MONST_PRIEST_DISEASE = 9,
    SPELL_MONST_PRIEST_HEAL = 10,
    SPELL_MONST_PRIEST_HOLY_SCOURGE = 11,
    SPELL_MONST_PRIEST_SMITE = 12,
    SPELL_MONST_PRIEST_CURSE_ALL = 13,
    SPELL_MONST_PRIEST_STICKS_TO_SNAKES = 14,
    SPELL_MONST_PRIEST_MARTYRS_SHIELD = 15,
    SPELL_MONST_PRIEST_BLESS_ALL = 16,
    SPELL_MONST_PRIEST_MAJOR_HEAL = 17,
    SPELL_MONST_PRIEST_FLAMESTRIKE = 18,
    SPELL_MONST_PRIEST_SUMMON_HOST = 19,
    SPELL_MONST_PRIEST_REVIVE_SELF = 20,// renamed from heal all, to avoid confusion (this isn't a mass spell !)
    SPELL_MONST_PRIEST_UNHOLY_RAVAGING = 21,
    SPELL_MONST_PRIEST_SUMMON_GUARDIAN = 22,
    SPELL_MONST_PRIEST_PESTILENCE = 23,
    SPELL_MONST_PRIEST_REVIVE_ALL = 24,
    SPELL_MONST_PRIEST_AVATAR = 25,
    SPELL_MONST_PRIEST_DIVINE_THUD = 26,
};

enum eShopTypes {
    SHOP_WEAPON_SHOP = 0,
    SHOP_ARMOR_SHOP = 1,
    SHOP_MISC_SHOP = 2,
    SHOP_HEALER = 3,
    SHOP_FOOD = 4,
    SHOP_MAGIC_SHOP_1 = 5,
    SHOP_MAGIC_SHOP_2 = 6,
    SHOP_MAGIC_SHOP_3 = 7,
    SHOP_MAGIC_SHOP_4 = 8,
    SHOP_MAGIC_SHOP_5 = 9,
    SHOP_MAGE_SPELLS = 10,
    SHOP_PRIEST_SPELLS = 11,
    SHOP_ALCHEMY = 12,
};

#endif
