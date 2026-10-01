#pragma once

#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"

namespace dih {
    namespace interactor {
        namespace char_t {
            // ========== ADDITION ==========
            // Semántica: char + X siempre devuelve string_t (concatenación)
            inline types::char_t add(types::char_t a, types::u8_t b)  { return static_cast<types::char_t>(a + b); }
            inline types::char_t add(types::char_t a, types::u16_t b) { return static_cast<types::char_t>(a + b); }
            inline types::char_t add(types::char_t a, types::u32_t b) { return static_cast<types::char_t>(a + b); }
            inline types::char_t add(types::char_t a, types::u64_t b) { return static_cast<types::char_t>(a + b); }

            inline types::char_t add(types::char_t a, types::i8_t b)  { return static_cast<types::char_t>(a + b); }
            inline types::char_t add(types::char_t a, types::i16_t b) { return static_cast<types::char_t>(a + b); }
            inline types::char_t add(types::char_t a, types::i32_t b) { return static_cast<types::char_t>(a + b); }
            inline types::char_t add(types::char_t a, types::i64_t b) { return static_cast<types::char_t>(a + b); }

            inline types::f32_t add(types::char_t a, types::f32_t b) { return static_cast<types::f32_t>(a) + b; }
            inline types::f64_t add(types::char_t a, types::f64_t b) { return static_cast<types::f64_t>(a) + b; }

            inline types::string_t add(types::char_t a, types::char_t b)   { return types::string_t(1, a) + types::string_t(1, b); }
            inline types::char_t add(types::char_t a, types::bool_t b)   { return static_cast<types::char_t>(a + (b ? 1 : 0)); }
            inline types::string_t add(types::char_t a, types::string_t b) { return types::string_t(1, a) + b; }

            inline special::dihValueContainer add(types::char_t a, types::var_t b) {
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
                else if (ti == typeid(types::char_t))   return add(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t))   return add(a, std::any_cast<types::bool_t>(b));
                else if (ti == typeid(types::string_t)) return add(a, std::any_cast<types::string_t>(b));
                throw logger::types::RuntimeError("cannot add var to char.");
                return "";
            }
        
            // ========== SUBTRACTION ==========
            // char - char = código ASCII (devuelve i64)
            inline types::char_t sub(types::char_t a, types::char_t b) {
                return static_cast<types::char_t>(a - b);
            }
            // char - number = código ASCII - number
            inline types::char_t sub(types::char_t a, types::u8_t b)  { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::u16_t b) { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::u32_t b) { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::u64_t b) { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::i8_t b)  { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::i16_t b) { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::i32_t b) { return static_cast<types::char_t>(a - b); }
            inline types::char_t sub(types::char_t a, types::i64_t b) { return static_cast<types::char_t>(a - b); }
            inline types::f32_t sub(types::char_t a, types::f32_t b) { return static_cast<types::f32_t>(a) - b; }
            inline types::f64_t sub(types::char_t a, types::f64_t b) { return static_cast<types::f64_t>(a) - b; }
            inline types::char_t sub(types::char_t a, types::bool_t b) { return static_cast<types::char_t>(a) - (b ? 1 : 0); }
            inline types::char_t sub(types::char_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract string from char.");
                return 0;
            }
            inline types::var_t sub(types::char_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot substract var from char.");
                return 0;
            }
        
            // ========== MULTIPLICATION ==========
            inline types::string_t mul(types::char_t a, types::u8_t b) {
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::u16_t b) {
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::u32_t b) {
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::u64_t b) {
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::i8_t b) {
                if (b < 0) throw logger::types::RuntimeError("cannot multiply char by negative number.");
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::i16_t b) {
                if (b < 0) throw logger::types::RuntimeError("cannot multiply char by negative number.");
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::i32_t b) {
                if (b < 0) throw logger::types::RuntimeError("cannot multiply char by negative number.");
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::i64_t b) {
                if (b < 0) throw logger::types::RuntimeError("cannot multiply char by negative number.");
                return types::string_t(static_cast<size_t>(b), a);
            }
            inline types::string_t mul(types::char_t a, types::f32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply char by f32.");
                return "";
            }
            inline types::string_t mul(types::char_t a, types::f64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply char by f64.");
                return "";
            }
            inline types::string_t mul(types::char_t a, types::char_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply char by char.");
                return "";
            }
            inline types::string_t mul(types::char_t a, types::bool_t b) {
                if (!b) return "";
                return types::string_t(1, a);
            }
            inline types::string_t mul(types::char_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply char by string.");
                return "";
            }
            inline types::string_t mul(types::char_t a, types::var_t b) {
                const std::type_info& ti = b.type();
                if (ti == typeid(types::i64_t))      return mul(a, std::any_cast<types::i64_t>(b));
                else if (ti == typeid(types::u64_t)) return mul(a, std::any_cast<types::u64_t>(b));
                else if (ti == typeid(types::i32_t)) return mul(a, std::any_cast<types::i32_t>(b));
                else if (ti == typeid(types::u32_t)) return mul(a, std::any_cast<types::u32_t>(b));
                else if (ti == typeid(types::i16_t)) return mul(a, std::any_cast<types::i16_t>(b));
                else if (ti == typeid(types::u16_t)) return mul(a, std::any_cast<types::u16_t>(b));
                else if (ti == typeid(types::i8_t))  return mul(a, std::any_cast<types::i8_t>(b));
                else if (ti == typeid(types::u8_t))  return mul(a, std::any_cast<types::u8_t>(b));
                else if (ti == typeid(types::char_t)) return mul(a, std::any_cast<types::char_t>(b));
                else if (ti == typeid(types::bool_t)) return mul(a, std::any_cast<types::bool_t>(b));
                throw logger::types::RuntimeError("cannot multiply char by non-integer var.");
                return "";
            }
        
            // ========== DIVISION ==========
            inline types::char_t div(types::char_t a, types::var_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot divide char.");
                return '\0';
            }
        
            // ========== POWER ==========
            inline types::char_t pow(types::char_t a, types::var_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return '\0';
            }
        }  // namespace char_t
    }
}