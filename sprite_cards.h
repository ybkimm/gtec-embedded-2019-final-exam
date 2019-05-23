#ifndef __SPRITE_CARDS_H__
#define __SPRITE_CARDS_H__

#define SPRITE_CARD_SIZE_W 8
#define SPRITE_CARD_SIZE_H 6

#define SPRITE_CARD_SPADE_A "\
┌──────┐\
│ A    │\
│ ♠    │\
│      │\
│      │\
└──────┘"
#define SPRITE_CARD_SPADE_2 "\
┌──────┐\
│ 2    │\
│ ♠    │\
│      │\
│      │\
└──────┘"
#define SPRITE_CARD_SPADE_3 "\
┌──────┐\
│ 3    │\
│ ♠    │\
│      │\
│      │\
└──────┘"
#define SPRITE_CARD_SPADE_4 "\
┌──────┐\
│ 4    │\
│ ♠    │\
│      │\
│      │\
└──────┘"

#define SPRITE_CARD_HEART_A "\
┌──────┐\
│ A    │\
│ ♥    │\
│      │\
│      │\
└──────┘"
#define SPRITE_CARD_HEART_2 "\
┌──────┐\
│ 2    │\
│ ♥    │\
│      │\
│      │\
└──────┘"
#define SPRITE_CARD_HEART_3 "\
┌──────┐\
│ 3    │\
│ ♥    │\
│      │\
│      │\
└──────┘"
#define SPRITE_CARD_HEART_4 "\
┌──────┐\
│ 4    │\
│ ♥    │\
│      │\
│      │\
└──────┘"

#define SPRITE_CARD_UNKNOWN "\
┌──────┐\
│ ?    │\
│      │\
│      │\
│      │\
└──────┘"

#define SPRITE_CARD(m,n) ( \
	(m) == 'S' ? ( \
		(n) == 1 ? SPRITE_CARD_SPADE_A : \
		(n) == 2 ? SPRITE_CARD_SPADE_2 : \
		(n) == 3 ? SPRITE_CARD_SPADE_3 : \
		(n) == 4 ? SPRITE_CARD_SPADE_4 : \
		SPRITE_CARD_UNKNOWN \
	): \
	(m) == 'H' ? ( \
		(n) == 1 ? SPRITE_CARD_HEART_A : \
		(n) == 2 ? SPRITE_CARD_HEART_2 : \
		(n) == 3 ? SPRITE_CARD_HEART_3 : \
		(n) == 4 ? SPRITE_CARD_HEART_4 : \
		SPRITE_CARD_UNKNOWN \
	): \
	SPRITE_CARD_UNKNOWN \
)

#endif
