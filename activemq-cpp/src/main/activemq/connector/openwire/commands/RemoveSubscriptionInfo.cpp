/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/RemoveSubscriptionInfo.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for RemoveSubscriptionInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
RemoveSubscriptionInfo::RemoveSubscriptionInfo()
{
    this->connectionId = NULL;
    this->subcriptionName = "";
    this->clientId = "";
}

////////////////////////////////////////////////////////////////////////////////
RemoveSubscriptionInfo::~RemoveSubscriptionInfo()
{
    delete this->connectionId;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* RemoveSubscriptionInfo::cloneDataStructure() const {
    RemoveSubscriptionInfo* removeSubscriptionInfo = new RemoveSubscriptionInfo();

    // Copy the data from the base class or classes
    removeSubscriptionInfo->copyDataStructure( this );

    return removeSubscriptionInfo;
}

////////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const RemoveSubscriptionInfo* srcPtr = dynamic_cast<const RemoveSubscriptionInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "RemoveSubscriptionInfo::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getConnectionId() != NULL ) {
        this->setConnectionId( 
            dynamic_cast<ConnectionId*>( 
                srcPtr->getConnectionId()->cloneDataStructure() ) );
    }
    this->setSubcriptionName( srcPtr->getSubcriptionName() );
    this->setClientId( srcPtr->getClientId() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char RemoveSubscriptionInfo::getDataStructureType() const {
    return RemoveSubscriptionInfo::ID_REMOVESUBSCRIPTIONINFO; 
}

////////////////////////////////////////////////////////////////////////////////
const ConnectionId* RemoveSubscriptionInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
ConnectionId* RemoveSubscriptionInfo::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfo::setConnectionId(ConnectionId* connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& RemoveSubscriptionInfo::getSubcriptionName() const {
    return subcriptionName;
}

////////////////////////////////////////////////////////////////////////////////
std::string& RemoveSubscriptionInfo::getSubcriptionName() {
    return subcriptionName;
}

////////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfo::setSubcriptionName(const std::string& subcriptionName ) {
    this->subcriptionName = subcriptionName;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& RemoveSubscriptionInfo::getClientId() const {
    return clientId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& RemoveSubscriptionInfo::getClientId() {
    return clientId;
}

////////////////////////////////////////////////////////////////////////////////
void RemoveSubscriptionInfo::setClientId(const std::string& clientId ) {
    this->clientId = clientId;
}

