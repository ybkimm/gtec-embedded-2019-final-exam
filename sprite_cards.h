#ifndef __SPRITE_CARDS_H__
#define __SPRITE_CARDS_H__

#define SPRITE_CARD_SIZE_W 8
#define SPRITE_CARD_SIZE_H 6

#define SPRITE_CARD_SPADE_A L"┌──────┐" \
                            L"│ A    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_2 L"┌──────┐" \
                            L"│ 2    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_3 L"┌──────┐" \
                            L"│ 3    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_4 L"┌──────┐" \
                            L"│ 4    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_5 L"┌──────┐" \
                            L"│ 5    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_6 L"┌──────┐" \
                            L"│ 6    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_7 L"┌──────┐" \
                            L"│ 7    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_8 L"┌──────┐" \
                            L"│ 8    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_9 L"┌──────┐" \
                            L"│ 9    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_J L"┌──────┐" \
                            L"│ J    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_Q L"┌──────┐" \
                            L"│ Q    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_SPADE_K L"┌──────┐" \
                            L"│ K    │" \
                            L"│ ♠    │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"
#define SPRITE_CARD_UNKNOWN L"┌──────┐" \
                            L"│ ?    │" \
                            L"│      │" \
                            L"│      │" \
                            L"│      │" \
                            L"└──────┘"

#define SPRITE_CARD(m,n) ( \
	(m) == 'S' ? ( \
		(n) ==  1 ? SPRITE_CARD_SPADE_A : \
		(n) ==  2 ? SPRITE_CARD_SPADE_2 : \
		(n) ==  3 ? SPRITE_CARD_SPADE_3 : \
		(n) ==  4 ? SPRITE_CARD_SPADE_4 : \
		(n) ==  5 ? SPRITE_CARD_SPADE_5 : \
		(n) ==  6 ? SPRITE_CARD_SPADE_6 : \
		(n) ==  7 ? SPRITE_CARD_SPADE_7 : \
		(n) ==  8 ? SPRITE_CARD_SPADE_8 : \
		(n) ==  9 ? SPRITE_CARD_SPADE_9 : \
		(n) == 10 ? SPRITE_CARD_SPADE_J : \
		(n) == 11 ? SPRITE_CARD_SPADE_Q : \
		(n) == 12 ? SPRITE_CARD_SPADE_K : \
		SPRITE_CARD_UNKNOWN \
	): \
	SPRITE_CARD_UNKNOWN \
)

#define CREATE_CARD_SPRITE(m,n) \
	create_sprite(SPRITE_CARD_SIZE_W, SPRITE_CARD_SIZE_H, SPRITE_CARD((m), (n)));

#endif
