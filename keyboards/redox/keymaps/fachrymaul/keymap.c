#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _SYMB   2
#define _NAV    3
#define _ADJUST 4

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  SYMB,
  NAV,
  ADJUST,
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)
#define NAV_L   MO(_NAV)

#define SPSM    LT(_SYMB, KC_SPC)
#define BSSM    LT(_SYMB, KC_BSPC)
#define ENNV    LT(_NAV, KC_ENT)
#define DLNV    LT(_NAV, KC_DEL)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)
#define KC_CTBS LCTL(KC_BSPC)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_TGQW TG(_QWERTY)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

// GASC Config for Home row QWERTY and DVORAK
// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SC RGUI_T(KC_SCLN)

// Left-hand home row mods
#define HODV_A LGUI_T(KC_A)
#define HODV_O LALT_T(KC_O)
#define HODV_E LSFT_T(KC_E)
#define HODV_U LCTL_T(KC_U)

// Right-hand home row mods
#define HODV_H RCTL_T(KC_H)
#define HODV_T RSFT_T(KC_T)
#define HODV_N LALT_T(KC_N)
#define HODV_S RGUI_T(KC_S)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_QUOT ,KC_COMM ,KC_DOT  ,KC_P    ,KC_Y    ,KC_TGQW ,                          KC_TGQW ,KC_F    ,KC_G    ,KC_C    ,KC_R    ,KC_L    ,KC_SLSH ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,HODV_A  ,HODV_O  ,HODV_E  ,HODV_U  ,KC_I    ,KC_PSCR ,                          KC_CAPS ,KC_D    ,HODV_H  ,HODV_T  ,HODV_N  ,HODV_S  ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_SCLN ,KC_Q    ,KC_J    ,KC_K    ,KC_X    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_B    ,KC_M    ,KC_W    ,KC_V    ,KC_Z    ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_PLUS ,KC_MINS ,KC_BSLS ,     KC_TAB  ,    SPSM    ,ENNV    ,        DLNV    ,BSSM    ,    KC_BSLS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_QUOT ,KC_COMM ,KC_DOT  ,KC_P    ,KC_Y    ,KC_TGQW ,                          KC_TGQW ,KC_F    ,KC_G    ,KC_C    ,KC_R    ,KC_L    ,KC_SLSH ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC  ,KC_A    ,KC_O    ,HODV_E  ,KC_U    ,KC_I    ,XXXXXXX ,                          XXXXXXX ,KC_D    ,KC_H    ,HODV_T  ,KC_N    ,KC_S    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_SCLN ,KC_Q    ,KC_J    ,KC_K    ,KC_X    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_B    ,KC_M    ,KC_W    ,KC_V    ,KC_Z    ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_PLUS ,KC_MINS ,KC_BSLS ,     KC_TAB  ,    SPSM    ,ENNV    ,        DLNV    ,KC_CTBS    ,    KC_BSLS ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,_______ ,                          _______ ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,_______ ,                          _______ ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LBRC ,KC_RBRC ,KC_LCBR ,KC_RCBR ,KC_BSLS ,_______ ,_______ ,        _______ ,_______ ,KC_EQL  ,KC_DOT  ,KC_SLASH,KC_PLUS ,KC_MINS ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_F11  ,    _______ ,_______ ,        _______ ,KC_CTBS ,    KC_F12  ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            KC_WH_L ,KC_WH_D ,KC_WH_U ,KC_WH_R ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_VOLD ,KC_MUTE ,KC_VOLU ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_U ,KC_MS_R ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_MPLY ,KC_MNXT ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_BRID ,XXXXXXX ,KC_BRIU ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,KC_BTN3 ,        KC_BTN3 ,KC_BTN2 ,    KC_BTN1 ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};
