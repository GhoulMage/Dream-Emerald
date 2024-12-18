#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoDreamEmerald[] =
{
#endif

    [SPECIES_RALTSD] =
    {
        .baseHP        = 30,
        .baseAttack    = 38,
        .baseDefense   = 25,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 35,
        .types = { TYPE_PSYCHIC, TYPE_DARK },
        .catchRate = 120,
        .expYield = 46,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(75.5),
        .eggCycles = 20,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_DARK_POWER, ABILITY_DARK_POWER, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Ralts D"),
        .cryId = CRY_RALTSD,
        .natDexNum = NATIONAL_DEX_RALTSD,
        .categoryName = _("Rare"),
        .height = 4,
        .weight = 66,
        .description = COMPOUND_STRING(
            "This very unique Ralts does not have\n"
            "horns. Despite this, it is as sensitive\n"
            "to emotions as other Ralts, It looks at\n"
            "people with unease."),
        .pokemonScale = 457,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_RaltsD,
        .frontPicSize = MON_COORDS_SIZE(24, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_RaltsD,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_RaltsD,
        .backPicSize = MON_COORDS_SIZE(32, 30),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_RaltsD,
        .shinyPalette = gMonShinyPalette_RaltsD,
        .iconSprite = gMonIcon_RaltsD,
        .iconPalIndex = 2,
        FOOTPRINT(RaltsD)
        .levelUpLearnset = sRaltsDLevelUpLearnset,
        .teachableLearnset = sRaltsDTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 23, SPECIES_KIRLIAD})
    },
    [SPECIES_KIRLIAD] =
    {
        .baseHP        = 40,
        .baseAttack    = 53,
        .baseDefense   = 37,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 55,
        .types = { TYPE_PSYCHIC, TYPE_DARK },
        .catchRate = 60,
        .expYield = 105,
        .evYield_Attack = 2,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(75.5),
        .eggCycles = 20,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_DARK_POWER, ABILITY_DARK_POWER, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Kirlia D"),
        .cryId = CRY_KIRLIAD,
        .natDexNum = NATIONAL_DEX_KIRLIAD,
        .categoryName = _("Rejection"),
        .height = 9,
        .weight = 226,
        .description = COMPOUND_STRING(
            "Dark Kirlia is getting used to its trainer.\n"
            "Its physical power seems to be stronger\n"
            "than that of other Kirlia."),
        .pokemonScale = 317,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KirliaD,
        .frontPicSize = MON_COORDS_SIZE(32, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_KirliaD,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_KirliaD,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_KirliaD,
        .shinyPalette = gMonShinyPalette_KirliaD,
        .iconSprite = gMonIcon_KirliaD,
        .iconPalIndex = 2,
        FOOTPRINT(KirliaD)
        .levelUpLearnset = sKirliaDLevelUpLearnset,
        .teachableLearnset = sKirliaDTeachableLearnset,
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_GARDEVOIRD})
    },

    [SPECIES_GARDEVOIRD] =
    {
        .baseHP        = 72,
        .baseAttack    = 113,
        .baseDefense   = 74,
        .baseSpeed     = 96,
        .baseSpAttack  = 113,
        .baseSpDefense = 75,
        .types = { TYPE_PSYCHIC, TYPE_DARK },
        .catchRate = 20,
        .expYield = 240,
        .evYield_Attack = 3,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(75.5),
        .eggCycles = 20,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_AMORPHOUS },
        .abilities = {ABILITY_INTIMIDATE, ABILITY_DARK_POWER, ABILITY_TELEPATHY},
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Gardevoir"),
        .cryId = CRY_GARDEVOIRD,
        .natDexNum = NATIONAL_DEX_GARDEVOIRD,
        .categoryName = _("Renounce"),
        .height = 18,
        .weight = 526,
        .description = COMPOUND_STRING(
            "An unique breed of Gardevoir, strong Dark\n"
            "and Psychic power emanates from it. Its\n"
            "love for its trainer is unrivaled, but\n"
            "despises everyone else."),
        .pokemonScale = 278,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GardevoirD,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GardevoirD,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GardevoirD,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_GardevoirD,
        .shinyPalette = gMonShinyPalette_GardevoirD,
        .iconSprite = gMonIcon_GardevoirD,
        .iconPalIndex = 2,
        FOOTPRINT(GardevoirD)
        .levelUpLearnset = sGardevoirDLevelUpLearnset,
        .teachableLearnset = sGardevoirDTeachableLearnset,
    },

    [SPECIES_ADOKANA] =
    {
        .baseHP        = 70,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .baseAttack    = 120,
        .types = { TYPE_POISON, TYPE_SOUND },
        .catchRate = 40,
        .expYield = 195,
        .evYield_Attack    = 2,
        .evYield_Speed     = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 50,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },
        .abilities = {ABILITY_INTIMIDATE, ABILITY_TERRORIZE, ABILITY_CRESCENDO},
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Adokana"),
        .cryId = CRY_ADOKANA,
        .natDexNum = NATIONAL_DEX_ADOKANA,
        .categoryName = _("Anaconda"),
        .height = 40,
        .weight = 500,
        .description = COMPOUND_STRING(
            "It can create a loud sound that stuns\n"
            "foes easily. It then wraps around enemies\n"
            "to asphixiate them. Its peculiar design\n"
            "scares foes that approach it."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Adokana,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Adokana,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Adokana,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Adokana,
        .shinyPalette = gMonShinyPalette_Adokana,
        .iconSprite = gMonIcon_Adokana,
        .iconPalIndex = 2,
        FOOTPRINT(Adokana)
        .levelUpLearnset = sAdokanaLevelUpLearnset,
        .teachableLearnset = sAdokanaTeachableLearnset,
    },

    [SPECIES_BONEDEA] =
    {
        .baseHP        = 134,
        .baseDefense   = 54,
        .baseSpeed     = 34,
        .baseSpAttack  = 134,
        .baseSpDefense = 74,
        .baseAttack    = 54,
        .types = { TYPE_GHOST, TYPE_GROUND },
        .catchRate = 10,
        .expYield = 215,
        .evYield_Defense    = 2,
        .evYield_SpDefense  = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 40,
        .friendship = 20,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = {ABILITY_ROCK_HEAD, ABILITY_LIGHTNING_ROD, ABILITY_BATTLE_ARMOR},
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bonedea"),
        .cryId = CRY_BONEDEA,
        .natDexNum = NATIONAL_DEX_BONEDEA,
        .categoryName = _("Mother"),
        .height = 14,
        .weight = 550,
        .description = COMPOUND_STRING(
            "She was not able to overcomer her injuries\n"
            "but she came back in perpetual anger.\n"
            "Her strength seems to be coming from\n"
            "her own repent."),
        .pokemonScale = 325,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bonedea,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Bonedea,
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Bonedea,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Bonedea,
        .shinyPalette = gMonShinyPalette_Bonedea,
        .iconSprite = gMonIcon_Bonedea,
        .iconPalIndex = 0,
        FOOTPRINT(Bonedea)
        .levelUpLearnset = sBonedeaLevelUpLearnset,
        .teachableLearnset = sBonedeaTeachableLearnset,
    },

    [SPECIES_PLUDENTEE] =
    {
        .baseHP        = 80,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 105,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 10,
        .expYield = 210,
        .evYield_Speed = 2,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_PLUS, ABILITY_POSITIVE, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pludentee"),
        .cryId = CRY_PLUSLE,
        .natDexNum = NATIONAL_DEX_PLUDENTEE,
        .categoryName = _("Uplifting"),
        .height = 12,
        .weight = 123,
        .description = COMPOUND_STRING(
            "Its static energy gives energy to those\n"
            "around. Often times Pludentee are dispatched\n"
            "in towns after catastrophes to help them\n"
            "recover from the tragedy."),
        .pokemonScale = 480,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pludentee,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Pludentee,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Pludentee,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Pludentee,
        .shinyPalette = gMonShinyPalette_Pludentee,
        .iconSprite = gMonIcon_Pludentee,
        .iconPalIndex = 0,
        FOOTPRINT(Pludentee)
        OVERWORLD(
            sPicTable_Pludentee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Pludentee,
            gShinyOverworldPalette_Pludentee
        )
        .levelUpLearnset = sPludenteeLevelUpLearnset,
        .teachableLearnset = sPludenteeTeachableLearnset,
        .eggMoveLearnset = sPludenteeEggMoveLearnset,
    },

    [SPECIES_MIDENTEE] =
    {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 80,
        .baseSpeed     = 105,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 10,
        .expYield = 210,
        .evYield_Speed = 2,
        .evYield_Attack = 2,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_MINUS, ABILITY_NEGATIVE, ABILITY_VOLT_ABSORB },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Midentee"),
        .cryId = CRY_MINUN,
        .natDexNum = NATIONAL_DEX_MIDENTEE,
        .categoryName = _("Uplifting"),
        .height = 12,
        .weight = 123,
        .description = COMPOUND_STRING(
            "It is well known that trainers that have\n"
            "both Pludentee and Midentee experience\n"
            "sudden bursts of energy, allowing them to\n"
            "perform better during Battles and Contests."),
        .pokemonScale = 410,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Midentee,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Midentee,
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Midentee,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Midentee,
        .shinyPalette = gMonShinyPalette_Midentee,
        .iconSprite = gMonIcon_Midentee,
        .iconPalIndex = 0,
        FOOTPRINT(Midentee)
        OVERWORLD(
            sPicTable_Midentee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            gOverworldPalette_Midentee,
            gShinyOverworldPalette_Midentee
        )
        .levelUpLearnset = sMidenteeLevelUpLearnset,
        .teachableLearnset = sMidenteeTeachableLearnset,
        .eggMoveLearnset = sMidenteeEggMoveLearnset,
    },

#ifdef __INTELLISENSE__
};
#endif