/*
 * Copyright (c) 2014 Amlogic, Inc. All rights reserved.
 *
 * This source code is subject to the terms and conditions defined in the
 * file 'LICENSE' which is part of this source code package.
 *
 * Description: header file
 */

#ifndef _TV_UTILS_H_
#define _TV_UTILS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utils/Mutex.h>
#include <string>
#include <map>

#include "PQType.h"

#define SYS_STR_LEN                         1024
#define AUDIO_OUTMODE_PATH "/sys/module/atvdemod_fe/parameters/aud_mode"
#define ATVDEMODE_DEBUG_PATH "/sys/class/amlatvdemod/atvdemod_debug"


int tvReadSysfs(const char *path, char *value);
int tvWriteSysfs(const char *path, const char *value);
int tvWriteSysfs(const char *path, int value, int base=10);
int tvWriteDisplayMode(const char *mode);
//add for PQ
int tvResetLastVppSettingsSourceType(void);
int tvLoadPQSettings(source_input_param_t source_input_param);
int tvLoadCpqLdimRegs(void);
int tvSSMReadNTypes(int id, int data_len,  int *data_buf, int offset);
int tvSSMWriteNTypes(int id, int data_len, int data_buf, int offset);
int tvGetActualAddr(int id);
int tvGetActualSize(int id);

int tvSetPQMode ( vpp_picture_mode_t mode, source_input_param_t source_input_param, int is_save );
vpp_picture_mode_t tvGetPQMode ( source_input_param_t source_input_param );
int tvSavePQMode ( vpp_picture_mode_t mode, source_input_param_t source_input_param );
int tvGetPQParams(source_input_param_t source_input_param, vpp_picture_mode_t pq_mode, vpp_pq_para_t *pq_para);

int tvSetBrightness ( int brightness, source_input_param_t source_input_param, int is_save );
int tvGetBrightness ( source_input_param_t source_input_param );
int tvSaveBrightness ( int brightness, source_input_param_t source_input_param );
int tvSetContrast ( int contrast, source_input_param_t source_input_param,  int is_save );
int tvGetContrast ( source_input_param_t source_input_param );
int tvSaveContrast ( int contrast, source_input_param_t source_input_param );
int tvSetSaturation ( int satuation, source_input_param_t source_input_param, int is_save );
int tvGetSaturation ( source_input_param_t source_input_param );
int tvSaveSaturation ( int satuation, source_input_param_t source_input_param );
int tvSetHue ( int hue, source_input_param_t source_input_param, int is_save );
int tvGetHue ( source_input_param_t source_input_param );
int tvSaveHue ( int hue, source_input_param_t source_input_param );
int tvSetSharpness ( int value, source_input_param_t source_input_param, int en, int is_save );
int tvGetSharpness ( source_input_param_t source_input_param );
int tvSaveSharpness ( int value, source_input_param_t source_input_param );
int tvSetColorTemperature ( vpp_color_temperature_mode_t mode, source_input_param_t source_input_param, int is_save );
int tvGetColorTemperature ( source_input_param_t source_input_param );
int tvSaveColorTemperature ( vpp_color_temperature_mode_t mode, source_input_param_t source_input_param );
int tvSetColorTemperatureParams(vpp_color_temperature_mode_t Tempmode, tcon_rgb_ogo_t params);
int tvGetColorTemperatureParams(vpp_color_temperature_mode_t Tempmode, pq_color_param_t id);
int tvSaveColorTemperatureParams(vpp_color_temperature_mode_t Tempmode, tcon_rgb_ogo_t params);
int tvSetNoiseReductionMode ( vpp_noise_reduction_mode_t mode, source_input_param_t source_input_param, int is_save );
int tvGetNoiseReductionMode ( source_input_param_t source_input_param );
int tvSaveNoiseReductionMode ( vpp_noise_reduction_mode_t mode, source_input_param_t source_input_param );
int tvSetGamma(int gamma_curve, int is_save);
int tvGetGamma();
int tvSetBaseColorMode(int basemode, source_input_param_t source_input_param);
int tvGetBaseColorMode(void);
int tvSaveBaseColorMode(int basemode);
int tvSetEyeProtectionMode(source_input_param_t source_input_param, int enable);
int tvGetEyeProtectionMode(void);
int tvGetDisplayMode(source_input_param_t source_input_param);
int tvFactoryResetNonlinear(void);
int tvGetOverscanParam(source_input_param_t source_input_param, tvin_cutwin_param_t id);


int tvFactoryResetPQMode(void);
int tvFactoryResetColorTemp(void);
int tvFactorySetPQParam(source_input_param_t source_input_param, int pq_mode, vpp_pq_param_t id, int value);
int tvFactoryGetPQParam(source_input_param_t source_input_param, int pq_mode, vpp_pq_param_t id);
int tvFactorySetColorTemperatureParam(int colortemperature_mode, pq_color_param_t id, int value);
int tvFactoryGetColorTemperatureParam(int colortemperature_mode, pq_color_param_t id);
int tvFactorySaveColorTemperatureParam(int colortemperature_mode, pq_color_param_t id, int value);
int tvFactorySetOverscanParam(source_input_param_t source_input_param, int value, int id);
int tvFactoryGetOverscanParam(source_input_param_t source_input_param, int id);
int tvFactorySetNolineParams(source_input_param_t source_input_param, int type, int value, int id);
int tvFactoryGetNolineParams(source_input_param_t source_input_param, int type, int id);
int tvFactorySetParamsDefault(void);
int tvFactorySSMRestore(void);
int tvSSMRecovery(void);
int tvGetSSMStatus(void);
int tvSetPLLValues(source_input_param_t source_input_param);
int tvSetCVD2Values(source_input_param_t source_input_param);
int tvSetDNLP(source_input_param_t source_input_param);
int tvSetPQConfig(Set_Flag_Cmd_t id, int value);
//PQ end

extern int Tv_MiscRegs(const char *cmd);

extern int TvMisc_SetLVDSSSC(int val);
extern int TvMisc_SetUserCounterTimeOut(int timeout);
extern int TvMisc_SetUserCounter(int count);
extern int TvMisc_SetUserPetResetEnable(int enable);
extern int TvMisc_SetSystemPetResetEnable(int enable);
extern int TvMisc_SetSystemPetEnable(int enable);
extern int TvMisc_SetSystemPetCounter(int count);
extern int SetAudioOutmode(int mode);
extern int GetAudioOutmode();

extern void TvMisc_EnableWDT(bool kernelpet_disable, unsigned int userpet_enable, unsigned int kernelpet_timeout, unsigned int userpet_timeout, unsigned int userpet_reset);
extern void TvMisc_DisableWDT(unsigned int userpet_enable);
extern int GetTvDBDefineSize();

extern int Set_Fixed_NonStandard(int value);


extern int TvMisc_DeleteDirFiles(const char *strPath, int flag);

extern bool isFileExist(const char *file_name);
extern int GetPlatformHaveDDFlag();
extern int getBootEnv(const char *key, char *value, const char *def_val);
extern void setBootEnv(const char *key, const char *value);
extern int readSysfs(const char *path, char *value);
extern void writeSysfs(const char *path, const char *value);
extern int GetFileAttrIntValue(const char *fp, int flag = O_RDWR);

template<typename T1, typename T2>
int ArrayCopy(T1 dst_buf[], T2 src_buf[], int copy_size)
{
    int i = 0;

    for (i = 0; i < copy_size; i++) {
        dst_buf[i] = src_buf[i];
    }

    return 0;
};


typedef std::map<std::string, std::string> STR_MAP;

extern void jsonToMap(STR_MAP &m, const std::string &j);
extern void mapToJson(std::string &j, const STR_MAP &m);
extern void mapToJson(std::string &j, const STR_MAP &m, const std::string &k);
extern void mapToJsonAppend(std::string &j, const STR_MAP &m, const std::string &k);

class Paras {
protected:
    STR_MAP mparas;

public:
    Paras() {}
    Paras(const Paras &paras):mparas(paras.mparas) {}
    Paras(const char *paras) { jsonToMap(mparas, std::string(paras)); }
    Paras(const STR_MAP &paras):mparas(paras) {}

    void clear() { mparas.clear(); }

    int getInt (const char *key, int def) const;
    void setInt(const char *key, int v);

    const std::string toString() { std::string s; mapToJson(s, mparas); return s; }

    Paras operator + (const Paras &p);
    Paras& operator = (const Paras &p) { mparas = p.mparas; return *this; };
};

float getUptimeSeconds();

#endif  //__TV_MISC_H__
