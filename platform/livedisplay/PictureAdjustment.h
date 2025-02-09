/*
 * Copyright (C) 2017-2024 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <vendor/lineage/livedisplay/2.0/IPictureAdjustment.h>

namespace vendor {
namespace lineage {
namespace livedisplay {
namespace V2_0 {
namespace sdm {

using ::android::hardware::Return;
using ::android::hardware::Void;

class PictureAdjustment : public IPictureAdjustment {
public:
  PictureAdjustment(void *libHandle, uint64_t cookie);

  bool isSupported();

  // Methods from ::vendor::lineage::livedisplay::V2_0::IPictureAdjustment
  // follow.
  Return<void> getHueRange(getHueRange_cb _hidl_cb) override;
  Return<void> getSaturationRange(getSaturationRange_cb _hidl_cb) override;
  Return<void> getIntensityRange(getIntensityRange_cb _hidl_cb) override;
  Return<void> getContrastRange(getContrastRange_cb _hidl_cb) override;
  Return<void>
  getSaturationThresholdRange(getSaturationThresholdRange_cb _hidl_cb) override;
  Return<void> getPictureAdjustment(getPictureAdjustment_cb _hidl_cb) override;
  Return<void>
  getDefaultPictureAdjustment(getDefaultPictureAdjustment_cb _hidl_cb) override;
  Return<bool> setPictureAdjustment(
      const ::vendor::lineage::livedisplay::V2_0::HSIC &hsic) override;

private:
  void *mLibHandle;
  uint64_t mCookie;

  int32_t (*disp_api_get_feature_version)(uint64_t, uint32_t, void *,
                                          uint32_t *);
  int32_t (*disp_api_get_global_pa_range)(uint64_t, uint32_t, void *);
  int32_t (*disp_api_get_global_pa_config)(uint64_t, uint32_t, uint32_t *,
                                           void *);
  int32_t (*disp_api_set_global_pa_config)(uint64_t, uint32_t, uint32_t,
                                           void *);
};

} // namespace sdm
} // namespace V2_0
} // namespace livedisplay
} // namespace lineage
} // namespace vendor
