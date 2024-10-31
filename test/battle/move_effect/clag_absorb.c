#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_CLAG_ABSORB].effect == EFFECT_CLAG_ABSORB);
}

SINGLE_BATTLE_TEST("Clag Absorb cures Poison")
{
    u32 poisonStatus;
    PARAMETRIZE { poisonStatus = STATUS1_POISON; }
    PARAMETRIZE { poisonStatus = STATUS1_TOXIC_POISON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RATTATA) { Status1(poisonStatus); }
    } WHEN {
        TURN { MOVE(player, MOVE_CLAG_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLAG_ABSORB, player);
    } SCENE {
        MESSAGE("Rattata was cured of its poisoning.");
    }
}

SINGLE_BATTLE_TEST("Clag Absorb does not cure Poison in Toxic Weather")
{
    u32 poisonStatus;
    PARAMETRIZE { poisonStatus = STATUS1_POISON; }
    PARAMETRIZE { poisonStatus = STATUS1_TOXIC_POISON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RATTATA) { Status1(poisonStatus); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPREAD); MOVE(opponent, MOVE_SPLASH); }
        TURN { MOVE(player, MOVE_CLAG_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPREAD, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLAG_ABSORB, player);
    } SCENE {
        STATUS_ICON(opponent, poisonStatus);
    }
}

SINGLE_BATTLE_TEST("Clag Absorb deals more damage to Poisoned Pokémon", s16 damage)
{
    u32 poisonStatus;
    PARAMETRIZE { poisonStatus = STATUS1_NONE; }
    PARAMETRIZE { poisonStatus = STATUS1_POISON; }
    PARAMETRIZE { poisonStatus = STATUS1_TOXIC_POISON; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RATTATA) { Status1(poisonStatus); }
    } WHEN {
        TURN { MOVE(player, MOVE_CLAG_ABSORB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CLAG_ABSORB, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT(results[0].damage < results[1].damage);
        EXPECT(results[0].damage < results[2].damage);
    }
}
