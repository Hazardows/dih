#pragma once

#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"

#include <cmath>

namespace dih {
    namespace interactor {
        namespace i8_t {
            // ========== ADDITION ==========
            inline types::i8_t add(types::i8_t a, types::u8_t b)  { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::u16_t b) { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::u32_t b) { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::u64_t b) { return static_cast<types::i8_t>(a + b); }
        
            inline types::i8_t add(types::i8_t a, types::i8_t b)  { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::i16_t b) { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::i32_t b) { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::i64_t b) { return static_cast<types::i8_t>(a + b); }
        
            inline types::i8_t add(types::i8_t a, types::f32_t b) { return static_cast<types::i8_t>(a + b); }
            inline types::i8_t add(types::i8_t a, types::f64_t b) { return static_cast<types::i8_t>(a + b); }
        
            inline types::i8_t add(types::i8_t a, types::char_t b) {
                return static_cast<types::i8_t>(a + static_cast<unsigned char>(b));
            }
            inline types::i8_t add(types::i8_t a, types::bool_t b) { return static_cast<types::i8_t>(a + (b ? 1 : 0)); }
            inline types::i8_t add(types::i8_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot add string to i8.");
                return 0;
            }
            inline types::i8_t add(types::i8_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot add var to i8.");
                return 0;
            }
        
            // ========== SUBTRACTION ==========
            inline types::i8_t sub(types::i8_t a, types::u8_t b)  { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::u16_t b) { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::u32_t b) { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::u64_t b) { return static_cast<types::i8_t>(a - b); }
        
            inline types::i8_t sub(types::i8_t a, types::i8_t b)  { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::i16_t b) { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::i32_t b) { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::i64_t b) { return static_cast<types::i8_t>(a - b); }
        
            inline types::i8_t sub(types::i8_t a, types::f32_t b) { return static_cast<types::i8_t>(a - b); }
            inline types::i8_t sub(types::i8_t a, types::f64_t b) { return static_cast<types::i8_t>(a - b); }
        
            inline types::i8_t sub(types::i8_t a, types::char_t b) {
                return static_cast<types::i8_t>(a - static_cast<unsigned char>(b));
            }
            inline types::i8_t sub(types::i8_t a, types::bool_t b) { return static_cast<types::i8_t>(a - (b ? 1 : 0)); }
            inline types::i8_t sub(types::i8_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract string from i8.");
                return 0;
            }
            inline types::i8_t sub(types::i8_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot substract var from i8.");
                return 0;
            }
        
            // ========== MULTIPLICATION ==========
            inline types::i8_t mul(types::i8_t a, types::u8_t b)  { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::u16_t b) { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::u32_t b) { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::u64_t b) { return static_cast<types::i8_t>(a * b); }
        
            inline types::i8_t mul(types::i8_t a, types::i8_t b)  { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::i16_t b) { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::i32_t b) { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::i64_t b) { return static_cast<types::i8_t>(a * b); }
        
            inline types::i8_t mul(types::i8_t a, types::f32_t b) { return static_cast<types::i8_t>(a * b); }
            inline types::i8_t mul(types::i8_t a, types::f64_t b) { return static_cast<types::i8_t>(a * b); }
        
            inline types::i8_t mul(types::i8_t a, types::char_t b) {
                return static_cast<types::i8_t>(a * static_cast<unsigned char>(b));
            }
            inline types::i8_t mul(types::i8_t a, types::bool_t b) { return static_cast<types::i8_t>(a * (b ? 1 : 0)); }
            inline types::i8_t mul(types::i8_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply i8 by string.");
                return 0;
            }
            inline types::i8_t mul(types::i8_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot multiply var by i8.");
                return 0;
            }
        
            // ========== DIVISION ==========
            inline types::i8_t div(types::i8_t a, types::u8_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::u16_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::u32_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::u64_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
        
            inline types::i8_t div(types::i8_t a, types::i8_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::i16_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::i32_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::i64_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
        
            inline types::i8_t div(types::i8_t a, types::f32_t b) {
                if (b == 0.0f) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
            inline types::i8_t div(types::i8_t a, types::f64_t b) {
                if (b == 0.0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / b);
            }
        
            inline types::i8_t div(types::i8_t a, types::char_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return static_cast<types::i8_t>(a / static_cast<unsigned char>(b));
            }
            inline types::i8_t div(types::i8_t a, types::bool_t b) {
                if (!b) throw logger::types::RuntimeError("division by zero.");
                return a;
            }
            inline types::i8_t div(types::i8_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot divide i8 by string.");
                return 0;
            }
            inline types::i8_t div(types::i8_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot divide i8 by var.");
                return 0;
            }
        
            inline types::i8_t pow(types::i8_t a, types::u8_t b)  { return std::pow(a, static_cast<types::i8_t>(b)); }
            inline types::i8_t pow(types::i8_t a, types::u16_t b) { return std::pow(a, static_cast<types::i8_t>(b)); }
            inline types::i8_t pow(types::i8_t a, types::u32_t b) { return std::pow(a, static_cast<types::i8_t>(b)); }
            inline types::i8_t pow(types::i8_t a, types::u64_t b) { return std::pow(a, static_cast<types::i8_t>(b)); }
        
            inline types::i8_t pow(types::i8_t a, types::i8_t b)  { return std::pow(a, b); }
            inline types::i8_t pow(types::i8_t a, types::i16_t b) {
                if (b < 0) throw logger::types::RuntimeError("negative exponent not allowed for integers.");
                return std::pow(a, static_cast<types::i8_t>(b));
            }
            inline types::i8_t pow(types::i8_t a, types::i32_t b) {
                if (b < 0) throw logger::types::RuntimeError("negative exponent not allowed for integers.");
                return std::pow(a, static_cast<types::i8_t>(b));
            }
            inline types::i8_t pow(types::i8_t a, types::i64_t b) {
                if (b < 0) throw logger::types::RuntimeError("negative exponent not allowed for integers.");
                return std::pow(a, static_cast<types::i8_t>(b));
            }
        
            // f32/f64: resultado truncado a entero (con posible pérdida)
            inline types::i8_t pow(types::i8_t a, types::f32_t b) { return static_cast<types::i8_t>(std::pow(a, b)); }
            inline types::i8_t pow(types::i8_t a, types::f64_t b) { return static_cast<types::i8_t>(std::pow(a, b)); }
        
            inline types::i8_t pow(types::i8_t a, types::char_t b) {
                return std::pow(a, static_cast<types::i8_t>(static_cast<unsigned char>(b)));
            }
            inline types::i8_t pow(types::i8_t a, types::bool_t b) { return std::pow(a, b ? 1 : 0); }
            inline types::i8_t pow(types::i8_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot raise i8 to string power.");
                return 0;
            }
            inline types::i8_t pow(types::i8_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot raise i8 to var power.");
                return 0;
            }
        }  // namespace i8_t
    }
}