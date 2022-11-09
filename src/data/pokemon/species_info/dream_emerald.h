#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen1[] =
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
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Rebel"),
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
        FRONT_PIC(RaltsD, 24, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_RaltsD,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(RaltsD, 32, 30),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(RaltsD),
        ICON(RaltsD, 2),
        .footprint = gMonFootprint_RaltsD,
        LEARNSETS(RaltsD),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_KIRLIAD})
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
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Growing"),
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
        FRONT_PIC(KirliaD, 32, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_KirliaD,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(KirliaD, 48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(KirliaD),
        ICON(KirliaD, 2),
        .footprint = gMonFootprint_KirliaD,
        LEARNSETS(KirliaD),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_GARDEVOIRD})
    },

#ifdef __INTELLISENSE__
};
#endif