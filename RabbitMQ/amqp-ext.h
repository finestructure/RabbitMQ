//
//  amqp-ext.h
//  HastyHare
//
//  Created by Sven A. Schmidt on 28/09/2015.
//  Copyright © 2015 feinstruktur. All rights reserved.
//

#ifndef HastyHare_amqp_ext_h
#define HastyHare_amqp_ext_h

#include "amqp_tcp_socket.h"
#include "amqp.h"
#include "amqp_framing.h"

amqp_rpc_reply_t amqp_login_with_credentials(amqp_connection_state_t state, char const *vhost,
                                             int channel_max, int frame_max, int heartbeat,
                                             amqp_sasl_method_enum sasl_method, const char * user, const char * password);

// make union structs accessible from Swift
amqp_method_t payload_method(amqp_frame_t *frame);
amqp_basic_deliver_t *method_decoded(amqp_frame_t *frame);

// getters for amqp_field_value_t union
amqp_boolean_t get_field_value_boolean(amqp_field_value_t v);
int8_t get_field_value_i8(amqp_field_value_t v);
uint8_t get_field_value_u8(amqp_field_value_t v);
int16_t get_field_value_i16(amqp_field_value_t v);
uint16_t get_field_value_u16(amqp_field_value_t v);
int32_t get_field_value_i32(amqp_field_value_t v);
uint32_t get_field_value_u32(amqp_field_value_t v);
int64_t get_field_value_i64(amqp_field_value_t v);
uint64_t get_field_value_u64(amqp_field_value_t v);
float get_field_value_f32(amqp_field_value_t v);
double get_field_value_f64(amqp_field_value_t v);
amqp_decimal_t get_field_value_decimal(amqp_field_value_t v);
amqp_bytes_t get_field_value_bytes(amqp_field_value_t v);
amqp_table_t get_field_value_table(amqp_field_value_t v);
amqp_array_t get_field_value_array(amqp_field_value_t v);

// setters for amqp_field_value_t union (partial)
void set_field_value_bytes(amqp_field_value_t *v, amqp_bytes_t new_value);

#endif /* HastyHare_amqp_ext_h */
