#pragma once

#include "interactors/u8_t.hpp"
#include "interactors/u16_t.hpp"
#include "interactors/u32_t.hpp"
#include "interactors/u64_t.hpp"

#include "interactors/i8_t.hpp"
#include "interactors/i16_t.hpp"
#include "interactors/i32_t.hpp"
#include "interactors/i64_t.hpp"

#include "interactors/f32_t.hpp"
#include "interactors/f64_t.hpp"

#include "interactors/char_t.hpp"
#include "interactors/string_t.hpp"
#include "interactors/bool_t.hpp"
// #include "interactors/var_t.hpp"

#include "interactors/compare.hpp"

namespace dih {
    namespace interactor {
        inline special::dihValueContainer interact_add(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
            if (a.type_id == dihTypeId::u8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u8_t::add(a.get_u8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u8_t::add(a.get_u8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u8_t::add(a.get_u8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u8_t::add(a.get_u8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u8_t::add(a.get_u8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u8_t::add(a.get_u8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u8_t::add(a.get_u8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u8_t::add(a.get_u8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u8_t::add(a.get_u8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u8_t::add(a.get_u8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u8_t::add(a.get_u8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u8_t::add(a.get_u8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u8_t::add(a.get_u8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u8_t::add(a.get_u8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to u8.");
            }
            else if (a.type_id == dihTypeId::u16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u16_t::add(a.get_u16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u16_t::add(a.get_u16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u16_t::add(a.get_u16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u16_t::add(a.get_u16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u16_t::add(a.get_u16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u16_t::add(a.get_u16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u16_t::add(a.get_u16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u16_t::add(a.get_u16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u16_t::add(a.get_u16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u16_t::add(a.get_u16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u16_t::add(a.get_u16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u16_t::add(a.get_u16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u16_t::add(a.get_u16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u16_t::add(a.get_u16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to u16.");
            }
            else if (a.type_id == dihTypeId::u32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u32_t::add(a.get_u32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u32_t::add(a.get_u32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u32_t::add(a.get_u32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u32_t::add(a.get_u32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u32_t::add(a.get_u32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u32_t::add(a.get_u32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u32_t::add(a.get_u32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u32_t::add(a.get_u32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u32_t::add(a.get_u32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u32_t::add(a.get_u32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u32_t::add(a.get_u32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u32_t::add(a.get_u32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u32_t::add(a.get_u32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u32_t::add(a.get_u32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to u32.");
            }
            else if (a.type_id == dihTypeId::u64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u64_t::add(a.get_u64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u64_t::add(a.get_u64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u64_t::add(a.get_u64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u64_t::add(a.get_u64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u64_t::add(a.get_u64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u64_t::add(a.get_u64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u64_t::add(a.get_u64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u64_t::add(a.get_u64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u64_t::add(a.get_u64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u64_t::add(a.get_u64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u64_t::add(a.get_u64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u64_t::add(a.get_u64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u64_t::add(a.get_u64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u64_t::add(a.get_u64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to u64.");
            }
            else if (a.type_id == dihTypeId::i8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i8_t::add(a.get_i8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i8_t::add(a.get_i8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i8_t::add(a.get_i8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i8_t::add(a.get_i8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i8_t::add(a.get_i8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i8_t::add(a.get_i8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i8_t::add(a.get_i8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i8_t::add(a.get_i8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i8_t::add(a.get_i8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i8_t::add(a.get_i8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i8_t::add(a.get_i8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i8_t::add(a.get_i8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i8_t::add(a.get_i8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i8_t::add(a.get_i8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to i8.");
            }
            else if (a.type_id == dihTypeId::i16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i16_t::add(a.get_i16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i16_t::add(a.get_i16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i16_t::add(a.get_i16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i16_t::add(a.get_i16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i16_t::add(a.get_i16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i16_t::add(a.get_i16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i16_t::add(a.get_i16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i16_t::add(a.get_i16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i16_t::add(a.get_i16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i16_t::add(a.get_i16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i16_t::add(a.get_i16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i16_t::add(a.get_i16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i16_t::add(a.get_i16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i16_t::add(a.get_i16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to i16.");
            }
            else if (a.type_id == dihTypeId::i32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i32_t::add(a.get_i32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i32_t::add(a.get_i32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i32_t::add(a.get_i32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i32_t::add(a.get_i32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i32_t::add(a.get_i32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i32_t::add(a.get_i32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i32_t::add(a.get_i32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i32_t::add(a.get_i32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i32_t::add(a.get_i32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i32_t::add(a.get_i32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i32_t::add(a.get_i32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i32_t::add(a.get_i32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i32_t::add(a.get_i32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i32_t::add(a.get_i32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to i32.");
            }
            else if (a.type_id == dihTypeId::i64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i64_t::add(a.get_i64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i64_t::add(a.get_i64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i64_t::add(a.get_i64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i64_t::add(a.get_i64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i64_t::add(a.get_i64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i64_t::add(a.get_i64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i64_t::add(a.get_i64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i64_t::add(a.get_i64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i64_t::add(a.get_i64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i64_t::add(a.get_i64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i64_t::add(a.get_i64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i64_t::add(a.get_i64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i64_t::add(a.get_i64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i64_t::add(a.get_i64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to i64.");
            }
            else if (a.type_id == dihTypeId::f32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f32_t::add(a.get_f32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f32_t::add(a.get_f32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f32_t::add(a.get_f32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f32_t::add(a.get_f32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f32_t::add(a.get_f32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f32_t::add(a.get_f32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f32_t::add(a.get_f32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f32_t::add(a.get_f32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f32_t::add(a.get_f32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f32_t::add(a.get_f32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f32_t::add(a.get_f32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f32_t::add(a.get_f32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f32_t::add(a.get_f32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f32_t::add(a.get_f32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to f32.");
            }
            else if (a.type_id == dihTypeId::f64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f64_t::add(a.get_f64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f64_t::add(a.get_f64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f64_t::add(a.get_f64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f64_t::add(a.get_f64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f64_t::add(a.get_f64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f64_t::add(a.get_f64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f64_t::add(a.get_f64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f64_t::add(a.get_f64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f64_t::add(a.get_f64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f64_t::add(a.get_f64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f64_t::add(a.get_f64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f64_t::add(a.get_f64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f64_t::add(a.get_f64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f64_t::add(a.get_f64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to f64.");
            }
            else if (a.type_id == dihTypeId::char_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return char_t::add(a.get_char(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return char_t::add(a.get_char(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return char_t::add(a.get_char(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return char_t::add(a.get_char(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return char_t::add(a.get_char(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return char_t::add(a.get_char(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return char_t::add(a.get_char(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return char_t::add(a.get_char(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return char_t::add(a.get_char(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return char_t::add(a.get_char(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return char_t::add(a.get_char(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return char_t::add(a.get_char(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return char_t::add(a.get_char(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return char_t::add(a.get_char(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to char.");
            }
            else if (a.type_id == dihTypeId::string_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return string_t::add(a.get_string(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return string_t::add(a.get_string(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return string_t::add(a.get_string(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return string_t::add(a.get_string(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return string_t::add(a.get_string(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return string_t::add(a.get_string(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return string_t::add(a.get_string(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return string_t::add(a.get_string(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return string_t::add(a.get_string(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return string_t::add(a.get_string(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return string_t::add(a.get_string(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return string_t::add(a.get_string(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return string_t::add(a.get_string(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return string_t::add(a.get_string(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to string.");
            }
            else if (a.type_id == dihTypeId::bool_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return bool_t::add(a.get_bool(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return bool_t::add(a.get_bool(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return bool_t::add(a.get_bool(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return bool_t::add(a.get_bool(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return bool_t::add(a.get_bool(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return bool_t::add(a.get_bool(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return bool_t::add(a.get_bool(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return bool_t::add(a.get_bool(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return bool_t::add(a.get_bool(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return bool_t::add(a.get_bool(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return bool_t::add(a.get_bool(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return bool_t::add(a.get_bool(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return bool_t::add(a.get_bool(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return bool_t::add(a.get_bool(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to add unknown type to bool.");
            }
            // This is a placeholder :)
            return "";
        }
        inline special::dihValueContainer interact_sub(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
            if (a.type_id == dihTypeId::u8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u8_t::sub(a.get_u8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u8_t::sub(a.get_u8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u8_t::sub(a.get_u8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u8_t::sub(a.get_u8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u8_t::sub(a.get_u8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u8_t::sub(a.get_u8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u8_t::sub(a.get_u8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u8_t::sub(a.get_u8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u8_t::sub(a.get_u8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u8_t::sub(a.get_u8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u8_t::sub(a.get_u8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u8_t::sub(a.get_u8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u8_t::sub(a.get_u8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u8_t::sub(a.get_u8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to u8.");
            }
            else if (a.type_id == dihTypeId::u16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u16_t::sub(a.get_u16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u16_t::sub(a.get_u16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u16_t::sub(a.get_u16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u16_t::sub(a.get_u16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u16_t::sub(a.get_u16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u16_t::sub(a.get_u16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u16_t::sub(a.get_u16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u16_t::sub(a.get_u16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u16_t::sub(a.get_u16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u16_t::sub(a.get_u16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u16_t::sub(a.get_u16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u16_t::sub(a.get_u16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u16_t::sub(a.get_u16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u16_t::sub(a.get_u16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to u16.");
            }
            else if (a.type_id == dihTypeId::u32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u32_t::sub(a.get_u32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u32_t::sub(a.get_u32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u32_t::sub(a.get_u32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u32_t::sub(a.get_u32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u32_t::sub(a.get_u32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u32_t::sub(a.get_u32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u32_t::sub(a.get_u32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u32_t::sub(a.get_u32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u32_t::sub(a.get_u32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u32_t::sub(a.get_u32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u32_t::sub(a.get_u32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u32_t::sub(a.get_u32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u32_t::sub(a.get_u32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u32_t::sub(a.get_u32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to u32.");
            }
            else if (a.type_id == dihTypeId::u64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u64_t::sub(a.get_u64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u64_t::sub(a.get_u64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u64_t::sub(a.get_u64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u64_t::sub(a.get_u64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u64_t::sub(a.get_u64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u64_t::sub(a.get_u64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u64_t::sub(a.get_u64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u64_t::sub(a.get_u64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u64_t::sub(a.get_u64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u64_t::sub(a.get_u64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u64_t::sub(a.get_u64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u64_t::sub(a.get_u64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u64_t::sub(a.get_u64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u64_t::sub(a.get_u64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to u64.");
            }
            else if (a.type_id == dihTypeId::i8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i8_t::sub(a.get_i8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i8_t::sub(a.get_i8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i8_t::sub(a.get_i8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i8_t::sub(a.get_i8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i8_t::sub(a.get_i8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i8_t::sub(a.get_i8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i8_t::sub(a.get_i8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i8_t::sub(a.get_i8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i8_t::sub(a.get_i8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i8_t::sub(a.get_i8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i8_t::sub(a.get_i8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i8_t::sub(a.get_i8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i8_t::sub(a.get_i8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i8_t::sub(a.get_i8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to i8.");
            }
            else if (a.type_id == dihTypeId::i16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i16_t::sub(a.get_i16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i16_t::sub(a.get_i16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i16_t::sub(a.get_i16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i16_t::sub(a.get_i16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i16_t::sub(a.get_i16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i16_t::sub(a.get_i16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i16_t::sub(a.get_i16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i16_t::sub(a.get_i16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i16_t::sub(a.get_i16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i16_t::sub(a.get_i16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i16_t::sub(a.get_i16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i16_t::sub(a.get_i16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i16_t::sub(a.get_i16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i16_t::sub(a.get_i16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to i16.");
            }
            else if (a.type_id == dihTypeId::i32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i32_t::sub(a.get_i32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i32_t::sub(a.get_i32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i32_t::sub(a.get_i32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i32_t::sub(a.get_i32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i32_t::sub(a.get_i32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i32_t::sub(a.get_i32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i32_t::sub(a.get_i32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i32_t::sub(a.get_i32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i32_t::sub(a.get_i32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i32_t::sub(a.get_i32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i32_t::sub(a.get_i32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i32_t::sub(a.get_i32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i32_t::sub(a.get_i32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i32_t::sub(a.get_i32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to i32.");
            }
            else if (a.type_id == dihTypeId::i64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i64_t::sub(a.get_i64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i64_t::sub(a.get_i64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i64_t::sub(a.get_i64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i64_t::sub(a.get_i64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i64_t::sub(a.get_i64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i64_t::sub(a.get_i64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i64_t::sub(a.get_i64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i64_t::sub(a.get_i64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i64_t::sub(a.get_i64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i64_t::sub(a.get_i64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i64_t::sub(a.get_i64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i64_t::sub(a.get_i64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i64_t::sub(a.get_i64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i64_t::sub(a.get_i64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to i64.");
            }
            else if (a.type_id == dihTypeId::f32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f32_t::sub(a.get_f32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f32_t::sub(a.get_f32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f32_t::sub(a.get_f32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f32_t::sub(a.get_f32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f32_t::sub(a.get_f32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f32_t::sub(a.get_f32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f32_t::sub(a.get_f32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f32_t::sub(a.get_f32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f32_t::sub(a.get_f32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f32_t::sub(a.get_f32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f32_t::sub(a.get_f32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f32_t::sub(a.get_f32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f32_t::sub(a.get_f32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f32_t::sub(a.get_f32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to f32.");
            }
            else if (a.type_id == dihTypeId::f64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f64_t::sub(a.get_f64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f64_t::sub(a.get_f64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f64_t::sub(a.get_f64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f64_t::sub(a.get_f64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f64_t::sub(a.get_f64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f64_t::sub(a.get_f64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f64_t::sub(a.get_f64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f64_t::sub(a.get_f64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f64_t::sub(a.get_f64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f64_t::sub(a.get_f64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f64_t::sub(a.get_f64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f64_t::sub(a.get_f64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f64_t::sub(a.get_f64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f64_t::sub(a.get_f64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to f64.");
            }
            else if (a.type_id == dihTypeId::char_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return char_t::sub(a.get_char(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return char_t::sub(a.get_char(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return char_t::sub(a.get_char(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return char_t::sub(a.get_char(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return char_t::sub(a.get_char(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return char_t::sub(a.get_char(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return char_t::sub(a.get_char(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return char_t::sub(a.get_char(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return char_t::sub(a.get_char(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return char_t::sub(a.get_char(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return char_t::sub(a.get_char(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return char_t::sub(a.get_char(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return char_t::sub(a.get_char(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return char_t::sub(a.get_char(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to char.");
            }
            else if (a.type_id == dihTypeId::string_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return string_t::sub(a.get_string(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return string_t::sub(a.get_string(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return string_t::sub(a.get_string(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return string_t::sub(a.get_string(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return string_t::sub(a.get_string(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return string_t::sub(a.get_string(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return string_t::sub(a.get_string(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return string_t::sub(a.get_string(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return string_t::sub(a.get_string(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return string_t::sub(a.get_string(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return string_t::sub(a.get_string(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return string_t::sub(a.get_string(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return string_t::sub(a.get_string(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return string_t::sub(a.get_string(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to string.");
            }
            else if (a.type_id == dihTypeId::bool_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return bool_t::sub(a.get_bool(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return bool_t::sub(a.get_bool(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return bool_t::sub(a.get_bool(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return bool_t::sub(a.get_bool(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return bool_t::sub(a.get_bool(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return bool_t::sub(a.get_bool(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return bool_t::sub(a.get_bool(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return bool_t::sub(a.get_bool(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return bool_t::sub(a.get_bool(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return bool_t::sub(a.get_bool(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return bool_t::sub(a.get_bool(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return bool_t::sub(a.get_bool(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return bool_t::sub(a.get_bool(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return bool_t::sub(a.get_bool(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to sub unknown type to bool.");
            }

            // This is a placeholder :)
            return "";
        }
        inline special::dihValueContainer interact_mul(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
            if (a.type_id == dihTypeId::u8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u8_t::mul(a.get_u8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u8_t::mul(a.get_u8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u8_t::mul(a.get_u8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u8_t::mul(a.get_u8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u8_t::mul(a.get_u8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u8_t::mul(a.get_u8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u8_t::mul(a.get_u8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u8_t::mul(a.get_u8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u8_t::mul(a.get_u8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u8_t::mul(a.get_u8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u8_t::mul(a.get_u8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u8_t::mul(a.get_u8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u8_t::mul(a.get_u8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u8_t::mul(a.get_u8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to u8.");
            }
            else if (a.type_id == dihTypeId::u16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u16_t::mul(a.get_u16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u16_t::mul(a.get_u16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u16_t::mul(a.get_u16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u16_t::mul(a.get_u16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u16_t::mul(a.get_u16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u16_t::mul(a.get_u16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u16_t::mul(a.get_u16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u16_t::mul(a.get_u16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u16_t::mul(a.get_u16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u16_t::mul(a.get_u16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u16_t::mul(a.get_u16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u16_t::mul(a.get_u16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u16_t::mul(a.get_u16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u16_t::mul(a.get_u16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to u16.");
            }
            else if (a.type_id == dihTypeId::u32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u32_t::mul(a.get_u32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u32_t::mul(a.get_u32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u32_t::mul(a.get_u32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u32_t::mul(a.get_u32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u32_t::mul(a.get_u32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u32_t::mul(a.get_u32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u32_t::mul(a.get_u32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u32_t::mul(a.get_u32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u32_t::mul(a.get_u32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u32_t::mul(a.get_u32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u32_t::mul(a.get_u32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u32_t::mul(a.get_u32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u32_t::mul(a.get_u32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u32_t::mul(a.get_u32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to u32.");
            }
            else if (a.type_id == dihTypeId::u64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u64_t::mul(a.get_u64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u64_t::mul(a.get_u64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u64_t::mul(a.get_u64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u64_t::mul(a.get_u64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u64_t::mul(a.get_u64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u64_t::mul(a.get_u64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u64_t::mul(a.get_u64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u64_t::mul(a.get_u64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u64_t::mul(a.get_u64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u64_t::mul(a.get_u64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u64_t::mul(a.get_u64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u64_t::mul(a.get_u64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u64_t::mul(a.get_u64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u64_t::mul(a.get_u64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to u64.");
            }
            else if (a.type_id == dihTypeId::i8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i8_t::mul(a.get_i8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i8_t::mul(a.get_i8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i8_t::mul(a.get_i8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i8_t::mul(a.get_i8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i8_t::mul(a.get_i8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i8_t::mul(a.get_i8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i8_t::mul(a.get_i8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i8_t::mul(a.get_i8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i8_t::mul(a.get_i8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i8_t::mul(a.get_i8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i8_t::mul(a.get_i8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i8_t::mul(a.get_i8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i8_t::mul(a.get_i8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i8_t::mul(a.get_i8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to i8.");
            }
            else if (a.type_id == dihTypeId::i16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i16_t::mul(a.get_i16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i16_t::mul(a.get_i16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i16_t::mul(a.get_i16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i16_t::mul(a.get_i16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i16_t::mul(a.get_i16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i16_t::mul(a.get_i16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i16_t::mul(a.get_i16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i16_t::mul(a.get_i16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i16_t::mul(a.get_i16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i16_t::mul(a.get_i16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i16_t::mul(a.get_i16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i16_t::mul(a.get_i16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i16_t::mul(a.get_i16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i16_t::mul(a.get_i16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to i16.");
            }
            else if (a.type_id == dihTypeId::i32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i32_t::mul(a.get_i32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i32_t::mul(a.get_i32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i32_t::mul(a.get_i32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i32_t::mul(a.get_i32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i32_t::mul(a.get_i32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i32_t::mul(a.get_i32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i32_t::mul(a.get_i32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i32_t::mul(a.get_i32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i32_t::mul(a.get_i32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i32_t::mul(a.get_i32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i32_t::mul(a.get_i32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i32_t::mul(a.get_i32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i32_t::mul(a.get_i32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i32_t::mul(a.get_i32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to i32.");
            }
            else if (a.type_id == dihTypeId::i64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i64_t::mul(a.get_i64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i64_t::mul(a.get_i64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i64_t::mul(a.get_i64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i64_t::mul(a.get_i64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i64_t::mul(a.get_i64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i64_t::mul(a.get_i64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i64_t::mul(a.get_i64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i64_t::mul(a.get_i64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i64_t::mul(a.get_i64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i64_t::mul(a.get_i64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i64_t::mul(a.get_i64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i64_t::mul(a.get_i64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i64_t::mul(a.get_i64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i64_t::mul(a.get_i64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to i64.");
            }
            else if (a.type_id == dihTypeId::f32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f32_t::mul(a.get_f32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f32_t::mul(a.get_f32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f32_t::mul(a.get_f32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f32_t::mul(a.get_f32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f32_t::mul(a.get_f32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f32_t::mul(a.get_f32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f32_t::mul(a.get_f32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f32_t::mul(a.get_f32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f32_t::mul(a.get_f32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f32_t::mul(a.get_f32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f32_t::mul(a.get_f32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f32_t::mul(a.get_f32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f32_t::mul(a.get_f32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f32_t::mul(a.get_f32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to f32.");
            }
            else if (a.type_id == dihTypeId::f64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f64_t::mul(a.get_f64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f64_t::mul(a.get_f64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f64_t::mul(a.get_f64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f64_t::mul(a.get_f64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f64_t::mul(a.get_f64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f64_t::mul(a.get_f64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f64_t::mul(a.get_f64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f64_t::mul(a.get_f64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f64_t::mul(a.get_f64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f64_t::mul(a.get_f64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f64_t::mul(a.get_f64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f64_t::mul(a.get_f64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f64_t::mul(a.get_f64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f64_t::mul(a.get_f64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to f64.");
            }
            else if (a.type_id == dihTypeId::char_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return char_t::mul(a.get_char(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return char_t::mul(a.get_char(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return char_t::mul(a.get_char(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return char_t::mul(a.get_char(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return char_t::mul(a.get_char(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return char_t::mul(a.get_char(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return char_t::mul(a.get_char(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return char_t::mul(a.get_char(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return char_t::mul(a.get_char(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return char_t::mul(a.get_char(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return char_t::mul(a.get_char(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return char_t::mul(a.get_char(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return char_t::mul(a.get_char(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return char_t::mul(a.get_char(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to char.");
            }
            else if (a.type_id == dihTypeId::string_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return string_t::mul(a.get_string(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return string_t::mul(a.get_string(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return string_t::mul(a.get_string(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return string_t::mul(a.get_string(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return string_t::mul(a.get_string(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return string_t::mul(a.get_string(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return string_t::mul(a.get_string(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return string_t::mul(a.get_string(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return string_t::mul(a.get_string(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return string_t::mul(a.get_string(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return string_t::mul(a.get_string(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return string_t::mul(a.get_string(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return string_t::mul(a.get_string(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return string_t::mul(a.get_string(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to string.");
            }
            else if (a.type_id == dihTypeId::bool_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return bool_t::mul(a.get_bool(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return bool_t::mul(a.get_bool(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return bool_t::mul(a.get_bool(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return bool_t::mul(a.get_bool(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return bool_t::mul(a.get_bool(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return bool_t::mul(a.get_bool(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return bool_t::mul(a.get_bool(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return bool_t::mul(a.get_bool(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return bool_t::mul(a.get_bool(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return bool_t::mul(a.get_bool(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return bool_t::mul(a.get_bool(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return bool_t::mul(a.get_bool(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return bool_t::mul(a.get_bool(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return bool_t::mul(a.get_bool(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to mul unknown type to bool.");
            }

            // This is a placeholder :)
            return "";
        }
        inline special::dihValueContainer interact_div(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
            if (a.type_id == dihTypeId::u8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u8_t::div(a.get_u8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u8_t::div(a.get_u8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u8_t::div(a.get_u8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u8_t::div(a.get_u8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u8_t::div(a.get_u8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u8_t::div(a.get_u8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u8_t::div(a.get_u8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u8_t::div(a.get_u8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u8_t::div(a.get_u8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u8_t::div(a.get_u8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u8_t::div(a.get_u8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u8_t::div(a.get_u8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u8_t::div(a.get_u8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u8_t::div(a.get_u8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to u8.");
            }
            else if (a.type_id == dihTypeId::u16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u16_t::div(a.get_u16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u16_t::div(a.get_u16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u16_t::div(a.get_u16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u16_t::div(a.get_u16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u16_t::div(a.get_u16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u16_t::div(a.get_u16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u16_t::div(a.get_u16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u16_t::div(a.get_u16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u16_t::div(a.get_u16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u16_t::div(a.get_u16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u16_t::div(a.get_u16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u16_t::div(a.get_u16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u16_t::div(a.get_u16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u16_t::div(a.get_u16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to u16.");
            }
            else if (a.type_id == dihTypeId::u32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u32_t::div(a.get_u32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u32_t::div(a.get_u32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u32_t::div(a.get_u32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u32_t::div(a.get_u32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u32_t::div(a.get_u32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u32_t::div(a.get_u32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u32_t::div(a.get_u32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u32_t::div(a.get_u32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u32_t::div(a.get_u32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u32_t::div(a.get_u32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u32_t::div(a.get_u32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u32_t::div(a.get_u32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u32_t::div(a.get_u32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u32_t::div(a.get_u32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to u32.");
            }
            else if (a.type_id == dihTypeId::u64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u64_t::div(a.get_u64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u64_t::div(a.get_u64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u64_t::div(a.get_u64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u64_t::div(a.get_u64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u64_t::div(a.get_u64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u64_t::div(a.get_u64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u64_t::div(a.get_u64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u64_t::div(a.get_u64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u64_t::div(a.get_u64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u64_t::div(a.get_u64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u64_t::div(a.get_u64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u64_t::div(a.get_u64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u64_t::div(a.get_u64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u64_t::div(a.get_u64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to u64.");
            }
            else if (a.type_id == dihTypeId::i8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i8_t::div(a.get_i8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i8_t::div(a.get_i8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i8_t::div(a.get_i8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i8_t::div(a.get_i8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i8_t::div(a.get_i8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i8_t::div(a.get_i8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i8_t::div(a.get_i8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i8_t::div(a.get_i8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i8_t::div(a.get_i8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i8_t::div(a.get_i8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i8_t::div(a.get_i8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i8_t::div(a.get_i8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i8_t::div(a.get_i8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i8_t::div(a.get_i8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to i8.");
            }
            else if (a.type_id == dihTypeId::i16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i16_t::div(a.get_i16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i16_t::div(a.get_i16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i16_t::div(a.get_i16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i16_t::div(a.get_i16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i16_t::div(a.get_i16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i16_t::div(a.get_i16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i16_t::div(a.get_i16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i16_t::div(a.get_i16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i16_t::div(a.get_i16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i16_t::div(a.get_i16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i16_t::div(a.get_i16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i16_t::div(a.get_i16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i16_t::div(a.get_i16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i16_t::div(a.get_i16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to i16.");
            }
            else if (a.type_id == dihTypeId::i32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i32_t::div(a.get_i32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i32_t::div(a.get_i32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i32_t::div(a.get_i32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i32_t::div(a.get_i32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i32_t::div(a.get_i32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i32_t::div(a.get_i32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i32_t::div(a.get_i32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i32_t::div(a.get_i32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i32_t::div(a.get_i32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i32_t::div(a.get_i32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i32_t::div(a.get_i32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i32_t::div(a.get_i32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i32_t::div(a.get_i32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i32_t::div(a.get_i32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to i32.");
            }
            else if (a.type_id == dihTypeId::i64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i64_t::div(a.get_i64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i64_t::div(a.get_i64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i64_t::div(a.get_i64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i64_t::div(a.get_i64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i64_t::div(a.get_i64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i64_t::div(a.get_i64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i64_t::div(a.get_i64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i64_t::div(a.get_i64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i64_t::div(a.get_i64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i64_t::div(a.get_i64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i64_t::div(a.get_i64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i64_t::div(a.get_i64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i64_t::div(a.get_i64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i64_t::div(a.get_i64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to i64.");
            }
            else if (a.type_id == dihTypeId::f32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f32_t::div(a.get_f32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f32_t::div(a.get_f32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f32_t::div(a.get_f32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f32_t::div(a.get_f32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f32_t::div(a.get_f32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f32_t::div(a.get_f32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f32_t::div(a.get_f32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f32_t::div(a.get_f32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f32_t::div(a.get_f32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f32_t::div(a.get_f32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f32_t::div(a.get_f32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f32_t::div(a.get_f32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f32_t::div(a.get_f32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f32_t::div(a.get_f32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to f32.");
            }
            else if (a.type_id == dihTypeId::f64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f64_t::div(a.get_f64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f64_t::div(a.get_f64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f64_t::div(a.get_f64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f64_t::div(a.get_f64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f64_t::div(a.get_f64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f64_t::div(a.get_f64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f64_t::div(a.get_f64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f64_t::div(a.get_f64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f64_t::div(a.get_f64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f64_t::div(a.get_f64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f64_t::div(a.get_f64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f64_t::div(a.get_f64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f64_t::div(a.get_f64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f64_t::div(a.get_f64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to f64.");
            }
            else if (a.type_id == dihTypeId::char_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return char_t::div(a.get_char(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return char_t::div(a.get_char(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return char_t::div(a.get_char(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return char_t::div(a.get_char(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return char_t::div(a.get_char(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return char_t::div(a.get_char(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return char_t::div(a.get_char(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return char_t::div(a.get_char(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return char_t::div(a.get_char(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return char_t::div(a.get_char(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return char_t::div(a.get_char(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return char_t::div(a.get_char(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return char_t::div(a.get_char(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return char_t::div(a.get_char(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to char.");
            }
            else if (a.type_id == dihTypeId::string_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return string_t::div(a.get_string(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return string_t::div(a.get_string(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return string_t::div(a.get_string(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return string_t::div(a.get_string(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return string_t::div(a.get_string(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return string_t::div(a.get_string(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return string_t::div(a.get_string(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return string_t::div(a.get_string(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return string_t::div(a.get_string(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return string_t::div(a.get_string(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return string_t::div(a.get_string(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return string_t::div(a.get_string(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return string_t::div(a.get_string(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return string_t::div(a.get_string(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to string.");
            }
            else if (a.type_id == dihTypeId::bool_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return bool_t::div(a.get_bool(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return bool_t::div(a.get_bool(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return bool_t::div(a.get_bool(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return bool_t::div(a.get_bool(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return bool_t::div(a.get_bool(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return bool_t::div(a.get_bool(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return bool_t::div(a.get_bool(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return bool_t::div(a.get_bool(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return bool_t::div(a.get_bool(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return bool_t::div(a.get_bool(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return bool_t::div(a.get_bool(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return bool_t::div(a.get_bool(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return bool_t::div(a.get_bool(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return bool_t::div(a.get_bool(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to div unknown type to bool.");
            }

            // This is a placeholder :)
            return "";
        }
        inline special::dihValueContainer interact_pow(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
            if (a.type_id == dihTypeId::u8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u8_t::pow(a.get_u8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u8_t::pow(a.get_u8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u8_t::pow(a.get_u8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u8_t::pow(a.get_u8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u8_t::pow(a.get_u8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u8_t::pow(a.get_u8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u8_t::pow(a.get_u8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u8_t::pow(a.get_u8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u8_t::pow(a.get_u8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u8_t::pow(a.get_u8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u8_t::pow(a.get_u8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u8_t::pow(a.get_u8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u8_t::pow(a.get_u8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u8_t::pow(a.get_u8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to u8.");
            }
            else if (a.type_id == dihTypeId::u16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u16_t::pow(a.get_u16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u16_t::pow(a.get_u16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u16_t::pow(a.get_u16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u16_t::pow(a.get_u16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u16_t::pow(a.get_u16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u16_t::pow(a.get_u16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u16_t::pow(a.get_u16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u16_t::pow(a.get_u16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u16_t::pow(a.get_u16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u16_t::pow(a.get_u16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u16_t::pow(a.get_u16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u16_t::pow(a.get_u16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u16_t::pow(a.get_u16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u16_t::pow(a.get_u16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to u16.");
            }
            else if (a.type_id == dihTypeId::u32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u32_t::pow(a.get_u32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u32_t::pow(a.get_u32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u32_t::pow(a.get_u32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u32_t::pow(a.get_u32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u32_t::pow(a.get_u32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u32_t::pow(a.get_u32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u32_t::pow(a.get_u32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u32_t::pow(a.get_u32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u32_t::pow(a.get_u32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u32_t::pow(a.get_u32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u32_t::pow(a.get_u32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u32_t::pow(a.get_u32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u32_t::pow(a.get_u32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u32_t::pow(a.get_u32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to u32.");
            }
            else if (a.type_id == dihTypeId::u64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return u64_t::pow(a.get_u64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return u64_t::pow(a.get_u64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return u64_t::pow(a.get_u64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return u64_t::pow(a.get_u64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return u64_t::pow(a.get_u64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return u64_t::pow(a.get_u64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return u64_t::pow(a.get_u64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return u64_t::pow(a.get_u64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return u64_t::pow(a.get_u64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return u64_t::pow(a.get_u64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return u64_t::pow(a.get_u64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return u64_t::pow(a.get_u64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return u64_t::pow(a.get_u64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return u64_t::pow(a.get_u64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to u64.");
            }
            else if (a.type_id == dihTypeId::i8_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i8_t::pow(a.get_i8(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i8_t::pow(a.get_i8(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i8_t::pow(a.get_i8(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i8_t::pow(a.get_i8(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i8_t::pow(a.get_i8(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i8_t::pow(a.get_i8(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i8_t::pow(a.get_i8(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i8_t::pow(a.get_i8(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i8_t::pow(a.get_i8(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i8_t::pow(a.get_i8(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i8_t::pow(a.get_i8(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i8_t::pow(a.get_i8(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i8_t::pow(a.get_i8(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i8_t::pow(a.get_i8(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to i8.");
            }
            else if (a.type_id == dihTypeId::i16_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i16_t::pow(a.get_i16(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i16_t::pow(a.get_i16(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i16_t::pow(a.get_i16(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i16_t::pow(a.get_i16(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i16_t::pow(a.get_i16(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i16_t::pow(a.get_i16(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i16_t::pow(a.get_i16(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i16_t::pow(a.get_i16(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i16_t::pow(a.get_i16(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i16_t::pow(a.get_i16(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i16_t::pow(a.get_i16(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i16_t::pow(a.get_i16(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i16_t::pow(a.get_i16(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i16_t::pow(a.get_i16(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to i16.");
            }
            else if (a.type_id == dihTypeId::i32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i32_t::pow(a.get_i32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i32_t::pow(a.get_i32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i32_t::pow(a.get_i32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i32_t::pow(a.get_i32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i32_t::pow(a.get_i32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i32_t::pow(a.get_i32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i32_t::pow(a.get_i32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i32_t::pow(a.get_i32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i32_t::pow(a.get_i32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i32_t::pow(a.get_i32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i32_t::pow(a.get_i32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i32_t::pow(a.get_i32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i32_t::pow(a.get_i32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i32_t::pow(a.get_i32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to i32.");
            }
            else if (a.type_id == dihTypeId::i64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return i64_t::pow(a.get_i64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return i64_t::pow(a.get_i64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return i64_t::pow(a.get_i64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return i64_t::pow(a.get_i64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return i64_t::pow(a.get_i64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return i64_t::pow(a.get_i64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return i64_t::pow(a.get_i64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return i64_t::pow(a.get_i64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return i64_t::pow(a.get_i64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return i64_t::pow(a.get_i64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return i64_t::pow(a.get_i64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return i64_t::pow(a.get_i64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return i64_t::pow(a.get_i64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return i64_t::pow(a.get_i64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to i64.");
            }
            else if (a.type_id == dihTypeId::f32_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f32_t::pow(a.get_f32(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f32_t::pow(a.get_f32(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f32_t::pow(a.get_f32(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f32_t::pow(a.get_f32(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f32_t::pow(a.get_f32(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f32_t::pow(a.get_f32(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f32_t::pow(a.get_f32(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f32_t::pow(a.get_f32(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f32_t::pow(a.get_f32(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f32_t::pow(a.get_f32(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f32_t::pow(a.get_f32(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f32_t::pow(a.get_f32(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f32_t::pow(a.get_f32(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f32_t::pow(a.get_f32(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to f32.");
            }
            else if (a.type_id == dihTypeId::f64_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return f64_t::pow(a.get_f64(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return f64_t::pow(a.get_f64(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return f64_t::pow(a.get_f64(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return f64_t::pow(a.get_f64(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return f64_t::pow(a.get_f64(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return f64_t::pow(a.get_f64(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return f64_t::pow(a.get_f64(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return f64_t::pow(a.get_f64(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return f64_t::pow(a.get_f64(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return f64_t::pow(a.get_f64(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return f64_t::pow(a.get_f64(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return f64_t::pow(a.get_f64(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return f64_t::pow(a.get_f64(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return f64_t::pow(a.get_f64(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to f64.");
            }
            else if (a.type_id == dihTypeId::char_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return char_t::pow(a.get_char(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return char_t::pow(a.get_char(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return char_t::pow(a.get_char(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return char_t::pow(a.get_char(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return char_t::pow(a.get_char(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return char_t::pow(a.get_char(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return char_t::pow(a.get_char(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return char_t::pow(a.get_char(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return char_t::pow(a.get_char(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return char_t::pow(a.get_char(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return char_t::pow(a.get_char(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return char_t::pow(a.get_char(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return char_t::pow(a.get_char(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return char_t::pow(a.get_char(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to char.");
            }
            else if (a.type_id == dihTypeId::string_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return string_t::pow(a.get_string(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return string_t::pow(a.get_string(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return string_t::pow(a.get_string(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return string_t::pow(a.get_string(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return string_t::pow(a.get_string(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return string_t::pow(a.get_string(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return string_t::pow(a.get_string(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return string_t::pow(a.get_string(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return string_t::pow(a.get_string(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return string_t::pow(a.get_string(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return string_t::pow(a.get_string(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return string_t::pow(a.get_string(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return string_t::pow(a.get_string(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return string_t::pow(a.get_string(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to string.");
            }
            else if (a.type_id == dihTypeId::bool_t) {
                // unsigned number types
                if (b.type_id == dihTypeId::u8_t) {
                    return bool_t::pow(a.get_bool(), b.get_u8());
                }
                else if (b.type_id == dihTypeId::u16_t) {
                    return bool_t::pow(a.get_bool(), b.get_u16());
                }
                else if (b.type_id == dihTypeId::u32_t) {
                    return bool_t::pow(a.get_bool(), b.get_u32());
                }
                else if (b.type_id == dihTypeId::u64_t) {
                    return bool_t::pow(a.get_bool(), b.get_u64());
                }
                // signed number types
                else if (b.type_id == dihTypeId::i8_t) {
                    return bool_t::pow(a.get_bool(), b.get_i8());
                }
                else if (b.type_id == dihTypeId::i16_t) {
                    return bool_t::pow(a.get_bool(), b.get_i16());
                }
                else if (b.type_id == dihTypeId::i32_t) {
                    return bool_t::pow(a.get_bool(), b.get_i32());
                }
                else if (b.type_id == dihTypeId::i64_t) {
                    return bool_t::pow(a.get_bool(), b.get_i64());
                }
                // floating point numbers
                else if (b.type_id == dihTypeId::f32_t) {
                    return bool_t::pow(a.get_bool(), b.get_f32());
                }
                else if (b.type_id == dihTypeId::f64_t) {
                    return bool_t::pow(a.get_bool(), b.get_f64());
                }
                // other builtin types
                else if (b.type_id == dihTypeId::char_t) {
                    return bool_t::pow(a.get_bool(), b.get_char());
                }
                else if (b.type_id == dihTypeId::string_t) {
                    return bool_t::pow(a.get_bool(), b.get_string());
                }
                else if (b.type_id == dihTypeId::bool_t) {
                    return bool_t::pow(a.get_bool(), b.get_bool());
                }
                else if (b.type_id == dihTypeId::var_t) {
                    return bool_t::pow(a.get_bool(), b.get_var());
                }

                throw logger::types::RuntimeError("tried to pow unknown type to bool.");
            }

            // This is a placeholder :)
            return "";
        }
    };
};