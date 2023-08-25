/*
 *  Copyright (c) 2023, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * This header file defines the OpenThread core configuration example for an Border Router. This is intended for use
 * in `script/check-size`.
 *
 */

#ifndef OT_CORE_CONFIG_CHECK_SIZE_BR_H_
#define OT_CORE_CONFIG_CHECK_SIZE_BR_H_

#define OPENTHREAD_CONFIG_THREAD_VERSION OT_THREAD_VERSION_1_3

#define OPENTHREAD_CONFIG_ASSERT_ENABLE 1
#define OPENTHREAD_CONFIG_BACKBONE_ROUTER_ENABLE 1
#define OPENTHREAD_CONFIG_BORDER_AGENT_ENABLE 1
#define OPENTHREAD_CONFIG_BORDER_AGENT_ID_ENABLE 1
#define OPENTHREAD_CONFIG_BORDER_ROUTER_ENABLE 1
#define OPENTHREAD_CONFIG_BORDER_ROUTING_DHCP6_PD_ENABLE 1
#define OPENTHREAD_CONFIG_BORDER_ROUTING_ENABLE 1
#define OPENTHREAD_CONFIG_CHANNEL_MANAGER_ENABLE 1
#define OPENTHREAD_CONFIG_CHANNEL_MONITOR_ENABLE 1
#define OPENTHREAD_CONFIG_COAP_API_ENABLE 1
#define OPENTHREAD_CONFIG_COAP_BLOCKWISE_TRANSFER_ENABLE 0
#define OPENTHREAD_CONFIG_COAP_OBSERVE_API_ENABLE 0
#define OPENTHREAD_CONFIG_COAP_SECURE_API_ENABLE 1
#define OPENTHREAD_CONFIG_COMMISSIONER_ENABLE 1
#define OPENTHREAD_CONFIG_DATASET_UPDATER_ENABLE 1
#define OPENTHREAD_CONFIG_DHCP6_CLIENT_ENABLE 1
#define OPENTHREAD_CONFIG_DHCP6_SERVER_ENABLE 1
#define OPENTHREAD_CONFIG_DIAG_ENABLE 1
#define OPENTHREAD_CONFIG_DNSSD_SERVER_ENABLE 1
#define OPENTHREAD_CONFIG_DNS_CLIENT_ENABLE 1
#define OPENTHREAD_CONFIG_DNS_DSO_ENABLE 1
#define OPENTHREAD_CONFIG_DNS_UPSTREAM_QUERY_ENABLE 1
#define OPENTHREAD_CONFIG_DUA_ENABLE 1
#define OPENTHREAD_CONFIG_ECDSA_ENABLE 1
#define OPENTHREAD_CONFIG_HISTORY_TRACKER_ENABLE 1
#define OPENTHREAD_CONFIG_IP6_BR_COUNTERS_ENABLE 1
#define OPENTHREAD_CONFIG_IP6_SLAAC_ENABLE 1
#define OPENTHREAD_CONFIG_JAM_DETECTION_ENABLE 1
#define OPENTHREAD_CONFIG_JOINER_ENABLE 1
#define OPENTHREAD_CONFIG_LINK_RAW_ENABLE 1
#define OPENTHREAD_CONFIG_LOG_LEVEL OT_LOG_LEVEL_INFO
#define OPENTHREAD_CONFIG_LOG_LEVEL_DYNAMIC_ENABLE 1
#define OPENTHREAD_CONFIG_MAC_CSL_RECEIVER_ENABLE 1
#define OPENTHREAD_CONFIG_MAC_FILTER_ENABLE 1
#define OPENTHREAD_CONFIG_MESH_DIAG_ENABLE 1
#define OPENTHREAD_CONFIG_MESSAGE_USE_HEAP_ENABLE 1
#define OPENTHREAD_CONFIG_MLE_LINK_METRICS_INITIATOR_ENABLE 1
#define OPENTHREAD_CONFIG_MLE_LINK_METRICS_SUBJECT_ENABLE 1
#define OPENTHREAD_CONFIG_MLR_ENABLE 1
#define OPENTHREAD_CONFIG_MULTIPLE_INSTANCE_ENABLE 0
#define OPENTHREAD_CONFIG_NAT64_BORDER_ROUTING_ENABLE 1
#define OPENTHREAD_CONFIG_NAT64_TRANSLATOR_ENABLE 1
#define OPENTHREAD_CONFIG_NETDATA_PUBLISHER_ENABLE 1
#define OPENTHREAD_CONFIG_PING_SENDER_ENABLE 1
#define OPENTHREAD_CONFIG_SNTP_CLIENT_ENABLE 1
#define OPENTHREAD_CONFIG_SRP_CLIENT_ENABLE 1
#define OPENTHREAD_CONFIG_SRP_SERVER_ENABLE 1
#define OPENTHREAD_CONFIG_TIME_SYNC_ENABLE 0
#define OPENTHREAD_CONFIG_TMF_ANYCAST_LOCATOR_ENABLE 1
#define OPENTHREAD_CONFIG_TMF_NETDATA_SERVICE_ENABLE 1
#define OPENTHREAD_CONFIG_TMF_NETDIAG_CLIENT_ENABLE 1
#define OPENTHREAD_CONFIG_TX_QUEUE_STATISTICS_ENABLE 1
#define OPENTHREAD_CONFIG_UDP_FORWARD_ENABLE 1
#define OPENTHREAD_CONFIG_UPTIME_ENABLE 1

// Enable mock platform APIs
#define OPENTHREAD_CONFIG_DNS_DSO_MOCK_PLAT_APIS_ENABLE 1
#define OPENTHREAD_CONFIG_BORDER_ROUTING_MOCK_PLAT_APIS_ENABLE 1
#define OPENTHREAD_CONFIG_DNS_UPSTREAM_QUERY_MOCK_PLAT_APIS_ENABLE 1

#endif // OT_CORE_CONFIG_CHECK_SIZE_BR_H_
