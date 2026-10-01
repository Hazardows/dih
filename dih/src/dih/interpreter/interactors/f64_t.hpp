#pragma once

#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"

#include <cmath>

namespace dih {
    namespace interactor {
        namespace f64_t {
            // ========== ADDITION ==========
            inline types::f64_t add(types::f64_t a, types::u8_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::u16_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::u32_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::u64_t b) {
                return a + static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t add(types::f64_t a, types::i8_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::i16_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::i32_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::i64_t b) {
                return a + static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t add(types::f64_t a, types::f32_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::f64_t b) {
                return a + b;
            }
        
            inline types::f64_t add(types::f64_t a, types::char_t b) {
                return a + static_cast<types::f64_t>(b);
            }
            inline types::f64_t add(types::f64_t a, types::bool_t b) {
                return a + (b ? 1.0 : 0.0);
            }
            inline types::f64_t add(types::f64_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot add string to f64.");
                return 0.0;
            }
            inline types::f64_t add(types::f64_t a, types::var_t b) {
                const std::type_info& type_info = b.type();
                if (type_info == typeid(types::i64_t)) {
                    return add(a, std::any_cast<types::i64_t>(b));
                }
                else if (type_info == typeid(types::u64_t)) {
                    return add(a, std::any_cast<types::u64_t>(b));
                }
                else if (type_info == typeid(types::f64_t)) {
                    return add(a, std::any_cast<types::f64_t>(b));
                }
                else if (type_info == typeid(types::i32_t)) {
                    return add(a, std::any_cast<types::i32_t>(b));
                }
                else if (type_info == typeid(types::u32_t)) {
                    return add(a, std::any_cast<types::u32_t>(b));
                }
                else if (type_info == typeid(types::f32_t)) {
                    return add(a, std::any_cast<types::f32_t>(b));
                }
                else if (type_info == typeid(types::i16_t)) {
                    return add(a, std::any_cast<types::i16_t>(b));
                }
                else if (type_info == typeid(types::u16_t)) {
                    return add(a, std::any_cast<types::u16_t>(b));
                }
                else if (type_info == typeid(types::i8_t)) {
                    return add(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::u8_t)) {
                    return add(a, std::any_cast<types::u8_t>(b));  // ¡ojo! u8_t, no i8_t
                }
                else if (type_info == typeid(types::char_t)) {
                    return add(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return add(a, std::any_cast<types::bool_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return add(a, std::any_cast<types::string_t>(b));  // lanzará error
                }
            
                throw logger::types::RuntimeError("cannot add var to f64.");
                return 0.0;
            }
        
            // ========== SUBTRACTION ==========
            inline types::f64_t sub(types::f64_t a, types::u8_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::u16_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::u32_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::u64_t b) {
                return a - static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t sub(types::f64_t a, types::i8_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::i16_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::i32_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::i64_t b) {
                return a - static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t sub(types::f64_t a, types::f32_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::f64_t b) {
                return a - b;
            }
        
            inline types::f64_t sub(types::f64_t a, types::char_t b) {
                return a - static_cast<types::f64_t>(b);
            }
            inline types::f64_t sub(types::f64_t a, types::bool_t b) {
                return a - (b ? 1.0 : 0.0);
            }
            inline types::f64_t sub(types::f64_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract string from f64.");
                return 0.0;
            }
            inline types::f64_t sub(types::f64_t a, types::var_t b) {
                const std::type_info& type_info = b.type();
                if (type_info == typeid(types::i64_t)) {
                    return sub(a, std::any_cast<types::i64_t>(b));
                }
                else if (type_info == typeid(types::u64_t)) {
                    return sub(a, std::any_cast<types::u64_t>(b));
                }
                else if (type_info == typeid(types::f64_t)) {
                    return sub(a, std::any_cast<types::f64_t>(b));
                }
                else if (type_info == typeid(types::i32_t)) {
                    return sub(a, std::any_cast<types::i32_t>(b));
                }
                else if (type_info == typeid(types::u32_t)) {
                    return sub(a, std::any_cast<types::u32_t>(b));
                }
                else if (type_info == typeid(types::f32_t)) {
                    return sub(a, std::any_cast<types::f32_t>(b));
                }
                else if (type_info == typeid(types::i16_t)) {
                    return sub(a, std::any_cast<types::i16_t>(b));
                }
                else if (type_info == typeid(types::u16_t)) {
                    return sub(a, std::any_cast<types::u16_t>(b));
                }
                else if (type_info == typeid(types::i8_t)) {
                    return sub(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::u8_t)) {
                    return sub(a, std::any_cast<types::u8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return sub(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return sub(a, std::any_cast<types::bool_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return sub(a, std::any_cast<types::string_t>(b));
                }
            
                throw logger::types::RuntimeError("cannot substract var from f64.");
                return 0.0;
            }
        
            // ========== MULTIPLICATION ==========
            inline types::f64_t mul(types::f64_t a, types::u8_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::u16_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::u32_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::u64_t b) {
                return a * static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t mul(types::f64_t a, types::i8_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::i16_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::i32_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::i64_t b) {
                return a * static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t mul(types::f64_t a, types::f32_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::f64_t b) {
                return a * b;
            }
        
            inline types::f64_t mul(types::f64_t a, types::char_t b) {
                return a * static_cast<types::f64_t>(b);
            }
            inline types::f64_t mul(types::f64_t a, types::bool_t b) {
                return a * (b ? 1.0 : 0.0);
            }
            inline types::f64_t mul(types::f64_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply f64 by string.");
                return 0.0;
            }
            inline types::f64_t mul(types::f64_t a, types::var_t b) {
                const std::type_info& type_info = b.type();
                if (type_info == typeid(types::i64_t)) {
                    return mul(a, std::any_cast<types::i64_t>(b));
                }
                else if (type_info == typeid(types::u64_t)) {
                    return mul(a, std::any_cast<types::u64_t>(b));
                }
                else if (type_info == typeid(types::f64_t)) {
                    return mul(a, std::any_cast<types::f64_t>(b));
                }
                else if (type_info == typeid(types::i32_t)) {
                    return mul(a, std::any_cast<types::i32_t>(b));
                }
                else if (type_info == typeid(types::u32_t)) {
                    return mul(a, std::any_cast<types::u32_t>(b));
                }
                else if (type_info == typeid(types::f32_t)) {
                    return mul(a, std::any_cast<types::f32_t>(b));
                }
                else if (type_info == typeid(types::i16_t)) {
                    return mul(a, std::any_cast<types::i16_t>(b));
                }
                else if (type_info == typeid(types::u16_t)) {
                    return mul(a, std::any_cast<types::u16_t>(b));
                }
                else if (type_info == typeid(types::i8_t)) {
                    return mul(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::u8_t)) {
                    return mul(a, std::any_cast<types::u8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return mul(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return mul(a, std::any_cast<types::bool_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return mul(a, std::any_cast<types::string_t>(b));
                }
            
                throw logger::types::RuntimeError("cannot multiply var by f64.");
                return 0.0;
            }
        
            // ========== DIVISION ==========
            inline types::f64_t div(types::f64_t a, types::u8_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::u16_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::u32_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::u64_t b) {
                return a / static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t div(types::f64_t a, types::i8_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::i16_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::i32_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::i64_t b) {
                return a / static_cast<types::f64_t>(b);
            }
        
            inline types::f64_t div(types::f64_t a, types::f32_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::f64_t b) {
                return a / b;
            }
        
            inline types::f64_t div(types::f64_t a, types::char_t b) {
                return a / static_cast<types::f64_t>(b);
            }
            inline types::f64_t div(types::f64_t a, types::bool_t b) {
                return a / (b ? 1.0 : 0.0);
            }
            inline types::f64_t div(types::f64_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot divide f64 by string.");
                return 0.0;
            }
            inline types::f64_t div(types::f64_t a, types::var_t b) {
                const std::type_info& type_info = b.type();
                if (type_info == typeid(types::i64_t)) {
                    return div(a, std::any_cast<types::i64_t>(b));
                }
                else if (type_info == typeid(types::u64_t)) {
                    return div(a, std::any_cast<types::u64_t>(b));
                }
                else if (type_info == typeid(types::f64_t)) {
                    return div(a, std::any_cast<types::f64_t>(b));
                }
                else if (type_info == typeid(types::i32_t)) {
                    return div(a, std::any_cast<types::i32_t>(b));
                }
                else if (type_info == typeid(types::u32_t)) {
                    return div(a, std::any_cast<types::u32_t>(b));
                }
                else if (type_info == typeid(types::f32_t)) {
                    return div(a, std::any_cast<types::f32_t>(b));
                }
                else if (type_info == typeid(types::i16_t)) {
                    return div(a, std::any_cast<types::i16_t>(b));
                }
                else if (type_info == typeid(types::u16_t)) {
                    return div(a, std::any_cast<types::u16_t>(b));
                }
                else if (type_info == typeid(types::i8_t)) {
                    return div(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::u8_t)) {
                    return div(a, std::any_cast<types::u8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return div(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return div(a, std::any_cast<types::bool_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return div(a, std::any_cast<types::string_t>(b));
                }
            
                throw logger::types::RuntimeError("cannot divide var by f64.");
                return 0.0;
            }
        
            // ========== POWER ==========
            // helper para convertir cualquier tipo a f64
            inline types::f64_t pow(types::f64_t a, types::u8_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::u16_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::u32_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::u64_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
        
            inline types::f64_t pow(types::f64_t a, types::i8_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::i16_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::i32_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::i64_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
        
            inline types::f64_t pow(types::f64_t a, types::f32_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::f64_t b) {
                return std::pow(a, b);
            }
        
            inline types::f64_t pow(types::f64_t a, types::char_t b) {
                return std::pow(a, static_cast<types::f64_t>(b));
            }
            inline types::f64_t pow(types::f64_t a, types::bool_t b) {
                return std::pow(a, (b ? 1.0 : 0.0));
            }
            inline types::f64_t pow(types::f64_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot raise f64 to string power.");
                return 0.0;
            }
            inline types::f64_t pow(types::f64_t a, types::var_t b) {
                const std::type_info& type_info = b.type();
                if (type_info == typeid(types::i64_t)) {
                    return pow(a, std::any_cast<types::i64_t>(b));
                }
                else if (type_info == typeid(types::u64_t)) {
                    return pow(a, std::any_cast<types::u64_t>(b));
                }
                else if (type_info == typeid(types::f64_t)) {
                    return pow(a, std::any_cast<types::f64_t>(b));
                }
                else if (type_info == typeid(types::i32_t)) {
                    return pow(a, std::any_cast<types::i32_t>(b));
                }
                else if (type_info == typeid(types::u32_t)) {
                    return pow(a, std::any_cast<types::u32_t>(b));
                }
                else if (type_info == typeid(types::f32_t)) {
                    return pow(a, std::any_cast<types::f32_t>(b));
                }
                else if (type_info == typeid(types::i16_t)) {
                    return pow(a, std::any_cast<types::i16_t>(b));
                }
                else if (type_info == typeid(types::u16_t)) {
                    return pow(a, std::any_cast<types::u16_t>(b));
                }
                else if (type_info == typeid(types::i8_t)) {
                    return pow(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::u8_t)) {
                    return pow(a, std::any_cast<types::u8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return pow(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return pow(a, std::any_cast<types::bool_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return pow(a, std::any_cast<types::string_t>(b));
                }
            
                throw logger::types::RuntimeError("cannot raise f64 to var power.");
                return 0.0;
            }
        }  // namespace f64_t
    }
}