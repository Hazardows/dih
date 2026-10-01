#pragma once

#include "platform.h"
#include "ast/typeid.hpp"

#include <any>
#include <string>
#include <cstdint>
#include <cstddef>
#include <memory>
#include <variant>
#include <vector>

namespace dih {
    class Callable;

    namespace types {
        // forbidden
        using nil_t = struct{};
        using null_t = std::nullptr_t;
        
        // specific
        using u8_t = uint8_t;
        using u16_t = uint16_t;
        using u32_t = uint32_t;
        using u64_t = uint64_t;
        using i8_t = int8_t;
        using i16_t = int16_t;
        using i32_t = int32_t;
        using i64_t = int64_t;
        using f32_t = float;
        using f64_t = double;

        class dih_allocation {
            public:
            char* mem_start;
            u64_t range;
            bool alive;
        };

        class ptr_t {
            public:
            void* direction;
            
            bool is_native = false;
            std::shared_ptr<dih_allocation> alloc;
            dihTypeId type_pointed;

            static bool checkptr(ptr_t& ptr);
        };

        // general
        using char_t = char;
        using string_t = std::string;
        using bool_t = bool;
        using void_t = void;
        using var_t = std::any;
        /*class var_t {
            public:
            std::variant<
                types::u8_t, types::u16_t, types::u32_t, types::u64_t,
                types::i8_t, types::i16_t, types::i32_t, types::i64_t,
                types::f32_t, types::f64_t,
                types::bool_t, types::char_t, types::string_t, types::var_t,
                std::shared_ptr<Callable>
            > value;
            dihTypeId type_id;
            var_t(dihTypeId type, std::variant<
                types::u8_t, types::u16_t, types::u32_t, types::u64_t,
                types::i8_t, types::i16_t, types::i32_t, types::i64_t,
                types::f32_t, types::f64_t,
                types::bool_t, types::char_t, types::string_t, types::var_t,
                std::shared_ptr<Callable>> var) : type_id(type) {
                value = var;
            }
        }*/
        
        // Tokenizer turns this into the asigned types
        // this is not needed anymore.
        // using int_t = i64_t;
        // using float_t = f32_t;
        // using double_t = f64_t;
    }
    
    // turn any var type into a string
    std::string toString(const types::var_t& value);
    // turn any var type into a number
    types::f64_t toNumber(const types::var_t& val);

    namespace special {
        inline constexpr types::nil_t nil = {};
        inline constexpr types::null_t null = nullptr;

        class dihValueContainer {
            private:
            void update_var_wrap();

            public:
            std::variant<
                types::u8_t, types::u16_t, types::u32_t, types::u64_t,
                types::i8_t, types::i16_t, types::i32_t, types::i64_t,
                types::f32_t, types::f64_t,
                types::bool_t, types::char_t, types::string_t, types::var_t,
                std::shared_ptr<Callable>, types::ptr_t
            > value;
            dihTypeId type_id;
            dihTypeId var_wrap_type_id;

            dihValueContainer(types::u8_t var) : value(var), type_id(dihTypeId::u8_t) {}
            dihValueContainer(types::u16_t var) : value(var), type_id(dihTypeId::u16_t) {}
            dihValueContainer(types::u32_t var) : value(var), type_id(dihTypeId::u32_t) {}
            dihValueContainer(types::u64_t var) : value(var), type_id(dihTypeId::u64_t) {}
            dihValueContainer(types::i8_t var) : value(var), type_id(dihTypeId::i8_t) {}
            dihValueContainer(types::i16_t var) : value(var), type_id(dihTypeId::i16_t) {}
            dihValueContainer(types::i32_t var) : value(var), type_id(dihTypeId::i32_t) {}
            dihValueContainer(types::i64_t var) : value(var), type_id(dihTypeId::i64_t) {}
            dihValueContainer(types::f32_t var) : value(var), type_id(dihTypeId::f32_t) {}
            dihValueContainer(types::f64_t var) : value(var), type_id(dihTypeId::f64_t) {}
            dihValueContainer(types::bool_t var) : value(var), type_id(dihTypeId::bool_t) {}
            dihValueContainer(types::char_t var) : value(var), type_id(dihTypeId::char_t) {}
            dihValueContainer(types::string_t var) : value(var), type_id(dihTypeId::string_t) {}
            dihValueContainer(types::ptr_t var) : value(var), type_id(dihTypeId::internal_ptr) {}
            dihValueContainer(types::var_t var) : value(var), type_id(dihTypeId::var_t) {
                update_var_wrap();
            }
            dihValueContainer(dihTypeId id) {
                switch (id) {
                    case dihTypeId::u8_t: 
                        value = types::u8_t(0);
                        break;
                    case dihTypeId::u16_t:
                        value = types::u16_t(0);
                        break;
                    case dihTypeId::u32_t:
                        value = types::u32_t(0);
                        break;
                    case dihTypeId::u64_t:
                        value = types::u64_t(0);
                        break;
                    case dihTypeId::i8_t:
                        value = types::i8_t(0);
                        break;
                    case dihTypeId::i16_t:
                        value = types::i16_t(0);
                        break;
                    case dihTypeId::i32_t:
                        value = types::i32_t(0);
                        break;
                    case dihTypeId::i64_t:
                        value = types::i64_t(0);
                        break;
                    case dihTypeId::f32_t:
                        value = types::f32_t(0.0f);
                        break;
                    case dihTypeId::f64_t:
                        value = types::f64_t(0.0);
                        break;
                    case dihTypeId::char_t:
                        value = types::char_t('\0');
                        break;
                    case dihTypeId::string_t:
                        value = types::string_t("");
                        break;
                    case dihTypeId::bool_t:
                        value = types::bool_t(false);
                        break;
                    case dihTypeId::var_t:
                        value = types::var_t(special::nil);
                        var_wrap_type_id = dihTypeId::internal_nil;
                        break;
                    case dihTypeId::internal_callable:
                        value = std::shared_ptr<Callable>(nullptr);
                        break;
                    case dihTypeId::internal_nil:
                        value = types::var_t(special::nil);
                        type_id = dihTypeId::var_t;
                        var_wrap_type_id = dihTypeId::internal_nil;
                        return;
                    case dihTypeId::internal_ptr:
                        value = types::ptr_t();
                        break;
                }
                type_id = id;
            }

            // store functions
            dihValueContainer(std::shared_ptr<Callable> var) : value(var), type_id(dihTypeId::internal_callable) {}

            types::u8_t& get_u8() {
                return get<types::u8_t>(value);
            }
            const types::u8_t& get_u8() const {
                return get<types::u8_t>(value);
            }

            types::u16_t& get_u16() {
                return get<types::u16_t>(value);
            }
            const types::u16_t& get_u16() const {
                return get<types::u16_t>(value);
            }
            types::u32_t& get_u32() {
                return get<types::u32_t>(value);
            }
            const types::u32_t& get_u32() const {
                return get<types::u32_t>(value);
            }
            types::u64_t& get_u64() {
                return get<types::u64_t>(value);
            }
            const types::u64_t& get_u64() const {
                return get<types::u64_t>(value);
            }

            types::i8_t& get_i8() {
                return get<types::i8_t>(value);
            }
            const types::i8_t& get_i8() const {
                return get<types::i8_t>(value);
            }
            types::i16_t& get_i16() {
                return get<types::i16_t>(value);
            }
            const types::i16_t& get_i16() const {
                return get<types::i16_t>(value);
            }
            types::i32_t& get_i32() {
                return get<types::i32_t>(value);
            }
            const types::i32_t& get_i32() const {
                return get<types::i32_t>(value);
            }
            types::i64_t& get_i64() {
                return get<types::i64_t>(value);
            }
            const types::i64_t& get_i64() const {
                return get<types::i64_t>(value);
            }

            types::f32_t& get_f32() {
                return get<types::f32_t>(value);
            }
            const types::f32_t& get_f32() const {
                return get<types::f32_t>(value);
            }
            types::f64_t& get_f64() {
                return get<types::f64_t>(value);
            }
            const types::f64_t& get_f64() const {
                return get<types::f64_t>(value);
            }

            types::var_t& get_var() {
                return get<types::var_t>(value);
            }
            const types::var_t& get_var() const {
                return get<types::var_t>(value);
            }
            types::char_t& get_char() {
                return get<types::char_t>(value);
            }
            const types::char_t& get_char() const {
                return get<types::char_t>(value);
            }
            types::string_t& get_string() {
                return get<types::string_t>(value);
            }
            const types::string_t& get_string() const {
                return get<types::string_t>(value);
            }
            types::bool_t& get_bool() {
                return get<types::bool_t>(value);
            }
            const types::bool_t& get_bool() const {
                return get<types::bool_t>(value);
            }

            std::shared_ptr<Callable> get_Callable() {
                return get<std::shared_ptr<Callable>>(value);
            }
            const std::shared_ptr<Callable> get_Callable() const {
                return get<std::shared_ptr<Callable>>(value);
            }

            types::ptr_t& get_ptr() {
                return get<types::ptr_t>(value);
            }
            const types::ptr_t& get_ptr() const {
                return get<types::ptr_t>(value);
            }

            const types::string_t stingize() const;
        };
    }

    // helper class for inspecting var types
    class var_inspector {
    
        public:
        const std::type_info& type_info;
        bool is_number;
        bool is_float;
        bool is_string;
        bool is_char;
        bool is_bool;
        bool is_nil;

        var_inspector(const types::var_t& var);
    };
}
