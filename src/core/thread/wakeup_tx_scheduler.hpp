/*
 *  Copyright (c) 2024, The OpenThread Authors.
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

#ifndef WAKEUP_TX_SCHEDULER_HPP_
#define WAKEUP_TX_SCHEDULER_HPP_

#include "openthread-core-config.h"

#if OPENTHREAD_CONFIG_MAC_CSL_CENTRAL_ENABLE

#include "common/locator.hpp"
#include "common/non_copyable.hpp"
#include "common/timer.hpp"
#include "mac/mac.hpp"

namespace ot {

/**
 * @addtogroup core-mesh-forwarding
 *
 * @brief
 *   This module includes definitions for CSL wake-up sequence tx scheduling.
 *
 * @{
 */

class Child;

/**
 * This class implements CSL wake-up sequence tx scheduling functionality.
 *
 */
class WakeupTxScheduler : public InstanceLocator, private NonCopyable
{
    friend class Mac::Mac;

public:
    /**
     * This constructor initializes the CSL wake-up tx scheduler object.
     *
     * @param[in]  aInstance   A reference to the OpenThread instance.
     *
     */
    explicit WakeupTxScheduler(Instance &aInstance);

    /**
     * This method initiates the wake-up sequence to the target device.
     *
     * @param[in] aTarget     The extended address of the target device.
     * @param[in] aIntervalUs An interval between consecutive wake-up frames in microseconds.
     * @param[in] aDurationMs Duration of the wake-up sequence in milliseconds.
     *
     * @retval kErrorNone         Successfully started the wake-up sequence.
     * @retval kErrorInvalidState This or another device is currently being woken-up.
     */
    Error WakeUp(const Mac::ExtAddress &aTarget, uint16_t aIntervalUs, uint16_t aDurationMs);

    /**
     * Returns the connection window used by the present device.
     *
     * The connection window is amount of time that this device waits for
     * a link establishment message after sending the last wake-up frame.
     *
     * @retval Connection window in the units of microseconds.
     */
    uint32_t GetConnectionWindowUs() const { return mIntervalUs * kConnectionRetryInterval * kConnectionRetryCount; }

    /**
     * Returns the end of the wake-up sequence time.
     *
     * @retval End of the wake-up sequence time.
     */
    TimeMicro GetTxEndTime() const { return mTxEndTimeUs; }

    /**
     * This method stops the wake-up scheduler.
     *
     */
    void Stop(void);

private:
    using WakeupTimer = TimerMicroIn<Mac::Mac, &Mac::Mac::RequestWakeupFrameTransmission>;

    constexpr static uint8_t kConnectionRetryInterval = OPENTHREAD_CONFIG_MAC_CSL_CENTRAL_CONNECTION_RETRY_INTERVAL;
    constexpr static uint8_t kConnectionRetryCount    = OPENTHREAD_CONFIG_MAC_CSL_CENTRAL_CONNECTION_RETRY_COUNT;

    /*
     * Called by the MAC layer when a wake-up frame is about to be sent.
     */
    Mac::TxFrame *PrepareWakeupFrame(Mac::TxFrames &aTxFrames);

    /*
     * Called by the MAC layer when a wake-up frame transmission is done.
     */
    void ScheduleNext(bool aIsFirstFrame = false);

    Mac::ExtAddress mTarget;               //< Extended address of the target device.
    TimeMicro       mTxTimeUs;             //< Point in time when the next TX occurs.
    TimeMicro       mTxEndTimeUs;          //< Point in time when the wake-up sequence is over.
    const uint16_t  mTxRequestAheadTimeUs; //< How much ahead the TX MAC operation needs to be requested.
    uint16_t        mIntervalUs;           //< Interval between consecutive wake-up frames.
    WakeupTimer     mTimer;
    bool            mSequenceOngoing : 1;  //< Indicates that a wake-up sequence is ongoing.
};

/**
 * @}
 *
 */

} // namespace ot

#endif // OPENTHREAD_CONFIG_MAC_CSL_CENTRAL_ENABLE

#endif // WAKEUP_TX_SCHEDULER_HPP_
