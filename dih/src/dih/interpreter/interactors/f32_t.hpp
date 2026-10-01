#pragma once

#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"

#include <cmath>

namespace dih {
    namespace interactor {
        namespace f32_t {
            // ========== ADDITION ==========
            inline types::f32_t add(types::f32_t a, types::u8_t b)  { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::u16_t b) { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::u32_t b) { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::u64_t b) { return a + static_cast<types::f32_t>(b); }
                
            inline types::f32_t add(types::f32_t a, types::i8_t b)  { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::i16_t b) { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::i32_t b) { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::i64_t b) { return a + static_cast<types::f32_t>(b); }
                
            inline types::f32_t add(types::f32_t a, types::f32_t b) { return a + b; }
            inline types::f32_t add(types::f32_t a, types::f64_t b) { return a + static_cast<types::f32_t>(b); }
                
            inline types::f32_t add(types::f32_t a, types::char_t b) { return a + static_cast<types::f32_t>(b); }
            inline types::f32_t add(types::f32_t a, types::bool_t b) { return a + (b ? 1.0f : 0.0f); }
            inline types::f32_t add(types::f32_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot add string to f32.");
                return 0.0f;
            }
            inline types::f32_t add(types::f32_t a, types::var_t b) {
                const std::type_info& ti = b.type();
                if (ti == typeid(types::i64_t))      return add(a, std::any_cast<types::i64_t>(b));
                else if (ti == typeid(types::u64_t)) return add(a, std::any_cast<types::u64_t>(b));
                else if (ti == typeid(types::f64_t)) return add(a, std::any_cast<types::f64_t>(b));
                else if (ti == typeid(types::i32_t)) return add(a, std::any_cast<types::i32_t>(b));
                else if (ti == typeid(types::u32_t)) return add(a, std::any_cast<types::u32_t>(b));
                else if (ti == typeid(types::f32_t)) return add(a, std::any_cast<types::f32_t>(b));
                else if (ti == typeid(types::i16_t)) return add(a, std::any_cast<types::i16_t>(b));
                else if (ti == typeid(types::u16_t)) return add(a, std::any_cast<types::u16_t>(b));
                else if (ti == typeid(types::i8_t))  return add(a, std::any_cast<types::i8_t>(b));
                else if (ti == typeid(types::u8_t))  return add(a, std::any_cast<types::u8_t>(b));
                else if (ti == typeid(types::char_t)) return add(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t)) return add(a, std::any_cast<types::bool_t>(b));
                else if (ti == typeid(types::string_t)) return add(a, std::any_cast<types::string_t>(b));
                throw logger::types::RuntimeError("cannot add var to f32.");
                return 0.0f;
            }
        
            // ========== SUBTRACTION ==========
            inline types::f32_t sub(types::f32_t a, types::u8_t b)  { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::u16_t b) { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::u32_t b) { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::u64_t b) { return a - static_cast<types::f32_t>(b); }
        
            inline types::f32_t sub(types::f32_t a, types::i8_t b)  { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::i16_t b) { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::i32_t b) { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::i64_t b) { return a - static_cast<types::f32_t>(b); }
        
            inline types::f32_t sub(types::f32_t a, types::f32_t b) { return a - b; }
            inline types::f32_t sub(types::f32_t a, types::f64_t b) { return a - static_cast<types::f32_t>(b); }
        
            inline types::f32_t sub(types::f32_t a, types::char_t b) { return a - static_cast<types::f32_t>(b); }
            inline types::f32_t sub(types::f32_t a, types::bool_t b) { return a - (b ? 1.0f : 0.0f); }
            inline types::f32_t sub(types::f32_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract string from f32.");
                return 0.0f;
            }
            inline types::f32_t sub(types::f32_t a, types::var_t b) {
                const std::type_info& ti = b.type();
                if (ti == typeid(types::i64_t))      return sub(a, std::any_cast<types::i64_t>(b));
                else if (ti == typeid(types::u64_t)) return sub(a, std::any_cast<types::u64_t>(b));
                else if (ti == typeid(types::f64_t)) return sub(a, std::any_cast<types::f64_t>(b));
                else if (ti == typeid(types::i32_t)) return sub(a, std::any_cast<types::i32_t>(b));
                else if (ti == typeid(types::u32_t)) return sub(a, std::any_cast<types::u32_t>(b));
                else if (ti == typeid(types::f32_t)) return sub(a, std::any_cast<types::f32_t>(b));
                else if (ti == typeid(types::i16_t)) return sub(a, std::any_cast<types::i16_t>(b));
                else if (ti == typeid(types::u16_t)) return sub(a, std::any_cast<types::u16_t>(b));
                else if (ti == typeid(types::i8_t))  return sub(a, std::any_cast<types::i8_t>(b));
                else if (ti == typeid(types::u8_t))  return sub(a, std::any_cast<types::u8_t>(b));
                else if (ti == typeid(types::char_t)) return sub(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t)) return sub(a, std::any_cast<types::bool_t>(b));
                else if (ti == typeid(types::string_t)) return sub(a, std::any_cast<types::string_t>(b));
                throw logger::types::RuntimeError("cannot substract var from f32.");
                return 0.0f;
            }
        
            // ========== MULTIPLICATION ==========
            inline types::f32_t mul(types::f32_t a, types::u8_t b)  { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::u16_t b) { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::u32_t b) { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::u64_t b) { return a * static_cast<types::f32_t>(b); }
        
            inline types::f32_t mul(types::f32_t a, types::i8_t b)  { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::i16_t b) { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::i32_t b) { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::i64_t b) { return a * static_cast<types::f32_t>(b); }
        
            inline types::f32_t mul(types::f32_t a, types::f32_t b) { return a * b; }
            inline types::f32_t mul(types::f32_t a, types::f64_t b) { return a * static_cast<types::f32_t>(b); }
        
            inline types::f32_t mul(types::f32_t a, types::char_t b) { return a * static_cast<types::f32_t>(b); }
            inline types::f32_t mul(types::f32_t a, types::bool_t b) { return a * (b ? 1.0f : 0.0f); }
            inline types::f32_t mul(types::f32_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply f32 by string.");
                return 0.0f;
            }
            inline types::f32_t mul(types::f32_t a, types::var_t b) {
                const std::type_info& ti = b.type();
                if (ti == typeid(types::i64_t))      return mul(a, std::any_cast<types::i64_t>(b));
                else if (ti == typeid(types::u64_t)) return mul(a, std::any_cast<types::u64_t>(b));
                else if (ti == typeid(types::f64_t)) return mul(a, std::any_cast<types::f64_t>(b));
                else if (ti == typeid(types::i32_t)) return mul(a, std::any_cast<types::i32_t>(b));
                else if (ti == typeid(types::u32_t)) return mul(a, std::any_cast<types::u32_t>(b));
                else if (ti == typeid(types::f32_t)) return mul(a, std::any_cast<types::f32_t>(b));
                else if (ti == typeid(types::i16_t)) return mul(a, std::any_cast<types::i16_t>(b));
                else if (ti == typeid(types::u16_t)) return mul(a, std::any_cast<types::u16_t>(b));
                else if (ti == typeid(types::i8_t))  return mul(a, std::any_cast<types::i8_t>(b));
                else if (ti == typeid(types::u8_t))  return mul(a, std::any_cast<types::u8_t>(b));
                else if (ti == typeid(types::char_t)) return mul(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t)) return mul(a, std::any_cast<types::bool_t>(b));
                else if (ti == typeid(types::string_t)) return mul(a, std::any_cast<types::string_t>(b));
                throw logger::types::RuntimeError("cannot multiply var by f32.");
                return 0.0f;
            }
        
            // ========== DIVISION ==========
            inline types::f32_t div(types::f32_t a, types::u8_t b)  { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::u16_t b) { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::u32_t b) { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::u64_t b) { return a / static_cast<types::f32_t>(b); }
        
            inline types::f32_t div(types::f32_t a, types::i8_t b)  { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::i16_t b) { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::i32_t b) { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::i64_t b) { return a / static_cast<types::f32_t>(b); }
        
            inline types::f32_t div(types::f32_t a, types::f32_t b) { return a / b; }
            inline types::f32_t div(types::f32_t a, types::f64_t b) { return a / static_cast<types::f32_t>(b); }
        
            inline types::f32_t div(types::f32_t a, types::char_t b) { return a / static_cast<types::f32_t>(b); }
            inline types::f32_t div(types::f32_t a, types::bool_t b) { return a / (b ? 1.0f : 0.0f); }
            inline types::f32_t div(types::f32_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot divide f32 by string.");
                return 0.0f;
            }
            inline types::f32_t div(types::f32_t a, types::var_t b) {
                const std::type_info& ti = b.type();
                if (ti == typeid(types::i64_t))      return div(a, std::any_cast<types::i64_t>(b));
                else if (ti == typeid(types::u64_t)) return div(a, std::any_cast<types::u64_t>(b));
                else if (ti == typeid(types::f64_t)) return div(a, std::any_cast<types::f64_t>(b));
                else if (ti == typeid(types::i32_t)) return div(a, std::any_cast<types::i32_t>(b));
                else if (ti == typeid(types::u32_t)) return div(a, std::any_cast<types::u32_t>(b));
                else if (ti == typeid(types::f32_t)) return div(a, std::any_cast<types::f32_t>(b));
                else if (ti == typeid(types::i16_t)) return div(a, std::any_cast<types::i16_t>(b));
                else if (ti == typeid(types::u16_t)) return div(a, std::any_cast<types::u16_t>(b));
                else if (ti == typeid(types::i8_t))  return div(a, std::any_cast<types::i8_t>(b));
                else if (ti == typeid(types::u8_t))  return div(a, std::any_cast<types::u8_t>(b));
                else if (ti == typeid(types::char_t)) return div(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t)) return div(a, std::any_cast<types::bool_t>(b));
                else if (ti == typeid(types::string_t)) return div(a, std::any_cast<types::string_t>(b));
                throw logger::types::RuntimeError("cannot divide f32 by var.");
                return 0.0f;
            }
        
            // ========== POWER ==========
            inline types::f32_t pow(types::f32_t a, types::u8_t b)  { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::u16_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::u32_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::u64_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
        
            inline types::f32_t pow(types::f32_t a, types::i8_t b)  { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::i16_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::i32_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::i64_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
        
            inline types::f32_t pow(types::f32_t a, types::f32_t b) { return std::pow(a, b); }
            inline types::f32_t pow(types::f32_t a, types::f64_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
        
            inline types::f32_t pow(types::f32_t a, types::char_t b) { return std::pow(a, static_cast<types::f32_t>(b)); }
            inline types::f32_t pow(types::f32_t a, types::bool_t b) { return std::pow(a, (b ? 1.0f : 0.0f)); }
            inline types::f32_t pow(types::f32_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot raise f32 to string power.");
                return 0.0f;
            }
            inline types::f32_t pow(types::f32_t a, types::var_t b) {
                const std::type_info& ti = b.type();
                if (ti == typeid(types::i64_t))      return pow(a, std::any_cast<types::i64_t>(b));
                else if (ti == typeid(types::u64_t)) return pow(a, std::any_cast<types::u64_t>(b));
                else if (ti == typeid(types::f64_t)) return pow(a, std::any_cast<types::f64_t>(b));
                else if (ti == typeid(types::i32_t)) return pow(a, std::any_cast<types::i32_t>(b));
                else if (ti == typeid(types::u32_t)) return pow(a, std::any_cast<types::u32_t>(b));
                else if (ti == typeid(types::f32_t)) return pow(a, std::any_cast<types::f32_t>(b));
                else if (ti == typeid(types::i16_t)) return pow(a, std::any_cast<types::i16_t>(b));
                else if (ti == typeid(types::u16_t)) return pow(a, std::any_cast<types::u16_t>(b));
                else if (ti == typeid(types::i8_t))  return pow(a, std::any_cast<types::i8_t>(b));
                else if (ti == typeid(types::u8_t))  return pow(a, std::any_cast<types::u8_t>(b));
                else if (ti == typeid(types::char_t)) return pow(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t)) return pow(a, std::any_cast<types::bool_t>(b));
                else if (ti == typeid(types::string_t)) return pow(a, std::any_cast<types::string_t>(b));
                throw logger::types::RuntimeError("cannot raise f32 to var power.");
                return 0.0f;
            }
        }  // namespace f32_t
    }
}