#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hydra converts Scratch into a three-strike move")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_SCRATCH) < 3);
        ASSUME(GetMoveEffect(MOVE_SCRATCH) == EFFECT_HIT);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_HYDRA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Hydra works as an innate")
{
    GIVEN {
        ASSUME(GetMoveCategory(MOVE_SCRATCH) != DAMAGE_CATEGORY_STATUS);
        ASSUME(GetMoveStrikeCount(MOVE_SCRATCH) < 3);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TELEPATHY); Innates(ABILITY_HYDRA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
        HP_BAR(opponent);
    }
}
#endif

