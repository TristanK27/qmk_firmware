/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Lets you roll mod-tap keys
//#define KEY_OVERRIDE_REPEAT_DELAY 300 // dictates how long you have to hold a key before it starts repeating, has a major impact on modifier keys
//#define TAPPING_TERM 150 // dictates when a key is considered a tap or a hold
#define TAPPING_TERM 200 // dictates when a key is considered a tap or a hold
#define PERMISSIVE_HOLD // makes it so that when you press a dual-role key, tap another key, and then release the dual-role key(all within the tapping term), the hold action gets executed instead of the tap action
#define QUICK_TAP_TERM 100 // dictates how much time you have to tap a key after a dual-role key to get the tap action
#define INGORE_MOD_TAP_INTERRUPT // makes it so that when you press a dual-role key, tap another key, and then release the dual-role key(all within the tapping term), the hold action gets executed instead of the tap action
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
