//
//  RabbitMQTests.m
//  RabbitMQTests
//
//  Created by Sven A. Schmidt on 05/10/2015.
//  Copyright © 2015 feinstruktur. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <RabbitMQ.h>

@interface RabbitMQTests : XCTestCase

@end

@implementation RabbitMQTests

- (void)testExample {
    amqp_connection_state_t conn = amqp_new_connection();
    XCTAssert(conn != nil);
}

@end
