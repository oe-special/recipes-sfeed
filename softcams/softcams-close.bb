SUMMARY = "meta file for enigma2 softcam packages"

require conf/license/license-gplv2.inc

PROVIDES = "openatv-softcams"

SOFTCAMS = "\
	enigma2-plugin-softcams-oscam-smod \
	enigma2-plugin-softcams-oscam-smod-ipv4only \
	enigma2-plugin-softcams-oscam-emu \
	enigma2-plugin-softcams-oscam-emu-ipv4only \
	enigma2-plugin-softcams-oscam-trunk \
	enigma2-plugin-softcams-oscam-trunk-ipv4only \
	\
        ${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-doscam", "", d)} \
        ${@bb.utils.contains("DEFAULTTUNE", "cortexa9hf-neon", "enigma2-plugin-softcams-doscam", "", d)} \
	\
        ${@bb.utils.contains("TARGET_ARCH", "mipsel", "enigma2-plugin-softcams-cccam", "", d)} \
        ${@bb.utils.contains("DEFAULTTUNE", "cortexa15hf-neon-vfpv4", "enigma2-plugin-softcams-cccam", "", d)} \
        ${@bb.utils.contains("DEFAULTTUNE", "aarch64", "enigma2-plugin-softcams-cccam", "", d)} \
"

DEPENDS = "\
	${SOFTCAMS} \
"
    
PR = "r0"
