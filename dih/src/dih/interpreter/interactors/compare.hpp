#pragma once
    
#include "../../core/types.hpp"
#include "../../core/logger/logger.hpp"
    
namespace dih {
    namespace interactor {
        // Convierte un dihValueContainer numérico a f64 (NO acepta string)
        inline types::f64_t to_f64(const special::dihValueContainer& v) {
            switch (v.type_id) {
                case dihTypeId::u8_t:   return static_cast<types::f64_t>(v.get_u8());
                case dihTypeId::u16_t:  return static_cast<types::f64_t>(v.get_u16());
                case dihTypeId::u32_t:  return static_cast<types::f64_t>(v.get_u32());
                case dihTypeId::u64_t:  return static_cast<types::f64_t>(v.get_u64());
                case dihTypeId::i8_t:   return static_cast<types::f64_t>(v.get_i8());
                case dihTypeId::i16_t:  return static_cast<types::f64_t>(v.get_i16());
                case dihTypeId::i32_t:  return static_cast<types::f64_t>(v.get_i32());
                case dihTypeId::i64_t:  return static_cast<types::f64_t>(v.get_i64());
                case dihTypeId::f32_t:  return static_cast<types::f64_t>(v.get_f32());
                case dihTypeId::f64_t:  return v.get_f64();
                case dihTypeId::char_t: return static_cast<types::f64_t>(
                                            static_cast<unsigned char>(v.get_char()));
                case dihTypeId::bool_t: return v.get_bool() ? 1.0 : 0.0;
                default:
                    throw logger::types::RuntimeError("cannot convert value to f64 for comparison.");
            }
        }

        // ¿Es un tipo numérico (o convertible a número)?
        inline bool is_numeric(dihTypeId id) {
            switch (id) {
                case dihTypeId::u8_t:  case dihTypeId::u16_t:
                case dihTypeId::u32_t: case dihTypeId::u64_t:
                case dihTypeId::i8_t:  case dihTypeId::i16_t:
                case dihTypeId::i32_t: case dihTypeId::i64_t:
                case dihTypeId::f32_t: case dihTypeId::f64_t:
                case dihTypeId::char_t:
                case dihTypeId::bool_t:
                    return true;
                default:
                    return false;
            }
        }

        // ¿Es tipo "texto" (string o char)?
        inline bool is_text(dihTypeId id) {
            return id == dihTypeId::string_t || id == dihTypeId::char_t;
        }

        // Si es var_t, lo desempaqueta; si no, lo devuelve igual.
        // (Asumo que tienes un constructor de dihValueContainer desde cada tipo primitivo)
        inline special::dihValueContainer unwrap_var(const special::dihValueContainer& v, bool allow_nil = false) {
            if (v.type_id != dihTypeId::var_t) return v;
            const types::var_t& vtu = v.get_var();
            switch (v.var_wrap_type_id) {
                case dihTypeId::u8_t:
                    // return v.get_u8();
                    return any_cast<types::u8_t>(vtu);
                case dihTypeId::u16_t:
                    // return v.get_u16();
                    return any_cast<types::u16_t>(vtu);
                case dihTypeId::u32_t:
                    // return v.get_u32();
                    return any_cast<types::u32_t>(vtu);
                case dihTypeId::u64_t:
                    // return v.get_u64();
                    return any_cast<types::u32_t>(vtu);
                case dihTypeId::i8_t:
                    // return v.get_i8();
                    return any_cast<types::i8_t>(vtu);
                case dihTypeId::i16_t:
                    // return v.get_i16();
                    return any_cast<types::i16_t>(vtu);
                case dihTypeId::i32_t:
                    // return v.get_i32();
                    return any_cast<types::i32_t>(vtu);
                case dihTypeId::i64_t:
                    // return v.get_i64();
                    return any_cast<types::i64_t>(vtu);
                case dihTypeId::f32_t:
                    // return v.get_f32();
                    return any_cast<types::f32_t>(vtu);
                case dihTypeId::f64_t:
                    // return v.get_f64();
                    return any_cast<types::f64_t>(vtu);
                case dihTypeId::char_t:
                    // return v.get_char();
                    return any_cast<types::char_t>(vtu);
                case dihTypeId::string_t:
                    // return v.get_string();
                    return any_cast<types::string_t>(vtu);
                case dihTypeId::bool_t:
                    // return v.get_bool();
                    return any_cast<types::bool_t>(vtu);
                case dihTypeId::internal_callable:
                    // return v.get_Callable();
                    return any_cast<std::shared_ptr<Callable>>(vtu);
                case dihTypeId::internal_ptr:
                    // return v.get_ptr();
                    return any_cast<types::ptr_t>(vtu);
                case dihTypeId::internal_nil:
                    if (allow_nil) return v;
                case dihTypeId::var_t:
                    throw logger::types::RuntimeError("unknown var type (nil).");
                    return v;
            }
            throw logger::types::RuntimeError("unknown var_t type (nil).");
            return v;
        }

        // Helper: envuelve el valor real de 'v' en un types::var_t
        // y devuelve un dihValueContainer con type_id = var_t.
        inline special::dihValueContainer wrap_in_var(const special::dihValueContainer& v) {
            types::var_t wrapped;
            switch (v.type_id) {
                case dihTypeId::u8_t:   wrapped = types::var_t(v.get_u8());     break;
                case dihTypeId::u16_t:  wrapped = types::var_t(v.get_u16());    break;
                case dihTypeId::u32_t:  wrapped = types::var_t(v.get_u32());    break;
                case dihTypeId::u64_t:  wrapped = types::var_t(v.get_u64());    break;
                case dihTypeId::i8_t:   wrapped = types::var_t(v.get_i8());     break;
                case dihTypeId::i16_t:  wrapped = types::var_t(v.get_i16());    break;
                case dihTypeId::i32_t:  wrapped = types::var_t(v.get_i32());    break;
                case dihTypeId::i64_t:  wrapped = types::var_t(v.get_i64());    break;
                case dihTypeId::f32_t:  wrapped = types::var_t(v.get_f32());    break;
                case dihTypeId::f64_t:  wrapped = types::var_t(v.get_f64());    break;
                case dihTypeId::char_t: wrapped = types::var_t(v.get_char());   break;
                case dihTypeId::bool_t: wrapped = types::var_t(v.get_bool());   break;
                case dihTypeId::string_t: wrapped = types::var_t(v.get_string()); break;
                case dihTypeId::internal_callable:
                    wrapped = types::var_t(v.get_Callable());                   break;
                case dihTypeId::internal_ptr: wrapped = types::var_t(v.get_ptr()); break;
                case dihTypeId::internal_nil: wrapped = types::var_t(special::nil); break;
                case dihTypeId::var_t:
                    // ya es un var_t: devolverlo tal cual sin re-envolver
                    return v;
                // default:
                //     throw logger::types::RuntimeError("cannot wrap this type into var_t.");
            }
            return special::dihValueContainer(wrapped);
        }

        inline special::dihValueContainer interact_greater(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
        
            const bool a_text = is_text(a.type_id);
            const bool b_text = is_text(b.type_id);
        
            if (a_text && b_text) {
                return special::dihValueContainer(a.stingize() > b.stingize());
            }
            if (a_text && is_numeric(b.type_id)) {
                // "abc" > 5  →  size("abc") > 5
                return special::dihValueContainer(a.stingize().size() > to_f64(b));
            }
            if (is_numeric(a.type_id) && b_text) {
                // 5 > "abc"  →  5 > size("abc")
                return special::dihValueContainer(to_f64(a) > b.stingize().size());
            }
            if (is_numeric(a.type_id) && is_numeric(b.type_id)) {
                return special::dihValueContainer(to_f64(a) > to_f64(b));
            }
            throw logger::types::RuntimeError("cannot compare these types using '>'.");
        }

        inline special::dihValueContainer interact_greater_equal(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
        
            const bool a_text = is_text(a.type_id);
            const bool b_text = is_text(b.type_id);
        
            if (a_text && b_text) {
                return special::dihValueContainer(a.stingize() >= b.stingize());
            }
            if (a_text && is_numeric(b.type_id)) {
                return special::dihValueContainer(a.stingize().size() >= to_f64(b));
            }
            if (is_numeric(a.type_id) && b_text) {
                return special::dihValueContainer(to_f64(a) >= b.stingize().size());
            }
            if (is_numeric(a.type_id) && is_numeric(b.type_id)) {
                return special::dihValueContainer(to_f64(a) >= to_f64(b));
            }
            throw logger::types::RuntimeError("cannot compare these types using '>='.");
        }

        inline special::dihValueContainer interact_less(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
        
            const bool a_text = is_text(a.type_id);
            const bool b_text = is_text(b.type_id);
        
            if (a_text && b_text) {
                return special::dihValueContainer(a.stingize() < b.stingize());
            }
            if (a_text && is_numeric(b.type_id)) {
                // "abc" < 5  →  size("abc") < 5
                return special::dihValueContainer(a.stingize().size() < to_f64(b));
            }
            if (is_numeric(a.type_id) && b_text) {
                return special::dihValueContainer(to_f64(a) < b.stingize().size());
            }
            if (is_numeric(a.type_id) && is_numeric(b.type_id)) {
                return special::dihValueContainer(to_f64(a) < to_f64(b));
            }
            throw logger::types::RuntimeError("cannot compare these types using '<'.");
        }

        inline special::dihValueContainer interact_less_equal(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
        
            const bool a_text = is_text(a.type_id);
            const bool b_text = is_text(b.type_id);
        
            if (a_text && b_text) {
                return special::dihValueContainer(a.stingize() <= b.stingize());
            }
            if (a_text && is_numeric(b.type_id)) {
                return special::dihValueContainer(a.stingize().size() <= to_f64(b));
            }
            if (is_numeric(a.type_id) && b_text) {
                return special::dihValueContainer(to_f64(a) <= b.stingize().size());
            }
            if (is_numeric(a.type_id) && is_numeric(b.type_id)) {
                return special::dihValueContainer(to_f64(a) <= to_f64(b));
            }
            throw logger::types::RuntimeError("cannot compare these types using '<='.");
        }

        // ========== IGUALDAD ==========
        inline special::dihValueContainer interact_equal(special::dihValueContainer a, special::dihValueContainer b) {
            a = unwrap_var(a);
            b = unwrap_var(b);
        
            const bool a_text = is_text(a.type_id);
            const bool b_text = is_text(b.type_id);
        
            if (a_text && b_text) {
                return special::dihValueContainer(a.stingize() == b.stingize());
            }
            if (a_text && is_numeric(b.type_id)) {
                // "abc" == 3  →  size("abc") == 3
                return special::dihValueContainer(a.stingize().size() == to_f64(b));
            }
            if (is_numeric(a.type_id) && b_text) {
                return special::dihValueContainer(to_f64(a) == b.stingize().size());
            }
            if (is_numeric(a.type_id) && is_numeric(b.type_id)) {
                return special::dihValueContainer(to_f64(a) == to_f64(b));
            }
            // tipos incompatibles: false, sin error
            return special::dihValueContainer(false);
        }

        inline special::dihValueContainer interact_not_equal(special::dihValueContainer a, special::dihValueContainer b) {
            // reutilizamos eq
            special::dihValueContainer eq = interact_equal(a, b);
            return special::dihValueContainer(!eq.get_bool());
        }

        inline special::dihValueContainer interact_assign(dihTypeId target, special::dihValueContainer value) {
            // NOTA: 'target' representa el tipo actual de la variable destino.
            // 'value' es el valor que se quiere asignar.
            // El interactor devuelve el valor YA CONVERTIDO al tipo de 'target',
            // y el caller (el intérprete) es quien actualiza el slot de la variable.
        
            // Fuente: desempaquetar var_t
            special::dihValueContainer v = unwrap_var(value, true);
        
            switch (target) {
            
                // ========== DESTINOS ENTEROS SIN SIGNO ==========
                case dihTypeId::u8_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::u8_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to u8.");
                }
                case dihTypeId::u16_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::u16_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to u16.");
                }
                case dihTypeId::u32_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::u32_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to u32.");
                }
                case dihTypeId::u64_t: {
                    if (is_numeric(v.type_id)) {
                        types::f64_t r = std::round(to_f64(v));
                        if (r < 0.0) throw logger::types::RuntimeError("cannot assign negative to u64.");
                        return special::dihValueContainer(static_cast<types::u64_t>(r));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to u64.");
                }
            
                // ========== DESTINOS ENTEROS CON SIGNO ==========
                case dihTypeId::i8_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::i8_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to i8.");
                }
                case dihTypeId::i16_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::i16_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to i16.");
                }
                case dihTypeId::i32_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::i32_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to i32.");
                }
                case dihTypeId::i64_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::i64_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to i64.");
                }
            
                // ========== DESTINOS FLOTANTES ==========
                case dihTypeId::f32_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(static_cast<types::f32_t>(to_f64(v)));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to f32.");
                }
                case dihTypeId::f64_t: {
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(to_f64(v));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to f64.");
                }
            
                // ========== CHAR ==========
                case dihTypeId::char_t: {
                    if (v.type_id == dihTypeId::char_t) return v;
                    if (v.type_id == dihTypeId::string_t) {
                        const types::string_t& s = v.get_string();
                        if (s.empty()) {
                            throw logger::types::RuntimeError("cannot assign empty string to char.");
                        }
                        return special::dihValueContainer(s[0]);
                    }
                    if (is_numeric(v.type_id)) {
                        return special::dihValueContainer(
                            static_cast<types::char_t>(std::llround(to_f64(v))));
                    }
                    throw logger::types::RuntimeError("cannot assign this value to char.");
                }
            
                // ========== BOOL ==========
                case dihTypeId::bool_t: {
                    if (v.type_id == dihTypeId::bool_t)   return v;
                    if (v.type_id == dihTypeId::string_t) return special::dihValueContainer(!v.get_string().empty());
                    if (is_numeric(v.type_id))            return special::dihValueContainer(to_f64(v) > 0.0);
                    throw logger::types::RuntimeError("cannot assign this value to bool.");
                }
            
                // ========== STRING ==========
                case dihTypeId::string_t: {
                    return special::dihValueContainer(v.stingize());
                    throw logger::types::RuntimeError("cannot assign this value to string.");
                }
            
                // ========== VAR ==========
                case dihTypeId::var_t:
                    // var_t acepta cualquier cosa: guarda el valor tal cual
                    return wrap_in_var(v);
                case dihTypeId::internal_callable:
                    return v;
                default:
                    throw logger::types::RuntimeError("unknown target type in assignment.");
            }
        }
    }
}