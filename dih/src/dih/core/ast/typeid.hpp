#pragma once

namespace dih {
    enum struct dihTypeId {
        u8_t, u16_t, u32_t, u64_t,
        i8_t, i16_t, i32_t, i64_t,
        f32_t, f64_t,
        char_t, string_t, bool_t, var_t,
        internal_callable, internal_ptr,
        internal_nil
    };
}