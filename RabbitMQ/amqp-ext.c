//
//  amqp-ext.c
//  HastyHare
//
//  Created by Sven A. Schmidt on 28/09/2015.
//  Copyright © 2015 feinstruktur. All rights reserved.
//

#include "amqp-ext.h"

amqp_rpc_reply_t amqp_login_with_credentials(amqp_connection_state_t state, char const *vhost,
                                             int channel_max, int frame_max, int heartbeat,
                                             amqp_sasl_method_enum sasl_method, const char * user, const char * password) {
    return amqp_login(state, vhost, channel_max, frame_max, heartbeat, sasl_method, user, password);
}


amqp_method_t payload_method(amqp_frame_t *frame) {
    return frame->payload.method;
}


amqp_basic_deliver_t *method_decoded(amqp_frame_t * frame) {
    return frame->payload.method.decoded;
}


amqp_boolean_t field_value_boolean(amqp_field_value_t v) {
    return v.value.boolean;
}


int8_t field_value_i8(amqp_field_value_t v) {
    return v.value.i8;
}


uint8_t field_value_u8(amqp_field_value_t v) {
    return v.value.u8;
}


int16_t field_value_i16(amqp_field_value_t v) {
    return v.value.i16;
}


uint16_t field_value_u16(amqp_field_value_t v) {
    return v.value.u16;
}


int32_t field_value_i32(amqp_field_value_t v) {
    return v.value.i32;
}


uint32_t field_value_u32(amqp_field_value_t v) {
    return v.value.u32;
}


int64_t field_value_i64(amqp_field_value_t v) {
    return v.value.i64;
}


uint64_t field_value_u64(amqp_field_value_t v) {
    return v.value.u64;
}


float field_value_f32(amqp_field_value_t v) {
    return v.value.f32;
}


double field_value_f64(amqp_field_value_t v) {
    return v.value.f64;
}


amqp_decimal_t field_value_decimal(amqp_field_value_t v) {
    return v.value.decimal;
}


amqp_bytes_t field_value_bytes(amqp_field_value_t v) {
    return v.value.bytes;
}


amqp_table_t field_value_table(amqp_field_value_t v) {
    return v.value.table;
}


amqp_array_t field_value_array(amqp_field_value_t v) {
    return v.value.array;
}


void set_field_value_bytes(amqp_field_value_t *v, amqp_bytes_t new_value) {
    v->kind = AMQP_FIELD_KIND_BYTES;
    v->value.bytes = new_value;
}

