/* Copyright 2022 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keyboard_report_util.hpp"
#include "keycode.h"
#include "action.h"
#include "test_common.hpp"
#include "action_tapping.h"
#include "test_fixture.hpp"
#include "test_keymap_key.hpp"


using testing::_;
using testing::InSequence;

class BilateralCombintations : public TestFixture {};

bool bilateral_combinations_left(keypos_t key) {
    return key.col == 1;
}

TEST_F(BilateralCombintations, basic_tap_hold_still_works) {
    TestDriver driver;
    InSequence s;
                                    //layer, column, row (and keycod;
    auto       shift_t = KeymapKey(0, 1, 0, LSFT_T(KC_T));
    auto       gui_s   = KeymapKey(0, 2, 0, LGUI_T(KC_S));


    set_keymap({shift_t, gui_s});

    EXPECT_CALL(driver, send_keyboard_mock(_)).Times(0);
    shift_t.press();
    idle_for(TAPPING_TERM);
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_LSFT)));
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);

    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport()));
    shift_t.release();
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(BilateralCombintations, keyboard_report_study) {
    TestDriver driver;
    InSequence s;
                                    //layer, column, row (and keycod;
    auto       ctl   = KeymapKey(0, 1, 0, KC_LCTL);
    auto       sft   = KeymapKey(0, 1, 1, KC_LSFT);

    set_keymap({ctl, sft});

    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_LCTL)));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_LSFT, KC_LCTL)));
    ctl.press();
    run_one_scan_loop();
    sft.press();
    run_one_scan_loop();
    testing::Mock::VerifyAndClearExpectations(&driver);
}

TEST_F(BilateralCombintations, same_side_send_two_letters) {
    TestDriver driver;
    InSequence s;
                                    //layer, column, row (and keycod;
    auto       shift_t = KeymapKey(0, 1, 0, LSFT_T(KC_T));
    auto       gui_s   = KeymapKey(0, 1, 1, LGUI_T(KC_S));


    set_keymap({shift_t, gui_s});


    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_LSFT)));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport()));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_T)));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport()));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport(KC_S)));
    EXPECT_CALL(driver, send_keyboard_mock(KeyboardReport()));
    shift_t.press();
    idle_for(TAPPING_TERM);
    run_one_scan_loop();
    gui_s.press();

    run_one_scan_loop();

    testing::Mock::VerifyAndClearExpectations(&driver);

}

