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
#include <activemq/connector/openwire/commands/ConnectionInfo.h>
#include <activemq/exceptions/ActiveMQException.h>
#include <decaf/lang/exceptions/NullPointerException.h>
#include <memory>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace decaf::lang::exceptions;

/*
 *
 *  Command and marshaling code for OpenWire format for ConnectionInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ConnectionInfo::ConnectionInfo()
{
    this->connectionId = NULL;
    this->clientId = "";
    this->password = "";
    this->userName = "";
    this->brokerMasterConnector = false;
    this->manageable = false;
    this->clientMaster = false;
}

////////////////////////////////////////////////////////////////////////////////
ConnectionInfo::~ConnectionInfo()
{
    delete this->connectionId;
    for( size_t ibrokerPath = 0; ibrokerPath < brokerPath.size(); ++ibrokerPath ) {
        delete brokerPath[ibrokerPath];
    }
}

////////////////////////////////////////////////////////////////////////////////
ConnectionInfo* ConnectionInfo::cloneDataStructure() const {
    std::auto_ptr<ConnectionInfo> connectionInfo( new ConnectionInfo() );

    // Copy the data from the base class or classes
    connectionInfo->copyDataStructure( this );

    return connectionInfo.release();
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const ConnectionInfo* srcPtr = dynamic_cast<const ConnectionInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {

        throw decaf::lang::exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ConnectionInfo::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getConnectionId() != NULL ) {
        this->setConnectionId(
            dynamic_cast<ConnectionId*>(
                srcPtr->getConnectionId()->cloneDataStructure() ) );
    }
    this->setClientId( srcPtr->getClientId() );
    this->setPassword( srcPtr->getPassword() );
    this->setUserName( srcPtr->getUserName() );
    for( size_t ibrokerPath = 0; ibrokerPath < srcPtr->getBrokerPath().size(); ++ibrokerPath ) {
        if( srcPtr->getBrokerPath()[ibrokerPath] != NULL ) {
            this->getBrokerPath().push_back(
                dynamic_cast<BrokerId*>(
                    srcPtr->getBrokerPath()[ibrokerPath]->cloneDataStructure() ) );
        } else {
            this->getBrokerPath().push_back( NULL );
        }
    }
    this->setBrokerMasterConnector( srcPtr->isBrokerMasterConnector() );
    this->setManageable( srcPtr->isManageable() );
    this->setClientMaster( srcPtr->isClientMaster() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ConnectionInfo::getDataStructureType() const {
    return ConnectionInfo::ID_CONNECTIONINFO;
}

////////////////////////////////////////////////////////////////////////////////
std::string ConnectionInfo::toString() const {

    ostringstream stream;

    stream << "Begin Class = ConnectionInfo" << std::endl;
    stream << " Value of ConnectionInfo::ID_CONNECTIONINFO = 3" << std::endl;
    stream << " Value of ConnectionId is Below:" << std::endl;
    if( this->getConnectionId() != NULL ) {
        stream << this->getConnectionId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of ClientId = " << this->getClientId() << std::endl;
    stream << " Value of Password = " << this->getPassword() << std::endl;
    stream << " Value of UserName = " << this->getUserName() << std::endl;
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        stream << " Value of BrokerPath[" << ibrokerPath << "] is Below:" << std::endl;
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            stream << this->getBrokerPath()[ibrokerPath]->toString() << std::endl;
        } else {
            stream << "   Object is NULL" << std::endl;
        }
    }
    stream << " Value of BrokerMasterConnector = " << this->isBrokerMasterConnector() << std::endl;
    stream << " Value of Manageable = " << this->isManageable() << std::endl;
    stream << " Value of ClientMaster = " << this->isClientMaster() << std::endl;
    stream << BaseCommand<transport::Command>::toString();
    stream << "End Class = ConnectionInfo" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ConnectionInfo::equals( const DataStructure* value ) const {
    const ConnectionInfo* valuePtr = dynamic_cast<const ConnectionInfo*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    if( this->getConnectionId() != NULL ) {
        if( !this->getConnectionId()->equals( valuePtr->getConnectionId() ) ) {
            return false;
        }
    } else if( valuePtr->getConnectionId() != NULL ) {
        return false;
    }
    if( this->getClientId() != valuePtr->getClientId() ) {
        return false;
    }
    if( this->getPassword() != valuePtr->getPassword() ) {
        return false;
    }
    if( this->getUserName() != valuePtr->getUserName() ) {
        return false;
    }
    for( size_t ibrokerPath = 0; ibrokerPath < this->getBrokerPath().size(); ++ibrokerPath ) {
        if( this->getBrokerPath()[ibrokerPath] != NULL ) {
            if( !this->getBrokerPath()[ibrokerPath]->equals( valuePtr->getBrokerPath()[ibrokerPath] ) ) {
                return false;
            }
        } else if( valuePtr->getBrokerPath()[ibrokerPath] != NULL ) {
            return false;
        }
    }
    if( this->isBrokerMasterConnector() != valuePtr->isBrokerMasterConnector() ) {
        return false;
    }
    if( this->isManageable() != valuePtr->isManageable() ) {
        return false;
    }
    if( this->isClientMaster() != valuePtr->isClientMaster() ) {
        return false;
    }
    if( !BaseCommand<transport::Command>::equals( value ) ) {
        return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////
const ConnectionId* ConnectionInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
ConnectionId* ConnectionInfo::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setConnectionId(ConnectionId* connectionId ) {
    this->connectionId = connectionId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ConnectionInfo::getClientId() const {
    return clientId;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ConnectionInfo::getClientId() {
    return clientId;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setClientId(const std::string& clientId ) {
    this->clientId = clientId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ConnectionInfo::getPassword() const {
    return password;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ConnectionInfo::getPassword() {
    return password;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setPassword(const std::string& password ) {
    this->password = password;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& ConnectionInfo::getUserName() const {
    return userName;
}

////////////////////////////////////////////////////////////////////////////////
std::string& ConnectionInfo::getUserName() {
    return userName;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setUserName(const std::string& userName ) {
    this->userName = userName;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerId*>& ConnectionInfo::getBrokerPath() const {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerId*>& ConnectionInfo::getBrokerPath() {
    return brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setBrokerPath(const std::vector<BrokerId*>& brokerPath ) {
    this->brokerPath = brokerPath;
}

////////////////////////////////////////////////////////////////////////////////
bool ConnectionInfo::isBrokerMasterConnector() const {
    return brokerMasterConnector;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setBrokerMasterConnector(bool brokerMasterConnector ) {
    this->brokerMasterConnector = brokerMasterConnector;
}

////////////////////////////////////////////////////////////////////////////////
bool ConnectionInfo::isManageable() const {
    return manageable;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setManageable(bool manageable ) {
    this->manageable = manageable;
}

////////////////////////////////////////////////////////////////////////////////
bool ConnectionInfo::isClientMaster() const {
    return clientMaster;
}

////////////////////////////////////////////////////////////////////////////////
void ConnectionInfo::setClientMaster(bool clientMaster ) {
    this->clientMaster = clientMaster;
}
