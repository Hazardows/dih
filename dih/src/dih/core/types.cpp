#include "types.hpp"
#include "../interpreter/callable.hpp"
#include "logger/logger.hpp"

using namespace std;
using namespace dih::types;

namespace dih {

    var_inspector::var_inspector(const var_t& var) : type_info(var.type()) {
        is_float = type_info == typeid(f64_t) || type_info == typeid(f32_t);
        is_number = (
            is_float ||
            (type_info == typeid(i64_t)) || (type_info == typeid(i32_t)) || 
            (type_info == typeid(i16_t)) || (type_info == typeid(i8_t))  || 
            (type_info == typeid(u64_t)) || (type_info == typeid(u32_t)) ||
            (type_info == typeid(u16_t)) || (type_info == typeid(u8_t))
        );
        is_string = (type_info == typeid(string_t));
        is_char = (type_info == typeid(char_t));
        is_bool = (type_info == typeid(bool_t));
        is_nil = (type_info == typeid(nil_t));
    }

    string toString(const var_t& value) {
        var_inspector data(value);
        if (data.is_nil) {
            return "nil";
        }
        else if (data.is_number) {
            f64_t val = toNumber(value);
            i64_t ival = static_cast<i64_t>(val);

            if (val == ival) {
                return to_string(ival);
            }
            return to_string(val);
        }
        else if (data.is_string) {
            return any_cast<string_t>(value);
        }
        else if (data.is_char) {
            return string(1, any_cast<char_t>(value));
        }
        else if (data.is_bool) {
            return any_cast<bool_t>(value) ? "true" : "false";
        }
        return "nil";
    }

    f64_t toNumber(const var_t& val) {
        const type_info& ti = val.type();
        if (ti == typeid(u8_t))          return any_cast<u8_t>(val);
        else if (ti == typeid(u16_t))    return any_cast<u16_t>(val);
        else if (ti == typeid(u32_t))    return any_cast<u32_t>(val);
        else if (ti == typeid(u64_t))    return static_cast<f64_t>(any_cast<u64_t>(val));
        else if (ti == typeid(i8_t))     return any_cast<i8_t>(val);
        else if (ti == typeid(i16_t))    return any_cast<i16_t>(val);
        else if (ti == typeid(i32_t))    return any_cast<i32_t>(val);
        else if (ti == typeid(i64_t))    return static_cast<f64_t>(any_cast<i64_t>(val));
        else if (ti == typeid(f32_t))    return any_cast<f32_t>(val);
        else if (ti == typeid(f64_t))    return any_cast<f64_t>(val);
        return 0.0;
    }

    namespace types {
        bool ptr_t::checkptr(ptr_t& ptr) {
            if (!ptr.is_native) {
                throw logger::types::RuntimeError("Cant use checkptr on allocations not made by dih.");
            }
            else if (ptr.alloc->alive && ((ptr.direction >= (ptr.alloc->mem_start + ptr.alloc->range)) || (ptr.direction < ptr.alloc->mem_start))) {
                ptr.direction = ptr.alloc->mem_start;
            }
            return ptr.alloc->alive;
        }
    };

    namespace special {
        const types::string_t dihValueContainer::stingize() const {
            switch (type_id) {
                case dihTypeId::u8_t:
                    return toString(get_u8());
                case dihTypeId::u16_t:
                    return toString(get_u16());
                case dihTypeId::u32_t:
                    return toString(get_u32());
                case dihTypeId::u64_t:
                    return toString(get_u64());
                case dihTypeId::i8_t:
                    return toString(get_i8());
                case dihTypeId::i16_t:
                    return toString(get_i16());
                case dihTypeId::i32_t:
                    return toString(get_i32());
                case dihTypeId::i64_t:
                    return toString(get_i64());
                case dihTypeId::f32_t:
                    return toString(get_f32());
                case dihTypeId::f64_t:
                    return toString(get_f64());
                case dihTypeId::bool_t:
                    return toString(get_bool());
                case dihTypeId::char_t:
                    return toString(get_char());
                case dihTypeId::string_t:
                    return get_string();
                case dihTypeId::var_t:
                    return toString(get_var());
                case dihTypeId::internal_callable:
                    return get_Callable()->toString();
                case dihTypeId::internal_nil:
                    return "nil";
                case dihTypeId::internal_ptr:
                    return to_string((u64_t)get_ptr().direction);
            }
        }

        void special::dihValueContainer::update_var_wrap() {
            if (type_id != dihTypeId::var_t) return;

            const std::type_info& ti = get_var().type();
            if (ti == typeid(types::u8_t))          var_wrap_type_id = dihTypeId::u8_t;
            else if (ti == typeid(types::u16_t))    var_wrap_type_id = dihTypeId::u16_t;
            else if (ti == typeid(types::u32_t))    var_wrap_type_id = dihTypeId::u32_t;
            else if (ti == typeid(types::u64_t))    var_wrap_type_id = dihTypeId::u64_t;
            else if (ti == typeid(types::i8_t))     var_wrap_type_id = dihTypeId::i8_t;
            else if (ti == typeid(types::i16_t))    var_wrap_type_id = dihTypeId::i16_t;
            else if (ti == typeid(types::i32_t))    var_wrap_type_id = dihTypeId::i32_t;
            else if (ti == typeid(types::i64_t))    var_wrap_type_id = dihTypeId::i64_t;
            else if (ti == typeid(types::f32_t))    var_wrap_type_id = dihTypeId::f32_t;
            else if (ti == typeid(types::f64_t))    var_wrap_type_id = dihTypeId::f64_t;
            else if (ti == typeid(types::char_t))   var_wrap_type_id = dihTypeId::char_t;
            else if (ti == typeid(types::string_t)) var_wrap_type_id = dihTypeId::string_t;
            else if (ti == typeid(types::bool_t))   var_wrap_type_id = dihTypeId::bool_t;
            else if (ti == typeid(types::ptr_t))    var_wrap_type_id = dihTypeId::internal_ptr;
            else if (ti == typeid(types::nil_t))    var_wrap_type_id = dihTypeId::internal_nil;
            else if (ti == typeid(std::shared_ptr<Callable>)) {
                var_wrap_type_id = dihTypeId::internal_callable;
            }
            else {
                std::printf("unknown type wrapped");
            }
        }
    };
}
