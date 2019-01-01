#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

#define KC_L1 LOWER
#define KC_L2 RAISE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,------------------------------------------------------------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
   * |------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |   `  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |   \  |
   * |------+------+------+------+------+------|------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |  Up  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Hyper| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Bksp |Shift | Left | Down |Right |
   * `------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
  //,--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_ENT ,
  //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //|--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------|
     KC_LCTL ,KC_LALT ,KC_LGUI ,KC_LGUI ,KC_L1   ,    KC_SPC       ,KC_L2   ,KC_LEFT ,KC_UP   ,KC_DOWN ,KC_RGHT
  //`--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+--------+--------'
  ),

/* Lower
 * ,------------------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_PPLS, KC_EQL,
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, KC_DQUO,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
  _______, _______, _______, _______, _______,     KC__MUTE,     _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,------------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
  KC_PGUP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_PGDN, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______, _______, KC_F12,
  KC_HOME, KC_4,    KC_5,    KC_6,    _______, _______, _______, _______, _______, _______, _______, _______,
  KC_END,  KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_0,    KC_0,    KC_DOT,  _______,     _______,      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 * ,------------------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------+------|
 * |      |      |      |Audoff|Aud on|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Musoff|Mus on|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |      |
 * `------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)


};

#ifdef AUDIO_ENABLE
float tone_startup[][2] = {
  {NOTE_B5, 20},
  {NOTE_B6, 8},
  {NOTE_DS6, 20},
  {NOTE_B6, 8}
};

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
              PLAY_SONG(tone_qwerty);
            #endif
            persistent_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
          return false;
          break;
      }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_SONG(tone_startup);
}

void shutdown_user()
{
    PLAY_SONG(tone_goodbye);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
