#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gMovesInfo[MOVE_SONIC_BOOM].effect == EFFECT_FIXED_DAMAGE_ARG);
    ASSUME(gMovesInfo[MOVE_SONIC_BOOM].additionalEffects[0].moveEffect == MOVE_EFFECT_FIXED_SUPER_EFFECTIVE_TO_ARG);
}

SINGLE_BATTLE_TEST("Sonic Boom deals fixed damage")
{
    s16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RATTATA);
    } WHEN {
        TURN { MOVE(player, MOVE_SONIC_BOOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT(damage == (gMovesInfo[MOVE_SONIC_BOOM].argument));
    }
}

SINGLE_BATTLE_TEST("Sonic Boom is super effective on sound types")
{
    s16 damage;
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_EKANS);
    } WHEN {
        TURN { MOVE(player, MOVE_SONIC_BOOM); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SONIC_BOOM, player);
        HP_BAR(opponent, captureDamage: &damage);
    } THEN {
        EXPECT(damage == (gMovesInfo[MOVE_SONIC_BOOM].argument * 2));
    }
}
