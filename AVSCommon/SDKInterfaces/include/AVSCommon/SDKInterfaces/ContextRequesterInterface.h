/*
 * ContextRequesterInterface.h
 *
 * Copyright 2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *     http://aws.amazon.com/apache2.0/
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef ALEXA_CLIENT_SDK_AVS_COMMON_SDK_INTERFACES_INCLUDE_AVS_COMMON_SDK_INTERFACES_CONTEXT_REQUESTER_INTERFACE_H
#define ALEXA_CLIENT_SDK_AVS_COMMON_SDK_INTERFACES_INCLUDE_AVS_COMMON_SDK_INTERFACES_CONTEXT_REQUESTER_INTERFACE_H

#include<string>

namespace alexaClientSDK {
namespace avsCommon {
namespace sdkInterfaces {

/**
 * This enum expresses the result of a getContext operation.
 */
enum class ContextRequestError {
    /// @c getContext request failed due to a timeout on one or more @c stateProviderInterfaces.
    STATE_PROVIDER_TIMEDOUT,

    /// @c getContext request failed due to an error building the context.
    BUILD_CONTEXT_ERROR
};

/**
 * This specifies the interface to a contextRequester.
 */
class ContextRequesterInterface {
public:
     /**
     * Destructor.
     */
    virtual ~ContextRequesterInterface() = default;

    /**
     * This is called by the ContextManager once the context is ready and available.
     *
     * @note The @c ContextRequester should perform minimum processing and return quickly. Otherwise it will block
     * the processing of updating the of other @c ContextProviders.
     *
     * @param jsonContext Context information.Context provided is of the format {"context"[{...}, {...}]}
     */
    virtual void onContextAvailable(const std::string& jsonContext) = 0;

    /**
     * The contextManager calls this if it is unable to process a @c getContext request successfully.
     *
     * @note The @c ContextRequester should perform minimum processing and return quickly. Otherwise it will block
     * the processing of updating the of other @c ContextProviders.
     *
     * @param error The reason why the getContext request failed.
     */
    virtual void onContextFailure(const ContextRequestError error) = 0;

};

} // namespace sdkInterfaces
} // namespace avsCommon
} // namespace alexaClientSDK

#endif // ALEXA_CLIENT_SDK_AVS_COMMON_SDK_INTERFACES_INCLUDE_AVS_COMMON_SDK_INTERFACES_CONTEXT_REQUESTER_INTERFACE_H