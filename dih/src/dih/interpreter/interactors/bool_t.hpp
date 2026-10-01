#pragma once

#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"

#include <cmath>

namespace dih {
    namespace interactor {
        namespace bool_t {
            // ========== ADDITION ==========
            // bool + number = number (promoción a i64 o f64)
            inline types::u8_t add(types::bool_t a, types::u8_t b)  { return (a ? 1 : 0) + b; }
            inline types::u16_t add(types::bool_t a, types::u16_t b) { return (a ? 1 : 0) + b; }
            inline types::u32_t add(types::bool_t a, types::u32_t b) { return (a ? 1 : 0) + b; }
            inline types::u64_t add(types::bool_t a, types::u64_t b) { return (a ? 1 : 0) + b; }
            inline types::i8_t add(types::bool_t a, types::i8_t b)  { return (a ? 1 : 0) + b; }
            inline types::i16_t add(types::bool_t a, types::i16_t b) { return (a ? 1 : 0) + b; }
            inline types::i32_t add(types::bool_t a, types::i32_t b) { return (a ? 1 : 0) + b; }
            inline types::i64_t add(types::bool_t a, types::i64_t b) { return (a ? 1 : 0) + b; }
        
            inline types::f32_t add(types::bool_t a, types::f32_t b) { return (a ? 1.0 : 0.0) + b; }
            inline types::f64_t add(types::bool_t a, types::f64_t b) { return (a ? 1.0 : 0.0) + b; }
        
            inline types::char_t add(types::bool_t a, types::char_t b) { return (a ? 1 : 0) + b; }
            inline types::bool_t add(types::bool_t a, types::bool_t b) { return (a || b) && (b != a);  }
            inline types::string_t add(types::bool_t a, types::string_t b) {
                return (a ? "true" : "false") + b;
            }
        
            inline special::dihValueContainer add(types::bool_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot add var to bool.");
                return 0;
            }
        
            // ========== SUBTRACTION ==========
            // todo: fix returns
            inline types::u8_t sub(types::bool_t a, types::u8_t b)  { return (a ? 1 : 0) - b; }
            inline types::u16_t sub(types::bool_t a, types::u16_t b) { return (a ? 1 : 0) - b; }
            inline types::u32_t sub(types::bool_t a, types::u32_t b) { return (a ? 1 : 0) - b; }
            inline types::u64_t sub(types::bool_t a, types::u64_t b) { return (a ? 1 : 0) - b; }
            inline types::i8_t sub(types::bool_t a, types::i8_t b)  { return (a ? 1 : 0) - b; }
            inline types::i16_t sub(types::bool_t a, types::i16_t b) { return (a ? 1 : 0) - b; }
            inline types::i32_t sub(types::bool_t a, types::i32_t b) { return (a ? 1 : 0) - b; }
            inline types::i64_t sub(types::bool_t a, types::i64_t b) { return (a ? 1 : 0) - b; }
            inline types::f32_t sub(types::bool_t a, types::f32_t b) { return (a ? 1.0 : 0.0) - b; }
            inline types::f64_t sub(types::bool_t a, types::f64_t b) { return (a ? 1.0 : 0.0) - b; }
            inline types::char_t sub(types::bool_t a, types::char_t b) { return (a ? 1 : 0) - b; }
            inline types::bool_t sub(types::bool_t a, types::bool_t b) { return (a || b) && (b != a); }
            inline types::bool_t sub(types::bool_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract string from bool.");
                return false;
            }
            inline special::dihValueContainer sub(types::bool_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot substract var from bool.");
                return 0;
            }

            // ========== MULTIPLICATION ==========
            inline types::u8_t mul(types::bool_t a, types::u8_t b)  { return (a ? b : 0); }
            inline types::u16_t mul(types::bool_t a, types::u16_t b) { return (a ? b : 0); }
            inline types::u32_t mul(types::bool_t a, types::u32_t b) { return (a ? b : 0); }
            inline types::u64_t mul(types::bool_t a, types::u64_t b) { return (a ? b : 0); }
            inline types::i8_t mul(types::bool_t a, types::i8_t b)  { return (a ? b : 0); }
            inline types::i16_t mul(types::bool_t a, types::i16_t b) { return (a ? b : 0); }
            inline types::i32_t mul(types::bool_t a, types::i32_t b) { return (a ? b : 0); }
            inline types::i64_t mul(types::bool_t a, types::i64_t b) { return (a ? b : 0); }
            inline types::f32_t mul(types::bool_t a, types::f32_t b) { return (a ? b : 0); }
            inline types::f64_t mul(types::bool_t a, types::f64_t b) { return (a ? b : 0); }
            inline types::char_t mul(types::bool_t a, types::char_t b) { return (a ? b : 0); }
            inline types::bool_t mul(types::bool_t a, types::bool_t b) { return (a ? b : false); }
            inline types::bool_t mul(types::bool_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply bool by string.");
                return false;
            }
            inline types::var_t mul(types::bool_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot multiply var by bool.");
                return 0;
            }

            // ========== DIVISION ==========
            inline types::u8_t div(types::bool_t a, types::u8_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::u16_t div(types::bool_t a, types::u16_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::u32_t div(types::bool_t a, types::u32_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::u64_t div(types::bool_t a, types::u64_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::i8_t div(types::bool_t a, types::i8_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::i16_t div(types::bool_t a, types::i16_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::i32_t div(types::bool_t a, types::i32_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::i64_t div(types::bool_t a, types::i64_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::f64_t div(types::bool_t a, types::f32_t b) {
                if (b == 0.0f) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1.0 : 0.0) / b;
            }
            inline types::f64_t div(types::bool_t a, types::f64_t b) {
                if (b == 0.0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1.0 : 0.0) / b;
            }
            inline types::char_t div(types::bool_t a, types::char_t b) {
                if (b == 0) throw logger::types::RuntimeError("division by zero.");
                return (a ? 1 : 0) / b;
            }
            inline types::bool_t div(types::bool_t a, types::bool_t b) {
                if (!b) throw logger::types::RuntimeError("division by zero.");
                return a;
            }
            inline types::i64_t div(types::bool_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot divide bool by string.");
                return 0;
            }
            inline types::var_t div(types::bool_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot divide bool by var.");
                return 0;
            }

            // ========== POWER ==========
            inline types::bool_t pow(types::bool_t a, types::u8_t b)  { return a; }
            inline types::bool_t pow(types::bool_t a, types::u16_t b) { return a; }
            inline types::bool_t pow(types::bool_t a, types::u32_t b) { return a; }
            inline types::bool_t pow(types::bool_t a, types::u64_t b) { return a; }
            inline types::bool_t pow(types::bool_t a, types::i8_t b) {
                return a && (b > 0);
            }
            inline types::bool_t pow(types::bool_t a, types::i16_t b) {
                return a && (b > 0);
            }
            inline types::bool_t pow(types::bool_t a, types::i32_t b) {
                return a && (b > 0);
            }
            inline types::bool_t pow(types::bool_t a, types::i64_t b) {
                return a && (b > 0);
            }
            inline types::bool_t pow(types::bool_t a, types::f32_t b) { return std::pow((a ? 1.0 : 0.0), b) >= 1; }
            inline types::bool_t pow(types::bool_t a, types::f64_t b) { return std::pow((a ? 1.0 : 0.0), b) >= 1; }
            inline types::bool_t pow(types::bool_t a, types::char_t b) { return a; }
            inline types::bool_t pow(types::bool_t a, types::bool_t b) { return a; }
            inline types::bool_t pow(types::bool_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot raise bool to string power.");
                return 0;
            }
            inline types::bool_t pow(types::bool_t a, types::var_t b) {
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
                throw logger::types::RuntimeError("cannot raise bool to var power.");
                return 0;
            }
        }  // namespace bool_t
    }
}