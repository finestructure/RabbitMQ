//
//  RabbitMQTests.m
//  RabbitMQTests
//
//  Created by Sven A. Schmidt on 05/10/2015.
//  Copyright © 2015 feinstruktur. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <RabbitMQ.h>


const char *hostname = "dockerhost";
int port = 5672;
const char *user = "guest";
const char *password = "guest";


@interface RabbitMQTests : XCTestCase

@end

@implementation RabbitMQTests

- (void)testExample {
    amqp_connection_state_t conn = amqp_new_connection();
    XCTAssert(conn != nil);

    { // connect
        amqp_socket_t *socket = amqp_tcp_socket_new(conn);
        XCTAssert(socket != nil);
        int status = amqp_socket_open(socket, hostname, port);
        XCTAssertEqual(status, AMQP_STATUS_OK);
    }

    { // login
        int channel_max = 0;
        int frame_max = 131072; // 128kB
        int heartbeat = 0;
        amqp_sasl_method_enum sasl_method = AMQP_SASL_METHOD_PLAIN;
        const char *vhost = "/";
        amqp_rpc_reply_t res = amqp_login_with_credentials(conn, vhost, channel_max, frame_max, heartbeat, sasl_method, user, password);
        XCTAssertEqual(res.reply_type, AMQP_RESPONSE_NORMAL);
    }
}

@end
