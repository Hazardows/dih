#pragma once

#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"

#include <string>
#include <cstring>

namespace dih {
    namespace interactor {
        namespace string_t {
            // addition
            inline types::string_t add(types::string_t a, types::u8_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::u16_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::u32_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::u64_t b) {
                return a + std::to_string(b);
            }

            inline types::string_t add(types::string_t a, types::i8_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::i16_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::i32_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::i64_t b) {
                return a + std::to_string(b);
            }

            inline types::string_t add(types::string_t a, types::f32_t b) {
                return a + std::to_string(b);
            }
            inline types::string_t add(types::string_t a, types::f64_t b) {
                return a + std::to_string(b);
            }

            inline types::string_t add(types::string_t a, types::char_t b) {
                return a + b;
            }
            inline types::string_t add(types::string_t a, types::bool_t b) {
                return a + (b ? "true" : "false");
            }
            inline types::string_t add(types::string_t a, types::string_t b) {
                return a + b;
            }
            inline types::string_t add(types::string_t a, types::var_t b) {
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
                    return add(a, std::any_cast<types::u8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return add(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return add(a, std::any_cast<types::string_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return add(a, std::any_cast<types::bool_t>(b));
                }

                // this should never get here
                throw logger::types::RuntimeError("cannot add var to string.");
                return "";
            }

            // substraction
            inline types::string_t sub(types::string_t a, types::u8_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract u8 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::u16_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract u16 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::u32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract u32 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::u64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract u64 from string.");
                return "";
            }

            inline types::string_t sub(types::string_t a, types::i8_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract i8 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::i16_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract i16 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::i32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract i32 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::i64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract i64 from string.");
                return "";
            }

            inline types::string_t sub(types::string_t a, types::f32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract f32 from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::f64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract f64 from string.");
                return "";
            }

            inline types::string_t sub(types::string_t a, types::char_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract char from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::bool_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract bool from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot substract string from string.");
                return "";
            }
            inline types::string_t sub(types::string_t a, types::var_t b) {
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
                    return sub(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return sub(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return sub(a, std::any_cast<types::string_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return sub(a, std::any_cast<types::bool_t>(b));
                }

                // this should never get here
                throw logger::types::RuntimeError("cannot substract var from string.");
                return "";
            }

            // multiplication
            inline types::string_t mul_helper(types::string_t a, types::u64_t b);
            inline types::string_t mul_helper(types::string_t a, types::i64_t b);

            inline types::string_t mul(types::string_t a, types::u8_t b) {
                return mul_helper(a, (types::u64_t)b);
            }
            inline types::string_t mul(types::string_t a, types::u16_t b) {
                return mul_helper(a, (types::u64_t)b);
            }
            inline types::string_t mul(types::string_t a, types::u32_t b) {
                return mul_helper(a, (types::u64_t)b);
            }
            inline types::string_t mul(types::string_t a, types::u64_t b) {
                return mul_helper(a, b);
            }

            inline types::string_t mul(types::string_t a, types::i8_t b) {
                return mul_helper(a, (types::i64_t)b);
            }
            inline types::string_t mul(types::string_t a, types::i16_t b) {
                return mul_helper(a, (types::i64_t)b);
            }
            inline types::string_t mul(types::string_t a, types::i32_t b) {
                return mul_helper(a, (types::i64_t)b);
            }
            inline types::string_t mul(types::string_t a, types::i64_t b) {
                return mul_helper(a, b);
            }

            inline types::string_t mul_helper(types::string_t a, types::u64_t b) {
                if (b == 0 || a.empty()) {
                    return "";
                }

                types::string_t result;
                if (a.size() == 1) {
                    result.resize(static_cast<size_t>(b), a[0]);
                    return result;
                }

                const size_t n = a.size();
                const size_t total = n * static_cast<size_t>(b);

                result.resize(total);
                for (size_t i = 0; i < total; i += n) {
                    std::memcpy(&result[i], a.data(), n);
                }
                return result;
            }
            inline types::string_t mul_helper(types::string_t a, types::i64_t b) {
                if (b < 0) {
                    throw logger::types::RuntimeError("cannot multiply a string by a number less than 0.");
                    return "";
                }
                if (b == 0 || a.empty()) {
                    return "";
                }

                types::string_t result;
                if (a.size() == 1) {
                    result.resize(static_cast<size_t>(b), a[0]);
                    return result;
                }

                const size_t n = a.size();
                const size_t total = n * static_cast<size_t>(b);

                result.resize(total);
                for (size_t i = 0; i < total; i += n) {
                    std::memcpy(&result[i], a.data(), n);
                }
                return result;
            }

            inline types::string_t mul(types::string_t a, types::f32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply a string by a f32.");
                return "";
            }
            inline types::string_t mul(types::string_t a, types::f64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply a string by a f64.");
                return "";
            }

            inline types::string_t mul(types::string_t a, types::char_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply a string by a char.");
                return "";
            }
            inline types::string_t mul(types::string_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply a string by a string.");
                return "";
            }
            inline types::string_t mul(types::string_t a, types::bool_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("cannot multiply a string by a bool.");
                return "";
            }
            inline types::string_t mul(types::string_t a, types::var_t b) {
                var_inspector vi(b);
                if (vi.is_number) {
                    return mul(a, static_cast<types::i64_t>(toNumber(b)));
                }
                throw logger::types::RuntimeError("cannot multiply a string by a non-integer value.");
                return "";
            }

            // division
            inline types::string_t div(types::string_t a, types::u8_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by u8.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::u16_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by u16.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::u32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by u32.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::u64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by u64.");
                return "";
            }

            inline types::string_t div(types::string_t a, types::i8_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by i8.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::i16_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by i16.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::i32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by i32.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::i64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by i64.");
                return "";
            }

            inline types::string_t div(types::string_t a, types::f32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by f32.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::f64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by f64.");
                return "";
            }

            inline types::string_t div(types::string_t a, types::char_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by char.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::bool_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by bool.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("strings cannot be divided by string.");
                return "";
            }
            inline types::string_t div(types::string_t a, types::var_t b) {
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
                    return div(a, std::any_cast<types::i8_t>(b));
                }
                else if (type_info == typeid(types::char_t)) {
                    return div(a, std::any_cast<types::char_t>(b));
                }
                else if (type_info == typeid(types::string_t)) {
                    return div(a, std::any_cast<types::string_t>(b));
                }
                else if (type_info == typeid(types::bool_t)) {
                    return div(a, std::any_cast<types::bool_t>(b));
                }

                // this should never get here
                throw logger::types::RuntimeError("strings cannot be divided by var.");
                return "";
            }

            // power
            inline types::string_t pow(types::string_t a, types::u8_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::u16_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::u32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::u64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }

            inline types::string_t pow(types::string_t a, types::i8_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::i16_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::i32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::i64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }

            inline types::string_t pow(types::string_t a, types::f32_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::f64_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }

            inline types::string_t pow(types::string_t a, types::char_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::bool_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::string_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
            inline types::string_t pow(types::string_t a, types::var_t b) {
                (void)a; (void)b;
                throw logger::types::RuntimeError("pow is only applicable to numbers.");
                return "";
            }
        };
    }
}