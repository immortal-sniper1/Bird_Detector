// SPDX-License-Identifier: (GPL-2.0 OR BSD-3-Clause)
/*
 * ALSA SoC TLV320ADC310X codec driver
 *
 * Author:      Dan Murphy <dmurphy@ti.com>
 * Copyright (C) 2017-2018 Texas Instruments, Inc.
 *
 *
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/pm.h>
#include <linux/i2c.h>
#include <linux/gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/slab.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

#include "tlv320adc310x.h"

static const char *adc310x_supply_names[ADC310X_NUM_SUPPLIES] = {
	"IOVDD",		/* I/O Voltage */
	"DVDD",			/* Digital Core Voltage */
	"AVDD",			/* Analog DAC Voltage */
	"DRVDD",		/* ADC Analog and Output Driver Voltage */
};

#define ADC310X_MODEL_310X 0
#define ADC310X_MODEL_3101 1
#define ADC310X_MODEL_3104 2

static LIST_HEAD(reset_list);

static int adc310x_init(struct snd_soc_codec *codec);

static const struct reg_default adc310x_reg[] = {
	{ADC310X_PAGE_SELECT, 0x00},
	{ADC310X_RESET, 0x00},
	{ADC310X_CLK_GEN_MUX, 0x04},
	{ADC310X_PLL_PR_VAL, 0x11},
	{ADC310X_PLL_J_VAL, 0x04},
	{ADC310X_PLL_D_VAL_MSB, 0x00},
	{ADC310X_PLL_D_VAL_LSB, 0x00},
	{ADC310X_NADC_CLK, 0x01},
	{ADC310X_MADC_CLK, 0x01},
	{ADC310X_AOSR, 0x80},
	{ADC310X_ADC_IADC, 0x80},
	{ADC310X_DSP_DECI, 0x04},
	{ADC310X_CLK_OUT_MUX, 0x00},
	{ADC310X_CLK_OUT_MDIV, 0x01},
	{ADC310X_ADC_INTF_CTRL_1, 0x00},
	{ADC310X_DATA_SLOT_OFF_CH_1, 0x00},
	{ADC310X_ADC_INTF_CTRL_2, 0x02},
	{ADC310X_BLCK_N_DIV, 0x01},
	{ADC310X_SEC_INTF_CTRL_1, 0x00},
	{ADC310X_SEC_INTF_CTRL_2, 0x00},
	{ADC310X_SEC_INTF_CTRL_3, 0x10},
	{ADC310X_I2S_SYNC, 0x00},
	{ADC310X_ADC_FLAG, 0x00},
	{ADC310X_DATA_SLOT_OFF_CH_2, 0x00},
	{ADC310X_I2S_TDM_CTRL, 0x02},
	{ADC310X_INT_FLAG_1, 0x00},
	{ADC310X_INT_FLAG_2, 0x00},
	{ADC310X_ADC_INT_FLAG_2, 0x00},
	{ADC310X_ADC_INT_2_CTRL, 0x00},
	{ADC310X_INT_1_CTRL, 0x00},
	{ADC310X_INT_2_CTRL, 0x00},
	{ADC310X_DMCLK_GPIO2, 0x00},
	{ADC310X_DMDIN_GPIO1, 0x00},
	{ADC310X_DOUT_CTRL, 0x12},
	{ADC310X_ADC_SYNC_CTRL_1, 0x00},
	{ADC310X_ADC_SYNC_CTRL_2, 0x00},
	{ADC310X_ADC_CIC_FILT_GN, 0x44},
	{ADC310X_ADC_PROC_BLK, 0x01},
	{ADC310X_INST_MD_CTRL, 0x00},
	{ADC310X_DMIC_POL, 0x00},
	{ADC310X_ADC_DIGITAL, 0x00},
	{ADC310X_ADC_VOL_CTRL, 0x88},
	{ADC310X_ADC_VOL_L, 0x00},
	{ADC310X_ADC_VOL_R, 0x00},
	{ADC310X_ADC_PHASE_COMP_L, 0x00},
	{ADC310X_AGC_GAIN_CTRL_L_1, 0x00},
	{ADC310X_AGC_GAIN_CTRL_L_2, 0x00},
	{ADC310X_AGC_MAX_GAIN_L, 0x7f},
	{ADC310X_AGC_ATTACK_TIME_L, 0x00},
	{ADC310X_AGC_DECAY_TIME_L, 0x00},
	{ADC310X_AGC_NOISE_DEBNCE_L, 0x00},
	{ADC310X_AGC_SIGNAL_DEBNCE_L, 0x00},
	{ADC310X_AGC_GAIN_APPLIED_L, 0x00},
	{ADC310X_AGC_GAIN_CTRL_R_1, 0x00},
	{ADC310X_AGC_GAIN_CTRL_R_2, 0x00},
	{ADC310X_AGC_MAX_GAIN_R, 0x7f},
	{ADC310X_AGC_ATTACK_TIME_R, 0x00},
	{ADC310X_AGC_DECAY_TIME_R, 0x00},
	{ADC310X_AGC_NOISE_DEBNCE_R, 0x00},
	{ADC310X_AGC_SIGNAL_DEBNCE_R, 0x00},
	{ADC310X_AGC_GAIN_APPLIED_R, 0x00},

	{ADC310X_ADC_FOIIR_N0_L1, 0x00},
	{ADC310X_ADC_FOIIR_N0_L2, 0x00},
	{ADC310X_ADC_FOIIR_N1_L1, 0x00},
	{ADC310X_ADC_FOIIR_N1_L2, 0x00},
	{ADC310X_ADC_FOIIR_D1_L1, 0x00},
	{ADC310X_ADC_FOIIR_D1_L2, 0x00},

	{ADC310X_ADC_BQA_N0_L1, 0x00},
	{ADC310X_ADC_BQA_N0_L2, 0x00},
	{ADC310X_ADC_BQA_N1_L1, 0x00},
	{ADC310X_ADC_BQA_N1_L2, 0x00},
	{ADC310X_ADC_BQA_N2_L1, 0x00},
	{ADC310X_ADC_BQA_N2_L2, 0x00},
	{ADC310X_ADC_BQA_D1_L1, 0x00},
	{ADC310X_ADC_BQA_D1_L2, 0x00},
	{ADC310X_ADC_BQA_D2_L1, 0x00},
	{ADC310X_ADC_BQA_D2_L2, 0x00},

	{ADC310X_ADC_BQB_N0_L1, 0x00},
	{ADC310X_ADC_BQB_N0_L2, 0x00},
	{ADC310X_ADC_BQB_N1_L1, 0x00},
	{ADC310X_ADC_BQB_N1_L2, 0x00},
	{ADC310X_ADC_BQB_N2_L1, 0x00},
	{ADC310X_ADC_BQB_N2_L2, 0x00},
	{ADC310X_ADC_BQB_D1_L1, 0x00},
	{ADC310X_ADC_BQB_D1_L2, 0x00},
	{ADC310X_ADC_BQB_D2_L1, 0x00},
	{ADC310X_ADC_BQB_D2_L2, 0x00},

	{ADC310X_ADC_BQC_N0_L1, 0x00},
	{ADC310X_ADC_BQC_N0_L2, 0x00},
	{ADC310X_ADC_BQC_N1_L1, 0x00},
	{ADC310X_ADC_BQC_N1_L2, 0x00},
	{ADC310X_ADC_BQC_N2_L1, 0x00},
	{ADC310X_ADC_BQC_N2_L2, 0x00},
	{ADC310X_ADC_BQC_D1_L1, 0x00},
	{ADC310X_ADC_BQC_D1_L2, 0x00},
	{ADC310X_ADC_BQC_D2_L1, 0x00},
	{ADC310X_ADC_BQC_D2_L2, 0x00},

	{ADC310X_ADC_BQD_N0_L1, 0x00},
	{ADC310X_ADC_BQD_N0_L2, 0x00},
	{ADC310X_ADC_BQD_N1_L1, 0x00},
	{ADC310X_ADC_BQD_N1_L2, 0x00},
	{ADC310X_ADC_BQD_N2_L1, 0x00},
	{ADC310X_ADC_BQD_N2_L2, 0x00},
	{ADC310X_ADC_BQD_D1_L1, 0x00},
	{ADC310X_ADC_BQD_D1_L2, 0x00},
	{ADC310X_ADC_BQD_D2_L1, 0x00},
	{ADC310X_ADC_BQD_D2_L2, 0x00},

	{ADC310X_ADC_BQE_N0_L1, 0x00},
	{ADC310X_ADC_BQE_N0_L2, 0x00},
	{ADC310X_ADC_BQE_N1_L1, 0x00},
	{ADC310X_ADC_BQE_N1_L2, 0x00},
	{ADC310X_ADC_BQE_N2_L1, 0x00},
	{ADC310X_ADC_BQE_N2_L2, 0x00},
	{ADC310X_ADC_BQE_D1_L1, 0x00},
	{ADC310X_ADC_BQE_D1_L2, 0x00},
	{ADC310X_ADC_BQE_D2_L1, 0x00},
	{ADC310X_ADC_BQE_D2_L2, 0x00},

	{ADC310X_ADC_FOIIR_N0_R1, 0x00},
	{ADC310X_ADC_FOIIR_N0_R2, 0x00},
	{ADC310X_ADC_FOIIR_N1_R1, 0x00},
	{ADC310X_ADC_FOIIR_N1_R2, 0x00},
	{ADC310X_ADC_FOIIR_D1_R1, 0x00},
	{ADC310X_ADC_FOIIR_D1_R2, 0x00},

	{ADC310X_ADC_BQA_N0_R1, 0x00},
	{ADC310X_ADC_BQA_N0_R2, 0x00},
	{ADC310X_ADC_BQA_N1_R1, 0x00},
	{ADC310X_ADC_BQA_N1_R2, 0x00},
	{ADC310X_ADC_BQA_N2_R1, 0x00},
	{ADC310X_ADC_BQA_N2_R2, 0x00},
	{ADC310X_ADC_BQA_D1_R1, 0x00},
	{ADC310X_ADC_BQA_D1_R2, 0x00},
	{ADC310X_ADC_BQA_D2_R1, 0x00},
	{ADC310X_ADC_BQA_D2_R2, 0x00},

	{ADC310X_ADC_BQB_N0_R1, 0x00},
	{ADC310X_ADC_BQB_N0_R2, 0x00},
	{ADC310X_ADC_BQB_N1_R1, 0x00},
	{ADC310X_ADC_BQB_N1_R2, 0x00},
	{ADC310X_ADC_BQB_N2_R1, 0x00},
	{ADC310X_ADC_BQB_N2_R2, 0x00},
	{ADC310X_ADC_BQB_D1_R1, 0x00},
	{ADC310X_ADC_BQB_D1_R2, 0x00},
	{ADC310X_ADC_BQB_D2_R1, 0x00},
	{ADC310X_ADC_BQB_D2_R2, 0x00},

	{ADC310X_ADC_BQC_N0_R1, 0x00},
	{ADC310X_ADC_BQC_N0_R2, 0x00},
	{ADC310X_ADC_BQC_N1_R1, 0x00},
	{ADC310X_ADC_BQC_N1_R2, 0x00},
	{ADC310X_ADC_BQC_N2_R1, 0x00},
	{ADC310X_ADC_BQC_N2_R2, 0x00},
	{ADC310X_ADC_BQC_D1_R1, 0x00},
	{ADC310X_ADC_BQC_D1_R2, 0x00},
	{ADC310X_ADC_BQC_D2_R1, 0x00},
	{ADC310X_ADC_BQC_D2_R2, 0x00},

	{ADC310X_ADC_BQD_N0_R1, 0x00},
	{ADC310X_ADC_BQD_N0_R2, 0x00},
	{ADC310X_ADC_BQD_N1_R1, 0x00},
	{ADC310X_ADC_BQD_N1_R2, 0x00},
	{ADC310X_ADC_BQD_N2_R1, 0x00},
	{ADC310X_ADC_BQD_N2_R2, 0x00},
	{ADC310X_ADC_BQD_D1_R1, 0x00},
	{ADC310X_ADC_BQD_D1_R2, 0x00},
	{ADC310X_ADC_BQD_D2_R1, 0x00},
	{ADC310X_ADC_BQD_D2_R2, 0x00},

	{ADC310X_ADC_BQE_N0_R1, 0x00},
	{ADC310X_ADC_BQE_N0_R2, 0x00},
	{ADC310X_ADC_BQE_N1_R1, 0x00},
	{ADC310X_ADC_BQE_N1_R2, 0x00},
	{ADC310X_ADC_BQE_N2_R1, 0x00},
	{ADC310X_ADC_BQE_N2_R2, 0x00},
	{ADC310X_ADC_BQE_D1_R1, 0x00},
	{ADC310X_ADC_BQE_D1_R2, 0x00},
	{ADC310X_ADC_BQE_D2_R1, 0x00},
	{ADC310X_ADC_BQE_D2_R2, 0x00},

};

static bool adc310x_volatile(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ADC310X_PAGE_SELECT:	/* regmap implementation requires this */
	case ADC310X_RESET:
		return true;
	}
	return false;
};

static bool adc310x_writeable(struct device *dev, unsigned int reg)
{
	switch (reg) {
	case ADC310X_INT_FLAG_1:
	case ADC310X_INT_FLAG_2:
	case ADC310X_ADC_INT_FLAG_1:
	case ADC310X_ADC_INT_FLAG_2:
	case ADC310X_AGC_GAIN_APPLIED_L:
	case ADC310X_AGC_GAIN_APPLIED_R:
	case ADC310X_PGA_ANALOG_FLAGS:
		return false;
	}
	return true;
}

static const struct regmap_range_cfg adc310x_ranges[] = {
	{
	 .range_min = 0,
	 .range_max = 5 * ADC310X_REGS_IN_PAGE,
	 .selector_reg = ADC310X_PAGE_SELECT,
	 .selector_mask = 0xff,
	 .selector_shift = 0,
	 .window_start = 0,
	 .window_len = ADC310X_REGS_IN_PAGE,
	 },
};

static const struct regmap_config adc310x_regmap = {
	.reg_bits = 8,
	.val_bits = 8,

	.max_register = 5 * 128,	/* 2 pages 128 registers per page */
	.reg_defaults = adc310x_reg,
	.num_reg_defaults = ARRAY_SIZE(adc310x_reg),
	.volatile_reg = adc310x_volatile,
	.writeable_reg = adc310x_writeable,
	.ranges = adc310x_ranges,
	.num_ranges = ARRAY_SIZE(adc310x_ranges),
	.cache_type = REGCACHE_RBTREE,
};

#define ADC310X_RATES	SNDRV_PCM_RATE_8000_96000
#define ADC310X_FORMATS	(SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S20_3LE | \
			 SNDRV_PCM_FMTBIT_S24_3LE | SNDRV_PCM_FMTBIT_S24_LE | \
			 SNDRV_PCM_FMTBIT_S32_LE)

static const DECLARE_TLV_DB_SCALE(adc_fgain_tlv, -12, 50, 0);

static const struct snd_kcontrol_new adc310x_snd_controls[] = {
	SOC_SINGLE_TLV("DMIC Capture Volume Left", ADC310X_ADC_VOL_L, 0,
		       0x28, 0, adc_fgain_tlv),
	SOC_SINGLE_TLV("DMIC Capture Volume Right", ADC310X_ADC_VOL_R, 0,
		       0x28, 0, adc_fgain_tlv),
};

#if 0
/*
 * mic bias power on/off share the same register bits with
 * output voltage of mic bias. when power on mic bias, we
 * need reclaim it to voltage value.
 * 0x0 = Powered off
 * 0x1 = MICBIAS output is powered to 2.0V,
 * 0x2 = MICBIAS output is powered to 2.5V
 * 0x3 = MICBIAS output is connected to AVDD
 */
static int mic_bias_event(struct snd_soc_dapm_widget *w,
			  struct snd_kcontrol *kcontrol, int event)
{
	struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);

	switch (event) {
	case SND_SOC_DAPM_POST_PMU:
		/* change mic bias voltage to user defined */
		snd_soc_update_bits(codec, ADC310X_MIC_BIAS_CTRL,
				    MICBIAS_LEVEL_MASK,
				    adc310x->micbias_vg << MICBIAS_LEVEL_SHIFT);
		break;

	case SND_SOC_DAPM_PRE_PMD:
		snd_soc_update_bits(codec, MICBIAS_CTRL, MICBIAS_LEVEL_MASK, 0);
		break;
	}
	return 0;
}
#endif

static const struct snd_kcontrol_new dmicl_enable_control =
SOC_DAPM_SINGLE("Switch", ADC310X_ADC_DIGITAL, 3, 1, 0);
static const struct snd_kcontrol_new dmicr_enable_control =
SOC_DAPM_SINGLE("Switch", ADC310X_ADC_DIGITAL, 2, 1, 0);

static const struct snd_soc_dapm_widget adc310x_dapm_widgets[] = {
/* Fix these widgets
	SND_SOC_DAPM_SUPPLY("MICB1 Audio", ADC310X_MIC_BIAS_CTRL, 4, 1, NULL, 0),
	SND_SOC_DAPM_SUPPLY("MICB2 Audio", ADC310X_MIC_BIAS_CTRL, 4, 1, NULL, 0),
	SND_SOC_DAPM_SUPPLY("Mic Bias", ADC310X_MIC_BIAS_CTRL, 6, 0,
			 mic_bias_event,
			 SND_SOC_DAPM_POST_PMU | SND_SOC_DAPM_PRE_PMD),

	SND_SOC_DAPM_MICBIAS("MICB2", ADC310X_MIC_BIAS_CTRL, 9, 0),
	SND_SOC_DAPM_MICBIAS("MICB1", ADC310X_MIC_BIAS_CTRL, 8, 0),
	SND_SOC_DAPM_SUPPLY("DMIC", ADC310X_ADC_DIGITAL, 3, 0, NULL, 0),
*/
#if 0
	/* Analog Mic In */
	SND_SOC_DAPM_INPUT("IN1LP"),
	SND_SOC_DAPM_INPUT("IN2LP"),
	SND_SOC_DAPM_INPUT("IN3LM"),

	SND_SOC_DAPM_INPUT("IN1RM"),
	SND_SOC_DAPM_INPUT("IN2RP"),
	SND_SOC_DAPM_INPUT("IN3RM"),

	/* ADC */
	SND_SOC_DAPM_ADC_E("ADC", "Capture", AIC31XX_ADCSETUP, 7, 0,
			   aic31xx_dapm_power_event, SND_SOC_DAPM_POST_PMU |
			   SND_SOC_DAPM_POST_PMD),

	/* Input Selection to MIC_PGA */
	SND_SOC_DAPM_MUX("IN1LP P-Terminal", SND_SOC_NOPM, 0, 0,
			 &p_term_mic1lp),
	SND_SOC_DAPM_MUX("MIC1RP P-Terminal", SND_SOC_NOPM, 0, 0,
			 &p_term_mic1rp),
	SND_SOC_DAPM_MUX("MIC1LM P-Terminal", SND_SOC_NOPM, 0, 0,
			 &p_term_mic1lm),

	SND_SOC_DAPM_MUX("IN1RM M-Terminal", SND_SOC_NOPM, 0, 0,
			 &m_term_mic1lm),

	/* Enabling & Disabling MIC Gain Ctl */
	SND_SOC_DAPM_PGA("MIC_GAIN_CTL_L", AIC31XX_MICPGA,
			 7, 1, NULL, 0),

	SND_SOC_DAPM_PGA("MIC_GAIN_CTL_R", AIC31XX_MICPGA,
			 7, 1, NULL, 0),
#endif
	SND_SOC_DAPM_SWITCH("DMIC left Capture", SND_SOC_NOPM, 0, 0,
			    &dmicl_enable_control),
	SND_SOC_DAPM_SWITCH("DMIC right Capture", SND_SOC_NOPM, 0, 0,
			    &dmicr_enable_control),

	SND_SOC_DAPM_AIF_OUT("DAIOUT", "Capture", 0, SND_SOC_NOPM, 0, 0),

	SND_SOC_DAPM_INPUT("DMDIN"),
#if 1
	SND_SOC_DAPM_SUPPLY("DAI", SND_SOC_NOPM, 0,
			    0, NULL,
			    SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD),
#else
	SND_SOC_DAPM_SUPPLY("DAI", ADC310X_DOUT_CTRL, 1,
			    0, NULL,
			    SND_SOC_DAPM_PRE_PMU | SND_SOC_DAPM_POST_PMD),
#endif
};

static const struct snd_soc_dapm_route routes[] = {
#if 1
	/* Connect Digital Mic directly to the DAI output */
	{"DAIOUT", NULL, "DMDIN"},
#else
	{"DMIC left Capture", "Switch", "DMDIN"},
	{"DMIC right Capture", "Switch", "DMDIN"},

	{"DAIOUT", NULL, "DMIC left Capture"},
	{"DAIOUT", NULL, "DMIC right Capture"},
#endif
};

static int adc310x_hw_params(struct snd_pcm_substream *substream,
			     struct snd_pcm_hw_params *params,
			     struct snd_soc_dai *dai)
{
	struct snd_soc_codec *codec = dai->codec;
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	int fsref;
	u8 data;
	int width = adc310x->slot_width;

	/* Re-initialise the codec, handles ESD failures etc/ */
	adc310x_init(codec);

	/* select data word length */
	data = snd_soc_read(codec, ADC310X_ADC_INTF_CTRL_1) & (~(0x3 << 4));
	switch (width) {
	case 16:
		break;
	case 20:
		data |= (0x01 << 4);
		break;
	case 24:
		data |= (0x02 << 4);
		break;
	case 32:
		data |= (0x03 << 4);
		break;
	}
	snd_soc_write(codec, ADC310X_ADC_INTF_CTRL_1, data);

	/* Fsref can be 44100 or 48000 */
	fsref = (params_rate(params) % 11025 == 0) ? 44100 : 48000;

	snd_soc_update_bits(codec, ADC310X_PLL_PR_VAL, PLL_ENABLE, PLL_ENABLE);

	return 0;
}

static int adc310x_prepare(struct snd_pcm_substream *substream,
			   struct snd_soc_dai *dai)
{
	struct snd_soc_codec *codec = dai->codec;
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	int width = adc310x->slot_width;
	int delay = 0;

	if (!width)
		width = substream->runtime->sample_bits;

	/* TDM slot selection only valid in DSP_A/_B mode */
	if (adc310x->dai_fmt == SND_SOC_DAIFMT_DSP_A)
		delay += (adc310x->tdm_delay * width + 1);
	else if (adc310x->dai_fmt == SND_SOC_DAIFMT_DSP_B)
		delay += adc310x->tdm_delay * width;

	/* Configure data delay */
	snd_soc_write(codec, ADC310X_DATA_SLOT_OFF_CH_1, delay);

	return 0;
}

static int adc310x_mute(struct snd_soc_dai *dai, int mute, int stream)
{
	struct snd_soc_codec *codec = dai->codec;
	u8 mute_reg = snd_soc_read(codec, ADC310X_ADC_VOL_CTRL) &
	    ~(ADC310X_LEFT_MUTE | ADC310X_RIGHT_MUTE);

	if (mute) {
		snd_soc_write(codec, ADC310X_ADC_VOL_CTRL,
			      mute_reg | ADC310X_RIGHT_MUTE |
			      ADC310X_LEFT_MUTE);
	} else {
		snd_soc_write(codec, ADC310X_ADC_VOL_CTRL, mute_reg);
	}

	return 0;
}

static int adc310x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
				  int clk_id, unsigned int freq, int dir)
{
	struct snd_soc_codec *codec = codec_dai->codec;
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);

	/* set clock on MCLK or BCLK */
	snd_soc_update_bits(codec, ADC310X_CLK_OUT_MUX, PLLCLK_IN_MASK, clk_id);
	snd_soc_update_bits(codec, ADC310X_CLK_OUT_MUX, CLKDIV_IN_MASK, clk_id);

	adc310x->sysclk = freq;
	return 0;
}

static int adc310x_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
	struct snd_soc_codec *codec = codec_dai->codec;
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	u8 iface_ctrla, iface_ctrlb;

	iface_ctrla = snd_soc_read(codec, ADC310X_ADC_INTF_CTRL_1) & 0x33;

	/* set master/slave audio interface */
	switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
	case SND_SOC_DAIFMT_CBM_CFM:
		adc310x->master = 1;
		iface_ctrla |= BIT_CLK_MASTER | WORD_CLK_MASTER;
		break;
	case SND_SOC_DAIFMT_CBS_CFS:
		adc310x->master = 0;
		iface_ctrla &= ~(BIT_CLK_MASTER | WORD_CLK_MASTER);
		break;
	default:
		return -EINVAL;
	}

	switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
	case SND_SOC_DAIFMT_I2S:
		break;
	case SND_SOC_DAIFMT_DSP_A:
	case SND_SOC_DAIFMT_DSP_B:
		iface_ctrla |= (0x01 << 6);
		break;
	case SND_SOC_DAIFMT_RIGHT_J:
		iface_ctrla |= (0x02 << 6);
		break;
	case SND_SOC_DAIFMT_LEFT_J:
		iface_ctrla |= (0x03 << 6);
		break;
	default:
		return -EINVAL;
	}

	iface_ctrlb = snd_soc_read(codec, ADC310X_ADC_INTF_CTRL_2) & 0xf7;
	switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
	case SND_SOC_DAIFMT_NB_NF:
	case SND_SOC_DAIFMT_NB_IF:
		break;
	case SND_SOC_DAIFMT_IB_NF:
	case SND_SOC_DAIFMT_IB_IF:
		iface_ctrlb |= (0x01 << 3);
		break;
	default:
		return -EINVAL;
	}

	adc310x->dai_fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;

	snd_soc_write(codec, ADC310X_ADC_INTF_CTRL_1, iface_ctrla);
	snd_soc_write(codec, ADC310X_ADC_INTF_CTRL_2, iface_ctrlb);

	return 0;
}

static int adc310x_set_dai_tdm_slot(struct snd_soc_dai *codec_dai,
				    unsigned int tx_mask, unsigned int rx_mask,
				    int slots, int slot_width)
{
	struct snd_soc_codec *codec = codec_dai->codec;
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	unsigned int lsb;

	if (tx_mask != rx_mask) {
		dev_err(codec->dev, "tx and rx masks must be symmetric\n");
		return -EINVAL;
	}

	if (unlikely(!tx_mask)) {
		dev_err(codec->dev, "tx and rx masks need to be non 0\n");
		return -EINVAL;
	}

	/* TDM based on DSP mode requires slots to be adjacent */
	lsb = __ffs(tx_mask);
	if ((lsb + 1) != __fls(tx_mask)) {
		dev_err(codec->dev, "Invalid mask, slots must be adjacent\n");
		return -EINVAL;
	}

	switch (slot_width) {
	case 16:
	case 20:
	case 24:
	case 32:
		break;
	default:
		dev_err(codec->dev, "Unsupported slot width %d\n", slot_width);
		return -EINVAL;
	}

	adc310x->tdm_delay = lsb;
	adc310x->slot_width = slot_width;

	/* DOUT in high-impedance on inactive bit clocks */
	snd_soc_update_bits(codec, ADC310X_ADC_INTF_CTRL_1,
			    DOUT_TRISTATE, DOUT_TRISTATE);
	return 0;
}

static const struct snd_soc_dai_ops adc310x_dai_ops = {
	.hw_params = adc310x_hw_params,
	.prepare = adc310x_prepare,
	.mute_stream = adc310x_mute,
	.set_sysclk = adc310x_set_dai_sysclk,
	.set_fmt = adc310x_set_dai_fmt,
	.set_tdm_slot = adc310x_set_dai_tdm_slot,
};

static struct snd_soc_dai_driver adc310x_dai = {
	.name = "tlv320adc310x",
	.capture = {
		    .stream_name = "Capture",
		    .channels_min = 1,
		    .channels_max = 2,
		    .rates = ADC310X_RATES,
		    .formats = ADC310X_FORMATS,},
	.ops = &adc310x_dai_ops,
	.symmetric_rates = 1,
};

static int adc310x_init(struct snd_soc_codec *codec)
{
	snd_soc_write(codec, ADC310X_RESET, SOFT_RESET);
	snd_soc_write(codec, ADC310X_PLL_PR_VAL, 0x11);
	snd_soc_write(codec, ADC310X_PLL_J_VAL, 24);
	snd_soc_write(codec, ADC310X_PLL_D_VAL_MSB, 0x00);
	snd_soc_write(codec, ADC310X_PLL_D_VAL_LSB, 0x00);
	snd_soc_write(codec, ADC310X_NADC_CLK, 0x90);
	snd_soc_write(codec, ADC310X_MADC_CLK, 0x86);
	snd_soc_write(codec, ADC310X_AOSR, 0x40);
	snd_soc_write(codec, ADC310X_BLCK_N_DIV, 0x81);
	snd_soc_write(codec, ADC310X_ADC_PROC_BLK, 0x01);
	snd_soc_write(codec, ADC310X_ADC_INTF_CTRL_2, 0x03);
	snd_soc_write(codec, ADC310X_ADC_VOL_L, 0x00);
	snd_soc_write(codec, ADC310X_ADC_VOL_R, 0x0);
	/*snd_soc_write(codec, ADC310X_MIC_BIAS_CTRL, 0x00); */
	snd_soc_write(codec, ADC310X_DMCLK_GPIO2, 0x28);
	snd_soc_write(codec, ADC310X_DMDIN_GPIO1, 0x04);

	return 0;
}

static bool adc310x_is_shared_reset(struct adc310x_priv *adc310x)
{
	struct adc310x_priv *a;

	list_for_each_entry(a, &reset_list, list) {
		if (gpio_is_valid(adc310x->gpio_reset) &&
		    adc310x->gpio_reset == a->gpio_reset)
			return true;
	}

	return false;
}

static int adc310x_regulator_event(struct notifier_block *nb,
				   unsigned long event, void *data)
{
	struct adc310x_disable_nb *disable_nb =
	    container_of(nb, struct adc310x_disable_nb, nb);
	struct adc310x_priv *adc310x = disable_nb->adc310x;

	if (event & REGULATOR_EVENT_DISABLE) {
		/*
		 * Put codec to reset and require cache sync as at least one
		 * of the supplies was disabled
		 */
		if (gpio_is_valid(adc310x->gpio_reset))
			gpio_set_value(adc310x->gpio_reset, 0);
		regcache_mark_dirty(adc310x->regmap);
	}

	return 0;
}

static int adc310x_set_power(struct snd_soc_codec *codec, int power)
{
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	int ret;
#if 0
	unsigned int i;

	printk("%s: Enter (%d)\n", __func__, power);
	for (i = 0; i < ARRAY_SIZE(adc310x_reg); i++) {
		uint8_t v = snd_soc_read(codec, adc310x_reg[i].reg);

		printk("%1u.%03u: %02X / %u\n", adc310x_reg[i].reg >> 7,
		       adc310x_reg[i].reg % 128, v, v);
	}
#endif

	if (power) {
		ret = regulator_bulk_enable(ARRAY_SIZE(adc310x->supplies),
					    adc310x->supplies);
		if (ret)
			goto out;
		adc310x->power = 1;

		if (gpio_is_valid(adc310x->gpio_reset)) {
			gpio_set_value(adc310x->gpio_reset, 0);
			udelay(100);
			gpio_set_value(adc310x->gpio_reset, 1);
		}

		adc310x_init(codec);
		/* Sync reg_cache with the hardware */
		regcache_cache_only(adc310x->regmap, false);
		regcache_sync(adc310x->regmap);
	} else {
		/*
		 * Do soft reset to this codec instance in order to clear
		 * possible VDD leakage currents in case the supply regulators
		 * remain on
		 */
		snd_soc_write(codec, ADC310X_PAGE_SELECT, PAGE0_SELECT);
		snd_soc_write(codec, ADC310X_RESET, SOFT_RESET);
		regcache_mark_dirty(adc310x->regmap);
		adc310x->power = 0;
		/* HW writes are needless when bias is off */
		regcache_cache_only(adc310x->regmap, true);
		ret = regulator_bulk_disable(ARRAY_SIZE(adc310x->supplies),
					     adc310x->supplies);
	}
out:
	return ret;
}

static int adc310x_set_bias_level(struct snd_soc_codec *codec,
				  enum snd_soc_bias_level level)
{
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);

	switch (level) {
	case SND_SOC_BIAS_ON:
		break;
	case SND_SOC_BIAS_PREPARE:
		printk("%s: Level is %i\n", __func__, level);
		break;
	case SND_SOC_BIAS_STANDBY:
		if (!adc310x->power)
			adc310x_set_power(codec, 1);
		if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_PREPARE
		    && adc310x->master) {
			printk("%s: Level is %i\n", __func__, level);
		}
		break;
	case SND_SOC_BIAS_OFF:
		if (adc310x->power)
			adc310x_set_power(codec, 0);
		break;
	}

	return 0;
}

static int adc310x_probe(struct snd_soc_codec *codec)
{
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	int ret, i;

	INIT_LIST_HEAD(&adc310x->list);
	adc310x->codec = codec;

	for (i = 0; i < ARRAY_SIZE(adc310x->supplies); i++) {
		adc310x->disable_nb[i].nb.notifier_call =
		    adc310x_regulator_event;
		adc310x->disable_nb[i].adc310x = adc310x;
		ret = regulator_register_notifier(adc310x->supplies[i].consumer,
						  &adc310x->disable_nb[i].nb);
		if (ret) {
			dev_err(codec->dev,
				"Failed to request regulator notifier: %d\n",
				ret);
			goto err_notif;
		}
	}

	regcache_mark_dirty(adc310x->regmap);
	/* set mic bias voltage */
	switch (adc310x->micbias1_vg) {
	case ADC310X_MICBIAS_2_0V:
	case ADC310X_MICBIAS_2_5V:
	case ADC310X_MICBIAS_AVDDV:
		snd_soc_update_bits(codec, ADC310X_MIC_BIAS_CTRL,
				    MICBIAS1_MASK,
				    (adc310x->micbias1_vg) << MICBIAS1_SHIFT);
		break;
	case ADC310X_MICBIAS_OFF:
		/*
		 * nothing to do. target won't enter here. This is just to avoid
		 * compile time warning "warning: enumeration value
		 * 'ADC310X_MICBIAS_OFF' not handled in switch"
		 */
		break;
	}

	/* set mic bias voltage */
	switch (adc310x->micbias2_vg) {
	case ADC310X_MICBIAS_2_0V:
	case ADC310X_MICBIAS_2_5V:
	case ADC310X_MICBIAS_AVDDV:
		snd_soc_update_bits(codec, ADC310X_MIC_BIAS_CTRL,
				    MICBIAS2_MASK,
				    (adc310x->micbias2_vg) << MICBIAS2_SHIFT);
		break;
	case ADC310X_MICBIAS_OFF:
		/*
		 * nothing to do. target won't enter here. This is just to avoid
		 * compile time warning "warning: enumeration value
		 * 'ADC310X_MICBIAS_OFF' not handled in switch"
		 */
		break;
	}

	adc310x_init(codec);

	return 0;

err_notif:
	while (i--)
		regulator_unregister_notifier(adc310x->supplies[i].consumer,
					      &adc310x->disable_nb[i].nb);
	return ret;
}

static int adc310x_remove(struct snd_soc_codec *codec)
{
	struct adc310x_priv *adc310x = snd_soc_codec_get_drvdata(codec);
	int i;

	list_del(&adc310x->list);
	for (i = 0; i < ARRAY_SIZE(adc310x->supplies); i++)
		regulator_unregister_notifier(adc310x->supplies[i].consumer,
					      &adc310x->disable_nb[i].nb);

	return 0;
}

static struct snd_soc_codec_driver soc_codec_dev_adc310x = {
	.set_bias_level = adc310x_set_bias_level,
	.idle_bias_off = true,
	.probe = adc310x_probe,
	.remove = adc310x_remove,

	.component_driver = {
			     .controls = adc310x_snd_controls,
			     .num_controls = ARRAY_SIZE(adc310x_snd_controls),

			     .dapm_widgets = adc310x_dapm_widgets,
			     .num_dapm_widgets =
			     ARRAY_SIZE(adc310x_dapm_widgets),

			     .dapm_routes = routes,
			     .num_dapm_routes = ARRAY_SIZE(routes),
			     }
};

static int adc310x_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	struct adc310x_pdata *pdata = i2c->dev.platform_data;
	struct adc310x_priv *adc310x;
	struct adc310x_setup_data *adc310x_setup;
	struct device_node *np = i2c->dev.of_node;
	int ret, i;
	u32 value;

	adc310x = devm_kzalloc(&i2c->dev, sizeof(struct adc310x_priv),
			       GFP_KERNEL);
	if (!adc310x)
		return -ENOMEM;

	adc310x->regmap = devm_regmap_init_i2c(i2c, &adc310x_regmap);
	if (IS_ERR(adc310x->regmap)) {
		ret = PTR_ERR(adc310x->regmap);
		return ret;
	}

	regcache_cache_only(adc310x->regmap, false);

	i2c_set_clientdata(i2c, adc310x);
	if (pdata) {
		adc310x->gpio_reset = pdata->gpio_reset;
		adc310x->setup = pdata->setup;
		adc310x->micbias1_vg = pdata->micbias1_vg;
		adc310x->micbias2_vg = pdata->micbias2_vg;
	} else if (np) {
		adc310x_setup = devm_kzalloc(&i2c->dev, sizeof(*adc310x_setup),
					     GFP_KERNEL);
		if (!adc310x_setup)
			return -ENOMEM;

		ret = of_get_named_gpio(np, "gpio-reset", 0);
		if (ret >= 0)
			adc310x->gpio_reset = ret;
		else
			adc310x->gpio_reset = -1;

		if (of_property_read_u32_array(np, "adc310x-gpio-func",
					       adc310x_setup->gpio_func,
					       2) >= 0) {
			adc310x->setup = adc310x_setup;
		}

		if (!of_property_read_u32(np, "adc310x-micbias1-vg", &value)) {
			switch (value) {
			case 1:
				adc310x->micbias1_vg = ADC310X_MICBIAS_2_0V;
				break;
			case 2:
				adc310x->micbias1_vg = ADC310X_MICBIAS_2_5V;
				break;
			case 3:
				adc310x->micbias1_vg = ADC310X_MICBIAS_AVDDV;
				break;
			default:
				adc310x->micbias1_vg = ADC310X_MICBIAS_OFF;
			}
		} else {
			adc310x->micbias2_vg = ADC310X_MICBIAS_OFF;
		}
		if (!of_property_read_u32(np, "adc310x-micbias2-vg", &value)) {
			switch (value) {
			case 1:
				adc310x->micbias2_vg = ADC310X_MICBIAS_2_0V;
				break;
			case 2:
				adc310x->micbias2_vg = ADC310X_MICBIAS_2_5V;
				break;
			case 3:
				adc310x->micbias2_vg = ADC310X_MICBIAS_AVDDV;
				break;
			default:
				adc310x->micbias2_vg = ADC310X_MICBIAS_OFF;
			}
		} else {
			adc310x->micbias2_vg = ADC310X_MICBIAS_OFF;
		}

	} else {
		adc310x->gpio_reset = -1;
	}

	adc310x->i2c = i2c;
#if defined(CONFIG_SND_SOC_DBG_TLV320ADC310X)
	tlv320adc310x_init_debug(adc310x);
#endif
	adc310x->model = id->driver_data;
	if (gpio_is_valid(adc310x->gpio_reset) &&
	    !adc310x_is_shared_reset(adc310x)) {
		ret = gpio_request(adc310x->gpio_reset, "tlv320adc310x reset");
		if (ret != 0)
			goto err;
		gpio_direction_output(adc310x->gpio_reset, 0);
	}

	for (i = 0; i < ARRAY_SIZE(adc310x->supplies); i++)
		adc310x->supplies[i].supply = adc310x_supply_names[i];

	ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(adc310x->supplies),
				      adc310x->supplies);
	if (ret != 0) {
		dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
		goto err_gpio;
	}

	ret = snd_soc_register_codec(&i2c->dev,
				     &soc_codec_dev_adc310x, &adc310x_dai, 1);

	if (ret != 0)
		goto err_gpio;

	list_add(&adc310x->list, &reset_list);

	return 0;

err_gpio:
	if (gpio_is_valid(adc310x->gpio_reset) &&
	    !adc310x_is_shared_reset(adc310x))
		gpio_free(adc310x->gpio_reset);
err:
	return ret;
}

static int adc310x_i2c_remove(struct i2c_client *client)
{
	struct adc310x_priv *adc310x = i2c_get_clientdata(client);

	snd_soc_unregister_codec(&client->dev);
	if (gpio_is_valid(adc310x->gpio_reset) &&
	    !adc310x_is_shared_reset(adc310x)) {
		gpio_set_value(adc310x->gpio_reset, 0);
		gpio_free(adc310x->gpio_reset);
	}
	return 0;
}

#if defined(CONFIG_OF)
static const struct of_device_id tlv320adc310x_of_match[] = {
	{.compatible = "ti,tlv320adc310x"},
	{.compatible = "ti,tlv320adc3101"},
	{.compatible = "ti,tlv320adc3104"},
	{},
};

MODULE_DEVICE_TABLE(of, tlv320adc310x_of_match);
#endif

static const struct i2c_device_id adc310x_i2c_id[] = {
	{"tlv320adc310x", ADC310X_MODEL_310X},
	{"tlv320adc3101", ADC310X_MODEL_3101},
	{"tlv320adc3104", ADC310X_MODEL_3104},
	{}
};

MODULE_DEVICE_TABLE(i2c, adc310x_i2c_id);

/* machine i2c codec control layer */
static struct i2c_driver adc310x_i2c_driver = {
	.driver = {
		   .name = "tlv320adc310x-codec",
		   .of_match_table = of_match_ptr(tlv320adc310x_of_match),
		   },
	.probe = adc310x_i2c_probe,
	.remove = adc310x_i2c_remove,
	.id_table = adc310x_i2c_id,
};

module_i2c_driver(adc310x_i2c_driver);

MODULE_DESCRIPTION("ASoC TLV320ADC310X codec driver");
MODULE_AUTHOR("Dan Murphy");
MODULE_LICENSE("Dual BSD/GPL");
