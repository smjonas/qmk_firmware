
#include QMK_KEYBOARD_H

#define XXX KC_NO

enum custom_keycodes {
    KC_HEART = SAFE_RANGE,
};

enum layers {
    _BASE,
    _MEDIA,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
};

// Formatted with qmk.nvim

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌───────┬───────────┬───────────┬─────────────────┬───────────┬───────────────┐   ┌───────────────┬────────────────┬───────────────┬───────────┬───────────┬──────┐
//    │ hEART │     q     │     w     │        f        │     p     │       b       │   │       j       │       l        │       u       │     y     │     /     │      │
//    ├───────┼───────────┼───────────┼─────────────────┼───────────┼───────────────┤   ├───────────────┼────────────────┼───────────────┼───────────┼───────────┼──────┤
//    │  tab  │ LGUI_T(a) │ LALT_T(r) │    LCTL_T(s)    │ LSFT_T(t) │       g       │   │       m       │   LSFT_T(n)    │   LCTL_T(e)   │ LALT_T(i) │ LGUI_T(o) │ rgui │
//    ├───────┼───────────┼───────────┼─────────────────┼───────────┼───────────────┤   ├───────────────┼────────────────┼───────────────┼───────────┼───────────┼──────┤
//    │ lctl  │     z     │ ALGR_T(x) │        c        │     d     │       v       │   │       k       │       h        │       ,       │ ALGR_T(.) │     /     │      │
//    └───────┴───────────┴───────────┴─────────────────┴───────────┴───────────────┘   └───────────────┴────────────────┴───────────────┴───────────┴───────────┴──────┘
//
//                                    ┌─────────────────┬───────────┬───────────────┐   ┌───────────────┬────────────────┬───────────────┐
//                                    │ LT(_MEDIA, esc) │   lsft    │ LT(_NAV, spc) │   │ LT(_SYM, ent) │ LT(_NUM, bspc) │ LT(_FUN, del) │
//                                    └─────────────────┴───────────┴───────────────┘   └───────────────┴────────────────┴───────────────┘
[_BASE] = LAYOUT_split_3x6_3(
  KC_HEART , KC_Q         , KC_W         , KC_F               , KC_P         , KC_B             ,     KC_J             , KC_L              , KC_U             , KC_Y           , KC_SLASH     , XXX    ,
  KC_TAB   , LGUI_T(KC_A) , LALT_T(KC_R) , LCTL_T(KC_S)       , LSFT_T(KC_T) , KC_G             ,     KC_M             , LSFT_T(KC_N)      , LCTL_T(KC_E)     , LALT_T(KC_I)   , LGUI_T(KC_O) , KC_RGUI,
  KC_LCTL  , KC_Z         , ALGR_T(KC_X) , KC_C               , KC_D         , KC_V             ,     KC_K             , KC_H              , KC_COMM          , ALGR_T(KC_DOT) , KC_SLASH     , XXX    ,

                                           LT(_MEDIA, KC_ESC) , KC_LSFT      , LT(_NAV, KC_SPC) ,     LT(_SYM, KC_ENT) , LT(_NUM, KC_BSPC) , LT(_FUN, KC_DEL)
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐   ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │     │     │     │     │     │     │   │      │      │      │      │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │     │     │     │     │     │     │   │ mprv │ vold │ volu │ mnxt │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │     │     │     │     │     │     │   │      │      │      │      │     │     │
//    └─────┴─────┴─────┴─────┴─────┴─────┘   └──────┴──────┴──────┴──────┴─────┴─────┘
//
//                      ┌─────┬─────┬─────┐   ┌──────┬──────┬──────┐
//                      │     │     │     │   │      │      │      │
//                      └─────┴─────┴─────┘   └──────┴──────┴──────┘
[_MEDIA] = LAYOUT_split_3x6_3(
  XXX , XXX , XXX , XXX , XXX , XXX ,     XXX                 , XXX               , XXX             , XXX                 , XXX , XXX,
  XXX , XXX , XXX , XXX , XXX , XXX ,     KC_MEDIA_PREV_TRACK , KC_AUDIO_VOL_DOWN , KC_AUDIO_VOL_UP , KC_MEDIA_NEXT_TRACK , XXX , XXX,
  XXX , XXX , XXX , XXX , XXX , XXX ,     XXX                 , XXX               , XXX             , XXX                 , XXX , XXX,

                    XXX , XXX , XXX ,     XXX                 , XXX               , XXX
),

//    ┌─────┬─────┬─────┬─────────────┬─────┬─────┐   ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │     │     │     │             │     │     │   │      │      │      │      │     │     │
//    ├─────┼─────┼─────┼─────────────┼─────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │     │     │     │  www_back   │     │     │   │ left │ down │  up  │ rght │     │     │
//    ├─────┼─────┼─────┼─────────────┼─────┼─────┤   ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │     │     │     │ www_forward │     │     │   │ ms_l │ ms_d │ ms_u │ ms_r │     │     │
//    └─────┴─────┴─────┴─────────────┴─────┴─────┘   └──────┴──────┴──────┴──────┴─────┴─────┘
//
//                      ┌─────────────┬─────┬─────┐   ┌──────┬──────┬──────┐
//                      │             │     │     │   │ btn2 │ btn1 │      │
//                      └─────────────┴─────┴─────┘   └──────┴──────┴──────┘
[_NAV] = LAYOUT_split_3x6_3(
  XXX , XXX , XXX , XXX            , XXX , XXX ,     XXX        , XXX        , XXX      , XXX         , XXX , XXX,
  XXX , XXX , XXX , KC_WWW_BACK    , XXX , XXX ,     KC_LEFT    , KC_DOWN    , KC_UP    , KC_RIGHT    , XXX , XXX,
  XXX , XXX , XXX , KC_WWW_FORWARD , XXX , XXX ,     KC_MS_LEFT , KC_MS_DOWN , KC_MS_UP , KC_MS_RIGHT , XXX , XXX,

                    XXX            , XXX , XXX ,     KC_MS_BTN2 , KC_MS_BTN1 , XXX
),

//    ┌─────┬───┬───┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬────┬─────┬─────┐
//    │     │ ! │ < │  >  │  $  │  %  │   │  &  │  {  │  }  │ '  │     │     │
//    ├─────┼───┼───┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┼─────┼─────┤
//    │     │ _ │ - │  +  │  =  │  ^  │   │  $  │  (  │  )  │ "  │     │     │
//    ├─────┼───┼───┼─────┼─────┼─────┤   ├─────┼─────┼─────┼────┼─────┼─────┤
//    │     │ ^ │ ~ │  /  │  *  │  \  │   │  |  │  [  │  ]  │ @  │     │     │
//    └─────┴───┴───┴─────┴─────┴─────┘   └─────┴─────┴─────┴────┴─────┴─────┘
//
//                  ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
//                  │     │     │     │   │     │     │     │
//                  └─────┴─────┴─────┘   └─────┴─────┴─────┘
[_SYM] = LAYOUT_split_3x6_3(
  XXX , KC_EXCLAIM    , KC_LT       , KC_GT      , KC_DOLLAR   , KC_PERCENT    ,     KC_AMPERSAND , KC_LEFT_CURLY_BRACE , KC_RIGHT_CURLY_BRACE , KC_QUOTE        , XXX , XXX,
  XXX , KC_UNDERSCORE , KC_KP_MINUS , KC_KP_PLUS , KC_KP_EQUAL , KC_CIRCUMFLEX ,     KC_DOLLAR    , KC_LEFT_PAREN       , KC_RIGHT_PAREN       , KC_DOUBLE_QUOTE , XXX , XXX,
  XXX , KC_CIRCUMFLEX , KC_TILDE    , KC_SLASH   , KC_ASTERISK , KC_BACKSLASH  ,     KC_PIPE      , KC_LEFT_BRACKET     , KC_RIGHT_BRACKET     , KC_AT           , XXX , XXX,

                                      XXX        , XXX         , XXX           ,     XXX          , XXX                 , XXX
),

//    ┌─────┬─────┬───┬───┬───┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │ 7 │ 8 │ 9 │     │   │     │     │     │     │     │     │
//    ├─────┼─────┼───┼───┼───┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │ 4 │ 5 │ 6 │  +  │   │     │     │     │     │     │     │
//    ├─────┼─────┼───┼───┼───┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │ 1 │ 2 │ 3 │  -  │   │     │     │     │     │     │     │
//    └─────┴─────┴───┴───┴───┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
//
//                    ┌───┬───┬─────┐   ┌─────┬─────┬─────┐
//                    │ 0 │ . │     │   │     │     │     │
//                    └───┴───┴─────┘   └─────┴─────┴─────┘
[_NUM] = LAYOUT_split_3x6_3(
  XXX , XXX , KC_7 , KC_8 , KC_9   , XXX         ,     XXX , XXX , XXX , XXX , XXX , XXX,
  XXX , XXX , KC_4 , KC_5 , KC_6   , KC_KP_PLUS  ,     XXX , XXX , XXX , XXX , XXX , XXX,
  XXX , XXX , KC_1 , KC_2 , KC_3   , KC_KP_MINUS ,     XXX , XXX , XXX , XXX , XXX , XXX,

                     KC_0 , KC_DOT , XXX         ,     XXX , XXX , XXX
),

//    ┌─────┬────┬─────┬─────┬─────┬─────┐   ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │ f9 │ f10 │ f11 │ f12 │     │   │     │     │     │     │     │     │
//    ├─────┼────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ f5 │ f6  │ f7  │ f8  │     │   │     │     │     │     │     │     │
//    ├─────┼────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │ f1 │ f2  │ f3  │ f4  │     │   │     │     │     │     │     │     │
//    └─────┴────┴─────┴─────┴─────┴─────┘   └─────┴─────┴─────┴─────┴─────┴─────┘
//
//                     ┌─────┬─────┬─────┐   ┌─────┬─────┬─────┐
//                     │     │     │     │   │     │     │     │
//                     └─────┴─────┴─────┘   └─────┴─────┴─────┘
[_FUN] = LAYOUT_split_3x6_3(
  XXX , KC_F9 , KC_F10 , KC_F11 , KC_F12 , XXX ,     XXX , XXX , XXX , XXX , XXX , XXX,
  XXX , KC_F5 , KC_F6  , KC_F7  , KC_F8  , XXX ,     XXX , XXX , XXX , XXX , XXX , XXX,
  XXX , KC_F1 , KC_F2  , KC_F3  , KC_F4  , XXX ,     XXX , XXX , XXX , XXX , XXX , XXX,

                         XXX    , XXX    , XXX ,     XXX , XXX , XXX
)
};

// Key overrides

// shift + , = ;
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
// shift + . = :
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, ALGR_T(KC_DOT), KC_COLON);

const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_key_override,
    &dot_key_override,
    NULL
};


// Combos

const uint16_t PROGMEM password_combo[] = {KC_HEART, KC_P, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(password_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
      SEND_STRING("password");
    }
}
